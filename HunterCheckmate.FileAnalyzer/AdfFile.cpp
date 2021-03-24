#include "AdfFile.h"

namespace HunterCheckmate_FileAnalyzer
{
	static TypedefHeader *HashExists(uint32_t hash, std::vector<TypedefHeader> *header_typedefs)
	{
		for (auto iterator = header_typedefs->begin(); iterator != header_typedefs->end(); ++iterator)
		{
			if (hash == iterator->name_hash) return &*iterator;
		}
		return nullptr;
	}

	Member::Member()
	{
			this->header_typedef = nullptr;
			this->header_member = nullptr;
			this->type = Type::None;
			this->primitive = Primitive::NONE;
			this->offset = 0;
			this->size = 0;
			this->data = nullptr;
			this->sub_members = nullptr;
	}

	Member::Member(TypedefHeader* header_typedef, MemberHeader *header_member)
	{
		this->header_typedef = header_typedef;
		this->header_member = header_member;
		this->type = Type::None;
		this->primitive = Primitive::NONE;
		this->offset = 0;
		this->size = 0;
		this->data = nullptr;
		this->sub_members = new std::vector<Member>(header_typedef->member_count);
	}

	Member::~Member()
	{
		delete sub_members;
		delete[] data;
	}
	
	Instance::Instance(std::vector<TypedefHeader>* header_typedefs, Utility *utility, InstanceHeader *header_instance, TypedefHeader *header_typedef)
	{
		this->header_typedefs = header_typedefs;
		this->utility = utility;
		this->header_instance = header_instance;
		this->header_typedef = header_typedef;
		this->members = new std::vector<Member>(this->header_typedef->member_headers.size());
	}

	Instance::~Instance()
	{
		delete members;
	}

	void Instance::PopulatePrimitive(Member *member, MemberHeader *header_member, uint32_t offset, Primitive primitive) const
	{
		member->header_typedef = nullptr;
		member->header_member = header_member;
		member->type = Type::Primitive;
		member->primitive = primitive;
		member->offset = offset;
		
		switch (member->primitive)
		{
		case (Primitive::UINT64_T):
			member->size = sizeof(uint64_t);
			break;
		case (Primitive::SINT32_T):
		case (Primitive::UINT32_T):
		case (Primitive::FLOAT):
			member->size = sizeof(float);
			break;
		case (Primitive::UINT8_T):
			member->size = sizeof(uint8_t);
			break;
		default:
			break;
		}

		char* data = new char[member->size];
		utility->Read(data, offset, member->size);
		member->data = data;
	}

	void Instance::PopulateStructure(Member *member, uint32_t offset, TypedefHeader *header_typedef)
	{
		member->header_typedef = header_typedef;
		member->type = header_typedef->type;
		member->primitive = Primitive::NONE;
		member->offset = offset;
		member->size = header_typedef->size;
		member->sub_members = new std::vector<Member>(header_typedef->member_count);

		for (auto it = member->sub_members->begin(); it != member->sub_members->end(); ++it)
		{
			uint32_t idx = it - member->sub_members->begin();
			MemberHeader *header_member = &header_typedef->member_headers.at(idx);
			TypedefHeader *sub_typedef = HashExists(header_member->type_hash, this->header_typedefs);

			const uint32_t tmp_offset = member->offset + header_member->offset;

			if (sub_typedef == nullptr) PopulatePrimitive(&*it, header_member, tmp_offset, Primitive(header_member->type_hash));
			else
			{
				switch (sub_typedef->type)
				{
				case (Type::Array):
					{
					char* buffer = new char[8];

					utility->Read(buffer, tmp_offset + 0x8, 8);
					uint32_t array_elem_count;
					memcpy(&array_elem_count, buffer, 4);

					utility->Read(buffer, tmp_offset, 8);
					uint32_t array_data_offset;
					memcpy(&array_data_offset, buffer, 4);
					delete[] buffer;

					PopulateArray(&*it, sub_typedef, this->header_instance->offset + array_data_offset, array_elem_count);

					break;
					}
				case (Type::Structure):
					PopulateStructure(&*it, tmp_offset, sub_typedef);
					break;
				default:
					break;
				}
			}
		}
	}
	
