#include "AnimalPopulation.h"

namespace HunterCheckmate_FileAnalyzer
{
	AnimalPopulation::AnimalPopulation(std::shared_ptr<FileHandler> file_handler, std::shared_ptr<ReserveData> reserve_data)
		: AdfFile(std::move(file_handler)), m_reserve_data(std::move(reserve_data)) {}

	uint32_t AnimalPopulation::ResolveNameHashToIdx(uint32_t name_hash)
	{
		auto it = instances.at(0).members.at(1).sub_members.begin();
		for (; it != instances.at(0).members.at(1).sub_members.end(); ++it)
		{
			const uint32_t idx = it - instances.at(0).members.at(1).sub_members.begin();
			const uint32_t it_hash = *reinterpret_cast<uint32_t*>(it->sub_members.at(0).data.data());
			if (it_hash == name_hash) return idx;
		}
		return UINT32_MAX;
	}

	uint32_t AnimalPopulation::GetAnimalOffset(AnimalType animal_type, uint32_t group_idx, uint32_t animal_idx)
	{
		if (!m_initialized) return 0;
		return instances.at(0).members.at(1).sub_members.at(ResolveNameHashToIdx(m_reserve_data->GetNameHash(animal_type)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2)
			.sub_members.at(animal_idx).offset;
	}

	bool AnimalPopulation::IsValidAnimal(AnimalType animal_type, const uint32_t group_idx, const uint32_t animal_idx)
	{
		if (!m_initialized) return false;

		const uint32_t name_idx = ResolveNameHashToIdx(m_reserve_data->GetNameHash(animal_type));
		if (name_idx == UINT32_MAX) return false;
		if (group_idx >= instances.at(0).members.at(1).sub_members.at(name_idx)
			.sub_members.at(1).sub_members.size()) return false;

		if (animal_idx >= instances.at(0).members.at(1).sub_members.at(name_idx)
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2).sub_members.size()) return false;

		return true;
	}

