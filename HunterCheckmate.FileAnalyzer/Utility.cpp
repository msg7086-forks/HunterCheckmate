#include "Utility.h"


namespace HunterCheckmate_FileAnalyzer
{
	Utility::Utility(Endian endian, const std::string &file_path)
	{
		this->endian = endian;
		this->ifstream = std::ifstream(file_path.c_str(), std::ios::binary | std::ios::out | std::ios::in | std::ios::ate);
		this->ofstream = std::ofstream(file_path.c_str(), std::ios::binary | std::ios::out | std::ios::in | std::ios::ate);
	}
	
	void Utility::Write(std::vector<char>* data, uint32_t offset, uint32_t size)
	{
		if (size == 0) size = data->size();

		for (auto it = data->begin(); it != data->end(); ++it)
		{
			const uint32_t idx = it - data->begin();
			this->ofstream.seekp(offset + idx);
			this->ofstream.put(*it);
		}
	}
}