#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <iomanip>
#include "Windows.h"
#include <boost/algorithm/string.hpp>
#include <random>
#include "ReserveData.h"
#include "AnimalTypeEnum.h"

namespace bs = boost::algorithm;

namespace HunterCheckmate_FileAnalyzer
{
#pragma region FurDB
	static struct FurDB
	{
		const AnimalType animal_type;
		std::string gender;
		uint32_t max_probability;
		struct FurTypes
		{
			uint32_t fur_idx;
			std::string fur_name;
			uint32_t fur_probability;
		} fur_types[20];
	} fur_db[] = {
	{
		AT_BlueWildebeest, "male", 99800,
		{
			{ 0, "Gold", 25000 },
			{ 2, "Albino", 100 },
			{ 3, "Grey", 37350 },
			{ 4, "Dark Grey", 37350 },
		}
	},
	{
		AT_BlueWildebeest, "female", 75000,
		{
			{ 1, "Crowned", 200 },
			{ 2, "Albino", 100 },
			{ 3, "Grey", 37350 },
			{ 4, "Dark Grey", 37350 },
		}
	},
	{
		AT_WesternCapercaillie, "male", 74832,
		{
			{ 2, "Leucistic", 66 },
			{ 3, "Leucistic", 33 },
			{ 4, "Pale", 33 },
			{ 1, "Dark", 74700 },
		}
	},
	{
		AT_WesternCapercaillie, "female", 99766,
		{
			{ 2, "Leucistic", 66 },
			{ 5, "Bright", 12500 },
			{ 6, "Ochre", 12500 },
			{ 0, "Brown", 74700 },
		}
	},
	{
		AT_RioGrandeTurkey, "male", 100000,
		{
			{ 2, "Light Brown", 12500 },
			{ 3, "Leucistic", 200 },
			{ 5, "Buff", 37350 },
			{ 4, "Melanistic", 50 },
			{ 6, "Lightbuff", 12500 },
			{ 0, "Brown", 37350 },
			{ 1, "Albino", 50 },
		}
	},
	{
		AT_RioGrandeTurkey, "female", 100000,
		{
			{ 2, "Light Brown", 12500 },
			{ 3, "Leucistic", 200 },
			{ 5, "Buff", 37350 },
			{ 4, "Melanistic", 50 },
			{ 6, "Lightbuff", 12500 },
			{ 0, "Brown", 37350 },
			{ 1, "Albino", 50 },
		}
	},
	{
		AT_BrownBear, "male", 100000,
		{
			{ 0, "Melanistic", 200 },
			{ 3, "Spirit", 5000 },
			{ 4, "Blonde", 5000 },
			{ 5, "Legendary", 0 }, 
			{ 6, "Red Brown", 24900 },
			{ 7, "Albino", 100 },
			{ 8, "Cinnamon", 24900 },
			{ 9, "Gold", 5000 },
			{ 10, "Dark Brown", 5000 },
			{ 11, "Grey", 5000 },
			{ 12, "Light Brown", 24900 },
		 }
	},
	{
		AT_BrownBear, "female", 100000,
		{
			{ 0, "Melanistic", 200 },
			{ 1, "Dark Brown", 5000 },
			{ 2, "Light Brown", 24900 },
			{ 3, "Spirit", 5000 },
			{ 4, "Blonde", 5000 },
			{ 5, "Legendary", 0 }, 
			{ 6, "Red Brown", 24900 },
			{ 7, "Albino", 100 },
			{ 8, "Cinnamon", 24900 },
			{ 9, "Gold", 5000 },
			{ 11, "Grey", 5000 },
		   }
	},
	{
		AT_BlackGrouse, "male", 74800,
		{
			{ 5, "Leucistic", 20 },
			{ 9, "Melanistic", 20 },
			{ 6, "Leucistic", 20 },
			{ 7, "Leucistic", 20 },
			{ 0, "Dark", 74700 },
			{ 8, "Melanistic", 20 },
		}
	},
	{
		AT_BlackGrouse, "female", 99900,
		{
			{ 2, "Gold", 100 },
			{ 3, "Dark", 25000 },
			{ 4, "Orange", 100 },
			{ 1, "Brown", 74700 },
		}
	},
	{
		AT_Lion, "male", 100000,
		{
			{ 0, "Dark Brown", 100 },
			{ 1, "Blonde", 100 },
			{ 2, "Albino", 100 },
			{ 3, "Tan", 74700 },
			{ 4, "Light Brown", 25000 },
		}
	},
	{
		AT_Lion, "female", 100000,
		{
			{ 0, "Dark Brown", 100 },
			{ 1, "Blonde", 100 },
			{ 2, "Albino", 100 },
			{ 3, "Tan", 74700 },
			{ 4, "Light Brown", 25000 },
		}
	},
	{
		AT_BighornSheep, "male", 99799,
		{
			{ 0, "Black", 8333 },
			{ 1, "Bronze", 8333 },
			{ 2, "Gray Brown", 8333 },
			{ 4, "Brown", 74700 },
			{ 3, "Albino", 100 },
		}
	},
	{
		AT_BighornSheep, "female", 99799,
		{
			{ 0, "Black", 8333 },
			{ 1, "Bronze", 8333 },
			{ 2, "Gray Brown", 8333 },
			{ 4, "Brown", 74700 },
			{ 3, "Albino", 100 },
		}
	},
	{
		AT_GreylagGoose, "male", 200150,
		{
			{ 2, "Hybrid", 25 },
			{ 3, "Leucistic", 25 },
			{ 5, "Leucistic", 25 },
			{ 4, "Leucistic", 25 },
			{ 6, "Leucistic", 25 },
			{ 7, "Leucistic", 25 },
			{ 0, "Brown", 150000 },
			{ 1, "Grey", 50000 },
		}
	},
	{
		AT_GreylagGoose, "female", 200150,
		{
			{ 2, "Hybrid", 25 },
			{ 3, "Leucistic", 25 },
			{ 5, "Leucistic", 25 },
			{ 4, "Leucistic", 25 },
			{ 6, "Leucistic", 25 },
			{ 7, "Leucistic", 25 },
			{ 0, "Brown", 150000 },
			{ 1, "Grey", 50000 },
		}
	},
	{
		AT_WaterBuffalo, "male", 77500,
		{
			{ 0, "Orange", 200 },
			{ 2, "Albino", 100 },
			{ 3, "Grey", 74700 },
			{ 4, "Black", 2500 },
		}
	},
	{
		AT_WaterBuffalo, "female", 114850,
		{
			{ 0, "Orange", 200 },
			{ 1, "Brown", 37350 },
			{ 2, "Albino", 100 },
			{ 3, "Grey", 74700 },
			{ 4, "Black", 2500 },
		}
	},
	{
		AT_EurasianLynx, "male", 74926,
		{
			{ 2, "Albino", 38 },
			{ 3, "Melanistic", 38 },
			{ 4, "Piebald", 150 },
			{ 5, "Grey", 37350 },
			{ 6, "Light Brown", 37350 },
		}
	},
	{
		AT_EurasianLynx, "female", 74926,
		{
			{ 0, "Grey", 37350 },
			{ 1, "Light Brown", 37350 },
			{ 2, "Albino", 38 },
			{ 3, "Melanistic", 38 },
			{ 4, "Piebald", 150 },
		}
	},
	{
		AT_RockPtarmigan, "male", 53555,
		{
			{ 3, "Molting", 21342 },
			{ 5, "White", 200 },
			{ 4, "Molting", 21342 },
			{ 0, "Bicolor", 10671 },
		}
	},
	{
		AT_RockPtarmigan, "female", 64226,
		{
			{ 2, "Mottled", 10671 },
			{ 3, "Molting", 21342 },
			{ 5, "White", 200 },
			{ 4, "Molting", 21342 },
			{ 1, "Mottled", 10671 },
		}
	},
	{
		AT_AmericanAlligator, "male", 100900,
		{
			{ 2, "Piebald", 200 },
			{ 3, "Piebald", 200 },
			{ 5, "Piebald", 200 },
			{ 4, "Piebald", 200 },
			{ 6, "Piebald", 200 },
			{ 7, "Melanistic", 100 },
			{ 0, "Olive", 74700 },
			{ 8, "Albino", 100 },
			{ 1, "Dark Brown", 25000 },
		}
	},
	{
		AT_AmericanAlligator, "female", 100900,
		{
			{ 2, "Piebald", 200 },
			{ 3, "Piebald", 200 },
			{ 5, "Piebald", 200 },
			{ 4, "Piebald", 200 },
			{ 6, "Piebald", 200 },
			{ 7, "Melanistic", 100 },
			{ 0, "Olive", 74700 },
			{ 8, "Albino", 100 },
			{ 1, "Dark Brown", 25000 },
		}
	},
	{
		AT_Puma, "male", 99730,
		{
			{ 0, "Dark_Red", 12465 },
			{ 1, "Albino", 50 },
			{ 2, "Melanistic", 50 },
			{ 3, "Light Brown", 74700 },
			{ 4, "Grey", 12465 },
		}
	},
	{
		AT_Puma, "female", 99730,
		{
			{ 0, "Dark Red", 12465 },
			{ 1, "Albino", 50 },
			{ 2, "Melanistic", 50 },
			{ 3, "Light_Brown", 74700 },
			{ 4, "Grey", 12465 },
		}
	},
			{
		AT_MountainLion, "male", 99730,
		{
			{ 0, "Dark_Red", 12465 },
			{ 1, "Albino", 50 },
			{ 2, "Melanistic", 50 },
			{ 3, "Light Brown", 74700 },
			{ 4, "Grey", 12465 },
		}
			},
	{
		AT_MountainLion, "female", 99730,
		{
			{ 0, "Dark Red", 12465 },
			{ 1, "Albino", 50 },
			{ 2, "Melanistic", 50 },
			{ 3, "Light_Brown", 74700 },
			{ 4, "Grey", 12465 },
		}
	},
	{
		AT_Gemsbok, "male", 74925,
		{
			{ 0, "Dark", 75 },
			{ 1, "Beige", 75 },
			{ 2, "Gold", 75 },
			{ 3, "Light Grey", 37350 },
			{ 4, "Grey", 37350 },
		}
	},
	{
		AT_Gemsbok, "female", 74925,
		{
			{ 0, "Dark", 75 },
			{ 1, "Beige", 75 },
			{ 2, "Gold", 75 },
			{ 3, "Light Grey", 37350 },
			{ 4, "Grey", 37350 },
		}
	},
	{
		AT_TuftedDuck, "male", 74899,
		{
			{ 2, "Eclipse", 100 },
			{ 5, "Leucistic", 33 },
			{ 4, "Leucistic", 33 },
			{ 6, "Albino", 33 },
			{ 0, "Black", 74700 },
		}
	},
	{
		AT_TuftedDuck, "female", 74866,
		{
			{ 3, "Cream", 100 },
			{ 5, "Leucistic", 33 },
			{ 4, "Leucistic", 33 },
			{ 1, "Brown", 74700 },
		}
	},
	{
		AT_LesserKudu, "male", 74793,
		{
			{ 3, "Albino", 55 },
			{ 4, "Melanistic", 38 },
			{ 5, "Grey", 74700 },
		}
	},
	{
		AT_LesserKudu, "female", 74905,
		{
			{ 0, "Dark Brown", 37350 },
			{ 1, "Dusky", 75 },
			{ 2, "Red Brown", 75 },
			{ 3, "Albino", 55 },
			{ 6, "Grey", 37350 },
		}
	},
	{
		AT_Caribou, "male", 74925,
		{
			{ 0, "Melanistic", 25 },
			{ 1, "Leucistic", 25 },
			{ 2, "Piebald", 150 },
			{ 3, "Albino", 25 },
			{ 4, "Light Brown", 37350 },
			{ 5, "Dark Brown", 37350 },
		}
	},
	{
		AT_Caribou, "female", 74775,
		{
			{ 0, "Melanistic", 25 },
			{ 1, "Leucistic", 25 },
			{ 3, "Albino", 25 },
			{ 4, "Light Brown", 37350 },
			{ 5, "Dark Brown", 37350 },
		}
	},
	{
		AT_Blackbuck, "male", 50100,
		{
			{ 0, "Dark", 25000 },
			{ 1, "Leucistic", 50 },
			{ 2, "Melanistic", 50 },
			{ 4, "Black", 25000 },
		}
	},
	{
		AT_Blackbuck, "female", 99800,
		{
			{ 0, "Dark", 25000 },
			{ 1, "Leucistic", 50 },
			{ 2, "Melanistic", 50 },
			{ 3, "Brown", 74700 },
		}
	},
	{
		AT_AntelopeJackrabbit, "male", 99730,
		{
			{ 2, "Dark Brown", 12465 },
			{ 3, "Mottled", 12465 },
			{ 5, "Melanistic", 50 },
			{ 4, "Albino", 50 },
			{ 0, "Brown", 37350 },
			{ 1, "Grey", 37350 },
		}
	},
	{
		AT_AntelopeJackrabbit, "female", 99730,
		{
			{ 2, "Dark Brown", 12465 },
			{ 3, "Mottled", 12465 },
			{ 5, "Melanistic", 50 },
			{ 4, "Albino", 50 },
			{ 0, "Brown", 37350 },
			{ 1, "Grey", 37350 },
		}
	},
	{
		AT_MuskDeer, "male", 74926,
		{
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Piebald", 150 },
			{ 5, "Gray Brown", 37350 },
			{ 6, "Dark Brown", 37350 },
		}
	},
	{
		AT_MuskDeer, "female", 74926,
		{
			{ 0, "Gray Brown", 37350 },
			{ 1, "Orange", 37350 },
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Piebald", 150 },
		}
	},
	{
		AT_Warthog, "male", 99705,
		{
			{ 0, "Red Brown", 24930 },
			{ 2, "Albino", 75 },
			{ 3, "Grey", 37350 },
			{ 4, "Dark", 37350 },
		}
	},
	{
		AT_Warthog, "female", 99755,
		{
			{ 0, "Red Brown", 24930 },
			{ 1, "Red", 50 },
			{ 2, "Albino", 75 },
			{ 3, "Grey", 37350 },
			{ 4, "Dark", 37350 },
		}
	},
	{
		AT_HarlequinDuck, "male", 99800,
		{
			{ 1, "Piebald", 25000 },
			{ 2, "Melanistic", 50 },
			{ 3, "Albino", 50 },
			{ 5, "Dark Grey", 74700 },
		}
	},
	{
		AT_HarlequinDuck, "female", 112288,
		{
			{ 0, "Dark", 150 },
			{ 3, "Albino", 50 },
			{ 4, "Grey", 38 },
			{ 5, "Dark Grey", 74700 },
			{ 6, "Dark Brown", 37350 },
		}
	},
	{
		AT_CanadaGoose, "male", 99999,
		{
			{ 0, "Brown Hybrid", 25000 },
			{ 1, "Grey", 200 },
			{ 2, "Light Grey Leucistic", 33 },
			{ 3, "Melanistic", 33 },
			{ 4, "Gray Brown", 74700 },
			{ 5, "Bald Leucistic", 33 },
		}
	},
	{
		AT_CanadaGoose, "female", 99999,
		{
			{ 0, "Brown Hybrid", 25000 },
			{ 1, "Grey", 200 },
			{ 2, "Light Grey Leucistic", 33 },
			{ 3, "Melanistic", 33 },
			{ 4, "Gray Brown", 74700 },
			{ 5, "Bald Leucistic", 33 },
		}
	},
	{
		AT_IberianWolf, "male", 100001,
		{
			{ 0, "Pristine", 67 },
			{ 1, "Olive", 67 },
			{ 2, "Albino", 50 },
			{ 3, "Winter", 67 },
			{ 4, "Sombra", 0 }, 
			{ 5, "Melanistic", 50 },
			{ 6, "Fantasma", 0 }, 
			{ 7, "Gray Brown", 74700 },
			{ 8, "Ogro", 0 }, 
			{ 9, "Grey", 25000 },
		}
	},
	{
		AT_IberianWolf, "female", 100001,
		{
			{ 0, "Pristine", 67 },
			{ 1, "Olive", 67 },
			{ 2, "Albino", 50 },
			{ 3, "Winter", 67 },
			{ 4, "Sombra", 0 }, 
			{ 5, "Melanistic", 50 },
			{ 6, "Fantasma", 0 }, 
			{ 7, "Gray Brown", 74700 },
			{ 8, "Ogro", 0 }, 
			{ 9, "Grey", 25000 },
		}
	},
	{
		AT_Springbok, "male", 74775,
		{
			{ 2, "Albino", 75 },
			{ 3, "Tan", 37350 },
			{ 4, "Orange", 37350 },
		}
	},
	{
		AT_Springbok, "female", 124675,
		{
			{ 0, "Black Brown", 24900 },
			{ 1, "Black Brown", 25000 },
			{ 2, "Albino", 75 },
			{ 3, "Tan", 37350 },
			{ 4, "Orange", 37350 },
		}
	},
	{
		AT_HazelGrouse, "male", 137200,
		{
			{ 2, "Dark", 25000 },
			{ 3, "Hybrid", 50 },
			{ 4, "Pale", 100 },
			{ 0, "Brown", 74700 },
			{ 1, "Grey", 37350 },
		}
	},
	{
		AT_HazelGrouse, "female", 100000,
		{
			{ 5, "Ochre", 12500 },
			{ 4, "Pale", 100 },
			{ 6, "Dark", 200 },
			{ 7, "Light Brown", 12500 },
			{ 0, "Brown", 74700 },
		}
	},
	{
		AT_Jackrabbit, "male", 74775,
		{
			{ 0, "Grey", 18675 },
			{ 1, "Beige", 18675 },
			{ 2, "Albino", 75 },
			{ 3, "Light Brown", 18675 },
			{ 4, "Brown", 18675 },
		}
	},
	{
		AT_Jackrabbit, "female", 74775,
		{
			{ 0, "Grey", 18675 },
			{ 1, "Beige", 18675 },
			{ 2, "Albino", 75 },
			{ 3, "Light Brown", 18675 },
			{ 4, "Brown", 18675 },
		}
	},
	{
		AT_TundraBeanGoose, "male", 49949,
		{
			{ 2, "Light Grey", 6250 },
			{ 3, "Leucistic", 33 },
			{ 5, "Leucistic", 33 },
			{ 4, "Leucistic", 33 },
			{ 0, "Brown", 37350 },
			{ 1, "Dark Grey", 6250 },
		}
	},
	{
		AT_TundraBeanGoose, "female", 49949,
		{
			{ 2, "Light Grey", 6250 },
			{ 3, "Leucistic", 33 },
			{ 5, "Leucistic", 33 },
			{ 4, "Leucistic", 33 },
			{ 0, "Brown", 37350 },
			{ 1, "Dark Grey", 6250 },
		}
	},
	{
		AT_Pronghorn, "male", 100000,
		{
			{ 0, "Tan", 37350 },
			{ 1, "Dark", 25000 },
			{ 3, "Piebald", 100 },
			{ 2, "Leucistic", 50 },
			{ 4, "Piebald", 100 },
			{ 6, "Brown", 37350 },
			{ 5, "Albino", 50 },
		}
	},
	{
		AT_Pronghorn, "female", 99900,
		{
			{ 0, "Tan", 37350 },
			{ 1, "Dark", 25000 },
			{ 3, "Piebald", 100 },
			{ 2, "Leucistic", 50 },
			{ 6, "Brown", 37350 },
			{ 5, "Albino", 50 },
		}
	},
	{
		AT_RingNeckedPheasant, "male", 99742,
		{
			{ 2, "White Brown", 37350 },
			{ 3, "Leucistic", 34 },
			{ 5, "Albino", 34 },
			{ 4, "Molting", 12470 },
			{ 6, "Melanistic", 34 },
			{ 0, "Brown", 37350 },
			{ 1, "Grey", 12470 },
		}
	},
	{
		AT_RingNeckedPheasant, "female", 42452,
		{
			{ 3, "Leucistic", 34 },
			{ 5, "Albino", 34 },
			{ 6, "Melanistic", 34 },
			{ 7, "Grey", 5000 },
			{ 0, "Brown", 37350 },
		}
	},
	{
		AT_MountainHare, "male", 99998,
		{
			{ 2, "Light Grey", 24900 },
			{ 3, "Light Brown", 25000 },
			{ 5, "Molting", 66 },
			{ 4, "Molting", 66 },
			{ 6, "White", 66 },
			{ 7, "Albino", 100 },
			{ 0, "Dark Grey", 24900 },
			{ 1, "Dark Brown", 24900 },
		}
	},
	{
		AT_MountainHare, "female", 99998,
		{
			{ 2, "Light Grey", 24900 },
			{ 3, "Light Brown", 25000 },
			{ 5, "Molting", 66 },
			{ 4, "Molting", 66 },
			{ 6, "White", 66 },
			{ 7, "Albino", 100 },
			{ 0, "Dark Grey", 24900 },
			{ 1, "Dark Brown", 24900 },
		}
	},
	{
		AT_SideStripedJackal, "male", 99696,
		{
			{ 0, "Grey", 24930 },
			{ 1, "Albino", 33 },
			{ 2, "Ghost", 0 }, 
			{ 3, "Melanistic", 33 },
			{ 4, "Light Brown", 37350 },
			{ 5, "Gray Brown", 37350 },
		}
	},
	{
		AT_SideStripedJackal, "female", 99696,
		{
			{ 0, "Grey", 24930 },
			{ 1, "Albino", 33 },
			{ 2, "Ghost", 0 }, 
			{ 3, "Melanistic", 33 },
			{ 4, "Light Brown", 37350 },
			{ 5, "Gray Brown", 37350 },
		}
	},
	{
		AT_RoeDeer, "male", 74926,
		{
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Piebald", 150 },
			{ 5, "Dark Grey", 24900 },
			{ 6, "Brown", 24900 },
			{ 8, "Dark Brown", 24900 },
		}
	},
	{
		AT_RoeDeer, "female", 74926,
		{
			{ 0, "Tan", 24900 },
			{ 1, "Orange", 24900 },
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Piebald", 150 },
			{ 7, "Brown", 24900 },
		}
	},
	{
		AT_BlackBear, "male", 75154,
		{
			{ 10, "Fabled Glacier", 38 },
			{ 13, "Fabled Spirit", 38 },
			{ 2, "Brown", 38 },
			{ 3, "Blonde", 38 },
			{ 11, "Fabled Cream", 38 },
			{ 12, "Fabled Spotted", 38 },
			{ 9, "Fabled Glacier", 38 },
			{ 4, "Cinnamon", 150 },
			{ 14, "Fabled Chestnut", 38 },
			{ 5, "Dark", 24900 },
			{ 6, "Black", 24900 },
			{ 8, "Dusky", 24900 },
		}
	},
	{
		AT_BlackBear, "female", 74926,
		{
			{ 0, "Black", 24900 },
			{ 1, "Dusky", 24900 },
			{ 2, "Brown", 38 },
			{ 3, "Blonde", 38 },
			{ 4, "Cinnamon", 150 },
			{ 7, "Dark", 24900 },
		}
	},
	{
		AT_EuroBison, "male", 74926,
		{
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Piebald", 150 },
			{ 5, "Light Brown", 24900 },
			{ 6, "Brown", 24900 },
			{ 8, "Dark Brown", 24900 },
		}
	},
	{
		AT_EuroBison, "female", 74926,
		{
			{ 0, "Brown", 24900 },
			{ 1, "Dark Brown", 24900 },
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Piebald", 150 },
			{ 7, "Light Brown", 24900 },
		}
	},
	{
		AT_GredosIbex, "male", 74776,
		{
			{ 0, "Gray_Brown", 18675 },
			{ 1, "Albino", 38 },
			{ 2, "Brown Hybrid", 18675 },
			{ 3, "Melanistic", 38 },
			{ 6, "Light Grey", 18675 },
			{ 7, "Grey", 18675 },
		}
	},
	{
		AT_GredosIbex, "female", 56101,
		{
			{ 1, "Albino", 38 },
			{ 3, "Melanistic", 38 },
			{ 4, "Light Brown", 18675 },
			{ 5, "Buff", 18675 },
			{ 6, "Light Grey", 18675 },
		}
	},
	{
		AT_WhitetailDeer, "male", 75264,
		{
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 9, "Fabled Piebald", 38 },
			{ 4, "Piebald", 150 },
			{ 5, "Tan", 25000 },
			{ 6, "Brown", 25000 },
			{ 8, "Dark Brown", 25000 },
		}
	},
	{
		AT_WhitetailDeer, "female", 75226,
		{
			{ 0, "Brown", 25000 },
			{ 1, "Dark Brown", 25000 },
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Piebald", 150 },
			{ 7, "Red Brown", 25000 },
		}
	},
	{
		AT_AxisDeer, "male", 87500,
		{
			{ 1, "Dark", 12500 },
			{ 2, "Piebald", 200 },
			{ 3, "Melanistic", 50 },
			{ 4, "Spotted", 74700 },
			{ 5, "Albino", 50 },
		}
	},
	{
		AT_AxisDeer, "female", 87500,
		{
			{ 0, "Orange", 12500 },
			{ 2, "Piebald", 200 },
			{ 3, "Melanistic", 50 },
			{ 4, "Spotted", 74700 },
			{ 5, "Albino", 50 },
		}
	},
	{
		AT_RedFox, "male", 74926,
		{
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Piebald", 150 },
			{ 5, "Dark Red", 24900 },
			{ 6, "Red", 24900 },
			{ 8, "Orange", 24900 },
		}
	},
	{
		AT_RedFox, "female", 74926,
		{
			{ 0, "Red", 24900 },
			{ 1, "Orange", 24900 },
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Piebald", 150 },
			{ 7, "Dark Red", 24900 },
		}
	},
	{
		AT_GrizzlyBear, "male", 74926,
		{
			{ 0, "Melanistic", 38 },
			{ 1, "Albino", 38 },
			{ 2, "Gray Brown", 74700 },
			{ 3, "Brown", 150 },
		}
	},
	{
		AT_GrizzlyBear, "female", 74926,
		{
			{ 0, "Melanistic", 38 },
			{ 1, "Albino", 38 },
			{ 4, "Brown", 150 },
			{ 2, "Gray Brown", 74700 },
		}
	},
	{
		AT_FeralGoat, "male", 99999,
		{
			{ 10, "White Brown", 8333 },
			{ 0, "Black", 50 },
			{ 1, "Black White", 8333 },
			{ 2, "Albino", 50 },
			{ 3, "Black Brown", 8333 },
			{ 9, "Mixed", 100 },
			{ 4, "Blonde", 18675 },
			{ 5, "Dark Brown", 18675 },
			{ 6, "White", 18675 },
			{ 8, "Mixed", 100 },
			{ 7, "Brown", 18675 },
		}
	},
	{
		AT_FeralGoat, "female", 45783,
		{
			{ 0, "Black", 50 },
			{ 1, "Black White", 8333 },
			{ 2, "Albino", 50 },
			{ 6, "White", 18675 },
			{ 7, "Brown", 18675 },
		}
	},
	{
		AT_SikaDeer, "male", 100000,
		{
			{ 4, "Brown", 37350 },
			{ 3, "Spotted", 12500 },
			{ 1, "Spotted Dark", 12500 },
			{ 2, "Spotted Red", 200 },
			{ 0, "Black", 37350 },
			{ 5, "Albino", 100 },
		}
	},
	{
		AT_SikaDeer, "female", 100000,
		{
			{ 4, "Brown", 37350 },
			{ 3, "Spotted", 12500 },
			{ 1, "Spotted Dark", 12500 },
			{ 2, "Spotted Red", 200 },
			{ 0, "Black", 37350 },
			{ 5, "Albino", 100 },
		}
	},
	{
		AT_MuleDeer, "male", 100000,
		{
			{ 0, "Blonde", 37350 },
			{ 1, "Dilute", 200 },
			{ 2, "Melanistic", 25 },
			{ 3, "Grey", 25000 },
			{ 4, "Piebald", 25 },
			{ 5, "Piebald", 25 },
			{ 6, "Brown", 37350 },
			{ 7, "Albino", 25 },
		}
	},
	{
		AT_MuleDeer, "female", 100000,
		{
			{ 0, "Blonde", 37350 },
			{ 1, "Dilute", 200 },
			{ 2, "Melanistic", 25 },
			{ 3, "Grey", 25000 },
			{ 4, "Piebald", 25 },
			{ 5, "Piebald", 25 },
			{ 6, "Brown", 37350 },
			{ 7, "Albino", 25 },
		}
	},
	{
		AT_SoutheasternSpanishIbex, "male", 74776,
		{
			{ 0, "Gray_Brown", 18675 },
			{ 1, "Albino", 38 },
			{ 2, "Light Grey", 18675 },
			{ 3, "Melanistic", 38 },
			{ 6, "Brown Hybrid", 18675 },
			{ 7, "Orange", 18675 },
		}
	},
	{
		AT_SoutheasternSpanishIbex, "female", 56101,
		{
			{ 1, "Albino", 38 },
			{ 3, "Melanistic", 38 },
			{ 4, "Light Brown", 18675 },
			{ 5, "Buff", 18675 },
			{ 6, "Brown Hybrid", 18675 },
		}
	},
	{
		AT_MexicanBobcat, "male", 100000,
		{
			{ 2, "Blue", 200 },
			{ 3, "Brown", 12500 },
			{ 5, "Red", 12500 },
			{ 4, "Melanistic", 50 },
			{ 6, "Tan", 37350 },
			{ 0, "Grey", 37350 },
			{ 1, "Albino", 50 },
		}
	},
	{
		AT_MexicanBobcat, "female", 100000,
		{
			{ 2, "Blue", 200 },
			{ 3, "Brown", 12500 },
			{ 5, "Red", 12500 },
			{ 4, "Melanistic", 50 },
			{ 6, "Tan", 37350 },
			{ 0, "Grey", 37350 },
			{ 1, "Albino", 50 },
		}
	},
	{
		AT_EurasianTeal, "male", 74800,
		{
			{ 2, "Dark_Green", 37350 },
			{ 3, "Hybrid Blue", 25 },
			{ 5, "Leucistic", 25 },
			{ 4, "Hybrid Green", 25 },
			{ 6, "Leucistic", 25 },
			{ 0, "Light Green", 37350 },
		}
	},
	{
		AT_EurasianTeal, "female", 74800,
		{
			{ 7, "Leucistic", 100 },
			{ 1, "Brown", 74700 },
		}
	},
	{
		AT_WildBoar, "male", 74926,
		{
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Blackgold", 150 },
			{ 5, "Light Brown", 24900 },
			{ 6, "Brown", 24900 },
			{ 8, "Light Brown", 24900 },
		}
	},
	{
		AT_WildBoar, "female", 74926,
		{
			{ 0, "Brown", 24900 },
			{ 1, "Light Brown", 24900 },
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Blackgold", 150 },
			{ 7, "Dark Brown", 24900 },
		}
	},
	{
		AT_GrayWolf, "male", 74926,
		{
			{ 0, "Melanistic", 38 },
			{ 1, "Albino", 38 },
			{ 2, "Eggwhite", 50 },
			{ 3, "Red Brown", 50 },
			{ 4, "Grey", 74700 },
			{ 5, "Dark Grey", 50 },
		}
	},
	{
		AT_GrayWolf, "female", 74926,
		{
			{ 0, "Melanistic", 38 },
			{ 1, "Albino", 38 },
			{ 2, "Eggwhite", 50 },
			{ 3, "Red Brown", 50 },
			{ 4, "Grey", 74700 },
			{ 5, "Dark Grey", 50 },
		}
	},
	{
		AT_CinnamonTeal, "male", 99800,
		{
			{ 0, "Melanistic", 100 },
			{ 1, "Piebald", 12500 },
			{ 3, "Cinnamon", 74700 },
			{ 4, "Red", 12500 },
		}
	},
	{
		AT_CinnamonTeal, "female", 87375,
		{
			{ 2, "Beige", 175 },
			{ 3, "Cinnamon", 74700 },
			{ 4, "Red", 12500 },
		}
	},
	{
		AT_MerriamTurkey, "male", 125000,
		{
			{ 2, "Light Brown", 25000 },
			{ 3, "Leucistic", 200 },
			{ 5, "Dark Brown", 25000 },
			{ 4, "Melanistic", 50 },
			{ 0, "Brown", 74700 },
			{ 1, "Albino", 50 },
		}
	},
	{
		AT_MerriamTurkey, "female", 125000,
		{
			{ 2, "Light Brown", 25000 },
			{ 3, "Leucistic", 200 },
			{ 5, "Dark Brown", 25000 },
			{ 4, "Melanistic", 50 },
			{ 0, "Brown", 74700 },
			{ 1, "Albino", 50 },
		}
	},
	{
		AT_Moose, "male", 74926,
		{
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 9, "Mocha", 0 }, 
			{ 4, "Piebald", 150 },
			{ 5, "Light Brown", 24900 },
			{ 6, "Tan", 24900 },
			{ 8, "Brown", 24900 },
		}
	},
	{
		AT_Moose, "female", 74926,
		{
			{ 0, "Tan", 24900 },
			{ 1, "Brown", 24900 },
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Piebald", 150 },
			{ 7, "Dark Brown", 24900 },
		}
	},
	{
		AT_Coyote, "male", 74926,
		{
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Piebald", 150 },
			{ 5, "Gray Brown", 24900 },
			{ 6, "Orange", 24900 },
			{ 8, "Dark Grey", 24900 },
		}
	},
	{
		AT_Coyote, "female", 74926,
		{
			{ 0, "Gray Brown", 24900 },
			{ 1, "Orange", 24900 },
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Piebald", 150 },
			{ 7, "Light Grey", 24900 },
		}
	},
	{
		AT_MountainGoat, "male", 299100,
		{
			{ 0, "Beige", 74700 },
			{ 3, "Melanistic", 150 },
			{ 2, "White", 74700 },
			{ 1, "Light Brown", 74700 },
			{ 5, "Light Grey", 74700 },
			{ 4, "Albino", 150 },
		}
	},
	{
		AT_MountainGoat, "female", 299100,
		{
			{ 0, "Beige", 74700 },
			{ 3, "Melanistic", 150 },
			{ 2, "White", 74700 },
			{ 1, "Light Brown", 74700 },
			{ 5, "Light Grey", 74700 },
			{ 4, "Albino", 150 },
		}
	},
	{
		AT_RockyMountainElk, "male", 100000,
		{
			{ 4, "Albino", 100 },
			{ 1, "Light Grey", 25000 },
			{ 3, "Piebald", 100 },
			{ 2, "Piebald", 100 },
			{ 5, "Light Brown", 37350 },
			{ 0, "Brown", 37350 },
		}
	},
	{
		AT_RockyMountainElk, "female", 100000,
		{
			{ 4, "Albino", 100 },
			{ 1, "Light Grey", 25000 },
			{ 3, "Piebald", 100 },
			{ 2, "Piebald", 100 },
			{ 5, "Light Brown", 37350 },
			{ 0, "Brown", 37350 },
		}
	},
	{
		AT_BlacktailDeer, "male", 74926,
		{
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Piebald", 150 },
			{ 5, "Gray Brown", 24900 },
			{ 6, "Grey", 24900 },
			{ 8, "Dark Grey", 24900 },
		}
	},
	{
		AT_BlacktailDeer, "female", 74926,
		{
			{ 0, "Tan", 24900 },
			{ 1, "Grey", 24900 },
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Piebald", 150 },
			{ 7, "Gray Brown", 24900 },
		}
	},
	{
		AT_EuroHare, "male", 74776,
		{
			{ 0, "Dark Brown", 18675 },
			{ 1, "Grey", 18675 },
			{ 2, "Albino", 38 },
			{ 3, "Melanistic", 38 },
			{ 4, "Brown", 18675 },
			{ 5, "Light Brown", 18675 },
		}
	},
	{
		AT_EuroHare, "female", 74776,
		{
			{ 0, "Dark Brown", 18675 },
			{ 1, "Grey", 18675 },
			{ 2, "Albino", 38 },
			{ 3, "Melanistic", 38 },
			{ 4, "Brown", 18675 },
			{ 5, "Light Brown", 18675 },
		}
	},
	{
		AT_Chamois, "male", 100000,
		{
			{ 1, "Gray_Brown", 37350 },
			{ 2, "Honeytones", 12500 },
			{ 4, "Melanistic", 50 },
			{ 3, "Leucistic", 200 },
			{ 0, "Brown", 12500 },
			{ 6, "Dark Brown", 37350 },
			{ 5, "Albino", 50 },
		}
	},
	{
		AT_Chamois, "female", 100000,
		{
			{ 1, "Gray Brown", 37350 },
			{ 2, "Honeytones", 12500 },
			{ 4, "Melanistic", 50 },
			{ 3, "Leucistic", 200 },
			{ 0, "Brown", 12500 },
			{ 6, "Dark Brown", 37350 },
			{ 5, "Albino", 50 },
		}
	},
	{
		AT_Goldeneye, "male", 75050,
		{
			{ 3, "Eclipse", 200 },
			{ 5, "Hybrid", 25 },
			{ 4, "Hybrid", 25 },
			{ 6, "Leucistic", 50 },
			{ 7, "Leucistic", 50 },
			{ 0, "Black", 74700 },
		}
	},
	{
		AT_Goldeneye, "female", 75000,
		{
			{ 2, "Dark", 200 },
			{ 6, "Leucistic", 50 },
			{ 7, "Leucistic", 50 },
			{ 1, "Grey", 74700 },
		}
	},
	{
		AT_Reindeer, "male", 74926,
		{
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Leucistic", 75 },
			{ 5, "Piebald", 75 },
			{ 6, "Light Brown", 37350 },
			{ 7, "Dark Brown", 37350 },
		}
	},
	{
		AT_Reindeer, "female", 74926,
		{
			{ 0, "Tan", 37350 },
			{ 1, "Brown", 37350 },
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Leucistic", 75 },
			{ 5, "Piebald", 75 },
		}
	},
	{
		AT_CommonRaccoon, "male", 100000,
		{
			{ 2, "Grey", 37350 },
			{ 3, "Piebald Blonde", 100 },
			{ 5, "Albino", 50 },
			{ 4, "Piebald Grey", 100 },
			{ 6, "Melanistic", 50 },
			{ 0, "Brown", 37350 },
			{ 1, "Blonde", 25000 },
		}
	},
	{
		AT_CommonRaccoon, "female", 62650,
		{
			{ 3, "Piebald Blonde", 100 },
			{ 5, "Albino", 50 },
			{ 4, "Piebald Grey", 100 },
			{ 6, "Melanistic", 50 },
			{ 0, "Brown", 37350 },
			{ 1, "Blonde", 25000 },
		}
	},
	{
		AT_RooseveltElk, "male", 74926,
		{
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Piebald", 150 },
			{ 5, "Brown", 24900 },
			{ 6, "Tan", 24900 },
			{ 8, "Orange", 24900 },
		}
	},
	{
		AT_RooseveltElk, "female", 74926,
		{
			{ 0, "Tan", 24900 },
			{ 1, "Orange", 24900 },
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Piebald", 150 },
			{ 7, "Brown", 24900 },
		}
	},
	{
		AT_PlainsBison, "male", 87225,
		{
			{ 0, "Light Grey", 24900 },
			{ 1, "Dark", 18675 },
			{ 2, "Leucistic", 25 },
			{ 3, "Albino", 25 },
			{ 4, "Melanistic", 25 },
			{ 5, "Brown", 18675 },
			{ 6, "Light Brown", 24900 },
		}
	},
	{
		AT_PlainsBison, "female", 87225,
		{
			{ 0, "Light Grey", 24900 },
			{ 1, "Dark", 18675 },
			{ 2, "Leucistic", 25 },
			{ 3, "Albino", 25 },
			{ 4, "Melanistic", 25 },
			{ 5, "Brown", 18675 },
			{ 6, "Light Brown", 24900 },
		}
	},
	{
		AT_FallowDeer, "male", 74926,
		{
			{ 0, "Piebald", 150 },
			{ 1, "Dark", 14940 },
			{ 3, "Spotted", 14940 },
			{ 5, "Spotted Dark", 14940 },
			{ 9, "Albino", 38 },
			{ 10, "Dark", 14940 },
			{ 11, "Melanistic", 38 },
			{ 12, "Spotted", 14940 },
		}
	},
	{
		AT_FallowDeer, "female", 64816,
		{
			{ 2, "Spotted", 24900 },
			{ 4, "Spotted Red", 24900 },
			{ 6, "Spotted Dark", 14940 },
			{ 7, "Melanistic", 38 },
			{ 8, "Albino", 38 },
		}
	},
	{
		AT_BobwhiteQuail, "male", 297008,
		{
			{ 2, "Grey", 99000 },
			{ 3, "Albino", 8 },
			{ 0, "Brown", 99000 },
			{ 1, "Red Brown", 99000 },
		}
	},
	{
		AT_BobwhiteQuail, "female", 99008,
		{
			{ 3, "Albino", 8 },
			{ 0, "Brown", 99000 },
		}
	},
	{
		AT_GrayFox, "male", 100001,
		{
			{ 2, "Tone", 12500 },
			{ 3, "Albino", 50 },
			{ 5, "Leucistic", 67 },
			{ 4, "Melanistic", 50 },
			{ 6, "Piebald", 67 },
			{ 7, "Piebald", 67 },
			{ 0, "Grey", 74700 },
			{ 1, "Red", 12500 },
		}
	},
	{
		AT_GrayFox, "female", 100001,
		{
			{ 2, "Tone", 12500 },
			{ 3, "Albino", 50 },
			{ 5, "Leucistic", 67 },
			{ 4, "Melanistic", 50 },
			{ 6, "Piebald", 67 },
			{ 7, "Piebald", 67 },
			{ 0, "Grey", 74700 },
			{ 1, "Red", 12500 },
		}
	},
	{
		AT_FeralPig, "male", 100000,
		{
			{ 6, "Brown Hybrid", 12450 },
			{ 5, "Brown Hybrid", 12450 },
			{ 3, "Black Spots", 12500 },
			{ 4, "Dark Brown", 12450 },
			{ 9, "Dark Brown", 12450 },
			{ 2, "Black Spots", 12500 },
			{ 1, "Pink", 200 },
			{ 8, "Brown", 12450 },
			{ 0, "Albino", 100 },
			{ 7, "Blackgold", 12450 },
		}
	},
	{
		AT_FeralPig, "female", 25200,
		{
			{ 3, "Black Spots", 12500 },
			{ 2, "Black Spots", 12500 },
			{ 1, "Pink", 200 },
		}
	},
	{
		AT_Mallard, "male", 99900,
		{
			{ 0, "Melanistic", 100 },
			{ 1, "Piebald", 12500 },
			{ 3, "Leucistic", 100 },
			{ 4, "Black Brown", 74700 },
			{ 5, "Brown Hybrid", 12500 },
		}
	},
	{
		AT_Mallard, "female", 99900,
		{
			{ 0, "Melanistic", 100 },
			{ 1, "Piebald", 12500 },
			{ 2, "Blonde", 100 },
			{ 4, "Black Brown", 74700 },
			{ 5, "Brown Hybrid", 12500 },
		}
	},
	{
		AT_EuroRabbit, "male", 100000,
		{
			{ 0, "Dark Brown", 37350 },
			{ 1, "Leucistic", 50 },
			{ 2, "Melanistic", 100 },
			{ 3, "Light Brown", 12500 },
			{ 4, "Light Grey", 100 },
			{ 5, "Brown", 12500 },
			{ 6, "Albino", 50 },
			{ 7, "Tan", 37350 },
		}
	},
	{
		AT_EuroRabbit, "female", 100000,
		{
			{ 0, "Dark Brown", 37350 },
			{ 1, "Leucistic", 50 },
			{ 2, "Melanistic", 100 },
			{ 3, "Light Brown", 12500 },
			{ 4, "Light Grey", 100 },
			{ 5, "Brown", 12500 },
			{ 6, "Albino", 50 },
			{ 7, "Tan", 37350 },
		}
	},
	{
		AT_EurasianWigeon, "male", 74999,
		{
			{ 2, "Brown", 37350 },
			{ 3, "Eclipse", 200 },
			{ 4, "Hybrid", 33 },
			{ 7, "Leucistic", 33 },
			{ 8, "Leucistic", 33 },
			{ 1, "Grey", 37350 },
		}
	},
	{
		AT_EurasianWigeon, "female", 74966,
		{
			{ 5, "Dark", 200 },
			{ 6, "Grey", 37350 },
			{ 7, "Leucistic", 33 },
			{ 0, "Brown", 37350 },
			{ 8, "Leucistic", 33 },
		}
	},
	{
		AT_CollaredPeccary, "male", 100000,
		{
			{ 2, "Leucistic", 100 },
			{ 3, "Ochre", 100 },
			{ 5, "Dark Grey", 12500 },
			{ 4, "Dark Brown", 12500 },
			{ 6, "Albino", 50 },
			{ 7, "Melanistic", 50 },
			{ 0, "Grey", 37350 },
			{ 1, "Brown", 37350 },
		}
	},
	{
		AT_CollaredPeccary, "female", 100000,
		{
			{ 2, "Leucistic", 100 },
			{ 3, "Ochre", 100 },
			{ 5, "Dark Grey", 12500 },
			{ 4, "Dark Brown", 12500 },
			{ 6, "Albino", 50 },
			{ 7, "Melanistic", 50 },
			{ 0, "Grey", 37350 },
			{ 1, "Brown", 37350 },
		}
	},
	{
		AT_BeceiteIbex, "male", 74776,
		{
			{ 1, "Grey", 18675 },
			{ 2, "Albino", 38 },
			{ 3, "Orange", 18675 },
			{ 4, "Melanistic", 38 },
			{ 5, "Brown Hybrid", 18675 },
			{ 6, "Gray Brown", 18675 },
		}
	},
	{
		AT_BeceiteIbex, "female", 68551,
		{
			{ 0, "Buff", 24900 },
			{ 2, "Albino", 38 },
			{ 4, "Melanistic", 38 },
			{ 6, "Gray Brown", 18675 },
			{ 7, "Light Brown", 24900 },
		}
	},
	{
		AT_IberianMuflon, "male", 74926,
		{
			{ 0, "Light Brown", 24900 },
			{ 1, "Grey", 150 },
			{ 2, "Albino", 38 },
			{ 5, "Melanistic", 38 },
			{ 3, "Brown", 24900 },
			{ 4, "Brown", 24900 },
		}
	},
	{
		AT_IberianMuflon, "female", 50026,
		{
			{ 1, "Grey", 150 },
			{ 2, "Albino", 38 },
			{ 5, "Melanistic", 38 },
			{ 3, "Brown", 24900 },
			{ 4, "Brown", 24900 },
		}
	},
	{
		AT_ScrubHare, "male", 77400,
		{
			{ 0, "Grey", 2500 },
			{ 1, "Light Grey", 200 },
			{ 2, "Brown", 37350 },
			{ 3, "Chestnut", 37350 },
		}
	},
	{
		AT_ScrubHare, "female", 77400,
		{
			{ 0, "Grey", 2500 },
			{ 1, "Light Grey", 200 },
			{ 2, "Brown", 37350 },
			{ 3, "Chestnut", 37350 },
		}
	},
	{
		AT_RondaIbex, "male", 74776,
		{
			{ 0, "Gray_Brown", 18675 },
			{ 1, "Albino", 38 },
			{ 2, "Brown Hybrid", 18675 },
			{ 3, "Melanistic", 38 },
			{ 6, "Brown", 18675 },
			{ 7, "Grey", 18675 },
		}
	},
	{
		AT_RondaIbex, "female", 56101,
		{
			{ 1, "Albino", 38 },
			{ 3, "Melanistic", 38 },
			{ 4, "Buff", 18675 },
			{ 5, "Light Brown", 18675 },
			{ 6, "Brown", 18675 },
		}
	},
	{
		AT_EasternWildTurkey, "male", 100000,
		{
			{ 2, "Light Brown", 12500 },
			{ 3, "Leucistic", 200 },
			{ 5, "Bronze", 37350 },
			{ 4, "Melanistic", 50 },
			{ 6, "Light Bronze", 12500 },
			{ 0, "Brown", 37350 },
			{ 1, "Albino", 50 },
		}
	},
	{
		AT_EasternWildTurkey, "female", 100000,
		{
			{ 2, "Light Brown", 12500 },
			{ 3, "Leucistic", 200 },
			{ 5, "Bronze", 37350 },
			{ 4, "Melanistic", 50 },
			{ 6, "Light Bronze", 12500 },
			{ 0, "Brown", 37350 },
			{ 1, "Albino", 50 },
		}
	},
	{
		AT_WillowPtarmigan, "male", 37650,
		{
			{ 3, "Molting", 24900 },
			{ 5, "White", 200 },
			{ 6, "Red", 100 },
			{ 0, "Bicolor", 12450 },
		}
	},
	{
		AT_WillowPtarmigan, "female", 62450,
		{
			{ 2, "Brown", 12450 },
			{ 3, "Molting", 24900 },
			{ 5, "White", 200 },
			{ 4, "Molting", 12450 },
			{ 1, "Bicolor", 12450 },
		}
	},
	{
		AT_RedDeer, "male", 74964,
		{
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 9, "Fabbled Spotted", 38 },
			{ 4, "Piebald", 150 },
			{ 5, "Brown", 24900 },
			{ 6, "Light Brown", 24900 },
			{ 8, "Dark Brown", 24900 },
		}
	},
	{
		AT_RedDeer, "female", 74926,
		{
			{ 0, "Dark Brown", 24900 },
			{ 1, "Brown", 24900 },
			{ 2, "Melanistic", 38 },
			{ 3, "Albino", 38 },
			{ 4, "Piebald", 150 },
			{ 7, "Grey", 24900 },
		}
	},
	{
		AT_CapeBuffalo, "male", 99730,
		{
			{ 0, "Grey", 37350 },
			{ 1, "Leucistic", 50 },
			{ 2, "Albino", 50 },
			{ 3, "Black", 37350 },
			{ 4, "Brown", 24930 },
		}
	},
	{
		AT_CapeBuffalo, "female", 99730,
		{
			{ 0, "Grey", 37350 },
			{ 1, "Leucistic", 50 },
			{ 2, "Albino", 50 },
			{ 3, "Black", 37350 },
			{ 4, "Brown", 24930 },
		}
	},
	{
		AT_EasternCottontailRabbit, "male", 100000,
		{
			{ 2, "Grey", 37350 },
			{ 3, "Leucistic", 100 },
			{ 5, "Light Grey", 12500 },
			{ 4, "Leucistic", 100 },
			{ 6, "Melanistic", 50 },
			{ 7, "Albino", 50 },
			{ 0, "Brown", 37350 },
			{ 1, "Light Brown", 12500 },
		}
	},
	{
		AT_EasternCottontailRabbit, "female", 100000,
		{
			{ 2, "Grey", 37350 },
			{ 3, "Leucistic", 100 },
			{ 5, "Light Grey", 12500 },
			{ 4, "Leucistic", 100 },
			{ 6, "Melanistic", 50 },
			{ 7, "Albino", 50 },
			{ 0, "Brown", 37350 },
			{ 1, "Light Brown", 12500 },
		}
	},
	{
		AT_RaccoonDog, "male", 87678,
		{
			{ 2, "Black White", 12500 },
			{ 3, "Orange", 200 },
			{ 5, "Piebald", 26 },
			{ 4, "Dark Brown", 200 },
			{ 6, "Piebald", 26 },
			{ 7, "Albino", 26 },
			{ 0, "Light Brown", 37350 },
			{ 1, "Grey", 37350 },
		}
	},
	{
		AT_RaccoonDog, "female", 87678,
		{
			{ 2, "Black White", 12500 },
			{ 3, "Orange", 200 },
			{ 5, "Piebald", 26 },
			{ 4, "Dark_Brown", 200 },
			{ 6, "Piebald", 26 },
			{ 7, "Albino", 26 },
			{ 0, "Light Brown", 37350 },
			{ 1, "Grey", 37350 },
		}
	}
	};
