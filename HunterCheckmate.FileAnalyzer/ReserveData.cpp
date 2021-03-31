#include "ReserveData.h"

namespace HunterCheckmate_FileAnalyzer
{
	ReserveData::ReserveData(uint8_t id)
	{
		this->id = id;
		switch (id)
		{
			// Hirschfelden
		case 0:
			{
			this->animal_names = std::map<std::string, uint32_t>();
			animal_names.emplace("wild_boar", 147581770);
			animal_names.emplace("fallow_deer", 798672823);
			animal_names.emplace("euro_bison", 1056739115);
			animal_names.emplace("roe_deer", 2052964502);
			animal_names.emplace("red_fox", 2105558160);
			animal_names.emplace("canada_goose", 3321523293);
			animal_names.emplace("red_deer", 3635849363);
			animal_names.emplace("euro_rabbit", 442307937);
			break;
			}
			// Layton
		case 1:
			{
			this->animal_names = std::map<std::string, uint32_t >();
			animal_names.emplace("moose", 155298792);
			animal_names.emplace("jackrabbit", 1227103483);
			animal_names.emplace("mallard", 1905502510);
			animal_names.emplace("black_bear", 2434390669);
			animal_names.emplace("roosevelt_elk", 2492964089);
			animal_names.emplace("coyote", 3041812107);
			animal_names.emplace("blacktail_deer", 3616431897);
			animal_names.emplace("whitetail_deer", 3845994887);
			break;
			}
			// Medved
/*		case 2:
			{
			this->animal_names = std::map<std::string, uint32_t>();
			animal_names.emplace("musk_deer");
			animal_names.emplace("moose");
			animal_names.emplace("wild_boar");
			animal_names.emplace("reindeer");
			animal_names.emplace("eurasian_lynx");
			animal_names.emplace("brown_bear");
			break;
			}
			// Vurhonga
		case 3:
			{
			this->animal_names = std::map<std::string, uint32_t>();
			animal_names.emplace("blue_wildebeest");
			animal_names.emplace("side_striped_jackal");
			animal_names.emplace("gemsbok");
			animal_names.emplace("lesser_kudu");
			animal_names.emplace("scrub_hare");
			animal_names.emplace("lion");
			animal_names.emplace("warthog");
			animal_names.emplace("cape_buffalo");
			animal_names.emplace("springbok");
			break;
			}
			// Parque
		case 4:
			{
			this->animal_names = std::map<std::string, uint32_t>();
			animal_names.emplace("red_deer");
			animal_names.emplace("water_buffalo");
			animal_names.emplace("puma");
			animal_names.emplace("blackbuck");
			animal_names.emplace("cinnamon_teal");
			animal_names.emplace("mule_deer");
			animal_names.emplace("axis_deer");
			break;
			}
			// Yukon
		case 6:
			{
			this->animal_names = std::map<std::string, uint32_t>();
			animal_names.emplace("harlequin_duck");
			animal_names.emplace("moose");
			animal_names.emplace("red_fox");
			animal_names.emplace("caribou");
			animal_names.emplace("grizzly_bear");
			animal_names.emplace("gray_wolf");
			animal_names.emplace("plains_bison");
			break;
			}
			// Cuatro
		case 8:
			{
				// TODO
			break;
			}
			// Silve Ridge
		case 9:
			{
			this->animal_names = std::map<std::string, uint32_t>();
			animal_names.emplace("pronghorn");
			animal_names.emplace("mountain_lion");
			animal_names.emplace("mountain_goat");
			animal_names.emplace("bighorn_sheep");
			animal_names.emplace("turkey");
			animal_names.emplace("black_bear");
			animal_names.emplace("mule_deer");
			animal_names.emplace("rocky_mountain_elk");
			animal_names.emplace("plains_bison");
			break;
			}
			// Te Awora
		case 10:
			{
				// TODO
			break;
			}*/
		default:
			{
			this->animal_names = std::map<std::string, uint32_t>();
			break;
			}
		}
	}

	bool ReserveData::Verify() const
	{
		return this->id <= 8 && !this->animal_names.empty();
	}

	uint32_t ReserveData::GetNameHash(const std::string &name) const
	{
		for (const auto& animal_name : animal_names)
		{
			if (animal_name.first.find(name) != std::string::npos) return animal_name.second;
		}
		return 0;
	}
}
