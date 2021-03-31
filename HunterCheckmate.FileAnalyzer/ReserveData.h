#pragma once
#include <cstdint>
#include <map>
#include <string>
#include <vector>

namespace HunterCheckmate_FileAnalyzer
{
	class ReserveData
	{
	public:
		uint8_t id;
		std::map<std::string, uint32_t> animal_names;

		ReserveData() = default;
		ReserveData(uint8_t id);
		~ReserveData() = default;

		bool Verify() const;
		uint32_t GetNameHash(const std::string &name) const;
	};
}