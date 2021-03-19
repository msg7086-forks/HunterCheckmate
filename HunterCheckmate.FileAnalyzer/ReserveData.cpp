#include "ReserveData.h"

#include <algorithm>


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
			this->animal_names = std::vector<std::string>();
			animal_names.emplace_back("wild_boar");
			animal_names.emplace_back("fallow_deer");
			animal_names.emplace_back("euro_bison");
			animal_names.emplace_back("roe_deer");
			animal_names.emplace_back("red_fox");
			animal_names.emplace_back("canada_goose");
			animal_names.emplace_back("red_deer");
			animal_names.emplace_back("euro_rabbit");
			break;
			}
			// Layton
		case 1:
			{
			this->animal_names = std::vector<std::string>();
			animal_names.emplace_back("moose");
			animal_names.emplace_back("jackrabbit");
			animal_names.emplace_back("mallard");
			animal_names.emplace_back("black_bear");
			animal_names.emplace_back("roosevelt_elk");
			animal_names.emplace_back("coyote");
			animal_names.emplace_back("blacktail_deer");
			animal_names.emplace_back("whitetail_deer");
			break;
			}
			// Medved
		case 2:
			{
			this->animal_names = std::vector<std::string>();
			animal_names.emplace_back("musk_deer");
			animal_names.emplace_back("moose");
			animal_names.emplace_back("wild_boar");
			animal_names.emplace_back("reindeer");
			animal_names.emplace_back("eurasian_lynx");
			animal_names.emplace_back("brown_bear");
			break;
			}
			// Vurhonga
		case 3:
			{
			this->animal_names = std::vector<std::string>();
			animal_names.emplace_back("blue_wildebeest");
			animal_names.emplace_back("side_striped_jackal");
			animal_names.emplace_back("gemsbok");
			animal_names.emplace_back("lesser_kudu");
			animal_names.emplace_back("scrub_hare");
			animal_names.emplace_back("lion");
			animal_names.emplace_back("warthog");
			animal_names.emplace_back("cape_buffalo");
			animal_names.emplace_back("springbok");
			break;
			}
			// Parque
		case 4:
			{
			this->animal_names = std::vector<std::string>();
			animal_names.emplace_back("red_deer");
			animal_names.emplace_back("water_buffalo");
			animal_names.emplace_back("puma");
			animal_names.emplace_back("blackbuck");
			animal_names.emplace_back("cinnamon_teal");
			animal_names.emplace_back("mule_deer");
			animal_names.emplace_back("axis_deer");
			break;
			}
			// Yukon
		case 6:
			{
			this->animal_names = std::vector<std::string>();
			animal_names.emplace_back("harlequin_duck");
			animal_names.emplace_back("moose");
			animal_names.emplace_back("red_fox");
			animal_names.emplace_back("caribou");
			animal_names.emplace_back("grizzly_bear");
			animal_names.emplace_back("gray_wolf");
			animal_names.emplace_back("plains_bison");
			break;
			}
			// Cuatro
		case 8:
			{
				// TODO
			}
			// Silve Ridge
		case 9:
			{
			this->animal_names = std::vector<std::string>();
			animal_names.emplace_back("pronghorn");
			animal_names.emplace_back("mountain_lion");
			animal_names.emplace_back("mountain_goat");
			animal_names.emplace_back("bighorn_sheep");
			animal_names.emplace_back("turkey");
			animal_names.emplace_back("black_bear");
			animal_names.emplace_back("mule_deer");
			animal_names.emplace_back("rocky_mountain_elk");
			animal_names.emplace_back("plains_bison");
			break;
			}
			// Te Awora
		case 10:
			{
				// TODO
			}
		default:
			{
			this->animal_names = std::vector<std::string>(0);
			}
		}
	}
	
	ReserveData::~ReserveData() = default;

	bool ReserveData::Verify() const
	{
		return this->id >= 0 && this->id <= 8 && !this->animal_names.empty();
	}

	uint32_t ReserveData::GetIndex(const std::string &name) const
	{
		const auto it = std::find(this->animal_names.begin(), this->animal_names.end(), name);
		return it - this->animal_names.begin();
	}

	uint32_t ReserveData::GetIndexSub(const std::string &name) const
	{
		auto tmp_elem = std::find_if(this->animal_names.begin(), this->animal_names.end(), [name](const std::string &str)
		{
			return !name.empty() && str.find(name) != std::string::npos;
		});
		if (tmp_elem != this->animal_names.end())
		{
			return tmp_elem - this->animal_names.begin();
		}
		return UINT32_MAX;
	}
}
