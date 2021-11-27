#include "CLI.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include "Utility.h"
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

	void CLI::print_usage()
	{
		std::cout << "Usage: HunterCheckmate.FileAnalyzer.exe <population_file_path> [-oc | -of | -ocg | -rep <[-custom | -preset]>]" << std::endl
			<< std::setw(6) << "-oc: " << std::setw(0) << "Output whole file contents on console" << std::endl
			<< std::setw(6) << "-of: " << std::setw(0) << "Output whole file contents into .txt file" << std::endl
			<< std::setw(6) << "-ocg: " << std::setw(0) << "Output animal group informations on console" << std::endl
			<< std::setw(6) << "-rep: " << std::setw(0) << "Replaces an animal with a new one" << std::endl
			<< "     " << std::setw(9) << "-custom: " << std::setw(0) << "Specify animal data yourself" << std::endl
			<< "     " << std::setw(9) << "-preset: " << std::setw(0) << "Choose from some of the presets" << std::endl;
	}

	CLI::CLI(int argc, char* argv[])
		: m_inputFilePath(), m_desc("Allowed options")
	{
		m_desc.add_options()
			("help,h", "print help message")
			("input-file,i", po::value<std::string>(), "input file path (population or loadout)")
			("output-console,c", "output whole file contents on console")
			("output-file,f", "output whole file contents into .txt file")
			("output-group,g",po::value<std::string>() , "output group informations for an animal on console")
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
		else if (m_vm.count("output-group"))
		{
			m_inputFilePath = fs::path(m_vm["input-file"].as<std::string>());
			std::string str_filename = m_inputFilePath.filename().generic_string();
			std::string str_filepath = m_inputFilePath.generic_string();
			std::string str_animal = m_vm["output-group"].as<std::string>();

			// TODO: do validation in actual file reversing class and throw exception or break
			if (str_filename.find("animal_population_") != std::string::npos)
			{
				// TODO: change utility class to use boost filesystem
				auto *utility = new Utility(Endian::Little, str_filepath);
				uint8_t reserve_id = static_cast<uint8_t>(str_filepath.back()) - static_cast<uint8_t>('0');
				auto *adf = new AnimalPopulation(utility, reserve_id);

				if (adf->Deserialize())
				{
					auto it_begin = adf->reserve_data.animal_names.begin();
					auto it_end = adf->reserve_data.animal_names.end();

					bool loop_all = str_animal.empty();

					for (; it_begin != it_end; ++it_begin)
					{
						std::string animal = it_begin->first;
						if (animal.find(str_animal) != std::string::npos)
						{
							uint32_t total_number_of_animals = 0;
							uint32_t number_of_groups = adf->GetNumberOfGroups(it_begin->first);
							std::cout << animal.c_str() << " Groups [ #" << number_of_groups << " ]" << std::endl;

							for (uint32_t j = 0; j < number_of_groups; j++)
							{
								uint32_t group_size = adf->GetGroupSize(it_begin->first, j);
								total_number_of_animals += group_size;

								std::cout << std::endl << "           " << "[ " << j << " | #" << std::setw(2) << group_size
									<< " | " << std::setw(0) << adf->GetSpawnAreaId(it_begin->first, j) << " ]" << std::endl;

								for (uint32_t k = 0; k < group_size; k++)
								{
									std::string gender_arr[2] = { "Male", "Female" };
									uint8_t ui_gender = adf->GetGender(it_begin->first, j, k);
									std::string gender = gender_arr[ui_gender - 1];
									float weight = adf->GetWeight(it_begin->first, j, k);
									float score = adf->GetScore(it_begin->first, j, k);
									bool is_great_one = adf->IsGreatOne(it_begin->first, j, k);
									uint32_t visual_variation_seed = adf->GetVisualVariationSeed(it_begin->first, j, k);

									std::cout << "[ " << std::setw(2) << k
										<< " | " << std::setw(6) << gender.c_str()
										<< " | " << std::setw(7) << weight
										<< " | " << std::setw(8) << score
										<< " | " << std::setw(1) << is_great_one
										<< " | " << std::setw(5) << visual_variation_seed
										<< " ]" << std::endl;
								}
							}

							std::cout << std::endl << "Total number of animals: " << static_cast<int>(total_number_of_animals) << std::endl << std::endl;
							if (!loop_all) break;
						}
					}
				}

				delete utility;
				delete adf;
			}
			else if (str_filename.find("thp_player_profile_adf") != std::string::npos)
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