	void Instance::PopulateArray(Member *member, TypedefHeader *header_typedef, uint32_t offset, uint32_t size, bool is_inline)
	{
		member->header_typedef = header_typedef;
		member->header_member = nullptr;
		member->type = header_typedef->type;
		member->primitive = Primitive::NONE;
		member->offset = offset;
		member->size = size;
		if (is_inline) member->sub_members = new std::vector<Member>(header_typedef->element_length);
		else member->sub_members = new std::vector<Member>(size);

		TypedefHeader *sub_typedef = HashExists(header_typedef->element_type_hash, this->header_typedefs);

		if (sub_typedef == nullptr)
		{
			for (auto it = member->sub_members->begin(); it != member->sub_members->end(); ++it)
			{
				const uint32_t idx = it - member->sub_members->begin();
				const Primitive prim = Primitive(header_typedef->element_type_hash);
				uint32_t tmp_size;
				switch (prim)
				{
				case (Primitive::UINT64_T):
					tmp_size = sizeof(uint64_t);
					break;
				case (Primitive::SINT32_T):
				case (Primitive::UINT32_T):
				case (Primitive::FLOAT):
					tmp_size = sizeof(float);
					break;
				case (Primitive::UINT8_T):
					tmp_size = sizeof(uint8_t);
					break;
				default:
					tmp_size = 0;
					break;
				}
				PopulatePrimitive(&*it, nullptr, offset + idx * tmp_size , prim);
			}
		}
		else
		{
			switch (sub_typedef->type)
			{
			case (Type::Array):
				break; // shouldn't happen in testing
			case (Type::Structure):
			{
				for (auto it = member->sub_members->begin(); it != member->sub_members->end(); ++it)
				{
					const uint32_t idx = it - member->sub_members->begin();
					const uint32_t tmp_offset = offset + idx * sub_typedef->size;
					PopulateStructure(&*it, tmp_offset, sub_typedef);
				}
				break;
			}
			default:
				break;
			}
		}
	}
	
	void Instance::PopulateMembers()
	{
		uint32_t base = this->header_instance->offset;

		for (auto it = members->begin(); it != members->end(); ++it)
		{
			Member* current = &*it;
			uint32_t idx = it - members->begin();
			MemberHeader* member_header = &header_typedef->member_headers.at(idx);
			uint32_t offset = base + member_header->offset;

			TypedefHeader* sub_typedef = HashExists(member_header->type_hash, this->header_typedefs);
			if (sub_typedef == nullptr)	PopulatePrimitive(current, member_header, offset, Primitive(member_header->type_hash));
			else
			{
				switch (sub_typedef->type)
				{
				case(Type::Array):
				{
					char* buffer = new char[8];
					
					utility->Read(buffer, offset + 0x8, 8);
					uint32_t array_elem_count;
					memcpy(&array_elem_count, buffer, 4);
						
					utility->Read(buffer, offset, 8);
					uint32_t array_data_offset;
					memcpy(&array_data_offset, buffer, 4);
					delete[] buffer;
						
					PopulateArray(current, sub_typedef, base + array_data_offset, array_elem_count);

					break;
				}
				case (Type::Structure):
				{
					PopulateStructure(&*it, offset, sub_typedef);
					break;
				}
				case (Type::InlineArray):
				{
					uint32_t inline_offset = base + member_header->offset;
					uint32_t size = sub_typedef->element_length;
					PopulateArray(&*it, sub_typedef, inline_offset, size, true);
					break;
				}
				default:
					break;
				}
			}
		}
	}

	AdfFile::AdfFile(Utility *utility)
	{
		this->utility = utility;
		this->header = AdfHeader();
		this->header_instances = std::vector<InstanceHeader>(0);
		this->header_typedef = std::vector<TypedefHeader>(0);
		this->header_strhash = std::vector<StrhashHeader>(0);
		this->header_nametable = NametableHeader();
		this->instances = std::vector<Instance>(0);
	}

	AdfFile::~AdfFile()
	{
		delete utility;
	}

