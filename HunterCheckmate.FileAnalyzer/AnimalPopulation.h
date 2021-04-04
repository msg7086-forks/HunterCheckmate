#pragma once
#include "AdfFile.h"

namespace HunterCheckmate_FileAnalyzer
{
	class AnimalPopulation : public AdfFile
	{
	private:
		uint32_t ResolveNameHash(uint32_t name_hash);
		uint32_t GetAnimalOffset(const std::string&name, uint32_t group_idx, uint32_t animal_idx);
	public:
		ReserveData reserve_data;
		AnimalPopulation(Utility *utility, uint8_t reserve_id);
		~AnimalPopulation() = default;
		
		bool IsValidAnimal(const std::string& name, uint32_t group_idx, uint32_t animal_idx);
		uint8_t GetGender(const std::string &name, uint32_t group_idx, uint32_t animal_idx);
		float GetWeight(const std::string &name, uint32_t group_idx, uint32_t animal_idx);
		float GetScore(const std::string &name, uint32_t group_idx, uint32_t animal_idx);
		bool IsGreatOne(const std::string &name, uint32_t group_idx, uint32_t animal_idx);
		uint32_t GetVisualVariationSeed(const std::string &name, uint32_t group_idx, uint32_t animal_idx);
		int32_t GetSpawnAreaId(const std::string &name, uint32_t group_idx);
		uint32_t GetNumberOfGroups(const std::string &name);
		uint32_t GetGroupSize(const std::string &name, uint32_t group_idx);
		bool ReplaceAnimal(std::vector<char> *animal_info, const std::string &name, uint32_t group_idx, uint32_t animal_idx);
		bool ReplaceAnimal(std::vector<char> *animal_info, uint32_t offset);
		bool ReplaceAnimal(AnimalData *animal_data, const std::string &name, uint32_t group_idx, uint32_t animal_idx);
		bool ReplaceAnimal(AnimalData *animal_data, uint32_t offset);
		AnimalData *GenerateAnimalData(std::string name, std::string gender, float weight, float score, uint8_t is_great_one, uint32_t visual_variation_seed);
		AnimalData* GenerateAnimalData(std::string name, std::string gender, std::string weight, std::string score, std::string visual_variation_seed);
	};
}