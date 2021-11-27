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
		FileHandler(Endian endian, const fs::path file_path);
		~FileHandler() = default;

		void open();
		void close();

		template<class T>
		void read(T* data, uint32_t offset, uint32_t size = 0)
		{
			this->open();

			if (size == 0) size = sizeof(*data);

			auto *buffer = new std::vector<char>(size);

			this->fstream.seekg(offset);
			for (auto& i : *buffer) this->fstream.get(i);
			if (endian == Endian::Big) std::reverse(buffer->begin(), buffer->end());
			memcpy(data, buffer->data(), size);

			delete buffer;

			this->close();
		}

		void write(std::vector<char>* data, uint32_t offset, uint32_t size = 0);
	};
}