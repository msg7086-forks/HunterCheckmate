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
			m_animals_hash.emplace(AT_WildBoar,		147581770);
			m_animals_hash.emplace(AT_EuRabbit,		442307937);
			m_animals_hash.emplace(AT_FallowDeer,	798672823);
			m_animals_hash.emplace(AT_EuBison,		1056739115);
			m_animals_hash.emplace(AT_RoeDeer,		2052964502);
			m_animals_hash.emplace(AT_RedFox,		2105558160);
			m_animals_hash.emplace(AT_CanadaGoose,	3321523293);
			m_animals_hash.emplace(AT_RedDeer,		3635849363);
			break;
		}
			// Layton
		case 1:
		{
			m_animals_hash.emplace(AT_Moose,		155298792);
			m_animals_hash.emplace(AT_Jackrabbit,	1227103483);
			m_animals_hash.emplace(AT_Mallard,		1905502510);
			m_animals_hash.emplace(AT_BlackBear,	2434390669);
			m_animals_hash.emplace(AT_RooseveltElk, 2492964089);
			m_animals_hash.emplace(AT_Coyote,		3041812107);
			m_animals_hash.emplace(AT_Blacktail,	3616431897);
			m_animals_hash.emplace(AT_Whitetail,	3845994887);
			break;
		}
			// Medved
		case 2:
		{
			m_animals_hash.emplace(AT_SiberianMuskDeer,		74472795);
			m_animals_hash.emplace(AT_Moose,				155298792);
			m_animals_hash.emplace(AT_WildBoar,				1570854601);
			m_animals_hash.emplace(AT_Reindeer,				1779251800);
			m_animals_hash.emplace(AT_EurasianLynx,			1814015872);
			m_animals_hash.emplace(AT_EurasianBrownBear,	1923623595);
			break;
		}
			// Vurhonga
		case 3:
		{
			m_animals_hash.emplace(AT_BlueWildebeest, 183848642);
			m_animals_hash.emplace(AT_SidestripedJackal, 802991936);
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
			m_animals_hash.emplace(AT_SoutheasternIbex, 29543097);
			m_animals_hash.emplace(AT_IberianWolf, 293462162);
			m_animals_hash.emplace(AT_RedDeer, 429398428);
			m_animals_hash.emplace(AT_IberianMouflon, 1027204131);
			m_animals_hash.emplace(AT_WildBoar, 1570854601);
			m_animals_hash.emplace(AT_BeceiteIbex, 1851402074);
			m_animals_hash.emplace(AT_EuHare, 2281707277);
			m_animals_hash.emplace(AT_RoeDeer, 2611909699);
			m_animals_hash.emplace(AT_RondaIbex, 2990876619);
			m_animals_hash.emplace(AT_GredosIbex, 4191307686);
			break;
		}
			// Silve Ridge
		case 9:
		{
			m_animals_hash.emplace(AT_ProngHorn, 758166478);
			m_animals_hash.emplace(AT_MountainLion, 769204555);
			m_animals_hash.emplace(AT_MountainGoat, 1115891555);
			m_animals_hash.emplace(AT_BighornSheep, 1257210256);
			m_animals_hash.emplace(AT_WildTurkey, 2179039330);
			m_animals_hash.emplace(AT_BlackBear, 2434390669);
			m_animals_hash.emplace(AT_MuleDeer, 2953920016);
			m_animals_hash.emplace(AT_RockymountainElk, 3114263951);
			m_animals_hash.emplace(AT_PlainsBison, 3653899466);
			break;
		}
			// Te Awora
		case 10:
		{
			m_animals_hash.emplace(AT_RedDeer, 429398428);
			m_animals_hash.emplace(AT_SikaDeer, 442307937);
			m_animals_hash.emplace(AT_Chamois, 762792036);
			m_animals_hash.emplace(AT_EuRabbit, 798672823);
			m_animals_hash.emplace(AT_FeralPig, 966940268);
			m_animals_hash.emplace(AT_FeralGoat, 2179039330);
			m_animals_hash.emplace(AT_WildTurkey, 3127869685);
			m_animals_hash.emplace(AT_FallowDeer, 3245885585);
			break;
		}
			// Rancho Del Arroyo
		case 11:
		{
			m_animals_hash.emplace(AT_RioGrandeTurkey, 371665048);
			m_animals_hash.emplace(AT_Pheasant, 3318792243);
			m_animals_hash.emplace(AT_AntelopeJackrabbit, 1959650903);
			m_animals_hash.emplace(AT_Coyote, 3041812107);
			m_animals_hash.emplace(AT_MexicanBobcat, 179923754);
			m_animals_hash.emplace(AT_CollaredPeccary, 1797311245);
			m_animals_hash.emplace(AT_BighornSheep, 1257210256);
			m_animals_hash.emplace(AT_Whitetail, 3845994887);
			m_animals_hash.emplace(AT_MuleDeer, 2953920016);
			break;
		}
			// Mississippi
		case 12:
		{
			// TODO
			m_animals_hash.emplace(AT_NorthernBobwhiteQuail, 1679436322);
			m_animals_hash.emplace(AT_EasternCottontailRabbit, 1207690777);
			m_animals_hash.emplace(AT_EasternWildTurkey, 1803270983);
			m_animals_hash.emplace(AT_GrayFox, 2116163067);
			m_animals_hash.emplace(AT_Raccoon, 1014373606);
			m_animals_hash.emplace(AT_Whitetail, 3845994887);
			m_animals_hash.emplace(AT_WildHog, 762792036);
			m_animals_hash.emplace(AT_AmericanAlligator, 3136476066);
			m_animals_hash.emplace(AT_BlackBear, 2434390669);
			break;
		}
			// Revontuli
		case 13:
		{
			// TODO
			m_animals_hash.emplace(AT_EurasianWigeon, 85987887);
			m_animals_hash.emplace(AT_TundraBeanGoose, 1391428829);
			m_animals_hash.emplace(AT_EurasianTeal, 2333697570);
			m_animals_hash.emplace(AT_BlackGrouse, 1298794856);
			m_animals_hash.emplace(AT_Goldeneye, 252578829);
			m_animals_hash.emplace(AT_HazelGrouse, 1827823733);
			m_animals_hash.emplace(AT_Mallard, 45103783);
			m_animals_hash.emplace(AT_WesternCapercaillie, 2467404394);
			m_animals_hash.emplace(AT_TuftedDuck, 1016008671);
			m_animals_hash.emplace(AT_RockPtarmigan, 51579273);
			m_animals_hash.emplace(AT_CanadaGoose, 3321523293);
			m_animals_hash.emplace(AT_WillowPtarmigan, 1755902232);
			m_animals_hash.emplace(AT_GreylagGoose, 3441968927);
			m_animals_hash.emplace(AT_MountainHare, 532701289);
			m_animals_hash.emplace(AT_RaccoonDog, 4067348893);
			m_animals_hash.emplace(AT_EurasianLynx, 1814015872);
			m_animals_hash.emplace(AT_Whitetail, 3845994887);
			m_animals_hash.emplace(AT_EurasianBrownBear, 1923623595);
			m_animals_hash.emplace(AT_Moose, 155298792);
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
	uint8_t ReserveData::ResolveFileNameToInt(std::string fn)
	{
		size_t i = 0;
		for (; i < fn.length(); i++) { if (isdigit(fn[i])) break;  }
		fn = fn.substr(i, fn.length() - 1);
		uint8_t id = std::stoi(fn);
		return id;
	}
}
