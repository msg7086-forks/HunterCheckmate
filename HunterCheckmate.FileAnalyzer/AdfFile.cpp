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
			this->offset = 0x0;
			this->size = 0x0;
			this->data = std::vector<char>();
			this->sub_members = std::vector<Member>(0);
	}

	Member::Member(TypedefHeader* header_typedef, MemberHeader *header_member)
	{
		this->header_typedef = header_typedef;
		this->header_member = header_member;
		this->type = Type::None;
		this->primitive = Primitive::NONE;
		this->offset = 0;
		this->size = 0;
		this->data = std::vector<char>();
		this->sub_members = std::vector<Member>(header_typedef->member_count);
	}
	
	Instance::Instance(std::vector<TypedefHeader>* header_typedefs, std::shared_ptr<FileHandler> file_handler, InstanceHeader *header_instance, TypedefHeader *header_typedef)
	{
		this->header_typedefs = header_typedefs;
		this->m_file_handler = file_handler;
		this->header_instance = header_instance;
		this->header_typedef = header_typedef;
		this->members = std::vector<Member>(this->header_typedef->member_headers.size());
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
		case (Primitive::UINT16_T):
			member->size = sizeof(uint16_t);
		case (Primitive::UINT8_T):
			member->size = sizeof(uint8_t);
			break;
		case (Primitive::STRING):
			member->size = sizeof(uint64_t);
			break;
		case(Primitive::NONE):
		default:
			break;
		}

		std::vector<char> data = std::vector<char>(member->size);
		m_file_handler->read(data.data(), offset, data.size());
		member->data = data;
	}

	void Instance::PopulateStructure(Member *member, uint32_t offset, TypedefHeader *header_typedef)
	{
		member->header_typedef = header_typedef;
		member->type = header_typedef->type;
		member->primitive = Primitive::NONE;
		member->offset = offset;
		member->size = header_typedef->size;
		member->sub_members = std::vector<Member>(header_typedef->member_count);

		for (auto it = member->sub_members.begin(); it != member->sub_members.end(); ++it)
		{
			uint32_t idx = it - member->sub_members.begin();
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
					std::vector<char> buffer(8);

					m_file_handler->read(buffer.data(), tmp_offset + 0x8, buffer.size());
					uint32_t array_elem_count;
					memcpy(&array_elem_count, buffer.data(), sizeof(array_elem_count));

					m_file_handler->read(buffer.data(), tmp_offset, buffer.size());
					uint32_t array_data_offset;
					memcpy(&array_data_offset, buffer.data(), sizeof(array_data_offset));

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
		if (is_inline) member->sub_members = std::vector<Member>(header_typedef->element_length);
		else member->sub_members = std::vector<Member>(size);

		TypedefHeader *sub_typedef = HashExists(header_typedef->element_type_hash, this->header_typedefs);

		if (sub_typedef == nullptr)
		{
			for (auto it = member->sub_members.begin(); it != member->sub_members.end(); ++it)
			{
				const uint32_t idx = it - member->sub_members.begin();
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
				for (auto it = member->sub_members.begin(); it != member->sub_members.end(); ++it)
				{
					const uint32_t idx = it - member->sub_members.begin();
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

		for (auto it = members.begin(); it != members.end(); ++it)
		{
			Member* current = &*it;
			uint32_t idx = it - members.begin();
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
					std::vector<char> buffer = std::vector<char>(8);

					m_file_handler->read(buffer.data(), offset + 0x8, buffer.size());
					uint32_t array_elem_count;
					memcpy(&array_elem_count, buffer.data(), sizeof(array_elem_count));
						
					m_file_handler->read(buffer.data(), offset, buffer.size());
					uint32_t array_data_offset;
					memcpy(&array_data_offset, buffer.data(), sizeof(array_data_offset));
						
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

	AdfFile::AdfFile(std::shared_ptr<FileHandler> file_handler)
		: m_sig(0x41444620),
		m_initialized(false),
		m_file_handler(std::move(file_handler)),
		header(AdfHeader()),
		header_instances(std::vector<InstanceHeader>(0)),
		header_typedef(std::vector<TypedefHeader>(0)),
		header_strhash(std::vector<StrhashHeader>(0)),
		header_nametable(NametableHeader()),
		instances(std::vector<Instance>(0))
	{
		m_valid = SigMatch();
	}

	bool AdfFile::SigMatch() const
	{
		uint32_t tmp_sig;
		m_file_handler->read(&tmp_sig, 0x0);
		return tmp_sig == m_sig;
	}

	bool AdfFile::DeserializeHeader()
	{
		header.sig = m_sig;
		m_file_handler->read(&header.version, 0x4);
		m_file_handler->read(&header.instance_count, 0x8);
		m_file_handler->read(&header.instance_offset, 0xC);
		m_file_handler->read(&header.typedef_count, 0x10);
		m_file_handler->read(&header.typedef_offset, 0x14);
		m_file_handler->read(&header.strhash_count, 0x18);
		m_file_handler->read(&header.strhash_offset, 0x1C);
		m_file_handler->read(&header.nametable_count, 0x20);
		m_file_handler->read(&header.nametable_offset, 0x24);
		m_file_handler->read(&header.total_size, 0x28);
		m_file_handler->read(&header.unknown_0x2C, 0x2C);
		m_file_handler->read(&header.unknown_0x30, 0x30);
		m_file_handler->read(&header.unknown_0x34, 0x34);
		m_file_handler->read(&header.unknown_0x38, 0x38);
		m_file_handler->read(&header.unknown_0x3C, 0x3C);

		return true;
	}

	bool AdfFile::DeserializeInstanceHeader()
	{
		for (uint32_t i = 0; i < header.instance_count; i++)
		{
			InstanceHeader buffer = InstanceHeader();
			const uint32_t base = header.instance_offset;

			m_file_handler->read(&buffer.name_hash, base);
			m_file_handler->read(&buffer.type_hash, base + 0x4);
			m_file_handler->read(&buffer.offset, base + 0x8);
			m_file_handler->read(&buffer.size, base + 0xC);
			m_file_handler->read(&buffer.name_idx, base + 0x10);
			header_instances.push_back(buffer);
		}

		return true;
	}

	bool AdfFile::DeserializeTypedefHeader()
	{
		constexpr uint32_t TYPEDEF_SIZE = 0x28;
		constexpr uint32_t MEMBER_SIZE = 0x20;
		uint32_t num_previous_members = 0;
		for (uint32_t i = 0; i < header.typedef_count; i++)
		{
			std::unique_ptr<TypedefHeader> buffer = std::make_unique<TypedefHeader>();
			const uint32_t base = header.typedef_offset + TYPEDEF_SIZE * i + num_previous_members * MEMBER_SIZE;

			m_file_handler->read(&buffer->type, base);
			m_file_handler->read(&buffer->size, base + 0x4);
			m_file_handler->read(&buffer->alignment, base + 0x8);
			m_file_handler->read(&buffer->name_hash, base + 0xC);
			m_file_handler->read(&buffer->name_idx, base + 0x10);
			m_file_handler->read(&buffer->flags, base + 0x18);
			m_file_handler->read(&buffer->element_type_hash, base + 0x1C);
			m_file_handler->read(&buffer->element_length, base + 0x20);
			m_file_handler->read(&buffer->member_count, base + 0x24);

			num_previous_members += buffer->member_count;

			DeserializeMemberHeader(*buffer, base, TYPEDEF_SIZE, MEMBER_SIZE);
			header_typedef.push_back(*buffer);
		}
		return true;
	}

	bool AdfFile::DeserializeMemberHeader(TypedefHeader& typedefHeader, uint32_t base, uint32_t typedef_size, uint32_t member_size) const
	{
		switch (typedefHeader.type)
		{
		case Type::Structure:
		{
			for (uint32_t i = 0; i < typedefHeader.member_count; i++)
			{
				MemberHeader member_header = MemberHeader();
				const uint32_t member_base = base + typedef_size + member_size * i;
				m_file_handler->read(&member_header.name_idx, member_base);
				m_file_handler->read(&member_header.type_hash, member_base + 0x8);
				m_file_handler->read(&member_header.size, member_base + 0xC);
				m_file_handler->read(&member_header.offset, member_base + 0x10);
				m_file_handler->read(&member_header.default_type, member_base + 0x14);
				m_file_handler->read(&member_header.default_value, member_base + 0x18);
				typedefHeader.member_headers.push_back(member_header);
			}
			break;
		}
		default:
			break;
		}
		return true;
	}

	bool AdfFile::DeserializeNametableHeader()
	{
		header_nametable.size = std::vector<uint8_t>(header.nametable_count);
		header_nametable.name = std::vector<std::string>(header.nametable_count);

		for (uint32_t i = 0; i < header.nametable_count; i++)
		{
			uint8_t buffer;
			const uint32_t base = header.nametable_offset + sizeof(uint8_t) * i;
			m_file_handler->read(&buffer, base, sizeof(buffer));
			header_nametable.size.at(i) = buffer;
		}

		uint32_t current_offset = 0;
		for (uint32_t i = 0; i < header.nametable_count; i++)
		{
			std::vector<char> buffer(header_nametable.size.at(i) + 1);
			const uint32_t base = header.nametable_offset + header.nametable_count + current_offset;

			m_file_handler->read(buffer.data(), base, buffer.size());
			current_offset += header_nametable.size.at(i) + 1;

			header_nametable.name.at(i).push_back(*buffer.data());

			//for (uint32_t j = 0; j < header_nametable.size.at(i); j++)
			//{
			//	header_nametable.name.at(i).push_back(buffer.at(j));
			//}
		}

		return true;
	}

	bool AdfFile::DeserializeInstances()
	{
		for (auto it = header_instances.begin(); it != header_instances.end(); ++it)
		{
			const uint32_t idx = it - header_instances.begin();
			std::unique_ptr<Instance> instance = std::make_unique<Instance>(&header_typedef, m_file_handler, &*it, &header_typedef.at(idx));
			instance->PopulateMembers();
			instances.push_back(*instance);
		}

		return true;
	}

	bool AdfFile::Deserialize()
	{
		if (!m_valid) return false;
		m_initialized = DeserializeHeader() && DeserializeInstanceHeader() && DeserializeTypedefHeader() && DeserializeNametableHeader() && DeserializeInstances();
		return m_initialized ;
	}

	bool AdfFile::Compress()
	{
		boost::filesystem::path in_path("C:\\Users\\oleSQL\\Documents\\thehunter working\\pop\\animalishXD");

		boost::filesystem::ifstream ifs(in_path, std::ios::in | std::ios::binary);
		std::string temp = "\x01\x01";
		temp += '\0';
		temp += '\0';
		temp += '\0';

		std::istreambuf_iterator<char> it_ifs = std::istreambuf_iterator<char>(ifs);
		for (; it_ifs != std::istreambuf_iterator<char>(); ++it_ifs)
			temp += *it_ifs;

		ifs.close();

		std::stringstream ofs;
		ofs << "\x53\x41\x56\x45\x74\x2A\x23";
		ofs << '\0';
		ofs << "\x7E\x24\x04";
		ofs << '\0';
		ofs << '\0';
		ofs << '\0';
		ofs << '\0';
		ofs << '\0';
		ofs << "\x43\x4F\x4D\x50\x01\x01";
		ofs << '\0';
		ofs << '\0';
		ofs << "\x7E\x24\x04";
		ofs << '\0';
		ofs << '\0';
		ofs << '\0';
		ofs << '\0';
		ofs << '\0';

		boost::iostreams::filtering_streambuf<boost::iostreams::output> out;
		boost::iostreams::zlib_params zp;
		zp.level = 1;
		out.push(boost::iostreams::zlib_compressor(zp));
		out.push(ofs);

		boost::iostreams::copy(boost::iostreams::basic_array_source<char>(&temp[0], temp.size()), out);


		boost::filesystem::fstream of("C:\\Users\\oleSQL\\Documents\\thehunter working\\pop\\decomp_animalishXD", std::ios::out | std::ios::binary);
		
		boost::iostreams::copy(ofs, of);

		of.close();

		return true;
	}

	bool AdfFile::Decompress()
	{
		boost::filesystem::path in_path("C:\\Users\\oleSQL\\Documents\\thehunter working\\pop\\animal_population_0");
		
		boost::filesystem::ifstream ifs(in_path, std::ios::in | std::ios::binary);
		ifs.seekg(0x20);
		std::string temp((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
		ifs.close();


		std::stringstream ofs;

		boost::iostreams::filtering_streambuf<boost::iostreams::output> out;
		out.push(boost::iostreams::zlib_decompressor());
		out.push(ofs);

		std::cout << std::hex << temp << "\n";
		boost::iostreams::copy(boost::iostreams::basic_array_source<char>(&temp[0], temp.size()), out);



		boost::filesystem::fstream of("C:\\Users\\oleSQL\\Documents\\thehunter working\\pop\\animalishXD", std::ios::out | std::ios::binary);

		ofs.seekg(5);
		boost::iostreams::copy(ofs, of);

		of.close();

		return true;
	}
}
