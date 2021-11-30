#include "ReserveData.h"

namespace HunterCheckmate_FileAnalyzer
{
	ReserveData::ReserveData(const uint8_t id)
		: m_id(id)
	{
		m_animals_hash = std::map<AnimalType, uint32_t>();

		switch (id)
		{
			// Hirschfelden
		case 0:
			{
			m_animals_hash.emplace(AT_WildBoar, 147581770);
			m_animals_hash.emplace(AT_EuroRabbit, 442307937);
			m_animals_hash.emplace(AT_FallowDeer, 798672823);
			m_animals_hash.emplace(AT_EuroBison, 1056739115);
			m_animals_hash.emplace(AT_RoeDeer, 2052964502);
			m_animals_hash.emplace(AT_RedFox, 2105558160);
			m_animals_hash.emplace(AT_CanadaGoose, 3321523293);
			m_animals_hash.emplace(AT_RedDeer, 3635849363);
			break;
			}
			// Layton
		case 1:
			{
			m_animals_hash.emplace(AT_Moose, 155298792);
			m_animals_hash.emplace(AT_Jackrabbit, 1227103483);
			m_animals_hash.emplace(AT_Mallard, 1905502510);
			m_animals_hash.emplace(AT_BlackBear, 2434390669);
			m_animals_hash.emplace(AT_RooseveltElk, 2492964089);
			m_animals_hash.emplace(AT_Coyote, 3041812107);
			m_animals_hash.emplace(AT_BlacktailDeer, 3616431897);
			m_animals_hash.emplace(AT_WhitetailDeer, 3845994887);
			break;
			}
			// Medved
		case 2:
			{
			m_animals_hash.emplace(AT_MuskDeer, 74472795);
			m_animals_hash.emplace(AT_Moose, 155298792);
			m_animals_hash.emplace(AT_WildBoar, 1570854601);
			m_animals_hash.emplace(AT_Reindeer, 1779251800);
			m_animals_hash.emplace(AT_EurasianLynx, 1814015872);
			m_animals_hash.emplace(AT_BrownBear, 1923623595);
			break;
			}
			// Vurhonga
		case 3:
			{
			m_animals_hash.emplace(AT_BlueWildebeest, 183848642);
			m_animals_hash.emplace(AT_SideStripedJackal, 802991936);
			m_animals_hash.emplace(AT_Gemsbok, 1148301097);
			m_animals_hash.emplace(AT_LesserKudu, 1955191955);
			m_animals_hash.emplace(AT_ScrubHare, 1961213070);
			m_animals_hash.emplace(AT_Lion, 2188838277);
			m_animals_hash.emplace(AT_Warthog, 3080620210);
			m_animals_hash.emplace(AT_CapeBuffalo, 3311120975);
			m_animals_hash.emplace(AT_Springbok, 4064523038);
			break;
			}
			// Parque
		case 4:
			{
			m_animals_hash.emplace(AT_RedDeer, 429398428);
			m_animals_hash.emplace(AT_WaterBuffalo, 743631237);
			m_animals_hash.emplace(AT_Puma, 769204555);
			m_animals_hash.emplace(AT_Blackbuck, 1729971715);
			m_animals_hash.emplace(AT_CinnamonTeal, 1756552882);
			m_animals_hash.emplace(AT_MuleDeer, 2953920016);
			m_animals_hash.emplace(AT_AxisDeer, 3406669569);
			break;
			}
			// Yukon
		case 6:
			{
			m_animals_hash.emplace(AT_HarlequinDuck, 1256214699);
			m_animals_hash.emplace(AT_Moose, 1812162018);
			m_animals_hash.emplace(AT_RedFox, 2233970641);
			m_animals_hash.emplace(AT_Caribou, 2777511015);
			m_animals_hash.emplace(AT_GrizzlyBear, 3501209982);
			m_animals_hash.emplace(AT_GrayWolf, 3512596996);
			m_animals_hash.emplace(AT_PlainsBison, 3653899466);
			break;
			}
			// Cuatro
		case 8:
			{
			m_animals_hash.emplace(AT_SoutheasternSpanishIbex, 29543097);
			m_animals_hash.emplace(AT_IberianWolf, 293462162);
			m_animals_hash.emplace(AT_RedDeer, 429398428);
			m_animals_hash.emplace(AT_IberianMuflon, 1027204131);
			m_animals_hash.emplace(AT_WildBoar, 1570854601);
			m_animals_hash.emplace(AT_BeceiteIbex, 1851402074);
			m_animals_hash.emplace(AT_EuroHare, 2281707277);
			m_animals_hash.emplace(AT_RoeDeer, 2611909699);
			m_animals_hash.emplace(AT_RondaIbex, 2990876619);
			m_animals_hash.emplace(AT_GredosIbex, 4191307686);
			break;
			}
			// Silve Ridge
		case 9:
			{
			m_animals_hash.emplace(AT_Pronghorn, 758166478);
			m_animals_hash.emplace(AT_MountainLion, 769204555);
			m_animals_hash.emplace(AT_MountainGoat, 1115891555);
			m_animals_hash.emplace(AT_BighornSheep, 1257210256);
			m_animals_hash.emplace(AT_Turkey, 2179039330);
			m_animals_hash.emplace(AT_BlackBear, 2434390669);
			m_animals_hash.emplace(AT_MuleDeer, 2953920016);
			m_animals_hash.emplace(AT_RockyMountainElk, 3114263951);
			m_animals_hash.emplace(AT_PlainsBison, 3653899466);
			break;
			}
			// Te Awora
		case 10:
			{
			m_animals_hash.emplace(AT_RedDeer, 429398428);
			m_animals_hash.emplace(AT_SikaDeer, 442307937);
			m_animals_hash.emplace(AT_Chamois, 762792036);
			m_animals_hash.emplace(AT_EuroRabbit, 798672823);
			m_animals_hash.emplace(AT_FeralPig, 966940268);
			m_animals_hash.emplace(AT_FeralGoat, 2179039330);
			m_animals_hash.emplace(AT_Turkey, 3127869685);
			m_animals_hash.emplace(AT_FallowDeer, 3245885585);
			break;
			}
		default:
			m_id = INT8_MAX;
			break;
		}

		m_valid = Verify();
	}

	bool ReserveData::Verify() const
	{
		return m_id < INT8_MAX && !m_animals_hash.empty();
	}

	uint32_t ReserveData::GetNameHash(AnimalType animal_type)
	{
		return m_animals_hash.at(animal_type);
	}
}
