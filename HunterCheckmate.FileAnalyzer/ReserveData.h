#pragma once
#include <cstdint>
#include <map>
#include "AnimalTypeEnum.h"
#include <cctype>
#include <string>

namespace HunterCheckmate_FileAnalyzer
{
	class ReserveData
	{
	private:
		inline bool Verify() const;
	public:
		uint8_t m_id;
		std::map<AnimalType, uint32_t> m_animals_hash;
		bool m_valid;

		explicit ReserveData(const uint8_t id);
		~ReserveData() = default;
		ReserveData(const ReserveData& src) = default;
		ReserveData(ReserveData&& src) = default;
		ReserveData& operator=(const ReserveData& rhs) = default;
		ReserveData& operator=(ReserveData&& rhs) = default;

		uint32_t GetNameHash(AnimalType animal_type);

		static uint8_t ResolveFileNameToInt(std::string fn);
	};
}