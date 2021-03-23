#pragma once
#include <fstream>
#include <boost/json.hpp>

namespace HunterCheckmate_FileAnalyzer
{
	class LoadoutData
	{
	private:
		std::ifstream *ifstream;
		boost::json::array data;
	public:
		LoadoutData();
		LoadoutData(std::ifstream *ifstream);
		~LoadoutData();
	};
}
