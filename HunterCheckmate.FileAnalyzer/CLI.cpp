#include "CLI.h"

#include <iostream>
#include <iomanip>
#include "FileHandler.h"
#include "AnimalPopulation.h"

namespace HunterCheckmate_FileAnalyzer
{
	/* Function used to check that 'opt1' and 'opt2' are not specified
   at the same time. */
	void CLI::conflicting_options(const po::variables_map& vm,
							 const char* opt1, const char* opt2)
	{
		if (vm.count(opt1) && !vm[opt1].defaulted()
			&& vm.count(opt2) && !vm[opt2].defaulted())
			throw std::logic_error(std::string("Conflicting options '")
							  + opt1 + "' and '" + opt2 + "'.");
	}

	/* Function used to check that of 'for_what' is specified, then
	   'required_option' is specified too. */
	void CLI::option_dependency(const po::variables_map& vm,
						   const char* for_what, const char* required_option)
	{
		if (vm.count(for_what) && !vm[for_what].defaulted())
			if (vm.count(required_option) == 0 || vm[required_option].defaulted())
				throw std::logic_error(std::string("Option '") + for_what
								  + "' requires option '" + required_option + "'.");
	}

	CLI::CLI(int argc, char* argv[])
		: m_desc("Allowed options")
	{
		m_desc.add_options()
			("help,h", "print help message")
			("input-file,i", po::value<std::string>(), "input file path (population or loadout)")
			("output-console,c", "output whole file contents on console")
			("output-file,f", "output whole file contents into .txt file")
			("output-group,g",po::value<std::string>(), "output group informations for an animal on console")
			("replace-custom,r", "replace an animal with a new one")
			("replace-preset,p", "replace an animal with one from the presets");
		po::store(po::parse_command_line(argc, argv, m_desc), m_vm);
		po::notify(m_vm);
		option_dependency(m_vm, "output-console", "input-file");
		option_dependency(m_vm, "output-file", "input-file");
		option_dependency(m_vm, "output-group", "input-file");
		option_dependency(m_vm, "replace-custom", "input-file");
		option_dependency(m_vm, "replace-presets", "input-file");
	}

	int CLI::run()
	{
		if (m_vm.count("help"))
		{
			std::cout << m_desc << std::endl;
			return 1;
		}
		if (m_vm.count("output-group"))
		{
			m_inputFilePath = fs::path(m_vm["input-file"].as<std::string>());
			std::string str_filename = m_inputFilePath.filename().generic_string();
			std::string str_filepath = m_inputFilePath.generic_string();
			std::string str_animal = m_vm["output-group"].as<std::string>();

			// TODO: do validation in actual file reversing class and throw exception or break
			if (str_filename.find("animal_population_") != std::string::npos)
			{
				std::shared_ptr<FileHandler> file_handler = std::make_shared<FileHandler>(Endian::Little, str_filepath);
				uint8_t reserve_id = static_cast<uint8_t>(str_filepath.back()) - static_cast<uint8_t>('0');
				std::unique_ptr<AnimalPopulation> adf = std::make_unique<AnimalPopulation>(file_handler, reserve_id);

				if (adf->Deserialize())
				{
					adf->GenerateMap();
					std::vector<AnimalGroupData> groups = adf->animals.at(str_animal);
					auto it_beg = groups.begin();
					auto it_end = groups.end();
					for (; it_beg != it_end; ++it_beg) std::cout << *it_beg;
				}

				return 0;
			}
			if (str_filename.find("thp_player_profile_adf") != std::string::npos)
			{
				// do inventory stuff
			}
			else
			{
				std::cout << "I don't know this file and I don't care to know this file!" << std::endl;
				return 0;
			}
			
			return 1;
		}
		else
		{
			std::cout << "Use --help option to display information" << std::endl;
			return 1;
		}
	}
}