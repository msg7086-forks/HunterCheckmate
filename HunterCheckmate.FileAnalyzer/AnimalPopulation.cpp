#include "AnimalPopulation.h"

namespace HunterCheckmate_FileAnalyzer
{
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
		if (!initialized) return 0;
		return this->instances.at(0).members.at(1).sub_members.at(ResolveNameHash(this->reserve_data.GetNameHash(name)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2)
			.sub_members.at(animal_idx).offset;
	}

	AnimalPopulation::AnimalPopulation(Utility *utility, uint8_t reserve_id): AdfFile(utility)
	{
		this->reserve_data = ReserveData(reserve_id);
	}

	bool AnimalPopulation::IsValidAnimal(const std::string &name, const uint32_t group_idx, const uint32_t animal_idx)
	{
		if (!initialized) return false;

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
		if (!initialized) return 0;

		std::vector<char> data = this->instances.at(0).members.at(1).sub_members.at(ResolveNameHash(this->reserve_data.GetNameHash(name)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2).sub_members.at(animal_idx).sub_members.at(0).data;
		return *reinterpret_cast<int8_t*>(data.data());
	}

	float AnimalPopulation::GetWeight(const std::string &name, uint32_t group_idx, uint32_t animal_idx)
	{
		if (!initialized) return 0;

		std::vector<char> data = this->instances.at(0).members.at(1).sub_members.at(ResolveNameHash(this->reserve_data.GetNameHash(name)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2).sub_members.at(animal_idx).sub_members.at(1).data;
		return *reinterpret_cast<float*>(data.data());
	}

	float AnimalPopulation::GetScore(const std::string &name, uint32_t group_idx, uint32_t animal_idx)
	{
		if (!initialized) return 0;

		std::vector<char> data = this->instances.at(0).members.at(1).sub_members.at(ResolveNameHash(this->reserve_data.GetNameHash(name)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2).sub_members.at(animal_idx).sub_members.at(2).data;
		return *reinterpret_cast<float*>(data.data());
	}

	bool AnimalPopulation::IsGreatOne(const std::string &name, uint32_t group_idx, uint32_t animal_idx)
	{
		if (!initialized) return 0;

		std::vector<char> data = this->instances.at(0).members.at(1).sub_members.at(ResolveNameHash(this->reserve_data.GetNameHash(name)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2).sub_members.at(animal_idx).sub_members.at(3).data;
		return *reinterpret_cast<bool*>(data.data());
	}

	uint32_t AnimalPopulation::GetVisualVariationSeed(const std::string &name, uint32_t group_idx, uint32_t animal_idx)
	{
		if (!initialized) return 0;

		std::vector<char> data = this->instances.at(0).members.at(1).sub_members.at(ResolveNameHash(this->reserve_data.GetNameHash(name)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2).sub_members.at(animal_idx).sub_members.at(4).data;
		return *reinterpret_cast<uint32_t*>(data.data());
	}

	int32_t AnimalPopulation::GetSpawnAreaId(const std::string &name, uint32_t group_idx)
	{
		if (!initialized) return 0;

		std::vector<char> data = this->instances.at(0).members.at(1).sub_members.at(ResolveNameHash(this->reserve_data.GetNameHash(name)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(0).data;
		return *reinterpret_cast<int32_t*>(data.data());
	}

	uint32_t AnimalPopulation::GetNumberOfGroups(const std::string &name)
	{
		if (!initialized) return 0;
		return this->instances.at(0).members.at(1).sub_members.at(ResolveNameHash(this->reserve_data.GetNameHash(name)))
			.sub_members.at(1).sub_members.size();
	}

	uint32_t AnimalPopulation::GetGroupSize(const std::string &name, uint32_t group_idx)
	{
		if (!initialized) return 0;
		return this->instances.at(0).members.at(1).sub_members.at(ResolveNameHash(this->reserve_data.GetNameHash(name)))
			.sub_members.at(1).sub_members.at(group_idx).sub_members.at(2)
			.sub_members.size();
	}

	bool AnimalPopulation::ReplaceAnimal(std::vector<char> *animal_info, const std::string &name, uint32_t group_idx, uint32_t animal_idx)
	{
		const uint32_t offset = this->GetAnimalOffset(name, group_idx, animal_idx);
		if (offset != 0)
		{
			this->utility->Write(animal_info, offset, animal_info->size());
			return true;
		}
		return false;
	}

	bool AnimalPopulation::ReplaceAnimal(std::vector<char> *animal_info, uint32_t offset)
	{
		this->utility->Write(animal_info, offset, animal_info->size());
		return true;
	}

	bool AnimalPopulation::ReplaceAnimal(AnimalData* animal_data, const std::string &name, uint32_t group_idx, uint32_t animal_idx)
	{
		const uint32_t offset = this->GetAnimalOffset(name, group_idx, animal_idx);
		std::vector<char> data = animal_data->GetBytes();
		this->utility->Write(&data, offset, data.size());
		return true;
	}

	bool AnimalPopulation::ReplaceAnimal(AnimalData *animal_data, uint32_t offset)
	{
		std::vector<char> data = animal_data->GetBytes();
		this->utility->Write(&data, offset, data.size());
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
}