	bool AdfFile::SigMatch() const
	{
		uint32_t tmp_sig;
		utility->Read(&tmp_sig, 0x0);
		return  tmp_sig == this->sig;
	}

	
	bool AdfFile::Deserialize()
	{
		constexpr uint32_t TYPEDEF_SIZE = 0x28;
		constexpr uint32_t MEMBER_SIZE = 0x20;

		if (!SigMatch()) return false;

		header.sig = this->sig;
		utility->Read(&header.version, 0x4);
		utility->Read(&header.instance_count, 0x8);
		utility->Read(&header.instance_offset, 0xC);
		utility->Read(&header.typedef_count, 0x10);
		utility->Read(&header.typedef_offset, 0x14);
		utility->Read(&header.strhash_count, 0x18);
		utility->Read(&header.strhash_offset, 0x1C);
		utility->Read(&header.nametable_count, 0x20);
		utility->Read(&header.nametable_offset, 0x24);
		utility->Read(&header.total_size, 0x28);
		utility->Read(&header.unknown_0x2C, 0x2C);
		utility->Read(&header.unknown_0x30, 0x30);
		utility->Read(&header.unknown_0x34, 0x34);
		utility->Read(&header.unknown_0x38, 0x38);
		utility->Read(&header.unknown_0x3C, 0x3C);

		for (uint32_t i = 0; i < header.instance_count; i++)
		{
			auto* buffer = new InstanceHeader;
			const uint32_t base = header.instance_offset;
			utility->Read(&buffer->name_hash, base);
			utility->Read(&buffer->type_hash, base + 0x4);
			utility->Read(&buffer->offset, base + 0x8);
			utility->Read(&buffer->size, base + 0xC);
			utility->Read(&buffer->name_idx, base + 0x10);

			header_instances.push_back(*buffer);
			delete buffer;
		}

		uint32_t num_previous_members = 0;
		for (uint32_t i = 0; i < header.typedef_count; i++)
		{
			auto* buffer = new TypedefHeader;
			uint32_t base;
			if (i == 0) base = header.typedef_offset;
			else base = header.typedef_offset + TYPEDEF_SIZE * i + num_previous_members * MEMBER_SIZE;

			utility->Read(&buffer->type, base);
			utility->Read(&buffer->size, base + 0x4);
			utility->Read(&buffer->alignment, base + 0x8);
			utility->Read(&buffer->name_hash, base + 0xC);
			utility->Read(&buffer->name_idx, base + 0x10);
			utility->Read(&buffer->flags, base + 0x18);
			utility->Read(&buffer->element_type_hash, base + 0x1C);
			utility->Read(&buffer->element_length, base + 0x20);
			utility->Read(&buffer->member_count, base + 0x24);

			num_previous_members += buffer->member_count;

			switch (buffer->type)
			{
			case Type::Structure:
			{
				for (uint32_t j = 0; j < buffer->member_count; j++)
				{
					MemberHeader member_header = MemberHeader();
					const uint32_t member_base = base + TYPEDEF_SIZE + MEMBER_SIZE * j;
					utility->Read(&member_header.name_idx, member_base);
					utility->Read(&member_header.type_hash, member_base + 0x8);
					utility->Read(&member_header.size, member_base + 0xC);
					utility->Read(&member_header.offset, member_base + 0x10);
					utility->Read(&member_header.default_type, member_base + 0x14);
					utility->Read(&member_header.default_value, member_base + 0x18);
					buffer->member_headers.push_back(member_header);
				}
				break;
			}
			default:
				break;
			}

			header_typedef.push_back(*buffer);
			delete buffer;
		}

		header_nametable.size = std::vector<uint8_t>(header.nametable_count);
		header_nametable.name = std::vector<std::string>(header.nametable_count);

		for (uint32_t i = 0; i < header.nametable_count; i++)
		{
			uint8_t buffer;
			const uint32_t base = header.nametable_offset + sizeof(uint8_t) * i;
			utility->Read(&buffer, base, sizeof(uint8_t));
			header_nametable.size.at(i) = buffer;
		}

		uint32_t current_offset = 0;
		for (uint32_t i = 0; i < header.nametable_count; i++)
		{
			char* buffer = new char[header_nametable.size.at(i) + 1];
			const uint32_t base = header.nametable_offset + header.nametable_count + current_offset;
			utility->Read(buffer, base, header_nametable.size.at(i));
			current_offset += header_nametable.size.at(i) + 1;

			for (uint32_t j = 0; j < header_nametable.size.at(i); j++)
			{
				header_nametable.name.at(i).push_back(buffer[j]);
			}
			delete[] buffer;
		}

		for (auto it = header_instances.begin(); it != header_instances.end(); ++it)
		{
			uint32_t idx = it - header_instances.begin();
			auto* instance = new Instance(&this->header_typedef, this->utility, &*it, &this->header_typedef.at(idx));
			instance->PopulateMembers();
			instances.push_back(*instance);
		}

		this->initialized = true;
		return true;
	}
}
