#pragma once
#include "FileHandler.h"
#include "Animal.h"

namespace HunterCheckmate_FileAnalyzer
{
	enum class Type : uint32_t
	{
		Primitive = 0,
		Structure = 1,
		Pointer = 2,
		Array = 3,
		InlineArray = 4,
		String = 5,
		BitField = 6,
		Enumeration = 7,
		StringHash = 8,
		None = 9
	};

	enum class Primitive : uint32_t
	{
		UINT8_T = 0xCA2821D,
		UINT32_T = 0x075E4E4F,
		UINT64_T = 0xA139E01F,
		SINT32_T = 0x192FE633,
		FLOAT = 0x7515A207,
		NONE = 0x0
	};

	static const char* typeString[] = {
		"Primitive", "Structure", "Pointer", "Array", "InlineArray", "String", "BitField","Enumeration", "StringHash"
	};

	static const char* primitiveString(Primitive primitive)
	{
		switch (primitive)
		{
		case (Primitive::UINT8_T):
			return "UINT8_T";
		case (Primitive::UINT32_T):
			return "UINT32_T";
		case (Primitive::UINT64_T):
			return "UINT64_T";
		case (Primitive::SINT32_T):
			return "SINT32_T";
		case (Primitive::FLOAT):
			return "FLOAT";
		case (Primitive::NONE):
		default:
			return "NONE";
		}
	}
	
	struct AdfHeader
	{
		uint32_t sig;
		uint32_t version;
		uint32_t instance_count;
		uint32_t instance_offset;
		uint32_t typedef_count;
		uint32_t typedef_offset;
		uint32_t strhash_count;
		uint32_t strhash_offset;
		uint32_t nametable_count;
		uint32_t nametable_offset;
		uint32_t total_size;
		uint32_t unknown_0x2C;
		uint32_t unknown_0x30;
		uint32_t unknown_0x34;
		uint32_t unknown_0x38;
		uint32_t unknown_0x3C;
		//comment

		AdfHeader() = default;
		~AdfHeader() = default;
		AdfHeader(AdfHeader& other) = default;
		AdfHeader& operator=(const AdfHeader& other) = default;
		AdfHeader(AdfHeader&& other) = default;
		AdfHeader& operator=(AdfHeader&& other) = default;
	};

	struct InstanceHeader
	{
		uint32_t name_hash;
		uint32_t type_hash;
		uint32_t offset;
		uint32_t size;
		uint64_t name_idx;

		InstanceHeader() = default;
		~InstanceHeader() = default;
	};

	struct MemberHeader
	{
		uint64_t name_idx;
		uint32_t name;
		uint32_t type_hash;
		uint32_t size;
		uint32_t offset;
		uint32_t default_type;
		uint64_t default_value;

		MemberHeader() = default;
		~MemberHeader() = default;
	};

	struct TypedefHeader
	{
		Type type = Type::None;
		uint32_t size = 0;
		uint32_t alignment = 0;
		uint32_t name_hash = 0;
		uint64_t name_idx = 0;
		uint32_t name = 0;
		uint32_t flags = 0;
		uint32_t element_type_hash = 0;
		uint32_t element_length = 0;
		uint32_t member_count = 0;
		std::vector<MemberHeader> member_headers;

		TypedefHeader() = default;
		~TypedefHeader() = default;
	};

	struct StrhashHeader{};

	struct NametableHeader
	{
		std::vector<uint8_t> size;
		std::vector<std::string> name;

		NametableHeader() = default;
		~NametableHeader() = default;
	};

	static TypedefHeader* HashExists(uint32_t hash, std::vector<TypedefHeader> *header_typedefs);
	
	class Member
	{
	public:
		TypedefHeader *header_typedef = nullptr;
		MemberHeader *header_member = nullptr;
		Type type = Type::None;
		Primitive primitive = Primitive::NONE;
		uint32_t offset = 0;
		uint32_t size = 0;
		std::vector<char> data;
		std::vector<Member> sub_members;

		Member();
		Member(TypedefHeader* header_typedef, MemberHeader *header_member);
		~Member() = default;
	};

	class Instance
	{
	public:
		std::vector<TypedefHeader> *header_typedefs = nullptr;
		std::shared_ptr<FileHandler> m_file_handler = nullptr;
		InstanceHeader *header_instance = nullptr;
		TypedefHeader *header_typedef = nullptr;
		std::vector<Member> members;

		Instance() = default;
		Instance(std::vector<TypedefHeader> *header_typedefs, std::shared_ptr<FileHandler> file_handler, InstanceHeader *header_instance, TypedefHeader *header_typedef);
		~Instance() = default;

		void PopulatePrimitive(Member *member, MemberHeader *header_member, uint32_t offset, Primitive primitive) const;
		void PopulateStructure(Member *member, uint32_t offset, TypedefHeader *header_typedef);
		void PopulateArray(Member *member, TypedefHeader *header_typedef, uint32_t offset, uint32_t size, bool is_inline = false);
		void PopulateMembers();
	};
	
	class AdfFile
	{
	private:
		bool SigMatch() const;
		bool DeserializeHeader();
		bool DeserializeInstanceHeader();
		bool DeserializeTypedefHeader();
		bool DeserializeMemberHeader(TypedefHeader & typedefHeader, uint32_t base, uint32_t typedef_size, uint32_t member_size) const;
		bool DeserializeNametableHeader();
		bool DeserializeInstances();

	protected:
		uint32_t m_sig;
		bool m_valid;
		bool m_initialized;
		std::shared_ptr<FileHandler> m_file_handler;
	public:
		AdfHeader header;
		std::vector<InstanceHeader> header_instances;
		std::vector<TypedefHeader> header_typedef;
		std::vector<StrhashHeader> header_strhash;
		NametableHeader header_nametable;
		std::vector<Instance> instances;
		
		AdfFile(std::shared_ptr<FileHandler> file_handler);
		~AdfFile() = default;

		bool Deserialize();
	};
}