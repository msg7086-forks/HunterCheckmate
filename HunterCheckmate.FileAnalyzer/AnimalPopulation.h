#pragma once
#include "AdfFile.h"
#include "AnimalGroup.h"
#include "AnimalTypeEnum.h"
#include <iostream>

namespace HunterCheckmate_FileAnalyzer
{
	class AnimalPopulation : public AdfFile
	{
	private:
		uint32_t ResolveNameHash(uint32_t name_hash);
		uint32_t GetAnimalOffset(AnimalType animal_type, uint32_t group_idx, uint32_t animal_idx);
	public:
		std::shared_ptr<ReserveData> m_reserve_data;
		std::map<AnimalType, std::vector<AnimalGroup>> m_animals;
		AnimalPopulation(std::shared_ptr<FileHandler> file_handler, uint8_t reserve_id);
		AnimalPopulation(std::shared_ptr<FileHandler> file_handler, std::shared_ptr<ReserveData> reserve_data);
		~AnimalPopulation() = default;
		
		bool IsValidAnimal(AnimalType animal_type, uint32_t group_idx, uint32_t animal_idx);
		uint8_t GetGender(AnimalType animal_type, uint32_t group_idx, uint32_t animal_idx);
		float GetWeight(AnimalType animal_type, uint32_t group_idx, uint32_t animal_idx);
		float GetScore(AnimalType animal_type, uint32_t group_idx, uint32_t animal_idx);
		bool IsGreatOne(AnimalType animal_type, uint32_t group_idx, uint32_t animal_idx);
		uint32_t GetVisualVariationSeed(AnimalType animal_type, uint32_t group_idx, uint32_t animal_idx);
		int32_t GetSpawnAreaId(AnimalType animal_type, uint32_t group_idx);
		uint32_t GetNumberOfGroups(AnimalType animal_type);
		uint32_t GetGroupSize(AnimalType animal_type, uint32_t group_idx);

		bool ReplaceAnimal(std::vector<char> *animal_info, AnimalType animal_type, uint32_t group_idx, uint32_t animal_idx);
		bool ReplaceAnimal(std::vector<char> *animal_info, uint32_t offset);
		bool ReplaceAnimal(Animal *animal_data, AnimalType animal_type, uint32_t group_idx, uint32_t animal_idx);
		bool ReplaceAnimal(std::shared_ptr<Animal> animal_data, AnimalType animal_type, uint32_t group_idx,
		                   uint32_t animal_idx);
		bool ReplaceAnimal(Animal *animal_data, uint32_t offset);
		void GenerateMap();

		friend std::ostream& operator<<(std::ostream& out, const AnimalPopulation& data);
	};
}
