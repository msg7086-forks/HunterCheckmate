#include "AnimalPopulation.h"

namespace HunterCheckmate_FileAnalyzer
{
	AnimalPopulation::AnimalPopulation(std::shared_ptr<FileHandler> file_handler, uint8_t reserve_id) : AdfFile(file_handler)
	{
		this->reserve_data = ReserveData(reserve_id);
	}

	uint32_t AnimalPopulation::ResolveNameHash(uint32_t name_hash)
	{
		auto it = this->instances.at(0).members.at(1).sub_members.begin();
		for (; it != this->instances.at(0).members.at(1).sub_members.end(); ++it)
		{
			const uint32_t idx = it - this->instances.at(0).members.at(1).sub_members.begin();
			const uint32_t it_hash = *reinterpret_cast<uint32_t*>(it->sub_members.at(0).data.data());
			if (it_hash == name_hash) return idx;
		}
		return 0;
	}

	uint32_t AnimalPopulation::GetAnimalOffset(const std::string &name, uint32_t group_idx, uint32_t animal_idx)
	{
		if (!m_initialized) return 0;
		return this->instances.at(0).members.at(1).sub_members.at(ResolveNameHash(this->reserve_data.GetNameHash(name)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2)
			.sub_members.at(animal_idx).offset;
	}

	bool AnimalPopulation::IsValidAnimal(const std::string &name, const uint32_t group_idx, const uint32_t animal_idx)
	{
		if (!m_initialized) return false;

		const uint32_t name_idx = ResolveNameHash(this->reserve_data.GetNameHash(name));
		if (name_idx == UINT32_MAX) return false;
		if (group_idx >= this->instances.at(0).members.at(1).sub_members.at(name_idx)
			.sub_members.at(1).sub_members.size()) return false;

		if (animal_idx >= this->instances.at(0).members.at(1).sub_members.at(name_idx)
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2).sub_members.size()) return false;

		return true;
	}

