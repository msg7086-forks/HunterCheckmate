#include "AnimalGroup.h"

namespace HunterCheckmate_FileAnalyzer
{
	AnimalGroup::AnimalGroup(AnimalType animal_type, std::string& name, uint32_t index, int32_t spawn_area_id, std::vector<Animal> animals)
		: m_animal_type(animal_type), m_name(name), m_index(index), m_spawn_area_id(spawn_area_id), m_animals(std::move(animals))
	{
		m_size = m_animals.size();
	}

	std::ostream& operator<<(std::ostream& out, const AnimalGroup& data)
	{
		out << "\n" << "           " << "[ " << data.m_index
			<< " | #" << std::setw(2) << data.m_size
			<< " | " << std::setw(0) << data.m_spawn_area_id
			<< " ]\n";
		auto beg = data.m_animals.begin();
		auto end = data.m_animals.end();
		for (;beg != end; ++beg)
		{
			out << *beg;
		}

		return out;
	}
}
