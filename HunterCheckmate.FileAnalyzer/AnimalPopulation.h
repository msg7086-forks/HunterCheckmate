#pragma once
#include "AdfFile.h"

namespace HunterCheckmate_FileAnalyzer
{
	class AnimalPopulation : public AdfFile
	{
	private:
		uint32_t GetAnimalOffset(const std::string&name, uint32_t group_idx, uint32_t animal_idx) const;
	public:
		ReserveData *reserve_data;
		AnimalPopulation(Utility *utility, ReserveData *reserve_data);
		~AnimalPopulation();
		
		bool IsValidAnimal(const std::string& name, uint32_t group_idx, uint32_t animal_idx) const;
		uint8_t GetGender(const std::string &name, uint32_t group_idx, uint32_t animal_idx) const;
		float GetWeight(const std::string &name, uint32_t group_idx, uint32_t animal_idx) const;
		float GetScore(const std::string &name, uint32_t group_idx, uint32_t animal_idx) const;
		bool IsGreatOne(const std::string &name, uint32_t group_idx, uint32_t animal_idx) const;
		uint32_t GetVisualVariationSeed(const std::string &name, uint32_t group_idx, uint32_t animal_idx) const;
		int32_t GetSpawnAreaId(const std::string &name, uint32_t group_idx) const;
		uint32_t GetNumberOfGroups(const std::string &name) const;
		uint32_t GetGroupSize(const std::string &name, uint32_t group_idx) const;
		bool ReplaceAnimal(std::vector<char> *animal_info, const std::string &name, uint32_t group_idx, uint32_t animal_idx) const;
		bool ReplaceAnimal(std::vector<char> *animal_info, uint32_t offset) const;
		bool ReplaceAnimal(AnimalData *animal_data, const std::string &name, uint32_t group_idx, uint32_t animal_idx) const;
		bool ReplaceAnimal(AnimalData *animal_data, uint32_t offset) const;
		AnimalData *GenerateAnimalData(std::string name, std::string gender, float weight, float score, uint8_t is_great_one, uint32_t visual_variation_seed) const;
		AnimalData* GenerateAnimalData(std::string name, std::string gender, std::string weight, std::string score, std::string visual_variation_seed) const;
	};
}