#pragma endregion

	class Animal
	{
	protected:
		std::vector<char> gender_bytes;
		std::vector<char> weight_bytes;
		std::vector<char> score_bytes;
		std::vector<char> is_great_one_bytes;
		std::vector<char> visual_variation_seed_bytes;

		void SetGender(const uint8_t gender);
		void SetGender(const std::string& gender);
		void SetWeight(const float weight);
		void SetScore(const float score);
		void SetIsGreatOne(const bool is_great_one);
		void SetIdx(const uint32_t idx);
		void SetVisualVariationSeed(const uint32_t visual_variation_seed);
		void SetFurType(const uint32_t visual_variation_seed);
		static FurDB::FurTypes* GetFurTypesFromDB(const AnimalType animal_type, const std::string& gender);

		bool VerifyGender() const;
		virtual bool VerifyWeight() const;
		virtual bool VerifyScore() const;
		bool VerifyVisualVariationSeed() const;
		bool Verify() const;

		void SetGenderBytes();
		void SetWeightBytes();
		void SetScoreBytes();
		void SetIsGreatOneBytes();
		void SetVisualVariationSeedBytes();

	public:
		AnimalType m_animal_type;
		std::string m_name;
		uint8_t m_gender_id;
		std::string m_gender;
		float m_weight;
		float m_score;
		uint8_t m_is_great_one;
		uint32_t m_visual_variation_seed;
		std::string m_fur_type;
		uint32_t m_fur_type_id;
		uint32_t m_idx;
		uint32_t m_grp_idx;
		bool m_valid;

		Animal(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx);
		virtual ~Animal() = default;
		Animal(const Animal& src) = default;
		Animal(Animal&& src) = default;
		Animal& operator=(const Animal& rhs) = default;
		Animal& operator=(Animal&& rhs) = default;

		static std::shared_ptr<Animal> Create(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx);

		static AnimalType ResolveAnimalType(std::string& name);
		static std::string ResolveGender(const uint8_t gender_id);
		static uint8_t ResolveGender(const std::string& gender);
		static uint32_t CreateVisualVariationSeed(const AnimalType animal_type, const std::string& str_gender, const std::string& fur_type);

		std::vector<char> GetByteStream();
		virtual float GetMinWeight();
		virtual float GetMaxWeight();
		virtual float GetMinScore();
		virtual float GetMaxScore();

		bool IsValid() const;

		friend std::ostream& operator<<(std::ostream& out, const Animal& data);
	};


	// Write max/min weight/score of each from animal_scoring.bin.xlsx
