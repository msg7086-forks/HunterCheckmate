#include "FileHandler.h"

namespace HunterCheckmate_FileAnalyzer
{
	FileHandler::FileHandler(Endian endian, const fs::path file_path)
	{
		this->endian = endian;
		this->file_path = file_path;
	}

	bool FileHandler::open()
	{
		fstream.open(file_path, fs::fstream::binary | fs::fstream::out | fs::fstream::in | fs::fstream::ate);
		return fstream.is_open();
	}

	void FileHandler::close()
	{
		fstream.close();
	}
	
	void FileHandler::write(std::vector<char>* data, uint32_t offset, uint32_t size)
	{
		this->open();

		if (size == 0) size = data->size();

		for (auto it = data->begin(); it != data->end(); ++it)
		{
			const uint32_t idx = it - data->begin();
			this->fstream.seekp(offset + idx);
			this->fstream.put(*it);
		}

		this->close();
	}
}