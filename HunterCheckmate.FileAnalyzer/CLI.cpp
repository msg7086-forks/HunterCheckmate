#include "CLI.h"

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
		std::string animal = m_vm["output-group"].as<std::string>();

		if (m_inputFileName.generic_string().find("animal_population_") != std::string::npos)
		{
			std::shared_ptr<FileHandler> file_handler = std::make_shared<FileHandler>(Endian::Little, m_inputFilePath);
			std::shared_ptr<ReserveData> reserve_data = std::make_shared<ReserveData>(static_cast<uint8_t>(std::stoi(std::string(1, m_inputFileName.generic_string().back()))));
			const std::unique_ptr<AnimalPopulation> animal_population = std::make_unique<AnimalPopulation>(file_handler, reserve_data);

			if (animal_population->Deserialize())
			{
				animal_population->MapAnimals();

				if (animal == "all")
				{
					std::cout << *animal_population;
				}
				else
				{
					const AnimalType animal_type = Animal::ResolveAnimalType(animal);
					std::vector<AnimalGroup> groups = animal_population->m_animals.at(animal_type);
					auto it_beg = groups.begin();
					uint32_t total_animals = 0;

					std::cout << "\n========== " << groups.at(0).m_name << " Groups [ #" << groups.size() << " ] ==========\n";
					for (; it_beg != groups.end(); ++it_beg)
					{
						std::cout << *it_beg;
						total_animals += it_beg->m_size;
					}
					std::cout << "Total amount of animals: " << total_animals;
				}
			}
			else PrintUnrecognizedFile();
		}
	}

	void CLI::InteractiveReplaceAnimal()
	{
		if (m_inputFileName.generic_string().find("animal_population_") != std::string::npos)
		{
			std::shared_ptr<FileHandler> file_handler = std::make_shared<FileHandler>(Endian::Little, m_inputFilePath);
			std::shared_ptr<ReserveData> reserve_data = std::make_shared<ReserveData>(static_cast<uint8_t>(std::stoi(std::string(1,m_inputFileName.generic_string().back()))));
			const std::unique_ptr<AnimalPopulation> animal_population = std::make_unique<AnimalPopulation>(file_handler, reserve_data);

			if (animal_population->Deserialize())
			{
				std::string in_name;
				std::string in_group_idx;
				std::string in_animal_idx;

				std::cout << "Which animal do you want to replace?\n";
				std::cout << "Name: ";				std::cin >> in_name;
				std::cout << "Group Index: ";		std::cin >> in_group_idx;
				std::cout << "Animal Index: ";		std::cin >> in_animal_idx;

				const uint32_t group_idx = std::stoul(in_group_idx);
				const uint32_t animal_idx = std::stoul(in_animal_idx);
				const AnimalType animal_type = Animal::ResolveAnimalType(in_name);

				if (!animal_population->IsValidAnimal(animal_type, group_idx, animal_idx))
				{
					std::cout << "\nYou have entered an invalid animal name, group index or animal index!\n";
				}
				else
				{
					std::string gender;
					std::string weight;
					std::string score;
					std::string is_great_one;
					std::string fur_type;

					std::cout << "\nAnimal found! Please enter the data of the " << in_name << ".\n";
					std::cout << "Gender [male/female]: "; std::cin >> gender;
					std::cout << "Weight: "; std::cin >> weight;
					std::cout << "Score: "; std::cin >> score;
					std::cout << "Is Great One [0/1]: "; std::cin >> is_great_one;
					std::cout << "Fur Type: "; std::cin >> fur_type;

					uint32_t visual_variation_seed = Animal::CreateVisualVariationSeed(animal_type, gender, fur_type);

					const std::shared_ptr<Animal> animal = Animal::Create(animal_type, Animal::ResolveGender(gender), std::stof(weight), std::stof(score), boost::lexical_cast<bool>(is_great_one), visual_variation_seed, animal_idx);

					if (animal->IsValid())
					{
						if (animal_population->ReplaceAnimal(animal, group_idx, animal_idx))
						{
							std::cout << std::endl << "Success! Good luck hunting down your new animal!\n";
						}
						else
						{
							std::cout << std::endl << "Something went wrong...\n";
						}
					}
				}
			}
		}
	}

	void CLI::InteractiveJson()
	{
		m_inputJsonPath = fs::path(m_vm["json"].as<std::string>());
		m_inputJsonName = m_inputJsonPath.filename();

		if (m_inputFileName.generic_string().find("thp_player_profile_adf") != std::string::npos
			&& m_inputJsonName.generic_string().find(".json") != std::string::npos)
		{
			std::shared_ptr<FileHandler> file_handler = std::make_shared<FileHandler>(Endian::Little, m_inputFilePath);
			std::shared_ptr<FileHandler> json_handler = std::make_shared<FileHandler>(m_inputJsonPath);
			std::unique_ptr<ThpPlayerProfile> adf = std::make_unique<ThpPlayerProfile>(file_handler, json_handler);
			std::shared_ptr<FileHandler> json_file_handler = std::make_shared<FileHandler>(Endian::Little, m_inputJsonPath);

			if (adf->Deserialize())
			{
				adf->Test();
				adf->SerializeJson();
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
			("output-group,g", po::value<std::string>(), "output group informations for an animal on console")
			("replace-custom,r", "replace an animal with a new one")
			("replace-preset,p", "replace an animal with one from the presets")
			("json,j", po::value<std::string>(), "get inventory info and load/save loadout");
		po::store(po::parse_command_line(argc, argv, m_desc), m_vm);
		po::notify(m_vm);
		option_dependency(m_vm, "output-console", "input-file");
		option_dependency(m_vm, "output-file", "input-file");
		option_dependency(m_vm, "output-group", "input-file");
		option_dependency(m_vm, "replace-custom", "input-file");
		option_dependency(m_vm, "replace-presets", "input-file");
		option_dependency(m_vm, "json", "input-file");
	}

	int CLI::run()
	{
		m_inputFilePath = fs::path(m_vm["input-file"].as<std::string>());
		m_inputFileName = m_inputFilePath.filename();
		
		if (true)
		{
			std::shared_ptr<FileHandler> file_handler = std::make_shared<FileHandler>(Endian::Little, m_inputFilePath);
			const std::unique_ptr<AdfFile> adf = std::make_unique<AdfFile>(file_handler);
			if (adf->Deserialize())
			{
				return 0;
			}

			return 0;
		}

		if (m_vm.count("help"))					PrintHelp();
		else if (m_vm.count("output-group"))	PrintGroupInformation();
		else if (m_vm.count("replace-custom"))	InteractiveReplaceAnimal();
		else if (m_vm.count("json"))			InteractiveJson();
		else std::cout << "Use --help option to display information\n";

		return 0;
	}
}