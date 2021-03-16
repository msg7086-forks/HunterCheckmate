#pragma once
#include "Utility.h"

namespace HunterCheckmate_FileAnalyzer
{
	enum class LaytonAnimal : uint32_t
	{
		Moose = 0,
		Jackrabbit = 1,
		Mallard = 2,
		BlackBear = 3,
		RooseveltElk = 4,
		Coyote = 5,
		BlacktailDeer = 6,
		WhitetailDeer = 7
	};
	
	// in little endian
	struct AnimalData
	{
		std::vector<char> *whitetail_great_one_0;
		std::vector<char> *whitetail_great_one_1;
		std::vector<char> *whitetail_max_weight_diamond;

		AnimalData()
		{
			whitetail_great_one_0 = new std::vector<char>({
					'\x00','\x00','\x00','\x00',
					'\x4B','\x78','\xCA','\x42',
					'\xAA','\x1F','\x94','\x43',
					'\x01','\x00','\x00','\x00',
					'\x16','\x37','\x00','\x00',
					'\x00','\x00','\x00','\x00',
					'\x00','\x00','\x00','\x00',
					'\x00','\x00','\x00','\x00'
				});

			whitetail_great_one_1 = new std::vector<char>({
					'\x01','\x00','\x00','\x00',
					'\x00','\x7E','\xD6','\x42',
					'\x42','\xE0','\x0A','\x44',
					'\x01','\x00','\x00','\x00',
					'\x16','\x37','\x00','\x00',
					'\x00','\x00','\x00','\x00',
					'\x00','\x00','\x00','\x00',
					'\x00','\x00','\x00','\x00'
				});

			whitetail_max_weight_diamond = new std::vector<char>({
					'\x01','\x00','\x00','\x00',
					'\x00','\x00','\xC8','\x42',
					'\x7E','\xC4','\x89','\x43',
					'\x00','\x00','\x00','\x00',
					'\x16','\x37','\x00','\x00',
					'\x00','\x00','\x00','\x00',
					'\x00','\x00','\x00','\x00',
					'\x00','\x00','\x00','\x00'
				});
		}

		~AnimalData()
		{
			delete whitetail_great_one_0;
			delete whitetail_great_one_1;
			delete whitetail_max_weight_diamond;
		}
	};
	
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
		char* comment = new char[32];

		AdfHeader() = default;
		~AdfHeader() { delete[] comment; }
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
		Type type;
		uint32_t size;
		uint32_t alignment;
		uint32_t name_hash;
		uint64_t name_idx;
		uint32_t name;
		uint32_t flags;
		uint32_t element_type_hash;
		uint32_t element_length;
		uint32_t member_count;
		std::vector<MemberHeader> member_headers;

		TypedefHeader() = default;
		~TypedefHeader() = default;
	};

	struct StrhashHeader{};

	struct NametableHeader
	{
		std::vector<uint8_t>* size;
		std::vector<std::string>* name;

		NametableHeader() = default;
		~NametableHeader()
		{
			delete size;
			delete name;
		}
	};

	static TypedefHeader* HashExists(uint32_t hash, std::vector<TypedefHeader> *header_typedefs);
	
	class Member
	{
	public:
		TypedefHeader *header_typedef;
		MemberHeader *header_member;
		Type type = Type::None;
		Primitive primitive = Primitive::NONE;
		uint32_t offset = 0;
		uint32_t size = 0;
		char* data;
		std::vector<Member> *sub_members;

		Member();
		Member(TypedefHeader* header_typedef, MemberHeader *header_member);
		~Member();
	};

	class Instance
	{
	public:
		std::vector<TypedefHeader> *header_typedefs;
		Utility *utility;
		InstanceHeader *header_instance;
		TypedefHeader *header_typedef;
		std::vector<Member> *members = nullptr;

		Instance(std::vector<TypedefHeader> *header_typedefs, Utility *utility, InstanceHeader *header_instance, TypedefHeader *header_typedef);
		~Instance();

		void PopulatePrimitive(Member *member, MemberHeader *header_member, uint32_t offset, Primitive primitive) const;
		void PopulateStructure(Member *member, uint32_t offset, TypedefHeader *header_typedef);
		void PopulateArray(Member *member, TypedefHeader *header_typedef, uint32_t offset, uint32_t size);
		void PopulateMembers();
	};
	
	class AdfFile
	{
	private:
		const uint32_t sig = 0x41444620;
		bool initialized = false;
		
		uint32_t GetAnimalOffset(LaytonAnimal population_idx, uint32_t group_idx, uint32_t animal_idx) const;
	public:
		Utility *utility;
		AdfHeader *header;
		std::vector<InstanceHeader> *header_instances;
		std::vector<TypedefHeader> *header_typedef;
		std::vector<StrhashHeader> *header_strhash;
		NametableHeader *header_nametable;
		std::vector<Instance> *instances;
		
		AdfFile(Utility *utility);
		~AdfFile();
		bool Deserialize();
		uint32_t GetNumberOfGroups(LaytonAnimal population_idx) const;
		uint32_t GetGroupSize(LaytonAnimal population_idx, uint32_t group_idx) const;
		bool ReplaceAnimal(std::vector<char> *animal_info, LaytonAnimal population_idx, uint32_t group_idx, uint32_t animal_idx) const;
		bool ReplaceAnimal(std::vector<char> *animal_info, uint32_t offset) const;
	};
}