	uint8_t AnimalPopulation::GetGender(AnimalType animal_type, uint32_t group_idx, uint32_t animal_idx)
	{
		if (!m_initialized) return 0;

		std::vector<char> data = instances.at(0).members.at(1).sub_members.at(ResolveNameHashToIdx(m_reserve_data->GetNameHash(animal_type)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2).sub_members.at(animal_idx).sub_members.at(0).data;
		return *reinterpret_cast<int8_t*>(data.data());
	}

	float AnimalPopulation::GetWeight(AnimalType animal_type, uint32_t group_idx, uint32_t animal_idx)
	{
		if (!m_initialized) return 0;

		std::vector<char> data = instances.at(0).members.at(1).sub_members.at(ResolveNameHashToIdx(m_reserve_data->GetNameHash(animal_type)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2).sub_members.at(animal_idx).sub_members.at(1).data;
		return *reinterpret_cast<float*>(data.data());
	}

	float AnimalPopulation::GetScore(AnimalType animal_type, uint32_t group_idx, uint32_t animal_idx)
	{
		if (!m_initialized) return 0;

		std::vector<char> data = instances.at(0).members.at(1).sub_members.at(ResolveNameHashToIdx(m_reserve_data->GetNameHash(animal_type)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2).sub_members.at(animal_idx).sub_members.at(2).data;
		return *reinterpret_cast<float*>(data.data());
	}

	bool AnimalPopulation::IsGreatOne(AnimalType animal_type, uint32_t group_idx, uint32_t animal_idx)
	{
		if (!m_initialized) return 0;

		std::vector<char> data = instances.at(0).members.at(1).sub_members.at(ResolveNameHashToIdx(m_reserve_data->GetNameHash(animal_type)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2).sub_members.at(animal_idx).sub_members.at(3).data;
		return *reinterpret_cast<bool*>(data.data());
	}

	uint32_t AnimalPopulation::GetVisualVariationSeed(AnimalType animal_type, uint32_t group_idx, uint32_t animal_idx)
	{
		if (!m_initialized) return 0;

		std::vector<char> data = instances.at(0).members.at(1).sub_members.at(ResolveNameHashToIdx(m_reserve_data->GetNameHash(animal_type)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2).sub_members.at(animal_idx).sub_members.at(4).data;
		return *reinterpret_cast<uint32_t*>(data.data());
	}

	int32_t AnimalPopulation::GetSpawnAreaId(AnimalType animal_type, uint32_t group_idx)
	{
		if (!m_initialized) return 0;

		std::vector<char> data = instances.at(0).members.at(1).sub_members.at(ResolveNameHashToIdx(m_reserve_data->GetNameHash(animal_type)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(0).data;
		return *reinterpret_cast<int32_t*>(data.data());
	}

	uint32_t AnimalPopulation::GetNumberOfGroups(AnimalType animal_type)
	{
		if (!m_initialized) return 0;
		return instances.at(0).members.at(1).sub_members.at(ResolveNameHashToIdx(m_reserve_data->GetNameHash(animal_type)))
			.sub_members.at(1).sub_members.size();
	}

	uint32_t AnimalPopulation::GetGroupSize(AnimalType animal_type, uint32_t group_idx)
	{
		if (!m_initialized) return UINT32_MAX;
		return instances.at(0).members.at(1).sub_members.at(ResolveNameHashToIdx(m_reserve_data->GetNameHash(animal_type)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2)
			.sub_members.size();
	}

	bool AnimalPopulation::ReplaceAnimal(const std::shared_ptr<Animal>& animal_data, uint32_t group_idx, uint32_t animal_idx)
	{
		const uint32_t offset = GetAnimalOffset(animal_data->m_animal_type, group_idx, animal_idx);
		std::vector<char> data = animal_data->GetBytes();
		m_file_handler->write(&data, offset, data.size());
		return true;
	}

	// TODO: maybe optimize
	void AnimalPopulation::GenerateMap()
	{
		if (m_initialized)
		{
			auto it_begin = m_reserve_data->m_animals_hash.begin();
			auto it_end = m_reserve_data->m_animals_hash.end();

			for (; it_begin != it_end; ++it_begin)
			{
				AnimalType animal_type = it_begin->first;
				std::vector<AnimalGroup> animal_groups;

				uint32_t total_number_of_animals = 0;
				const uint32_t number_of_groups = GetNumberOfGroups(it_begin->first);

				for (uint32_t j = 0; j < number_of_groups; j++)
				{
					std::vector<Animal> _animals;
					std::string animal_name;

					uint32_t group_size = GetGroupSize(it_begin->first, j);
					total_number_of_animals += group_size;
					uint32_t spawn_area_id = GetSpawnAreaId(it_begin->first, j);

					for (uint32_t k = 0; k < group_size; k++)
					{
						const uint8_t i_gender = GetGender(it_begin->first, j, k);
						float weight = GetWeight(it_begin->first, j, k);
						float score = GetScore(it_begin->first, j, k);
						bool is_great_one = IsGreatOne(it_begin->first, j, k);
						uint32_t visual_variation_seed = GetVisualVariationSeed(it_begin->first, j, k);

						std::string str_gender;
						if (i_gender == 1) str_gender = "male";
						else if (i_gender == 2) str_gender = "female";
						else str_gender = "foomale";

						std::shared_ptr<Animal> animal_data = Animal::Create(animal_type, str_gender, 
							std::to_string(weight), std::to_string(score), std::to_string(is_great_one), std::to_string(visual_variation_seed), std::to_string(k));
						animal_name = animal_data->m_name;

						if (animal_data->m_valid)
						{
							_animals.push_back(*animal_data);
						}
					}

					animal_groups.emplace_back(AnimalGroup(animal_type, animal_name, j, spawn_area_id, _animals));
				}

				m_animals.emplace(animal_type, animal_groups);
			}
		}
	}

	// DONT USE, INDEX OUT OF BONDS POSSIBLE
	std::ostream& operator<<(std::ostream& out, const AnimalPopulation& data)
	{
		auto it_beg = data.m_animals.begin();
		auto it_end = data.m_animals.end();

		for(;it_beg != it_end; ++it_beg)
		{
			out << "========== " << it_beg->second.at(0).m_name << " Groups [ #" << it_beg->second.size() << " ] ==========\n";

			auto it_beg2 = it_beg->second.begin();
			auto it_end2 = it_beg->second.end();
			for (;it_beg2 != it_end2; ++it_beg2)
			{
				out << "           "
					<< " [ "	<< it_beg2->m_index
					<< " | #"	<< std::setw(2) << it_beg2->m_size
					<< " | "	<< std::setw(0) << it_beg2->m_spawn_area_id
					<< " ]\n";
				auto it_beg3 = it_beg2->m_animals.begin();
				auto it_end3 = it_beg2->m_animals.end();
				for (;it_beg3 != it_end3; ++it_beg3)
				{
					out << " [ " << std::setw(2) << it_beg3->m_idx
						<< " | " << std::setw(6) << it_beg3->m_str_gender
						<< " | " << std::setw(7) << it_beg3->m_weight
						<< " | " << std::setw(8) << it_beg3->m_score
						<< " | " << std::setw(1) << static_cast<int>(it_beg3->m_is_great_one)
						<< " | " << std::setw(5) << it_beg3->m_fur_type
						<< " ]\n";
				}
				out << "\n\n";
			}
		}
		return out;
	}

	/*
		void AnimalPopulation::PrintNameHashes()
		{
			if (m_initialized)
			{
				uint32_t size = instances.at(0).members.at(1).sub_members.size();

				for (uint32_t i = 0; i < size; i++)
				{
					std::cout << "NameHash: " << *reinterpret_cast<uint32_t*>(instances.at(0).members.at(1).sub_members.at(i).sub_members.at(0).data.data()) << "\n";
				}
			}
		}
	*/
}