#include "LoadoutData.h"

namespace HunterCheckmate_FileAnalyzer
{
	LoadoutData::LoadoutData() = default;

	LoadoutData::LoadoutData(std::ifstream *ifstream)
	{
		this->ifstream = ifstream;
	}

	LoadoutData::~LoadoutData() = default;


}