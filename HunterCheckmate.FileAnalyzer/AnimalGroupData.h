#pragma once
#include <cstdint>
#include <vector>
#include "AnimalData.h"

namespace HunterCheckmate_FileAnalyzer
{
	class AnimalGroupData
	{
	public:
		std::string m_name;
		uint32_t m_size;
		uint32_t m_index;
		uint32_t m_spawn_area_id;
		std::vector<AnimalData> m_animals;
		AnimalGroupData(std::string& name, uint32_t size, uint32_t index, uint32_t spawn_area_id, std::vector<AnimalData> animals);
		~AnimalGroupData() = default;
		friend std::ostream& operator<<(std::ostream& out, const AnimalGroupData& data);
	};
}
