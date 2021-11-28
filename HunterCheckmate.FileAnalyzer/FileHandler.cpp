#include "FileHandler.h"

namespace HunterCheckmate_FileAnalyzer
{
	FileHandler::FileHandler(Endian endian, const fs::path file_path)
		: endian(endian),
	      file_path(file_path),
	      fstream(file_path.generic_string(), fs::fstream::binary | fs::fstream::out | fs::fstream::in | fs::fstream::ate) {}

	void FileHandler::write(std::vector<char>* data, uint32_t offset, uint32_t size)
	{
		if (fstream.is_open())
		{
			if (size == 0) size = data->size();

			for (auto it = data->begin(); it != data->end(); ++it)
			{
				const uint32_t idx = it - data->begin();
				this->fstream.seekp(offset + idx);
				this->fstream.put(*it);
			}
		}
	}
}