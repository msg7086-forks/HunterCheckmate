#pragma once
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/json.hpp>
#include "FileHandler.h"
#include "AnimalPopulation.h"
#include "ThpPlayerProfile.h"

namespace po = boost::program_options;
namespace fs = boost::filesystem;
namespace bs = boost::algorithm;
namespace json = boost::json;

namespace HunterCheckmate_FileAnalyzer
{
	class CLI
	{
	private:
		po::options_description m_desc;
		po::variables_map m_vm;
		fs::path m_inputFilePath;
		fs::path m_inputFileName;
		fs::path m_inputJsonPath;
		fs::path m_inputJsonName;

		static void conflicting_options(const po::variables_map& vm, const char* opt1, const char* opt2);
		static void option_dependency(const po::variables_map& vm, const char* for_what, const char* required_option);

		static inline void PrintUnrecognizedFile();
		inline void PrintHelp() const;
		inline static AnimalType ResolveAnimalType(std::string& name);
		inline void PrintGroupInformation();
		inline void InteractiveReplaceAnimal();
		inline void InteractiveJson();
	public:
		CLI(int argc, char* argv[]);
		~CLI() = default;
		int run();
	};
}