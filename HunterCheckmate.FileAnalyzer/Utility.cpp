#include "Utility.h"


namespace HunterCheckmate_FileAnalyzer
{
	Utility::Utility(Endian endian, std::ifstream *ifstream)
	{
		this->endian = endian;
		this->ifstream = ifstream;
		this->ofstream = nullptr;
	}

	Utility::Utility(Endian endian, std::ofstream *ofstream)
	{
		this->endian = endian;
		this->ifstream = nullptr;
		this->ofstream = ofstream;
	}
	
	Utility::Utility(Endian endian, std::ifstream *ifstream, std::ofstream *ofstream)
	{
		this->endian = endian;
		this->ifstream = ifstream;
		this->ofstream = ofstream;
	}

	Utility::~Utility()
	{
		ifstream->close();
		ofstream->close();
		delete this->ifstream;
		delete this->ofstream;
	}

	void Utility::Write(std::vector<char>* data, uint32_t offset, uint32_t size) const
	{
		if (size == 0) size = data->size();

		for (auto it = data->begin(); it != data->end(); ++it)
		{
			const uint32_t idx = it - data->begin();
			this->ofstream->seekp(offset + idx);
			this->ofstream->put(*it);
		}
	}
	
	bool Utility::CheckSig(uint32_t sig)
	{
		uint32_t _sig;
		Read(&_sig, 0x0);
		return _sig == sig;
	}

	std::ifstream *Utility::GetIfstream() const
	{
		return this->ifstream;
	}

	std::ofstream *Utility::GetOfstream() const
	{
		return this->ofstream;
	}

}