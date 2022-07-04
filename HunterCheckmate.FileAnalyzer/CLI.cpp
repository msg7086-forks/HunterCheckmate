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

	AnimalType CLI::ResolveAnimalType(std::string& name)
	{
		bs::to_lower(name);
		if (name.find("boar") != std::string::npos) return AT_WildBoar;
		if (name.find("fallow") != std::string::npos) return AT_FallowDeer;
		if (name.find("eu") != std::string::npos && name.find("bison") != std::string::npos) return AT_EuroBison;
		if (name.find("roe") != std::string::npos) return AT_RoeDeer;
		if (name.find("red") != std::string::npos && name.find("fox") != std::string::npos) return AT_RedFox;
		if (name.find("goose") != std::string::npos) return AT_CanadaGoose;
		if (name.find("red") != std::string::npos && name.find("deer") != std::string::npos) return AT_RedDeer;
		if (name.find("eu") != std::string::npos && name.find("rabbit") != std::string::npos) return AT_EuroRabbit;
		if (name.find("moose") != std::string::npos) return AT_Moose;
		if (name.find("jack") != std::string::npos && name.find("rabbit") != std::string::npos) return AT_Jackrabbit;
		if (name.find("mallard") != std::string::npos) return AT_Mallard;
		if (name.find("black") != std::string::npos && name.find("bear") != std::string::npos) return AT_BlackBear;
		if (name.find("roosevelt") != std::string::npos) return AT_RooseveltElk;
		if (name.find("coyote") != std::string::npos) return AT_Coyote;
		if (name.find("blacktail") != std::string::npos) return AT_BlacktailDeer;
		if (name.find("whitetail") != std::string::npos) return AT_WhitetailDeer;
		if (name.find("musk") != std::string::npos) return AT_MuskDeer;
		if (name.find("reindeer") != std::string::npos) return AT_Reindeer;
		if (name.find("lynx") != std::string::npos) return AT_EurasianLynx;
		if (name.find("brown") != std::string::npos && name.find("bear") != std::string::npos) return AT_BrownBear;
		if (name.find("wildebeest") != std::string::npos) return AT_BlueWildebeest;
		if (name.find("jackal") != std::string::npos) return AT_SideStripedJackal;
		if (name.find("gemsbok") != std::string::npos) return AT_Gemsbok;
		if (name.find("kudu") != std::string::npos) return AT_LesserKudu;
		if (name.find("hare") != std::string::npos && !(name.find("eu") != std::string::npos)) return AT_ScrubHare;
		if (name.find("lion") != std::string::npos && !(name.find("mountain") != std::string::npos)) return AT_Lion;
		if (name.find("warthog") != std::string::npos) return AT_Warthog;
		if (name.find("cape") != std::string::npos) return AT_CapeBuffalo;
		if (name.find("springbok") != std::string::npos) return AT_Springbok;
		if (name.find("water") != std::string::npos) return AT_WaterBuffalo;
		if (name.find("puma") != std::string::npos) return AT_Puma;
		if (name.find("blackbuck") != std::string::npos) return AT_Blackbuck;
		if (name.find("cinnamon") != std::string::npos) return AT_CinnamonTeal;
		if (name.find("mule") != std::string::npos) return AT_MuleDeer;
		if (name.find("axis") != std::string::npos) return AT_AxisDeer;
		if (name.find("harlequin") != std::string::npos || name.find("duck") != std::string::npos) return AT_HarlequinDuck;
		if (name.find("caribou") != std::string::npos) return AT_Caribou;
		if (name.find("grizzly") != std::string::npos) return AT_GrizzlyBear;
		if (name.find("gray") != std::string::npos && name.find("wolf") != std::string::npos) return AT_GrayWolf;
		if (name.find("plains") != std::string::npos) return AT_PlainsBison;
		if (name.find("south") != std::string::npos && name.find("ibex") != std::string::npos) return AT_SoutheasternSpanishIbex;
		if (name.find("iberian") != std::string::npos && name.find("wolf") != std::string::npos) return AT_IberianWolf;
		if (name.find("muflon") != std::string::npos) return AT_IberianMuflon;
		if (name.find("beceite") != std::string::npos) return AT_BeceiteIbex;
		if (name.find("eu") != std::string::npos && name.find("hare") != std::string::npos) return AT_EuroHare;
		if (name.find("ronda") != std::string::npos) return AT_RondaIbex;
		if (name.find("gredos") != std::string::npos) return AT_GredosIbex;
		if (name.find("pronghorn") != std::string::npos) return AT_Pronghorn;
		if (name.find("mountain") != std::string::npos && name.find("lion") != std::string::npos) return AT_MountainLion;
		if (name.find("mountain") != std::string::npos && name.find("goat") != std::string::npos) return AT_MountainGoat;
		if (name.find("bighorn") != std::string::npos) return AT_BighornSheep;
		if (name.find("merriam") != std::string::npos && name.find("turkey") != std::string::npos) return AT_MerriamTurkey;
		if (name.find("rocky") != std::string::npos) return AT_RockyMountainElk;
		if (name.find("sika") != std::string::npos) return AT_SikaDeer;
		if (name.find("chamois") != std::string::npos) return AT_Chamois;
		if (name.find("pig") != std::string::npos) return AT_FeralPig;
		if (name.find("feral") != std::string::npos && name.find("goat") != std::string::npos) return AT_FeralGoat;
		if (name.find("peccary") != std::string::npos || name.find("collared") != std::string::npos) return AT_CollaredPeccary;
		if (name.find("bobcat") != std::string::npos) return AT_MexicanBobcat;
		if (name.find("rio") != std::string::npos && name.find("turkey") != std::string::npos) return AT_RioGrandeTurkey;
		if (name.find("pheasant") != std::string::npos) return AT_RingNeckedPheasant;
		if (name.find("antelope") != std::string::npos && name.find("jackrabbit") != std::string::npos) return AT_AntelopeJackrabbit;
		if (name.find("alligator") != std::string::npos) return AT_AmericanAlligator;
		if (name.find("wild") != std::string::npos && name.find("hog") != std::string::npos) return AT_WildHog;
		if (name.find("gray") != std::string::npos && name.find("fox") != std::string::npos) return AT_GrayFox;
		if (name.find("racooon") != std::string::npos && !(name.find("dog") != std::string::npos)) return AT_CommonRaccoon;
		if (name.find("eastern") != std::string::npos && name.find("turkey") != std::string::npos) return AT_EasternWildTurkey;
		if (name.find("cottontail") != std::string::npos && name.find("rabbit") != std::string::npos) return AT_EasternCottontailRabbit;
		if (name.find("quail") != std::string::npos) return AT_BobwhiteQuail;
		if (name.find("raccoon") != std::string::npos && name.find("dog") != std::string::npos) return AT_RaccoonDog;
		if (name.find("wigeon") != std::string::npos) return AT_EurasianWigeon;
		if ((name.find("tundra") != std::string::npos || name.find("bean") != std::string::npos) && name.find("goose") != std::string::npos) return AT_TundraBeanGoose;
		if (name.find("eurasian") != std::string::npos && name.find("teal") != std::string::npos) return AT_EurasianTeal;
		if (name.find("black") != std::string::npos && name.find("grouse") != std::string::npos) return AT_BlackGrouse;
		if (name.find("goldeneye") != std::string::npos) return AT_Goldeneye;
		if (name.find("hazel") != std::string::npos && name.find("grouse") != std::string::npos) return AT_HazelGrouse;
		if (name.find("capercaillie") != std::string::npos) return AT_WesternCapercaillie;
		if (name.find("tufted") != std::string::npos) return AT_TuftedDuck;
		if (name.find("rock") != std::string::npos && name.find("ptarmigan") != std::string::npos) return AT_RockPtarmigan;
		if (name.find("willow") != std::string::npos && name.find("ptarmigan") != std::string::npos) return AT_WillowPtarmigan;
		if (name.find("greylag") != std::string::npos) return AT_GreylagGoose;
		if (name.find("mountain") != std::string::npos && name.find("hare") != std::string::npos) return AT_MountainHare;
		return AT_None;
	}

	void CLI::PrintGroupInformation()
	{
		std::string animal = m_vm["output-group"].as<std::string>();

		if (m_inputFileName.generic_string().find("animal_population_") != std::string::npos)
		{
			std::shared_ptr<FileHandler> file_handler = std::make_shared<FileHandler>(Endian::Little, m_inputFilePath);
			std::shared_ptr<ReserveData> reserve_data = std::make_shared<ReserveData>(static_cast<uint8_t>(std::stoi(std::string(1, m_inputFileName.generic_string().back()))));
			const std::unique_ptr<AnimalPopulation> adf = std::make_unique<AnimalPopulation>(file_handler, reserve_data);

			if (adf->Deserialize())
			{
				adf->GenerateMap();

				if (animal == "all")
				{
					// Index out of bounds possible
					std::cout << *adf;
				}
				else
				{
					const AnimalType animal_type = ResolveAnimalType(animal);
					std::vector<AnimalGroup> groups = adf->m_animals.at(animal_type);
					std::cout << "Printing all " << groups.at(0).m_name;
					auto it_beg = groups.begin();
					const auto it_end = groups.end();
					uint32_t total_animals = 0;
					for (; it_beg != it_end; ++it_beg)
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
			const std::unique_ptr<AnimalPopulation> adf = std::make_unique<AnimalPopulation>(file_handler, reserve_data);

			if (adf->Deserialize())
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
				const AnimalType animal_type = ResolveAnimalType(in_name);

				if (!adf->IsValidAnimal(animal_type, group_idx, animal_idx))
				{
					std::cout << "\nYou have entered an invalid animal name, group index or animal index!\n";
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

					const std::shared_ptr<Animal> animal = Animal::Create(animal_type, gender, weight, score, is_great_one, visual_variation_seed, std::to_string(animal_idx));

					if (animal->IsValid())
					{
						if (adf->ReplaceAnimal(animal, group_idx, animal_idx))
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

		if (m_vm.count("help"))					PrintHelp();
		else if (m_vm.count("output-group"))	PrintGroupInformation();
		else if (m_vm.count("replace-custom"))	InteractiveReplaceAnimal();
		else if (m_vm.count("json"))			InteractiveJson();
		else std::cout << "Use --help option to display information\n";

		return 0;
	}
}