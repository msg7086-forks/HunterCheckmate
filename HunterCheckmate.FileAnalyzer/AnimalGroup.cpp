#include "AnimalGroup.h"

namespace HunterCheckmate_FileAnalyzer
{
	AnimalGroup::AnimalGroup(AnimalType animal_type, std::string& name, uint32_t index, int32_t spawn_area_id, std::vector<Animal> animals)
		: m_animal_type(animal_type), m_name(name), m_index(index), m_spawn_area_id(spawn_area_id), m_animals(std::move(animals))
	{
		m_size = m_animals.size();
	}

	AnimalGroup::AnimalGroup(AnimalType animal_type, std::string & name, uint32_t index, int32_t spawn_area_id, std::vector<Animal> animals, float max_weight, float max_score)
		: m_animal_type(animal_type), m_name(name), m_index(index), m_spawn_area_id(spawn_area_id), m_animals(std::move(animals)), m_max_weight(max_weight), m_max_score(max_score)
	{
		m_size = m_animals.size();
	}

	bool AnimalGroup::cmpHighestWeight(Animal& a, Animal& b)
	{
		return (a.m_weight > b.m_weight);
	}

	bool AnimalGroup::cmpLowestWeight(Animal & a, Animal & b)
	{
		return (a.m_weight < b.m_weight);
	}

	bool AnimalGroup::cmpHighestScore(Animal & a, Animal & b)
	{
		return (a.m_score > b.m_score);
	}

	bool AnimalGroup::cmpLowestScore(Animal & a, Animal & b)
	{
		return (a.m_score < b.m_score);
	}

	bool AnimalGroup::cmpIdx(Animal & a, Animal & b)
	{
		return (a.m_idx < b.m_idx);
	}

	bool AnimalGroup::cmpFurTypeA(Animal & a, Animal & b)
	{
		return (a.m_fur_type < b.m_fur_type);
	}

	bool AnimalGroup::cmpFurTypeZ(Animal & a, Animal & b)
	{
		return (a.m_fur_type > b.m_fur_type);
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
