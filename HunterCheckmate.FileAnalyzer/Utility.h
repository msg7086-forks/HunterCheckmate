#pragma once
#include <cstdint>
#include <fstream>
#include <algorithm>
#include <vector>

namespace HunterCheckmate_FileAnalyzer
{
	enum class Endian
	{
		Big,
		Little
	};
	
	class Utility
	{
	private:
		Endian endian;
		std::ifstream *ifstream;
		std::ofstream *ofstream;
	public:
		Utility() = default;
		Utility(Endian endian, std::ifstream *ifstream);
		Utility(Endian endian, std::ofstream *ofstream);
		Utility(Endian endian, std::ifstream *ifstream, std::ofstream *ofstream);

		~Utility();
		
		template<class T>
		void Read(T* data, uint32_t offset, uint32_t size = 0) const
		{
			if (size == 0) size = sizeof(*data);

			auto *buffer = new std::vector<char>(size);

			this->ifstream->seekg(offset);
			for (auto& i : *buffer) this->ifstream->get(i);
			if (endian == Endian::Big) std::reverse(buffer->begin(), buffer->end());
			memcpy(data, buffer->data(), size);

			delete buffer;
		}

		void Write(std::vector<char>* data, uint32_t offset, uint32_t size = 0) const;
		std::ifstream *GetIfstream() const;
		std::ofstream *GetOfstream() const;
	};
}