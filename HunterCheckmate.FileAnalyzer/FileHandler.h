#pragma once
#include <cstdint>
#include <fstream>
#include <algorithm>
#include <vector>
#include <boost/filesystem.hpp>

namespace HunterCheckmate_FileAnalyzer
{
	namespace fs = boost::filesystem;

	enum class Endian
	{
		Big,
		Little
	};
	
	class FileHandler
	{
	private:
		Endian endian;
		fs::path file_path;
		fs::fstream fstream;
	public:
		FileHandler() = default;
		FileHandler(Endian endian, const fs::path& file_path);
		FileHandler(const fs::path& file_path);
		~FileHandler() = default;

		template<class T>
		void read(T* data, uint32_t offset, size_t size = 0)
		{
			if(fstream.is_open())
			{
				if (size == 0) size = sizeof(*data);

				const std::unique_ptr<std::vector<char>> buffer = std::make_unique<std::vector<char>>(size);

				fstream.seekg(offset);
				for (auto& i : *buffer) this->fstream.get(i);
				if (endian == Endian::Big) std::reverse(buffer->begin(), buffer->end());
				memcpy(data, buffer->data(), size);
			}
		}

		void write(std::vector<char>* data, uint32_t offset, size_t size = 0);

		void write_json(const std::string& data);
	};
}