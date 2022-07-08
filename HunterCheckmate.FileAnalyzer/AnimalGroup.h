#pragma once
#include <cstdint>
#include <vector>
#include "Animal.h"

namespace HunterCheckmate_FileAnalyzer
{
	class AnimalGroup
	{
	public:
		AnimalType m_animal_type;
		std::string m_name;
		uint32_t m_size;
		uint32_t m_index;
		int32_t m_spawn_area_id;
		std::vector<Animal> m_animals;
		float m_max_weight;
		float m_max_score;
		AnimalGroup() = default;
		AnimalGroup(AnimalType animal_type, std::string& name, uint32_t index, int32_t spawn_area_id, std::vector<Animal> animals);
		AnimalGroup(AnimalType animal_type, std::string& name, uint32_t index, int32_t spawn_area_id, std::vector<Animal> animals, float max_weight, float max_score);
		~AnimalGroup() = default;
		friend std::ostream& operator<<(std::ostream& out, const AnimalGroup& data);
		static bool cmpHighestWeight(Animal& a, Animal& b);
		static bool cmpLowestWeight(Animal& a, Animal& b);
		static bool cmpHighestScore(Animal& a, Animal& b);
		static bool cmpLowestScore(Animal& a, Animal& b);
		static bool cmpIdx(Animal& a, Animal& b);
		static bool cmpFurTypeA(Animal& a, Animal& b);
		static bool cmpFurTypeZ(Animal& a, Animal& b);
	};
}