	uint8_t AnimalPopulation::GetGender(const std::string &name, uint32_t group_idx, uint32_t animal_idx)
	{
		if (!m_initialized) return 0;

		std::vector<char> data = this->instances.at(0).members.at(1).sub_members.at(ResolveNameHash(this->reserve_data.GetNameHash(name)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2).sub_members.at(animal_idx).sub_members.at(0).data;
		return *reinterpret_cast<int8_t*>(data.data());
	}

	float AnimalPopulation::GetWeight(const std::string &name, uint32_t group_idx, uint32_t animal_idx)
	{
		if (!m_initialized) return 0;

		std::vector<char> data = this->instances.at(0).members.at(1).sub_members.at(ResolveNameHash(this->reserve_data.GetNameHash(name)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2).sub_members.at(animal_idx).sub_members.at(1).data;
		return *reinterpret_cast<float*>(data.data());
	}

	float AnimalPopulation::GetScore(const std::string &name, uint32_t group_idx, uint32_t animal_idx)
	{
		if (!m_initialized) return 0;

		std::vector<char> data = this->instances.at(0).members.at(1).sub_members.at(ResolveNameHash(this->reserve_data.GetNameHash(name)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2).sub_members.at(animal_idx).sub_members.at(2).data;
		return *reinterpret_cast<float*>(data.data());
	}

	bool AnimalPopulation::IsGreatOne(const std::string &name, uint32_t group_idx, uint32_t animal_idx)
	{
		if (!m_initialized) return 0;

		std::vector<char> data = this->instances.at(0).members.at(1).sub_members.at(ResolveNameHash(this->reserve_data.GetNameHash(name)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2).sub_members.at(animal_idx).sub_members.at(3).data;
		return *reinterpret_cast<bool*>(data.data());
	}

	uint32_t AnimalPopulation::GetVisualVariationSeed(const std::string &name, uint32_t group_idx, uint32_t animal_idx)
	{
		if (!m_initialized) return 0;

		std::vector<char> data = this->instances.at(0).members.at(1).sub_members.at(ResolveNameHash(this->reserve_data.GetNameHash(name)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2).sub_members.at(animal_idx).sub_members.at(4).data;
		return *reinterpret_cast<uint32_t*>(data.data());
	}

	int32_t AnimalPopulation::GetSpawnAreaId(const std::string &name, uint32_t group_idx)
	{
		if (!m_initialized) return 0;

		std::vector<char> data = this->instances.at(0).members.at(1).sub_members.at(ResolveNameHash(this->reserve_data.GetNameHash(name)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(0).data;
		return *reinterpret_cast<int32_t*>(data.data());
	}

	uint32_t AnimalPopulation::GetNumberOfGroups(const std::string &name)
	{
		if (!m_initialized) return 0;
		return this->instances.at(0).members.at(1).sub_members.at(ResolveNameHash(this->reserve_data.GetNameHash(name)))
			.sub_members.at(1).sub_members.size();
	}

	uint32_t AnimalPopulation::GetGroupSize(const std::string &name, uint32_t group_idx)
	{
		if (!m_initialized) return 0;
		return this->instances.at(0).members.at(1).sub_members.at(ResolveNameHash(this->reserve_data.GetNameHash(name)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2)
			.sub_members.size();
	}

	bool AnimalPopulation::ReplaceAnimal(std::vector<char> *animal_info, const std::string &name, uint32_t group_idx, uint32_t animal_idx)
	{
		const uint32_t offset = this->GetAnimalOffset(name, group_idx, animal_idx);
		if (offset != 0)
		{
			this->file_handler->write(animal_info, offset, animal_info->size());
			return true;
		}
		return false;
	}

	bool AnimalPopulation::ReplaceAnimal(std::vector<char> *animal_info, uint32_t offset)
	{
		this->file_handler->write(animal_info, offset, animal_info->size());
		return true;
	}

	bool AnimalPopulation::ReplaceAnimal(AnimalData* animal_data, const std::string &name, uint32_t group_idx, uint32_t animal_idx)
	{
		const uint32_t offset = this->GetAnimalOffset(name, group_idx, animal_idx);
		std::vector<char> data = animal_data->GetBytes();
		this->file_handler->write(&data, offset, data.size());
		return true;
	}

	bool AnimalPopulation::ReplaceAnimal(AnimalData *animal_data, uint32_t offset)
	{
		std::vector<char> data = animal_data->GetBytes();
		this->file_handler->write(&data, offset, data.size());
		return true;
	}

	AnimalData *AnimalPopulation::GenerateAnimalData(std::string name, std::string gender, float weight, float score, uint8_t is_great_one, uint32_t visual_variation_seed)
	{
		AnimalData *animal_data = new AnimalData(&this->reserve_data);
		if (animal_data->SetId(name) && animal_data->SetGender(gender) && animal_data->SetWeight(weight) && animal_data->SetScore(score)
			&& animal_data->SetIsGreatOne(is_great_one) && animal_data->SetVisualVariationSeed(visual_variation_seed))
		{
			return animal_data;
		}
		return nullptr;
	}

	AnimalData* AnimalPopulation::GenerateAnimalData(std::string name, std::string gender, std::string weight, std::string score,
		std::string visual_variation_seed)
	{
		AnimalData *animal_data = new AnimalData(&this->reserve_data);

		if (animal_data->SetId(name) && animal_data->SetGender(gender) && animal_data->SetWeight(weight)
			&& animal_data->SetScore(score) && animal_data->SetIsGreatOne(0) && animal_data->SetVisualVariationSeed(visual_variation_seed))
		{
			return animal_data;
		}
		return nullptr;
	}

	AnimalData* AnimalPopulation::GenerateAnimalData(std::string name, std::string gender, std::string weight, std::string score,
		std::string is_great_one, std::string visual_variation_seed)
	{
		AnimalData *animal_data = new AnimalData(&this->reserve_data);

		if (animal_data->SetId(name) && animal_data->SetGender(gender) && animal_data->SetWeight(weight)
			&& animal_data->SetScore(score) && animal_data->SetIsGreatOne(is_great_one) && animal_data->SetVisualVariationSeed(visual_variation_seed))
		{
			return animal_data;
		}
		return nullptr;
	}

	void AnimalPopulation::GenerateMap()
	{
		if (m_initialized)
		{

			auto it_begin = reserve_data.animal_names.begin();
			auto it_end = reserve_data.animal_names.end();

			for (; it_begin != it_end; ++it_begin)
			{
				std::string animal_name = it_begin->first;
				std::vector<AnimalGroupData> animal_groups;

				uint32_t total_number_of_animals = 0;
				const uint32_t number_of_groups = GetNumberOfGroups(it_begin->first);

				for (uint32_t j = 0; j < number_of_groups; j++)
				{
					std::vector<AnimalData> _animals;

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

						AnimalData animal_data = AnimalData(&reserve_data);
						animal_data.SetName(animal_name);
						animal_data.SetIdx(k);
						animal_data.SetGender(i_gender);
						animal_data.SetWeight(weight);
						animal_data.SetScore(score);
						animal_data.SetIsGreatOne(is_great_one);
						animal_data.SetVisualVariationSeed(visual_variation_seed);

						_animals.push_back(animal_data);
					}

					animal_groups.emplace_back(AnimalGroupData(animal_name, group_size, j, spawn_area_id, _animals));
				}

				this->animals.insert_or_assign(animal_name, animal_groups);
			}
		}
	}

	std::ostream& operator<<(std::ostream& out, const AnimalPopulation& data)
	{
		auto it_beg = data.animals.begin();
		auto it_end = data.animals.end();

		for(;it_beg != it_end; ++it_beg)
		{
			out << "========== " << it_beg->first << " Groups [ #" << it_beg->second.size() << " ] ==========\n";

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
					out << " [ " << std::setw(2) << it_beg3->idx
						<< " | " << std::setw(6) << it_beg3->str_gender
						<< " | " << std::setw(7) << it_beg3->weight
						<< " | " << std::setw(8) << it_beg3->score
						<< " | " << std::setw(1) << static_cast<int>(it_beg3->is_great_one)
						<< " | " << std::setw(5) << it_beg3->visual_variation_seed
						<< " ]\n";
				}
				out << "\n\n";
			}
		}
		return out;
	}
}