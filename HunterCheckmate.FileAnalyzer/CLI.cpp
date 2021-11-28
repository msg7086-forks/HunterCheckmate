#include "CLI.h"

#include <iostream>
#include "FileHandler.h"
#include "AnimalPopulation.h"

namespace HunterCheckmate_FileAnalyzer
{
	/* Function used to check that 'opt1' and 'opt2' are not specified
   at the same time. */
	void CLI::conflicting_options(const po::variables_map& vm, const char* opt1, const char* opt2)
	{
		if (vm.count(opt1) && !vm[opt1].defaulted()
			&& vm.count(opt2) && !vm[opt2].defaulted())
			throw std::logic_error(std::string("Conflicting options '")
							  + opt1 + "' and '" + opt2 + "'.");
	}

	/* Function used to check that of 'for_what' is specified, then
	   'required_option' is specified too. */
	void CLI::option_dependency(const po::variables_map& vm, const char* for_what, const char* required_option)
	{
		if (vm.count(for_what) && !vm[for_what].defaulted())
			if (vm.count(required_option) == 0 || vm[required_option].defaulted())
				throw std::logic_error(std::string("Option '") + for_what
								  + "' requires option '" + required_option + "'.");
	}

	void CLI::PrintUnrecognizedFile()
	{
		std::cout << "I don't know this file and I don't care to know this file!\n";
	}

	void CLI::PrintHelp() const
	{
		std::cout << m_desc << "\n";
	}

	void CLI::PrintGroupInformation()
	{
		const std::string animal = m_vm["output-group"].as<std::string>();

		if (m_inputFileName.generic_string().find("animal_population_") != std::string::npos)
		{
			std::shared_ptr<FileHandler> file_handler = std::make_shared<FileHandler>(Endian::Little, m_inputFilePath);
			uint8_t reserve_id = static_cast<uint8_t>(m_inputFilePath.generic_string().back()) - static_cast<uint8_t>('0');
			std::unique_ptr<AnimalPopulation> adf = std::make_unique<AnimalPopulation>(file_handler, reserve_id);

			if (adf->Deserialize())
			{
				adf->GenerateMap();
				std::vector<AnimalGroupData> groups = adf->animals.at(animal);
				auto it_beg = groups.begin();
				auto it_end = groups.end();
				for (; it_beg != it_end; ++it_beg) std::cout << *it_beg;
			}
			else PrintUnrecognizedFile();
		}
	}

	void CLI::InteractiveReplaceAnimal()
	{
		if (m_inputFileName.generic_string().find("animal_population_") != std::string::npos)
		{
			std::shared_ptr<FileHandler> file_handler = std::make_shared<FileHandler>(Endian::Little, m_inputFilePath);
			uint8_t reserve_id = static_cast<uint8_t>(m_inputFilePath.generic_string().back()) - static_cast<uint8_t>('0');
			std::unique_ptr<AnimalPopulation> adf = std::make_unique<AnimalPopulation>(file_handler, reserve_id);
			if (adf->Deserialize())
			{
				std::string in_name;
				std::string in_group_idx;
				std::string in_animal_idx;

				std::cout << "Which animal do you want to replace?" << std::endl;
				std::cout << "Name: ";				std::cin >> in_name;
				std::cout << "Group Index: ";		std::cin >> in_group_idx;
				std::cout << "Animal Index: ";		std::cin >> in_animal_idx;

				const uint32_t group_idx = std::stoul(in_group_idx);
				const uint32_t animal_idx = std::stoul(in_animal_idx);

				if (!adf->IsValidAnimal(in_name, group_idx, animal_idx))
				{
					std::cout << "\nYou have entered an invalid animal name, group index or animal index!" << std::endl;
				}
				else
				{
					std::string gender;
					std::string weight;
					std::string score;
					std::string is_great_one;
					std::string visual_variation_seed;

					std::cout << "\nAnimal found! Please enter the data of the " << in_name << ".\n";
					std::cout << "Gender: "; std::cin >> gender;
					std::cout << "Weight: "; std::cin >> weight;
					std::cout << "Score: "; std::cin >> score;
					std::cout << "Is Great One: "; std::cin >> is_great_one;
					std::cout << "Fur Type: "; std::cin >> visual_variation_seed;

					AnimalData* animal_data = adf->GenerateAnimalData(in_name, gender, weight, score, is_great_one, visual_variation_seed);
					if (animal_data != nullptr)
					{
						if (adf->ReplaceAnimal(animal_data, in_name, group_idx, animal_idx))
						{
							std::cout << std::endl << "Success! Good luck hunting down your new animal!" << std::endl;
						}
						else
						{
							std::cout << std::endl << "Something went wrong..." << std::endl;
						}

						delete animal_data;
					}
				}
			}
		}
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
		m_inputFilePath = fs::path(m_vm["input-file"].as<std::string>());
		m_inputFileName = m_inputFilePath.filename();

		if (m_vm.count("help"))					PrintHelp();
		else if (m_vm.count("output-group"))	PrintGroupInformation();
		else if (m_vm.count("replace-custom"))	InteractiveReplaceAnimal();
		else std::cout << "Use --help option to display information\n";

		return 0;
	}
}