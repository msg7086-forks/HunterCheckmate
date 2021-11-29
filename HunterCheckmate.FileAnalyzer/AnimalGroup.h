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
		uint32_t m_size;
		uint32_t m_index;
		uint32_t m_spawn_area_id;
		std::vector<Animal> m_animals;
		AnimalGroup(AnimalType animal_type , uint32_t index, uint32_t spawn_area_id, std::vector<Animal> animals);
		~AnimalGroup() = default;
		friend std::ostream& operator<<(std::ostream& out, const AnimalGroup& data);
	};
}