#pragma region Animals
	class WildBoar : public Animal
	{
	public:
		WildBoar(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Wild Boar";
			m_valid = Verify();
		}
		~WildBoar() override = default;

		float GetMinWeight()
		{
			if (m_gender == "male")
			{
				return 32.f;
			}
			else if (m_gender == "female")
			{
				return 25.f;
			}
			return 0.f;
		}

		float GetMaxWeight()
		{
			if (m_gender == "male")
			{
				return 240.f;
			}
			else if (m_gender == "female")
			{
				return 168.f;
			}
			return 0.f;
		}

		float GetMinScore()
		{
			if (m_gender == "male")
			{
				return 7.f;
			}
			else if (m_gender == "female")
			{
				return 7.f;
			}
			return 0.f;
		}

		float GetMaxScore()
		{
			if (m_gender == "male")
			{
				return 159.5f;
			}
			else if (m_gender == "female")
			{
				return 81.5f;
			}
			return 0.f;
		}
	};

	class FallowDeer : public Animal
	{
	public:
		FallowDeer(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Fallow Deer";
			m_valid = Verify();
		}
		~FallowDeer() override = default;
	};

	class EuroBison : public Animal
	{
	public:
		EuroBison(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "European Bison";
			m_valid = Verify();
		}
		~EuroBison() override = default;
	};

	class RoeDeer : public Animal
	{
	public:
		RoeDeer(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Roe Deer";

			m_valid = Verify();
		}
		~RoeDeer() override = default;
	};

	class RedFox : public Animal
	{
	public:
		RedFox(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Red Fox";

			m_valid = Verify();
		}
		~RedFox() override = default;
	};

	class CanadaGoose : public Animal
	{
	public:
		CanadaGoose(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Canada Goose";
			m_valid = Verify();
		}
		~CanadaGoose() override = default;
	};

	class RedDeer : public Animal
	{
	public:
		RedDeer(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Red Deer";
			m_valid = Verify();
		}
		~RedDeer() override = default;

		float GetMinWeight()
		{
			if (m_gender == "male")
			{
				return 160.f;
			}
			else if (m_gender == "female")
			{
				return 120.f;
			}
			return 0.f;
		}

		float GetMaxWeight()
		{
			if (m_gender == "male")
			{
				return 240.f;
			}
			else if (m_gender == "female")
			{
				return 170.f;
			}
			return 0.f;
		}

		float GetMinScore()
		{
			if (m_gender == "male")
			{
				return 44.626953125f;
			}
			else if (m_gender == "female")
			{
				return 0.f;
			}
			return 0.f;
		}

		float GetMaxScore()
		{
			if (m_gender == "male")
			{
				return 274.014526367187f;
			}
			else if (m_gender == "female")
			{
				return 0.f;
			}
			return 0.f;
		}
	};

	class EuroRabbit : public Animal
	{
	public:
		EuroRabbit(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "European Rabbit";
			m_valid = Verify();
		}
		~EuroRabbit() override = default;
	};

	class Moose : public Animal
	{
	public:
		Moose(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Moose";
			m_valid = Verify();
		}
		~Moose() override = default;
	};

	class Jackrabbit : public Animal
	{
	public:
		Jackrabbit(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Jackrabbit";

			m_valid = Verify();
		}
		~Jackrabbit() override = default;
	};

	class Mallard : public Animal
	{
	public:
		Mallard(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Mallard";

			m_valid = Verify();
		}
		~Mallard() override = default;
	};

	class BlackBear : public Animal
	{
	public:
		BlackBear(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Black Bear";

			m_valid = Verify();
		}
		~BlackBear() override = default;
	};

	class RooseveltElk : public Animal
	{
	public:
		RooseveltElk(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Roosevelt Elk";

			m_valid = Verify();
		}
		~RooseveltElk() override = default;
	};

	class Coyote : public Animal
	{
	public:
		Coyote(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Coyote";

			m_valid = Verify();
		}
		~Coyote() override = default;
	};

	class BlacktailDeer : public Animal
	{
	public:
		BlacktailDeer(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Blacktail Deer";

			m_valid = Verify();
		}
		~BlacktailDeer() override = default;
	};

	class WhitetailDeer : public Animal
	{
	public:
		WhitetailDeer(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Whitetail Deer";
			m_valid = Verify();
		}
		~WhitetailDeer() override = default;
	};

	class MuskDeer : public Animal
	{
	public:
		MuskDeer(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Musk Deer";

			m_valid = Verify();
		}
		~MuskDeer() override = default;
	};

	class Reindeer : public Animal
	{
	public:
		Reindeer(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Reindeer";

			m_valid = Verify();
		}
		~Reindeer() override = default;
	};

	class EurasianLynx : public Animal
	{
	public:
		EurasianLynx(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Eurasian Lynx";

			m_valid = Verify();
		}
		~EurasianLynx() override = default;
	};

	class BrownBear : public Animal
	{
	public:
		BrownBear(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Brown Bear";

			m_valid = Verify();
		}
		~BrownBear() override = default;
	};

	class BlueWildebeest : public Animal
	{
	public:
		BlueWildebeest(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Blue Wildebeest";

			m_valid = Verify();
		}
		~BlueWildebeest() override = default;
	};

	class SideStripedJackal : public Animal
	{
	public:
		SideStripedJackal(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Side-striped Jackal";

			m_valid = Verify();
		}
		~SideStripedJackal() override = default;
	};

	class Gemsbok : public Animal
	{
	public:
		Gemsbok(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Gemsbok";

			m_valid = Verify();
		}
		~Gemsbok() override = default;
	};

	class LesserKudu : public Animal
	{
	public:
		LesserKudu(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Lesser Kudu";

			m_valid = Verify();
		}
		~LesserKudu() override = default;
	};

	class ScrubHare : public Animal
	{
	public:
		ScrubHare(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Scrub Hare";

			m_valid = Verify();
		}
		~ScrubHare() override = default;
	};

	class Lion : public Animal
	{
	public:
		Lion(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Lion";

			m_valid = Verify();
		}
		~Lion() override = default;
	};

	class Warthog : public Animal
	{
	public:
		Warthog(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Warthog";

			m_valid = Verify();
		}
		~Warthog() override = default;
	};

	class CapeBuffalo : public Animal
	{
	public:
		CapeBuffalo(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Cape Buffalo";

			m_valid = Verify();
		}
		~CapeBuffalo() override = default;
	};

	class Springbok : public Animal
	{
	public:
		Springbok(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Springbok";

			m_valid = Verify();
		}
		~Springbok() override = default;
	};

	class WaterBuffalo : public Animal
	{
	public:
		WaterBuffalo(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Water Buffalo";

			m_valid = Verify();
		}
		~WaterBuffalo() override = default;
	};

	class Puma : public Animal
	{
	public:
		Puma(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Puma";

			m_valid = Verify();
		}
		~Puma() override = default;
	};

	class Blackbuck : public Animal
	{
	public:
		Blackbuck(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Blackbuck";

			m_valid = Verify();
		}
		~Blackbuck() override = default;
	};

	class CinnamonTeal : public Animal
	{
	public:
		CinnamonTeal(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Cinnamon Teal";

			m_valid = Verify();
		}
		~CinnamonTeal() override = default;
	};

	class MuleDeer : public Animal
	{
	public:
		MuleDeer(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Mule Deer";

			m_valid = Verify();
		}
		~MuleDeer() override = default;
	};

	class AxisDeer : public Animal
	{
	public:
		AxisDeer(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Axis Deer";

			m_valid = Verify();
		}
		~AxisDeer() override = default;
	};

	class HarlequinDuck : public Animal
	{
	public:
		HarlequinDuck(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Harlequin Duck";

			m_valid = Verify();
		}
		~HarlequinDuck() override = default;
	};

	class Caribou : public Animal
	{
	public:
		Caribou(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Caribou";

			m_valid = Verify();
		}
		~Caribou() override = default;
	};

	class GrizzlyBear : public Animal
	{
	public:
		GrizzlyBear(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Grizzly Bear";

			m_valid = Verify();
		}
		~GrizzlyBear() override = default;
	};

	class GrayWolf : public Animal
	{
	public:
		GrayWolf(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Gray Wolf";

			m_valid = Verify();
		}
		~GrayWolf() override = default;
	};

	class PlainsBison : public Animal
	{
	public:
		PlainsBison(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Plains Bison";

			m_valid = Verify();
		}
		~PlainsBison() override = default;
	};

	class SoutheasternSpanishIbex : public Animal
	{
	public:
		SoutheasternSpanishIbex(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Southeastern Spanish Ibex";

			m_valid = Verify();
		}
		~SoutheasternSpanishIbex() override = default;
	};

	class IberianWolf : public Animal
	{
	public:
		IberianWolf(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Iberian Wolf";

			m_valid = Verify();
		}
		~IberianWolf() override = default;
	};

	class IberianMuflon : public Animal
	{
	public:
		IberianMuflon(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Iberian Muflon";

			m_valid = Verify();
		}
		~IberianMuflon() override = default;
	};

	class BeceiteIbex : public Animal
	{
	public:
		BeceiteIbex(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Beceite Ibex";

			m_valid = Verify();
		}
		~BeceiteIbex() override = default;
	};

	class EuroHare : public Animal
	{
	public:
		EuroHare(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "European Hare";

			m_valid = Verify();
		}
		~EuroHare() override = default;
	};

	class RondaIbex : public Animal
	{
	public:
		RondaIbex(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Ronda Ibex";

			m_valid = Verify();
		}
		~RondaIbex() override = default;
	};

	class GredosIbex : public Animal
	{
	public:
		GredosIbex(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Gredos Ibex";

			m_valid = Verify();
		}
		~GredosIbex() override = default;
	};

	class Pronghorn : public Animal
	{
	public:
		Pronghorn(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Pronghorn";

			m_valid = Verify();
		}
		~Pronghorn() override = default;
	};

	class MountainLion : public Animal
	{
	public:
		MountainLion(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Mountain Lion";

			m_valid = Verify();
		}
		~MountainLion() override = default;
	};

	class MountainGoat : public Animal
	{
	public:
		MountainGoat(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Mountain Goat";

			m_valid = Verify();
		}
		~MountainGoat() override = default;
	};

	class BighornSheep : public Animal
	{
	public:
		BighornSheep(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Bighorn Sheep";

			m_valid = Verify();
		}
		~BighornSheep() override = default;
	};

	class MerriamTurkey : public Animal
	{
	public:
		MerriamTurkey(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Merriam Turkey";

			m_valid = Verify();
		}
		~MerriamTurkey() override = default;
	};

	class RockyMountainElk : public Animal
	{
	public:
		RockyMountainElk(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Rocky Mountain Elk";

			m_valid = Verify();
		}
		~RockyMountainElk() override = default;
	};

	class SikaDeer : public Animal
	{
	public:
		SikaDeer(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Sika Deer";

			m_valid = Verify();
		}
		~SikaDeer() override = default;
	};

	class Chamois : public Animal
	{
	public:
		Chamois(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Chamois";

			m_valid = Verify();
		}
		~Chamois() override = default;
	};

	class FeralPig : public Animal
	{
	public:
		FeralPig(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Feral Pig";

			m_valid = Verify();
		}
		~FeralPig() override = default;
	};

	class FeralGoat : public Animal
	{
	public:
		FeralGoat(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Feral Goat";

			m_valid = Verify();
		}
		~FeralGoat() override = default;
	};

	class CollaredPeccary : public Animal
	{
	public:
		CollaredPeccary(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Collared Peccary";

			m_valid = Verify();
		}
		~CollaredPeccary() override = default;
	};

	class MexicanBobcat : public Animal
	{
	public:
		MexicanBobcat(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Mexican Bobcat";

			m_valid = Verify();
		}
		~MexicanBobcat() override = default;
	};

	class RioGrandeTurkey : public Animal
	{
	public:
		RioGrandeTurkey(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Rio Grande Turkey";

			m_valid = Verify();
		}
		~RioGrandeTurkey() override = default;
	};

	class RingNeckedPheasant : public Animal
	{
	public:
		RingNeckedPheasant(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Ring-necked Pheasant";

			m_valid = Verify();
		}
		~RingNeckedPheasant() override = default;
	};

	class AntelopeJackrabbit : public Animal
	{
	public:
		AntelopeJackrabbit(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Antelope Jackrabbit";

			m_valid = Verify();
		}
		~AntelopeJackrabbit() override = default;
	};

	class AmericanAlligator : public Animal
	{
	public:
		AmericanAlligator(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "American Alligator";

			m_valid = Verify();
		}
		~AmericanAlligator() override = default;
	};

	class WildHog : public Animal
	{
	public:
		WildHog(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Wild Hog";

			m_valid = Verify();
		}
		~WildHog() override = default;
	};

	class GrayFox : public Animal
	{
	public:
		GrayFox(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Gray Fox";

			m_valid = Verify();
		}
		~GrayFox() override = default;
	};

	class CommonRaccoon : public Animal
	{
	public:
		CommonRaccoon(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Common Raccoon";

			m_valid = Verify();
		}
		~CommonRaccoon() override = default;
	};

	class EasternWildTurkey : public Animal
	{
	public:
		EasternWildTurkey(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Eastern Wild Turkey";

			m_valid = Verify();
		}
		~EasternWildTurkey() override = default;
	};

	class EasternCottontailRabbit : public Animal
	{
	public:
		EasternCottontailRabbit(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Eastern Cottontail Rabbit";

			m_valid = Verify();
		}
		~EasternCottontailRabbit() override = default;
	};

	class BobwhiteQuail : public Animal
	{
	public:
		BobwhiteQuail(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Bobwhite Quail";

			m_valid = Verify();
		}
		~BobwhiteQuail() override = default;
	};

	class RaccoonDog : public Animal
	{
	public:
		RaccoonDog(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Raccoon Dog";

			m_valid = Verify();
		}
		~RaccoonDog() override = default;
	};

	class EurasianWigeon : public Animal
	{
	public:
		EurasianWigeon(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Eurasian Wigeon";

			m_valid = Verify();
		}
		~EurasianWigeon() override = default;
	};

	class TundraBeanGoose : public Animal
	{
	public:
		TundraBeanGoose(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Tundra Bean Goose";

			m_valid = Verify();
		}
		~TundraBeanGoose() override = default;
	};

	class EurasianTeal : public Animal
	{
	public:
		EurasianTeal(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Eurasian Teal";

			m_valid = Verify();
		}
		~EurasianTeal() override = default;
	};

	class BlackGrouse : public Animal
	{
	public:
		BlackGrouse(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Black Grouse";

			m_valid = Verify();
		}
		~BlackGrouse() override = default;
	};

	class Goldeneye : public Animal
	{
	public:
		Goldeneye(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Goldeneye";

			m_valid = Verify();
		}
		~Goldeneye() override = default;
	};

	class HazelGrouse : public Animal
	{
	public:
		HazelGrouse(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Hazel Grouse";

			m_valid = Verify();
		}
		~HazelGrouse() override = default;
	};

	class WesternCapercaillie : public Animal
	{
	public:
		WesternCapercaillie(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Western Capercaillie";

			m_valid = Verify();
		}
		~WesternCapercaillie() override = default;
	};

	class TuftedDuck : public Animal
	{
	public:
		TuftedDuck(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Tufted Duck";

			m_valid = Verify();
		}
		~TuftedDuck() override = default;
	};

	class RockPtarmigan : public Animal
	{
	public:
		RockPtarmigan(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Rock Ptarmigan";

			m_valid = Verify();
		}
		~RockPtarmigan() override = default;
	};

	class WillowPtarmigan : public Animal
	{
	public:
		WillowPtarmigan(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Willow Ptarmigan";

			m_valid = Verify();
		}
		~WillowPtarmigan() override = default;
	};

	class GreylagGoose : public Animal
	{
	public:
		GreylagGoose(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Gerylag Goose";

			m_valid = Verify();
		}
		~GreylagGoose() override = default;
	};

	class MountainHare : public Animal
	{
	public:
		MountainHare(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx)
		{

			m_name = "Mountain Hare";

			m_valid = Verify();
		}
		~MountainHare() override = default;
	};
#pragma endregion
}
