#pragma once
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

namespace po = boost::program_options;
namespace fs = boost::filesystem;

namespace HunterCheckmate_FileAnalyzer
{
	class CLI
	{
	private:
		po::options_description m_desc;
		po::variables_map m_vm;
		fs::path m_inputFilePath;
		fs::path m_inputFileName;

		static void conflicting_options(const po::variables_map& vm, const char* opt1, const char* opt2);
		static void option_dependency(const po::variables_map& vm, const char* for_what, const char* required_option);

		static inline void PrintUnrecognizedFile();
		inline void PrintHelp() const;
		inline void PrintGroupInformation();
		inline void InteractiveReplaceAnimal();
	public:
		CLI(int argc, char* argv[]);
		~CLI() = default;
		int run();
	};
}