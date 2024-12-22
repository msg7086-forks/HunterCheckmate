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
	struct ScoreEntry
	{
		float min_score_male;
		float max_score_male;
		float min_score_female;
		float max_score_female;
	};

	struct WeightEntry
	{
		float min_weight_male;
		float max_weight_male;
		float min_weight_female;
		float max_weight_female;
	};

	struct FurType
	{
		uint32_t fur_idx;
		std::string fur_name;
		uint32_t fur_probability;
	};

	struct FurEntry
	{
		std::string gender;
		uint32_t max_probability;
		std::vector<FurType> fur_types;
	};

	static std::map < AnimalType, WeightEntry > weight_db =
	{
		{ AT_RedDeer, { 160.f, 240.f, 120.f, 170.f } },
		{ AT_WildBoar, { 32.f, 240.f, 25.f, 168.f } },
		{ AT_RedFox, { 2.420000076293945f, 15.39999961853027f, 1.980000019073486f, 12.60000038146973f } },
		{ AT_EuBison, { 400.f, 920.f, 300.f, 540.f } },
		{ AT_RoeDeer, { 18.f, 35.f, 14.f, 33.f } },
		{ AT_Whitetail, { 59.f, 100.f, 40.f, 59.f } },
		{ AT_RooseveltElk, { 300.f, 500.f, 260.f, 285.f } },
		{ AT_Blacktail, { 50.f, 95.f, 40.f, 59.f } },
		{ AT_FallowDeer, { 60.f, 100.f, 30.f, 50.f } },
		{ AT_Coyote, { 16.f, 27.f, 15.f, 20.f } },
		{ AT_Moose, { 400.f, 620.f, 320.f, 440.f } },
		{ AT_BlackBear, { 57.f, 290.f, 40.f, 145.f } },
		{ AT_EurasianLynx, { 18.f, 45.f, 8.f, 21.f } },
		{ AT_EurasianBrownBear, { 195.f, 482.f, 110.f, 340.f } },
		{ AT_SiberianMuskDeer, { 7.f, 17.f, 7.f, 17.f } },
		{ AT_Reindeer, { 159.f, 182.f, 80.f, 120.f } },
		{ AT_Jackrabbit, { 1.899999976158142f, 6.829999923706055f, 2.f, 4.599999904632568f } },
		{ AT_CanadaGoose, { 3.5f, 9.199999809265137f, 3.200000047683716f, 6.800000190734863f } },
		{ AT_CapeBuffalo, { 600.f, 950.f, 360.f, 530.f } },
		{ AT_Warthog, { 60.f, 150.f, 45.f, 80.f } },
		{ AT_SidestripedJackal, { 7.f, 14.f, 6.f, 10.f } },
		{ AT_Springbok, { 32.f, 42.f, 27.f, 37.f } },
		{ AT_LesserKudu, { 60.f, 105.f, 50.f, 95.f } },
		{ AT_ScrubHare, { 1.899999976158142f, 5.099999904632568f, 1.5f, 5.800000190734863f } },
		{ AT_BlueWildebeest, { 200.f, 290.f, 190.f, 260.f } },
		{ AT_Mallard, { 0.949999988079071f, 2.099999904632568f, 0.7200000286102295f, 1.600000023841858f } },
		{ AT_Gemsbok, { 180.f, 240.f, 100.f, 210.f } },
		{ AT_Puma, { 65.f, 105.f, 29.f, 64.f } },
		{ AT_MountainLion, { 65.f, 105.f, 29.f, 64.f } },
		{ AT_Blackbuck, { 34.f, 51.f, 25.f, 42.f } },
		{ AT_MuleDeer, { 100.f, 210.f, 70.f, 110.f } },
		{ AT_CinnamonTeal, { 0.3799999952316284f, 0.4799999892711639f, 0.300000011920929f, 0.4000000059604645f } },
		{ AT_AxisDeer, { 30.f, 75.f, 25.f, 42.f } },
		{ AT_WaterBuffalo, { 680.f, 1250.f, 520.f, 1025.f } },
		{ AT_Lion, { 170.f, 270.f, 135.f, 200.f } },
		{ AT_GrizzlyBear, { 225.f, 680.f, 165.f, 300.f } },
		{ AT_GrayWolf, { 45.f, 80.f, 30.f, 60.f } },
		{ AT_Caribou, { 150.f, 190.f, 75.f, 125.f } },
		{ AT_HarlequinDuck, { 0.5799999833106995f, 0.75f, 0.4799999892711639f, 0.6800000071525574f } },
		{ AT_PlainsBison, { 450.f, 1200.f, 350.f, 550.f } },
		{ AT_BeceiteIbex, { 75.f, 110.f, 35.f, 70.f } },
		{ AT_RondaIbex, { 45.f, 70.f, 35.f, 70.f } },
		{ AT_GredosIbex, { 70.f, 102.f, 35.f, 70.f } },
		{ AT_SoutheasternIbex, { 35.f, 87.5f, 35.f, 70.f } },
		{ AT_IberianMouflon, { 40.f, 60.f, 30.f, 40.f } },
		{ AT_IberianWolf, { 35.f, 50.f, 30.f, 40.f } },
		{ AT_EuHare, { 2.f, 4.f, 2.f, 7.f } },
		{ AT_WildTurkey, { 6.800000190734863f, 11.f, 3.599999904632568f, 5.400000095367432f } },
		{ AT_BighornSheep, { 70.f, 160.f, 50.f, 100.f } },
		{ AT_RockymountainElk, { 280.f, 480.f, 200.f, 250.f } },
		{ AT_MountainGoat, { 60.f, 145.f, 45.f, 105.f } },
		{ AT_ProngHorn, { 40.f, 65.f, 35.f, 50.f } },
		{ AT_EuRabbit, { 1.100000023841858f, 2.599999904632568f, 0.8999999761581421f, 1.700000047683716f } },
		{ AT_FeralPig, { 45.f, 205.f, 32.f, 114.f } },
		{ AT_FeralGoat, { 44.f, 50.f, 25.f, 35.f } },
		{ AT_Chamois, { 40.f, 65.f, 35.f, 50.f } },
		{ AT_SikaDeer, { 30.f, 75.f, 25.f, 42.f } },
		{ AT_MexicanBobcat, { 18.f, 45.f, 8.f, 21.f } },
		{ AT_CollaredPeccary, { 16.f, 31.f, 14.f, 27.f } },
		{ AT_Pheasant, { 0.75f, 3.f, 0.5f, 1.25f } },
		{ AT_RioGrandeTurkey, { 6.800000190734863f, 11.f, 3.599999904632568f, 5.400000095367432f } },
		{ AT_AntelopeJackrabbit, { 2.700000047683716f, 4.699999809265137f, 2.200000047683716f, 4.099999904632568f } },
		{ AT_AmericanAlligator, { 200.f, 530.f, 75.f, 145.f } },
		{ AT_Raccoon, { 4.f, 13.f, 3.f, 6.f } },
		{ AT_EasternWildTurkey, { 6.800000190734863f, 11.f, 3.599999904632568f, 5.400000095367432f } },
		{ AT_NorthernBobwhiteQuail, { 0.1299999952316284f, 0.25f, 0.1299999952316284f, 0.1749999970197678f } },
		{ AT_GrayFox, { 3.5f, 6.800000190734863f, 3.099999904632568f, 6.5f } },
		{ AT_EasternCottontailRabbit, { 0.800000011920929f, 1.799999952316284f, 1.100000023841858f, 2.099999904632568f } },
		{ AT_RaccoonDog, { 3.f, 10.f, 3.f, 6.5f } },
		{ AT_BlackGrouse, { 1.f, 1.25f, 0.75f, 1.100000023841858f } },
		{ AT_EurasianTeal, { 0.3199999928474426f, 0.3600000143051147f, 0.300000011920929f, 0.3400000035762787f } },
		{ AT_TuftedDuck, { 0.75f, 1.f, 0.6299999952316284f, 0.8999999761581421f } },
		{ AT_Goldeneye, { 0.6000000238418579f, 1.299999952316284f, 0.6000000238418579f, 1.100000023841858f } },
		{ AT_EurasianWigeon, { 0.5f, 0.949999988079071f, 0.5f, 0.800000011920929f } },
		{ AT_TundraBeanGoose, { 1.899999976158142f, 3.299999952316284f, 1.899999976158142f, 2.799999952316284f } },
		{ AT_GreylagGoose, { 2.5f, 4.f, 2.5f, 3.5f } },
		{ AT_HazelGrouse, { 0.300000011920929f, 0.449999988079071f, 0.300000011920929f, 0.4000000059604645f } },
		{ AT_WesternCapercaillie, { 3.599999904632568f, 5.f, 1.5f, 2.5f } },
		{ AT_RockPtarmigan, { 0.4399999976158142f, 0.7400000095367432f, 0.4300000071525574f, 0.699999988079071f } },
		{ AT_WillowPtarmigan, { 0.4300000071525574f, 0.8100000023841858f, 0.4300000071525574f, 0.7900000214576721f } },
		{ AT_MountainHare, { 2.f, 4.f, 2.f, 6.f } }
	};

	static std::map < AnimalType, ScoreEntry > score_db = 
	{
		{ AT_RedDeer, { 44.626953125f, 274.0145263671875f, 0.f, 0.f } },
		{ AT_WildBoar, { 7.f, 159.5f, 7.f, 81.5f } },
		{ AT_RedFox, { 2.420000076293945f, 15.39999961853027f, 1.980000019073486f, 12.60000038146973f } },
		{ AT_EuBison, { 7.f, 300.f, 4.f, 150.f } },
		{ AT_RoeDeer, { 29.38578224182129f, 87.69715118408203f, 0.f, 0.f } },
		{ AT_Whitetail, { 71.18055725097656f, 275.5350952148438f, 0.f, 0.f } },
		{ AT_RooseveltElk, { 56.6655387878418f, 416.8609924316406f, 0.f, 0.f } },
		{ AT_Blacktail, { 48.17201232910156f, 191.9611206054688f, 0.f, 0.f } },
		{ AT_FallowDeer, { 15.49038219451904f, 277.9747009277344f, 0.f, 0.f } },
		{ AT_Coyote, { 35.27391815185547f, 59.52473831176758f, 33.06930160522461f, 44.09239959716797f } },
		{ AT_Moose, { 32.29645538330078f, 301.9588317871094f, 0.f, 0.f } },
		{ AT_BlackBear, { 12.81599998474121f, 24.f, 12.f, 17.04000091552734f } },
		{ AT_EurasianLynx, { 19.50081062316895f, 28.97999954223633f, 15.98999977111816f, 20.55405426025391f } },
		{ AT_EurasianBrownBear, { 18.97043037414551f, 29.f, 16.f, 24.03763389587402f } },
		{ AT_SiberianMuskDeer, { 6.f, 276.f, 0.f, 0.f } },
		{ AT_Reindeer, { 73.19405364990234f, 469.9026184082031f, 73.19405364990234f, 158.f } },
		{ AT_Jackrabbit, { 1.899999976158142f, 6.829999923706055f, 2.f, 4.599999904632568f } },
		{ AT_CanadaGoose, { 3.5f, 9.199999809265137f, 3.200000047683716f, 6.800000190734863f } },
		{ AT_CapeBuffalo, { 91.f, 162.5f, 51.f, 114.f } },
		{ AT_Warthog, { 25.f, 63.f, 15.f, 25.f } },
		{ AT_SidestripedJackal, { 15.43233966827393f, 30.86467933654785f, 13.22772026062012f, 22.04619979858398f } },
		{ AT_Springbok, { 69.f, 116.5999984741211f, 57.59999847412109f, 82.f } },
		{ AT_LesserKudu, { 95.3170166015625f, 157.9007110595703f, 0.f, 0.f } },
		{ AT_ScrubHare, { 1.899999976158142f, 5.099999904632568f, 1.5f, 5.800000190734863f } },
		{ AT_BlueWildebeest, { 28.5f, 40.f, 17.f, 26.f } },
		{ AT_Mallard, { 9.5f, 21.f, 7.199999809265137f, 16.f } },
		{ AT_Gemsbok, { 196.f, 342.f, 154.f, 358.f } },
		{ AT_Puma, { 34.73684310913086f, 40.f, 30.f, 34.60526275634766f } },
		{ AT_MountainLion, { 34.73684310913086f, 40.f, 30.f, 34.60526275634766f } },
		{ AT_Blackbuck, { 54.5336799621582f, 140.8974151611328f, 0.f, 0.f } },
		{ AT_MuleDeer, { 37.28028869628906f, 342.7140808105469f, 0.f, 0.f } },
		{ AT_CinnamonTeal, { 3.799999952316284f, 4.800000190734863f, 3.f, 4.f } },
		{ AT_AxisDeer, { 31.5652027130127f, 237.9368438720703f, 0.f, 0.f } },
		{ AT_WaterBuffalo, { 80.f, 179.4385223388672f, 60.48808670043945f, 102.f } },
		{ AT_Lion, { 38.88888931274414f, 50.f, 35.f, 42.22222137451172f } },
		{ AT_GrizzlyBear, { 51.f, 69.f, 48.5f, 54.f } },
		{ AT_GrayWolf, { 33.f, 40.f, 30.f, 35.f } },
		{ AT_Caribou, { 73.19405364990234f, 469.9026184082031f, 73.19405364990234f, 158.f } },
		{ AT_HarlequinDuck, { 5.800000190734863f, 7.5f, 4.800000190734863f, 6.800000190734863f } },
		{ AT_PlainsBison, { 12.f, 245.5f, 2.f, 120.f } },
		{ AT_BeceiteIbex, { 45.55049514770508f, 207.8642120361328f, 45.55049514770508f, 60.f } },
		{ AT_RondaIbex, { 58.24422836303711f, 113.5166473388672f, 58.24422836303711f, 70.f } },
		{ AT_GredosIbex, { 41.25128936767578f, 106.7189559936523f, 41.25128936767578f, 50.f } },
		{ AT_SoutheasternIbex, { 38.32047271728516f, 95.38712310791016f, 38.32047271728516f, 60.f } },
		{ AT_IberianMouflon, { 73.42443084716797f, 191.3599853515625f, 0.f, 0.f } },
		{ AT_IberianWolf, { 33.f, 40.f, 30.f, 35.f } },
		{ AT_EuHare, { 2.f, 4.f, 2.f, 7.f } },
		{ AT_WildTurkey, { 3.799999952316284f, 4.800000190734863f, 3.f, 4.f } },
		{ AT_BighornSheep, { 69.08650970458984f, 175.2475280761719f, 69.08650970458984f, 120.f } },
		{ AT_RockymountainElk, { 91.13737487792969f, 524.77685546875f, 0.f, 0.f } },
		{ AT_MountainGoat, { 48.54271697998047f, 115.5292358398438f, 37.02085494995117f, 85.25108337402344f } },
		{ AT_ProngHorn, { 31.26031303405762f, 105.4471893310547f, 31.26031303405762f, 42.08193969726562f } },
		{ AT_EuRabbit, { 1.100000023841858f, 2.599999904632568f, 0.8999999761581421f, 1.700000047683716f } },
		{ AT_FeralPig, { 7.f, 159.5f, 7.f, 81.5f } },
		{ AT_FeralGoat, { 81.96337127685547f, 225.7583923339844f, 55.36909484863281f, 74.4432373046875f } },
		{ AT_Chamois, { 23.09284210205078f, 61.89008331298828f, 23.08282470703125f, 58.04738235473633f } },
		{ AT_SikaDeer, { 11.73466205596924f, 219.5238342285156f, 0.f, 0.f } },
		{ AT_MexicanBobcat, { 19.50081062316895f, 28.97999954223633f, 15.98999977111816f, 20.55405426025391f } },
		{ AT_CollaredPeccary, { 7.f, 159.5f, 7.f, 81.5f } },
		{ AT_Pheasant, { 7.900000095367432f, 21.89999961853027f, 5.900000095367432f, 7.900000095367432f } },
		{ AT_RioGrandeTurkey, { 3.799999952316284f, 4.800000190734863f, 3.f, 4.f } },
		{ AT_AntelopeJackrabbit, { 1.899999976158142f, 6.829999923706055f, 2.f, 4.599999904632568f } },
		{ AT_AmericanAlligator, { 200.f, 530.f, 150.f, 302.f } },
		{ AT_Raccoon, { 4.f, 13.f, 3.f, 6.f } },
		{ AT_EasternWildTurkey, { 3.799999952316284f, 4.800000190734863f, 3.f, 4.f } },
		{ AT_NorthernBobwhiteQuail, { 130.f, 250.f, 130.f, 275.f } },
		{ AT_GrayFox, { 3.5f, 6.800000190734863f, 3.099999904632568f, 6.5f } },
		{ AT_EasternCottontailRabbit, { 0.800000011920929f, 1.799999952316284f, 1.100000023841858f, 2.099999904632568f } },
		{ AT_RaccoonDog, { 3.f, 10.f, 3.f, 6.5f } },
		{ AT_BlackGrouse, { 100.f, 125.f, 75.f, 110.f } },
		{ AT_EurasianTeal, { 320.f, 360.f, 300.f, 340.f } },
		{ AT_TuftedDuck, { 750.f, 1000.f, 630.f, 900.f } },
		{ AT_Goldeneye, { 300.f, 1300.f, 600.f, 1100.f } },
		{ AT_EurasianWigeon, { 500.f, 950.f, 500.f, 800.f } },
		{ AT_TundraBeanGoose, { 1.899999976158142f, 3.299999952316284f, 1.899999976158142f, 2.799999952316284f } },
		{ AT_GreylagGoose, { 2.5f, 4.f, 2.5f, 3.5f } },
		{ AT_HazelGrouse, { 300.f, 450.f, 300.f, 400.f } },
		{ AT_WesternCapercaillie, { 3.599999904632568f, 5.f, 1.5f, 2.5f } },
		{ AT_RockPtarmigan, { 440.f, 740.f, 430.f, 700.f } },
		{ AT_WillowPtarmigan, { 430.f, 810.f, 430.f, 790.f } },
		{ AT_MountainHare, { 2.f, 4.f, 2.f, 6.f } }
	};

	static std::map < AnimalType,  std::vector<FurEntry> > fur_db = 
	{
		{ AT_Reindeer ,
		   {
			   {
				   "male", 74926,
					   {
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 4, "Leucistic", 75 },
						   { 5, "Piebald", 75 },
						   { 6, "LightBrown", 37350 },
						   { 7, "DarkBrown", 37350 },
					   }
			   },
			   {
				   "female", 74926,
					   {
						   { 0, "Tan", 37350 },
						   { 1, "Brown", 37350 },
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 4, "Leucistic", 75 },
						   { 5, "Piebald", 75 },
					   }
			   }
		   }
	    },

		{ AT_MexicanBobcat ,
		   {
			   {
				   "male", 100000,
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
				   "female", 100000,
					   {
						   { 2, "Blue", 200 },
						   { 3, "Brown", 12500 },
						   { 5, "Red", 12500 },
						   { 4, "Melanistic", 50 },
						   { 6, "Tan", 37350 },
						   { 0, "Grey", 37350 },
						   { 1, "Albino", 50 },
					   }
			   }
		   }
	   },

		{ AT_AxisDeer ,
		   {
			   {
				   "male", 87500,
					   {
						   { 1, "Dark", 12500 },
						   { 2, "Piebald", 200 },
						   { 3, "Melanistic", 50 },
						   { 4, "Spotted", 74700 },
						   { 5, "Albino", 50 },
					   }
			   },
			   {
				   "female", 87500,
					   {
						   { 0, "Orange", 12500 },
						   { 2, "Piebald", 200 },
						   { 3, "Melanistic", 50 },
						   { 4, "Spotted", 74700 },
						   { 5, "Albino", 50 },
					   }
			   }
		   }
	   },

		{ AT_HarlequinDuck ,
		   {
			   {
				   "male", 99800,
					   {
						   { 1, "Piebald", 25000 },
						   { 2, "Melanistic", 50 },
						   { 3, "Albino", 50 },
						   { 5, "DarkGrey", 74700 },
					   }
			   },
			   {
				   "female", 112288,
					   {
						   { 0, "Dark", 150 },
						   { 3, "Albino", 50 },
						   { 4, "Grey", 38 },
						   { 5, "DarkGrey", 74700 },
						   { 6, "DarkBrown", 37350 },
					   }
			   }
		   }
	   },

		{ AT_BlackBear ,
		   {
			   {
				   "male", 75154,
					   {
						   { 10, "GreatOneBlackBearFabledGlacier", 38 },
						   { 13, "GreatOneBlackBearFabledSpirit", 38 },
						   { 2, "Brown", 38 },
						   { 3, "Blonde", 38 },
						   { 11, "GreatOneBlackBearFabledCream", 38 },
						   { 12, "GreatOneBlackBearFabledSpotted", 38 },
						   { 9, "GreatOneBlackBearFabledGlacier", 38 },
						   { 4, "Cinnamon", 150 },
						   { 14, "GreatOneBlackBearFabledChestnut", 38 },
						   { 5, "Dark", 24900 },
						   { 6, "Black", 24900 },
						   { 8, "Dusky", 24900 },
					   }
			   },
			   {
				   "female", 74926,
					   {
						   { 0, "Black", 24900 },
						   { 1, "Dusky", 24900 },
						   { 2, "Brown", 38 },
						   { 3, "Blonde", 38 },
						   { 4, "Cinnamon", 150 },
						   { 7, "Dark", 24900 },
					   }
			   }
		   }
	   },

		{ AT_NorthernBobwhiteQuail ,
		   {
			   {
				   "male", 297008,
					   {
						   { 2, "Grey", 99000 },
						   { 3, "Albino", 8 },
						   { 0, "Brown", 99000 },
						   { 1, "RedBrown", 99000 },
					   }
			   },
			   {
				   "female", 99008,
					   {
						   { 3, "Albino", 8 },
						   { 0, "Brown", 99000 },
					   }
			   }
		   }
	   },

		{ AT_EurasianBrownBear ,
		   {
			   {
				   "male", 100000,
					   {
						   { 0, "Melanistic", 200 },
						   { 3, "Spirit", 5000 },
						   { 4, "Blonde", 5000 },
						   { 5, "Legendary", 0 },
						   { 6, "RedBrown", 24900 },
						   { 7, "Albino", 100 },
						   { 8, "Cinnamon", 24900 },
						   { 9, "Gold", 5000 },
						   { 10, "DarkBrown", 5000 },
						   { 11, "Grey", 5000 },
						   { 12, "LightBrown", 24900 },
					   }
			   },
			   {
				   "female", 100000,
					   {
						   { 0, "Melanistic", 200 },
						   { 1, "DarkBrown", 5000 },
						   { 2, "LightBrown", 24900 },
						   { 3, "Spirit", 5000 },
						   { 4, "Blonde", 5000 },
						   { 5, "Legendary", 0 },
						   { 6, "RedBrown", 24900 },
						   { 7, "Albino", 100 },
						   { 8, "Cinnamon", 24900 },
						   { 9, "Gold", 5000 },
						   { 11, "Grey", 5000 },
					   }
			   }
		   }
	   },

		{ AT_Springbok ,
		   {
			   {
				   "male", 74775,
					   {
						   { 2, "Albino", 75 },
						   { 3, "Tan", 37350 },
						   { 4, "Orange", 37350 },
					   }
			   },
			   {
				   "female", 124675,
					   {
						   { 0, "BlackBrown", 24900 },
						   { 1, "BlackBrown", 25000 },
						   { 2, "Albino", 75 },
						   { 3, "Tan", 37350 },
						   { 4, "Orange", 37350 },
					   }
			   }
		   }
	   },

		{ AT_FeralPig ,
		   {
			   {
				   "male", 100000,
					   {
						   { 6, "BrownHybrid", 12450 },
						   { 5, "BrownHybrid", 12450 },
						   { 3, "BlackSpots", 12500 },
						   { 4, "DarkBrown", 12450 },
						   { 9, "DarkBrown", 12450 },
						   { 2, "BlackSpots", 12500 },
						   { 1, "Pink", 200 },
						   { 8, "Brown", 12450 },
						   { 0, "Albino", 100 },
						   { 7, "Blackgold", 12450 },
					   }
			   },
			   {
				   "female", 25200,
					   {
						   { 3, "BlackSpots", 12500 },
						   { 2, "BlackSpots", 12500 },
						   { 1, "Pink", 200 },
					   }
			   }
		   }
	   },

		{ AT_WesternCapercaillie ,
		   {
			   {
				   "male", 74832,
					   {
						   { 2, "Leucistic", 66 },
						   { 3, "Leucistic", 33 },
						   { 4, "Pale", 33 },
						   { 1, "Dark", 74700 },
					   }
			   },
			   {
				   "female", 99766,
					   {
						   { 2, "Leucistic", 66 },
						   { 5, "Bright", 12500 },
						   { 6, "Ochre", 12500 },
						   { 0, "Brown", 74700 },
					   }
			   }
		   }
	   },

		{ AT_EuBison ,
		   {
			   {
				   "male", 74926,
					   {
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 4, "Piebald", 150 },
						   { 5, "LightBrown", 24900 },
						   { 6, "Brown", 24900 },
						   { 8, "DarkBrown", 24900 },
					   }
			   },
			   {
				   "female", 74926,
					   {
						   { 0, "Brown", 24900 },
						   { 1, "DarkBrown", 24900 },
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 4, "Piebald", 150 },
						   { 7, "LightBrown", 24900 },
					   }
			   }
		   }
	   },

		{ AT_EurasianTeal ,
		   {
			   {
				   "male", 74800,
					   {
						   { 2, "DarkGreen", 37350 },
						   { 3, "HybridBlue", 25 },
						   { 5, "Leucistic", 25 },
						   { 4, "HybridGreen", 25 },
						   { 6, "Leucistic", 25 },
						   { 0, "LightGreen", 37350 },
					   }
			   },
			   {
				   "female", 74800,
					   {
						   { 7, "Leucistic", 100 },
						   { 1, "Brown", 74700 },
					   }
			   }
		   }
	   },

		{ AT_MountainHare ,
		   {
			   {
				   "male", 99998,
					   {
						   { 2, "LightGrey", 24900 },
						   { 3, "LightBrown", 25000 },
						   { 5, "Molting", 66 },
						   { 4, "Molting", 66 },
						   { 6, "White", 66 },
						   { 7, "Albino", 100 },
						   { 0, "DarkGrey", 24900 },
						   { 1, "DarkBrown", 24900 },
					   }
			   },
			   {
				   "female", 99998,
					   {
						   { 2, "LightGrey", 24900 },
						   { 3, "LightBrown", 25000 },
						   { 5, "Molting", 66 },
						   { 4, "Molting", 66 },
						   { 6, "White", 66 },
						   { 7, "Albino", 100 },
						   { 0, "DarkGrey", 24900 },
						   { 1, "DarkBrown", 24900 },
					   }
			   }
		   }
	   },

		{ AT_WildBoar ,
		   {
			   {
				   "male", 74926,
					   {
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 4, "Blackgold", 150 },
						   { 5, "LightBrown", 24900 },
						   { 6, "Brown", 24900 },
						   { 8, "LightBrown", 24900 },
					   }
			   },
			   {
				   "female", 74926,
					   {
						   { 0, "Brown", 24900 },
						   { 1, "LightBrown", 24900 },
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 4, "Blackgold", 150 },
						   { 7, "DarkBrown", 24900 },
					   }
			   }
		   }
	   },

		{ AT_CollaredPeccary ,
		   {
			   {
				   "male", 100000,
					   {
						   { 2, "Leucistic", 100 },
						   { 3, "Ochre", 100 },
						   { 5, "DarkGrey", 12500 },
						   { 4, "DarkBrown", 12500 },
						   { 6, "Albino", 50 },
						   { 7, "Melanistic", 50 },
						   { 0, "Grey", 37350 },
						   { 1, "Brown", 37350 },
					   }
			   },
			   {
				   "female", 100000,
					   {
						   { 2, "Leucistic", 100 },
						   { 3, "Ochre", 100 },
						   { 5, "DarkGrey", 12500 },
						   { 4, "DarkBrown", 12500 },
						   { 6, "Albino", 50 },
						   { 7, "Melanistic", 50 },
						   { 0, "Grey", 37350 },
						   { 1, "Brown", 37350 },
					   }
			   }
		   }
	   },

		{ AT_Mallard ,
		   {
			   {
				   "male", 99900,
					   {
						   { 0, "Melanistic", 100 },
						   { 1, "Piebald", 12500 },
						   { 3, "Leucistic", 100 },
						   { 4, "BlackBrown", 74700 },
						   { 5, "BrownHybrid", 12500 },
					   }
			   },
			   {
				   "female", 99900,
					   {
						   { 0, "Melanistic", 100 },
						   { 1, "Piebald", 12500 },
						   { 2, "Blonde", 100 },
						   { 4, "BlackBrown", 74700 },
						   { 5, "BrownHybrid", 12500 },
					   }
			   }
		   }
	   },

		{ AT_LesserKudu ,
		   {
			   {
				   "male", 74793,
					   {
						   { 3, "Albino", 55 },
						   { 4, "Melanistic", 38 },
						   { 5, "Grey", 74700 },
					   }
			   },
			   {
				   "female", 74905,
					   {
						   { 0, "DarkBrown", 37350 },
						   { 1, "Dusky", 75 },
						   { 2, "RedBrown", 75 },
						   { 3, "Albino", 55 },
						   { 6, "Grey", 37350 },
					   }
			   }
		   }
	   },

		{ AT_RondaIbex ,
		   {
			   {
				   "male", 74776,
					   {
						   { 0, "GrayBrown", 18675 },
						   { 1, "Albino", 38 },
						   { 2, "BrownHybrid", 18675 },
						   { 3, "Melanistic", 38 },
						   { 6, "Brown", 18675 },
						   { 7, "Grey", 18675 },
					   }
			   },
			   {
				   "female", 56101,
					   {
						   { 1, "Albino", 38 },
						   { 3, "Melanistic", 38 },
						   { 4, "Buff", 18675 },
						   { 5, "LightBrown", 18675 },
						   { 6, "Brown", 18675 },
					   }
			   }
		   }
	   },

		{ AT_EuHare ,
		   {
			   {
				   "male", 74776,
					   {
						   { 0, "DarkBrown", 18675 },
						   { 1, "Grey", 18675 },
						   { 2, "Albino", 38 },
						   { 3, "Melanistic", 38 },
						   { 4, "Brown", 18675 },
						   { 5, "LightBrown", 18675 },
					   }
			   },
			   {
				   "female", 74776,
					   {
						   { 0, "DarkBrown", 18675 },
						   { 1, "Grey", 18675 },
						   { 2, "Albino", 38 },
						   { 3, "Melanistic", 38 },
						   { 4, "Brown", 18675 },
						   { 5, "LightBrown", 18675 },
					   }
			   }
		   }
	   },

		{ AT_GrayWolf ,
		   {
			   {
				   "male", 74926,
					   {
						   { 0, "Melanistic", 38 },
						   { 1, "Albino", 38 },
						   { 2, "Eggwhite", 50 },
						   { 3, "RedBrown", 50 },
						   { 4, "Grey", 74700 },
						   { 5, "DarkGrey", 50 },
					   }
			   },
			   {
				   "female", 74926,
					   {
						   { 0, "Melanistic", 38 },
						   { 1, "Albino", 38 },
						   { 2, "Eggwhite", 50 },
						   { 3, "RedBrown", 50 },
						   { 4, "Grey", 74700 },
						   { 5, "DarkGrey", 50 },
					   }
			   }
		   }
	   },

		{ AT_MountainGoat ,
		   {
			   {
				   "male", 299100,
					   {
						   { 0, "Beige", 74700 },
						   { 3, "Melanistic", 150 },
						   { 2, "White", 74700 },
						   { 1, "LightBrown", 74700 },
						   { 5, "LightGrey", 74700 },
						   { 4, "Albino", 150 },
					   }
			   },
			   {
				   "female", 299100,
					   {
						   { 0, "Beige", 74700 },
						   { 3, "Melanistic", 150 },
						   { 2, "White", 74700 },
						   { 1, "LightBrown", 74700 },
						   { 5, "LightGrey", 74700 },
						   { 4, "Albino", 150 },
					   }
			   }
		   }
	   },

		{ AT_RaccoonDog ,
		   {
			   {
				   "male", 87678,
					   {
						   { 2, "BlackWhite", 12500 },
						   { 3, "Orange", 200 },
						   { 5, "Piebald", 26 },
						   { 4, "DarkBrown", 200 },
						   { 6, "Piebald", 26 },
						   { 7, "Albino", 26 },
						   { 0, "LightBrown", 37350 },
						   { 1, "Grey", 37350 },
					   }
			   },
			   {
				   "female", 87678,
					   {
						   { 2, "BlackWhite", 12500 },
						   { 3, "Orange", 200 },
						   { 5, "Piebald", 26 },
						   { 4, "DarkBrown", 200 },
						   { 6, "Piebald", 26 },
						   { 7, "Albino", 26 },
						   { 0, "LightBrown", 37350 },
						   { 1, "Grey", 37350 },
					   }
			   }
		   }
	   },

		{ AT_RooseveltElk ,
		   {
			   {
				   "male", 74926,
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
				   "female", 74926,
					   {
						   { 0, "Tan", 24900 },
						   { 1, "Orange", 24900 },
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 4, "Piebald", 150 },
						   { 7, "Brown", 24900 },
					   }
			   }
		   }
	   },

		{ AT_AntelopeJackrabbit ,
		   {
			   {
				   "male", 99730,
					   {
						   { 2, "DarkBrown", 12465 },
						   { 3, "Mottled", 12465 },
						   { 5, "Melanistic", 50 },
						   { 4, "Albino", 50 },
						   { 0, "Brown", 37350 },
						   { 1, "Grey", 37350 },
					   }
			   },
			   {
				   "female", 99730,
					   {
						   { 2, "DarkBrown", 12465 },
						   { 3, "Mottled", 12465 },
						   { 5, "Melanistic", 50 },
						   { 4, "Albino", 50 },
						   { 0, "Brown", 37350 },
						   { 1, "Grey", 37350 },
					   }
			   }
		   }
	   },

		{ AT_RockymountainElk ,
		   {
			   {
				   "male", 100000,
					   {
						   { 4, "Albino", 100 },
						   { 1, "LightGrey", 25000 },
						   { 3, "Piebald", 100 },
						   { 2, "Piebald", 100 },
						   { 5, "LightBrown", 37350 },
						   { 0, "Brown", 37350 },
					   }
			   },
			   {
				   "female", 100000,
					   {
						   { 4, "Albino", 100 },
						   { 1, "LightGrey", 25000 },
						   { 3, "Piebald", 100 },
						   { 2, "Piebald", 100 },
						   { 5, "LightBrown", 37350 },
						   { 0, "Brown", 37350 },
					   }
			   }
		   }
	   },

		{ AT_Warthog ,
		   {
			   {
				   "male", 99705,
					   {
						   { 0, "RedBrown", 24930 },
						   { 2, "Albino", 75 },
						   { 3, "Grey", 37350 },
						   { 4, "Dark", 37350 },
					   }
			   },
			   {
				   "female", 99755,
					   {
						   { 0, "RedBrown", 24930 },
						   { 1, "Red", 50 },
						   { 2, "Albino", 75 },
						   { 3, "Grey", 37350 },
						   { 4, "Dark", 37350 },
					   }
			   }
		   }
	   },

		{ AT_Pheasant ,
		   {
			   {
				   "male", 99742,
					   {
						   { 2, "WhiteBrown", 37350 },
						   { 3, "Leucistic", 34 },
						   { 5, "Albino", 34 },
						   { 4, "Molting", 12470 },
						   { 6, "Melanistic", 34 },
						   { 0, "Brown", 37350 },
						   { 1, "Grey", 12470 },
					   }
			   },
			   {
				   "female", 42452,
					   {
						   { 3, "Leucistic", 34 },
						   { 5, "Albino", 34 },
						   { 6, "Melanistic", 34 },
						   { 7, "Grey", 5000 },
						   { 0, "Brown", 37350 },
					   }
			   }
		   }
	   },

		{ AT_EurasianLynx ,
		   {
			   {
				   "male", 74926,
					   {
						   { 2, "Albino", 38 },
						   { 3, "Melanistic", 38 },
						   { 4, "Piebald", 150 },
						   { 5, "Grey", 37350 },
						   { 6, "LightBrown", 37350 },
					   }
			   },
			   {
				   "female", 74926,
					   {
						   { 0, "Grey", 37350 },
						   { 1, "LightBrown", 37350 },
						   { 2, "Albino", 38 },
						   { 3, "Melanistic", 38 },
						   { 4, "Piebald", 150 },
					   }
			   }
		   }
	   },

		{ AT_CinnamonTeal ,
		   {
			   {
				   "male", 99800,
					   {
						   { 0, "Melanistic", 100 },
						   { 1, "Piebald", 12500 },
						   { 3, "Cinnamon", 74700 },
						   { 4, "Red", 12500 },
					   }
			   },
			   {
				   "female", 87375,
					   {
						   { 2, "Beige", 175 },
						   { 3, "Cinnamon", 74700 },
						   { 4, "Red", 12500 },
					   }
			   }
		   }
	   },

		{ AT_TundraBeanGoose ,
		   {
			   {
				   "male", 49949,
					   {
						   { 2, "LightGrey", 6250 },
						   { 3, "Leucistic", 33 },
						   { 5, "Leucistic", 33 },
						   { 4, "Leucistic", 33 },
						   { 0, "Brown", 37350 },
						   { 1, "DarkGrey", 6250 },
					   }
			   },
			   {
				   "female", 49949,
					   {
						   { 2, "LightGrey", 6250 },
						   { 3, "Leucistic", 33 },
						   { 5, "Leucistic", 33 },
						   { 4, "Leucistic", 33 },
						   { 0, "Brown", 37350 },
						   { 1, "DarkGrey", 6250 },
					   }
			   }
		   }
	   },

		{ AT_Chamois ,
		   {
			   {
				   "male", 100000,
					   {
						   { 1, "GrayBrown", 37350 },
						   { 2, "Honeytones", 12500 },
						   { 4, "Melanistic", 50 },
						   { 3, "Leucistic", 200 },
						   { 0, "Brown", 12500 },
						   { 6, "DarkBrown", 37350 },
						   { 5, "Albino", 50 },
					   }
			   },
			   {
				   "female", 100000,
					   {
						   { 1, "GrayBrown", 37350 },
						   { 2, "Honeytones", 12500 },
						   { 4, "Melanistic", 50 },
						   { 3, "Leucistic", 200 },
						   { 0, "Brown", 12500 },
						   { 6, "DarkBrown", 37350 },
						   { 5, "Albino", 50 },
					   }
			   }
		   }
	   },

		{ AT_CapeBuffalo ,
		   {
			   {
				   "male", 99730,
					   {
						   { 0, "Grey", 37350 },
						   { 1, "Leucistic", 50 },
						   { 2, "Albino", 50 },
						   { 3, "Black", 37350 },
						   { 4, "Brown", 24930 },
					   }
			   },
			   {
				   "female", 99730,
					   {
						   { 0, "Grey", 37350 },
						   { 1, "Leucistic", 50 },
						   { 2, "Albino", 50 },
						   { 3, "Black", 37350 },
						   { 4, "Brown", 24930 },
					   }
			   }
		   }
	   },

		{ AT_FallowDeer ,
		   {
			   {
				   "male", 74926,
					   {
						   { 0, "Piebald", 150 },
						   { 1, "Dark", 14940 },
						   { 3, "Spotted", 14940 },
						   { 5, "SpottedDark", 14940 },
						   { 9, "Albino", 38 },
						   { 10, "Dark", 14940 },
						   { 11, "Melanistic", 38 },
						   { 12, "Spotted", 14940 },
					   }
			   },
			   {
				   "female", 64816,
					   {
						   { 2, "Spotted", 24900 },
						   { 4, "SpottedRed", 24900 },
						   { 6, "SpottedDark", 14940 },
						   { 7, "Melanistic", 38 },
						   { 8, "Albino", 38 },
					   }
			   }
		   }
	   },

		{ AT_Raccoon ,
		   {
			   {
				   "male", 100000,
					   {
						   { 2, "Grey", 37350 },
						   { 3, "PiebaldBlonde", 100 },
						   { 5, "Albino", 50 },
						   { 4, "PiebaldGrey", 100 },
						   { 6, "Melanistic", 50 },
						   { 0, "Brown", 37350 },
						   { 1, "Blonde", 25000 },
					   }
			   },
			   {
				   "female", 62650,
					   {
						   { 3, "PiebaldBlonde", 100 },
						   { 5, "Albino", 50 },
						   { 4, "PiebaldGrey", 100 },
						   { 6, "Melanistic", 50 },
						   { 0, "Brown", 37350 },
						   { 1, "Blonde", 25000 },
					   }
			   }
		   }
	   },

		{ AT_MuleDeer ,
		   {
			   {
				   "male", 100000,
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
				   "female", 100000,
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
			   }
		   }
	   },

		{ AT_AmericanAlligator ,
		   {
			   {
				   "male", 100900,
					   {
						   { 2, "Piebald", 200 },
						   { 3, "Piebald", 200 },
						   { 5, "Piebald", 200 },
						   { 4, "Piebald", 200 },
						   { 6, "Piebald", 200 },
						   { 7, "Melanistic", 100 },
						   { 0, "Olive", 74700 },
						   { 8, "Albino", 100 },
						   { 1, "DarkBrown", 25000 },
					   }
			   },
			   {
				   "female", 100900,
					   {
						   { 2, "Piebald", 200 },
						   { 3, "Piebald", 200 },
						   { 5, "Piebald", 200 },
						   { 4, "Piebald", 200 },
						   { 6, "Piebald", 200 },
						   { 7, "Melanistic", 100 },
						   { 0, "Olive", 74700 },
						   { 8, "Albino", 100 },
						   { 1, "DarkBrown", 25000 },
					   }
			   }
		   }
	   },

		{ AT_RedFox ,
		   {
			   {
				   "male", 74926,
					   {
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 4, "Piebald", 150 },
						   { 5, "DarkRed", 24900 },
						   { 6, "Red", 24900 },
						   { 8, "Orange", 24900 },
					   }
			   },
			   {
				   "female", 74926,
					   {
						   { 0, "Red", 24900 },
						   { 1, "Orange", 24900 },
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 4, "Piebald", 150 },
						   { 7, "DarkRed", 24900 },
					   }
			   }
		   }
	   },

		{ AT_Blacktail ,
		   {
			   {
				   "male", 74926,
					   {
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 4, "Piebald", 150 },
						   { 5, "GrayBrown", 24900 },
						   { 6, "Grey", 24900 },
						   { 8, "DarkGrey", 24900 },
					   }
			   },
			   {
				   "female", 74926,
					   {
						   { 0, "Tan", 24900 },
						   { 1, "Grey", 24900 },
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 4, "Piebald", 150 },
						   { 7, "GrayBrown", 24900 },
					   }
			   }
		   }
	   },

		{ AT_SikaDeer ,
		   {
			   {
				   "male", 100000,
					   {
						   { 4, "Brown", 37350 },
						   { 3, "Spotted", 12500 },
						   { 1, "SpottedDark", 12500 },
						   { 2, "SpottedRed", 200 },
						   { 0, "Black", 37350 },
						   { 5, "Albino", 100 },
					   }
			   },
			   {
				   "female", 100000,
					   {
						   { 4, "Brown", 37350 },
						   { 3, "Spotted", 12500 },
						   { 1, "SpottedDark", 12500 },
						   { 2, "SpottedRed", 200 },
						   { 0, "Black", 37350 },
						   { 5, "Albino", 100 },
					   }
			   }
		   }
	   },

		{ AT_Coyote ,
		   {
			   {
				   "male", 74926,
					   {
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 4, "Piebald", 150 },
						   { 5, "GrayBrown", 24900 },
						   { 6, "Orange", 24900 },
						   { 8, "DarkGrey", 24900 },
					   }
			   },
			   {
				   "female", 74926,
					   {
						   { 0, "GrayBrown", 24900 },
						   { 1, "Orange", 24900 },
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 4, "Piebald", 150 },
						   { 7, "LightGrey", 24900 },
					   }
			   }
		   }
	   },

		{ AT_IberianMouflon ,
		   {
			   {
				   "male", 74926,
					   {
						   { 0, "LightBrown", 24900 },
						   { 1, "Grey", 150 },
						   { 2, "Albino", 38 },
						   { 5, "Melanistic", 38 },
						   { 3, "Brown", 24900 },
						   { 4, "Brown", 24900 },
					   }
			   },
			   {
				   "female", 50026,
					   {
						   { 1, "Grey", 150 },
						   { 2, "Albino", 38 },
						   { 5, "Melanistic", 38 },
						   { 3, "Brown", 24900 },
						   { 4, "Brown", 24900 },
					   }
			   }
		   }
	   },

		{ AT_SiberianMuskDeer ,
		   {
			   {
				   "male", 74926,
					   {
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 4, "Piebald", 150 },
						   { 5, "GrayBrown", 37350 },
						   { 6, "DarkBrown", 37350 },
					   }
			   },
			   {
				   "female", 74926,
					   {
						   { 0, "GrayBrown", 37350 },
						   { 1, "Orange", 37350 },
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 4, "Piebald", 150 },
					   }
			   }
		   }
	   },

		{ AT_EurasianWigeon ,
		   {
			   {
				   "male", 74999,
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
				   "female", 74966,
					   {
						   { 5, "Dark", 200 },
						   { 6, "Grey", 37350 },
						   { 7, "Leucistic", 33 },
						   { 0, "Brown", 37350 },
						   { 8, "Leucistic", 33 },
					   }
			   }
		   }
	   },

		{ AT_GrizzlyBear ,
		   {
			   {
				   "male", 74926,
					   {
						   { 0, "Melanistic", 38 },
						   { 1, "Albino", 38 },
						   { 2, "GrayBrown", 74700 },
						   { 3, "Brown", 150 },
					   }
			   },
			   {
				   "female", 74926,
					   {
						   { 0, "Melanistic", 38 },
						   { 1, "Albino", 38 },
						   { 4, "Brown", 150 },
						   { 2, "GrayBrown", 74700 },
					   }
			   }
		   }
	   },

		{ AT_Lion ,
		   {
			   {
				   "male", 100000,
					   {
						   { 0, "DarkBrown", 100 },
						   { 1, "Blonde", 100 },
						   { 2, "Albino", 100 },
						   { 3, "Tan", 74700 },
						   { 4, "LightBrown", 25000 },
					   }
			   },
			   {
				   "female", 100000,
					   {
						   { 0, "DarkBrown", 100 },
						   { 1, "Blonde", 100 },
						   { 2, "Albino", 100 },
						   { 3, "Tan", 74700 },
						   { 4, "LightBrown", 25000 },
					   }
			   }
		   }
	   },

		{ AT_RoeDeer ,
		   {
			   {
				   "male", 74926,
					   {
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 4, "Piebald", 150 },
						   { 5, "DarkGrey", 24900 },
						   { 6, "Brown", 24900 },
						   { 8, "DarkBrown", 24900 },
					   }
			   },
			   {
				   "female", 74926,
					   {
						   { 0, "Tan", 24900 },
						   { 1, "Orange", 24900 },
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 4, "Piebald", 150 },
						   { 7, "Brown", 24900 },
					   }
			   }
		   }
	   },

		{ AT_WillowPtarmigan ,
		   {
			   {
				   "male", 37650,
					   {
						   { 3, "Molting", 24900 },
						   { 5, "White", 200 },
						   { 6, "Red", 100 },
						   { 0, "Bicolor", 12450 },
					   }
			   },
			   {
				   "female", 62450,
					   {
						   { 2, "Brown", 12450 },
						   { 3, "Molting", 24900 },
						   { 5, "White", 200 },
						   { 4, "Molting", 12450 },
						   { 1, "Bicolor", 12450 },
					   }
			   }
		   }
	   },

		{ AT_BeceiteIbex ,
		   {
			   {
				   "male", 74776,
					   {
						   { 1, "Grey", 18675 },
						   { 2, "Albino", 38 },
						   { 3, "Orange", 18675 },
						   { 4, "Melanistic", 38 },
						   { 5, "BrownHybrid", 18675 },
						   { 6, "GrayBrown", 18675 },
					   }
			   },
			   {
				   "female", 68551,
					   {
						   { 0, "Buff", 24900 },
						   { 2, "Albino", 38 },
						   { 4, "Melanistic", 38 },
						   { 6, "GrayBrown", 18675 },
						   { 7, "LightBrown", 24900 },
					   }
			   }
		   }
	   },

		{ AT_GredosIbex ,
		   {
			   {
				   "male", 74776,
					   {
						   { 0, "GrayBrown", 18675 },
						   { 1, "Albino", 38 },
						   { 2, "BrownHybrid", 18675 },
						   { 3, "Melanistic", 38 },
						   { 6, "LightGrey", 18675 },
						   { 7, "Grey", 18675 },
					   }
			   },
			   {
				   "female", 56101,
					   {
						   { 1, "Albino", 38 },
						   { 3, "Melanistic", 38 },
						   { 4, "LightBrown", 18675 },
						   { 5, "Buff", 18675 },
						   { 6, "LightGrey", 18675 },
					   }
			   }
		   }
	   },

		{ AT_Jackrabbit ,
		   {
			   {
				   "male", 74775,
					   {
						   { 0, "Grey", 18675 },
						   { 1, "Beige", 18675 },
						   { 2, "Albino", 75 },
						   { 3, "LightBrown", 18675 },
						   { 4, "Brown", 18675 },
					   }
			   },
			   {
				   "female", 74775,
					   {
						   { 0, "Grey", 18675 },
						   { 1, "Beige", 18675 },
						   { 2, "Albino", 75 },
						   { 3, "LightBrown", 18675 },
						   { 4, "Brown", 18675 },
					   }
			   }
		   }
	   },

		{ AT_HazelGrouse ,
		   {
			   {
				   "male", 137200,
					   {
						   { 2, "Dark", 25000 },
						   { 3, "Hybrid", 50 },
						   { 4, "Pale", 100 },
						   { 0, "Brown", 74700 },
						   { 1, "Grey", 37350 },
					   }
			   },
			   {
				   "female", 100000,
					   {
						   { 5, "Ochre", 12500 },
						   { 4, "Pale", 100 },
						   { 6, "Dark", 200 },
						   { 7, "LightBrown", 12500 },
						   { 0, "Brown", 74700 },
					   }
			   }
		   }
	   },

		{ AT_RedDeer ,
		   {
			   {
				   "male", 74964,
					   {
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 9, "GreatOneRedDeer", 38 },
						   { 4, "Piebald", 150 },
						   { 5, "Brown", 24900 },
						   { 6, "LightBrown", 24900 },
						   { 8, "DarkBrown", 24900 },
					   }
			   },
			   {
				   "female", 74926,
					   {
						   { 0, "DarkBrown", 24900 },
						   { 1, "Brown", 24900 },
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 4, "Piebald", 150 },
						   { 7, "Grey", 24900 },
					   }
			   }
		   }
	   },

		{ AT_ScrubHare ,
		   {
			   {
				   "male", 77400,
					   {
						   { 0, "Grey", 2500 },
						   { 1, "LightGrey", 200 },
						   { 2, "Brown", 37350 },
						   { 3, "Chestnut", 37350 },
					   }
			   },
			   {
				   "female", 77400,
					   {
						   { 0, "Grey", 2500 },
						   { 1, "LightGrey", 200 },
						   { 2, "Brown", 37350 },
						   { 3, "Chestnut", 37350 },
					   }
			   }
		   }
	   },

		{ AT_CanadaGoose ,
		   {
			   {
				   "male", 99999,
					   {
						   { 0, "BrownHybrid", 25000 },
						   { 1, "Grey", 200 },
						   { 2, "Lightgreyleucistic", 33 },
						   { 3, "Melanistic", 33 },
						   { 4, "GrayBrown", 74700 },
						   { 5, "Baldleucistic", 33 },
					   }
			   },
			   {
				   "female", 99999,
					   {
						   { 0, "BrownHybrid", 25000 },
						   { 1, "Grey", 200 },
						   { 2, "Lightgreyleucistic", 33 },
						   { 3, "Melanistic", 33 },
						   { 4, "GrayBrown", 74700 },
						   { 5, "Baldleucistic", 33 },
					   }
			   }
		   }
	   },

		{ AT_BighornSheep ,
		   {
			   {
				   "male", 99799,
					   {
						   { 0, "Black", 8333 },
						   { 1, "Bronze", 8333 },
						   { 2, "GrayBrown", 8333 },
						   { 4, "Brown", 74700 },
						   { 3, "Albino", 100 },
					   }
			   },
			   {
				   "female", 99799,
					   {
						   { 0, "Black", 8333 },
						   { 1, "Bronze", 8333 },
						   { 2, "GrayBrown", 8333 },
						   { 4, "Brown", 74700 },
						   { 3, "Albino", 100 },
					   }
			   }
		   }
	   },

		{ AT_EasternCottontailRabbit ,
		   {
			   {
				   "male", 100000,
					   {
						   { 2, "Grey", 37350 },
						   { 3, "Leucistic", 100 },
						   { 5, "LightGrey", 12500 },
						   { 4, "Leucistic", 100 },
						   { 6, "Melanistic", 50 },
						   { 7, "Albino", 50 },
						   { 0, "Brown", 37350 },
						   { 1, "LightBrown", 12500 },
					   }
			   },
			   {
				   "female", 100000,
					   {
						   { 2, "Grey", 37350 },
						   { 3, "Leucistic", 100 },
						   { 5, "LightGrey", 12500 },
						   { 4, "Leucistic", 100 },
						   { 6, "Melanistic", 50 },
						   { 7, "Albino", 50 },
						   { 0, "Brown", 37350 },
						   { 1, "LightBrown", 12500 },
					   }
			   }
		   }
	   },

		{ AT_FeralGoat ,
		   {
			   {
				   "male", 99999,
					   {
						   { 10, "WhiteBrown", 8333 },
						   { 0, "Black", 50 },
						   { 1, "BlackWhite", 8333 },
						   { 2, "Albino", 50 },
						   { 3, "BlackBrown", 8333 },
						   { 9, "Mixed", 100 },
						   { 4, "Blonde", 18675 },
						   { 5, "DarkBrown", 18675 },
						   { 6, "White", 18675 },
						   { 8, "Mixed", 100 },
						   { 7, "Brown", 18675 },
					   }
			   },
			   {
				   "female", 45783,
					   {
						   { 0, "Black", 50 },
						   { 1, "BlackWhite", 8333 },
						   { 2, "Albino", 50 },
						   { 6, "White", 18675 },
						   { 7, "Brown", 18675 },
					   }
			   }
		   }
	   },

		{ AT_TuftedDuck ,
		   {
			   {
				   "male", 74899,
					   {
						   { 2, "Eclipse", 100 },
						   { 5, "Leucistic", 33 },
						   { 4, "Leucistic", 33 },
						   { 6, "Albino", 33 },
						   { 0, "Black", 74700 },
					   }
			   },
			   {
				   "female", 74866,
					   {
						   { 3, "Cream", 100 },
						   { 5, "Leucistic", 33 },
						   { 4, "Leucistic", 33 },
						   { 1, "Brown", 74700 },
					   }
			   }
		   }
	   },

		{ AT_BlackGrouse ,
		   {
			   {
				   "male", 74800,
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
				   "female", 99900,
					   {
						   { 2, "Gold", 100 },
						   { 3, "Dark", 25000 },
						   { 4, "Orange", 100 },
						   { 1, "Brown", 74700 },
					   }
			   }
		   }
	   },

		{ AT_Gemsbok ,
		   {
			   {
				   "male", 74925,
					   {
						   { 0, "Dark", 75 },
						   { 1, "Beige", 75 },
						   { 2, "Gold", 75 },
						   { 3, "LightGrey", 37350 },
						   { 4, "Grey", 37350 },
					   }
			   },
			   {
				   "female", 74925,
					   {
						   { 0, "Dark", 75 },
						   { 1, "Beige", 75 },
						   { 2, "Gold", 75 },
						   { 3, "LightGrey", 37350 },
						   { 4, "Grey", 37350 },
					   }
			   }
		   }
	   },

		{ AT_RockPtarmigan ,
		   {
			   {
				   "male", 53555,
					   {
						   { 3, "Molting", 21342 },
						   { 5, "White", 200 },
						   { 4, "Molting", 21342 },
						   { 0, "Bicolor", 10671 },
					   }
			   },
			   {
				   "female", 64226,
					   {
						   { 2, "Mottled", 10671 },
						   { 3, "Molting", 21342 },
						   { 5, "White", 200 },
						   { 4, "Molting", 21342 },
						   { 1, "Mottled", 10671 },
					   }
			   }
		   }
	   },

		{ AT_SoutheasternIbex ,
		   {
			   {
				   "male", 74776,
					   {
						   { 0, "GrayBrown", 18675 },
						   { 1, "Albino", 38 },
						   { 2, "LightGrey", 18675 },
						   { 3, "Melanistic", 38 },
						   { 6, "BrownHybrid", 18675 },
						   { 7, "Orange", 18675 },
					   }
			   },
			   {
				   "female", 56101,
					   {
						   { 1, "Albino", 38 },
						   { 3, "Melanistic", 38 },
						   { 4, "LightBrown", 18675 },
						   { 5, "Buff", 18675 },
						   { 6, "BrownHybrid", 18675 },
					   }
			   }
		   }
	   },

		{ AT_BlueWildebeest ,
		   {
			   {
				   "male", 99800,
					   {
						   { 0, "Gold", 25000 },
						   { 2, "Albino", 100 },
						   { 3, "Grey", 37350 },
						   { 4, "DarkGrey", 37350 },
					   }
			   },
			   {
				   "female", 75000,
					   {
						   { 1, "Crowned", 200 },
						   { 2, "Albino", 100 },
						   { 3, "Grey", 37350 },
						   { 4, "DarkGrey", 37350 },
					   }
			   }
		   }
	   },

		{ AT_Blackbuck ,
		   {
			   {
				   "male", 50100,
					   {
						   { 0, "Dark", 25000 },
						   { 1, "Leucistic", 50 },
						   { 2, "Melanistic", 50 },
						   { 4, "Black", 25000 },
					   }
			   },
			   {
				   "female", 99800,
					   {
						   { 0, "Dark", 25000 },
						   { 1, "Leucistic", 50 },
						   { 2, "Melanistic", 50 },
						   { 3, "Brown", 74700 },
					   }
			   }
		   }
	   },

		{ AT_WaterBuffalo ,
		   {
			   {
				   "male", 77500,
					   {
						   { 0, "Orange", 200 },
						   { 2, "Albino", 100 },
						   { 3, "Grey", 74700 },
						   { 4, "Black", 2500 },
					   }
			   },
			   {
				   "female", 114850,
					   {
						   { 0, "Orange", 200 },
						   { 1, "Brown", 37350 },
						   { 2, "Albino", 100 },
						   { 3, "Grey", 74700 },
						   { 4, "Black", 2500 },
					   }
			   }
		   }
	   },

		{ AT_Puma ,
		   {
			   {
				   "male", 99730,
					   {
						   { 0, "DarkRed", 12465 },
						   { 1, "Albino", 50 },
						   { 2, "Melanistic", 50 },
						   { 3, "LightBrown", 74700 },
						   { 4, "Grey", 12465 },
					   }
			   },
			   {
				   "female", 99730,
					   {
						   { 0, "DarkRed", 12465 },
						   { 1, "Albino", 50 },
						   { 2, "Melanistic", 50 },
						   { 3, "LightBrown", 74700 },
						   { 4, "Grey", 12465 },
					   }
			   }
		   }
	   },

	    { AT_MountainLion ,
		  {
			  {
				  "male", 99730,
					  {
						  { 0, "DarkRed", 12465 },
						  { 1, "Albino", 50 },
						  { 2, "Melanistic", 50 },
						  { 3, "LightBrown", 74700 },
						  { 4, "Grey", 12465 },
					  }
			  },
			  {
				  "female", 99730,
					  {
						  { 0, "DarkRed", 12465 },
						  { 1, "Albino", 50 },
						  { 2, "Melanistic", 50 },
						  { 3, "LightBrown", 74700 },
						  { 4, "Grey", 12465 },
					  }
			  }
		  }
		},

		{ AT_Whitetail ,
		   {
			   {
				   "male", 75264,
					   {
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 9, "GreatOneWhitetail", 38 },
						   { 4, "Piebald", 150 },
						   { 5, "Tan", 25000 },
						   { 6, "Brown", 25000 },
						   { 8, "DarkBrown", 25000 },
					   }
			   },
			   {
				   "female", 75226,
					   {
						   { 0, "Brown", 25000 },
						   { 1, "DarkBrown", 25000 },
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 4, "Piebald", 150 },
						   { 7, "RedBrown", 25000 },
					   }
			   }
		   }
	   },

		{ AT_GrayFox ,
		   {
			   {
				   "male", 100001,
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
				   "female", 100001,
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
			   }
		   }
	   },

		{ AT_Moose ,
		   {
			   {
				   "male", 74926,
					   {
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 9, "NzMooseMocha", 0 },
						   { 4, "Piebald", 150 },
						   { 5, "LightBrown", 24900 },
						   { 6, "Tan", 24900 },
						   { 8, "Brown", 24900 },
					   }
			   },
			   {
				   "female", 74926,
					   {
						   { 0, "Tan", 24900 },
						   { 1, "Brown", 24900 },
						   { 2, "Melanistic", 38 },
						   { 3, "Albino", 38 },
						   { 4, "Piebald", 150 },
						   { 7, "DarkBrown", 24900 },
					   }
			   }
		   }
	   },

		{ AT_PlainsBison ,
		   {
			   {
				   "male", 87225,
					   {
						   { 0, "LightGrey", 24900 },
						   { 1, "Dark", 18675 },
						   { 2, "Leucistic", 25 },
						   { 3, "Albino", 25 },
						   { 4, "Melanistic", 25 },
						   { 5, "Brown", 18675 },
						   { 6, "LightBrown", 24900 },
					   }
			   },
			   {
				   "female", 87225,
					   {
						   { 0, "LightGrey", 24900 },
						   { 1, "Dark", 18675 },
						   { 2, "Leucistic", 25 },
						   { 3, "Albino", 25 },
						   { 4, "Melanistic", 25 },
						   { 5, "Brown", 18675 },
						   { 6, "LightBrown", 24900 },
					   }
			   }
		   }
	   },

		{ AT_EasternWildTurkey ,
		   {
			   {
				   "male", 100000,
					   {
						   { 2, "LightBrown", 12500 },
						   { 3, "Leucistic", 200 },
						   { 5, "Bronze", 37350 },
						   { 4, "Melanistic", 50 },
						   { 6, "LightBronze", 12500 },
						   { 0, "Brown", 37350 },
						   { 1, "Albino", 50 },
					   }
			   },
			   {
				   "female", 100000,
					   {
						   { 2, "LightBrown", 12500 },
						   { 3, "Leucistic", 200 },
						   { 5, "Bronze", 37350 },
						   { 4, "Melanistic", 50 },
						   { 6, "LightBronze", 12500 },
						   { 0, "Brown", 37350 },
						   { 1, "Albino", 50 },
					   }
			   }
		   }
	   },

		{ AT_ProngHorn ,
		   {
			   {
				   "male", 100000,
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
				   "female", 99900,
					   {
						   { 0, "Tan", 37350 },
						   { 1, "Dark", 25000 },
						   { 3, "Piebald", 100 },
						   { 2, "Leucistic", 50 },
						   { 6, "Brown", 37350 },
						   { 5, "Albino", 50 },
					   }
			   }
		   }
	   },

		{ AT_SidestripedJackal ,
		   {
			   {
				   "male", 99696,
					   {
						   { 0, "Grey", 24930 },
						   { 1, "Albino", 33 },
						   { 2, "Ghost", 0 },
						   { 3, "Melanistic", 33 },
						   { 4, "LightBrown", 37350 },
						   { 5, "GrayBrown", 37350 },
					   }
			   },
			   {
				   "female", 99696,
					   {
						   { 0, "Grey", 24930 },
						   { 1, "Albino", 33 },
						   { 2, "Ghost", 0 },
						   { 3, "Melanistic", 33 },
						   { 4, "LightBrown", 37350 },
						   { 5, "GrayBrown", 37350 },
					   }
			   }
		   }
	   },

		{ AT_EuRabbit ,
		   {
			   {
				   "male", 100000,
					   {
						   { 0, "DarkBrown", 37350 },
						   { 1, "Leucistic", 50 },
						   { 2, "Melanistic", 100 },
						   { 3, "LightBrown", 12500 },
						   { 4, "LightGrey", 100 },
						   { 5, "Brown", 12500 },
						   { 6, "Albino", 50 },
						   { 7, "Tan", 37350 },
					   }
			   },
			   {
				   "female", 100000,
					   {
						   { 0, "DarkBrown", 37350 },
						   { 1, "Leucistic", 50 },
						   { 2, "Melanistic", 100 },
						   { 3, "LightBrown", 12500 },
						   { 4, "LightGrey", 100 },
						   { 5, "Brown", 12500 },
						   { 6, "Albino", 50 },
						   { 7, "Tan", 37350 },
					   }
			   }
		   }
	   },

		{ AT_WildTurkey ,
		   {
			   {
				   "male", 125000,
					   {
						   { 2, "LightBrown", 25000 },
						   { 3, "Leucistic", 200 },
						   { 5, "DarkBrown", 25000 },
						   { 4, "Melanistic", 50 },
						   { 0, "Brown", 74700 },
						   { 1, "Albino", 50 },
					   }
			   },
			   {
				   "female", 125000,
					   {
						   { 2, "LightBrown", 25000 },
						   { 3, "Leucistic", 200 },
						   { 5, "DarkBrown", 25000 },
						   { 4, "Melanistic", 50 },
						   { 0, "Brown", 74700 },
						   { 1, "Albino", 50 },
					   }
			   }
		   }
	   },

		{ AT_Caribou ,
		   {
			   {
				   "male", 74925,
					   {
						   { 0, "Melanistic", 25 },
						   { 1, "Leucistic", 25 },
						   { 2, "Piebald", 150 },
						   { 3, "Albino", 25 },
						   { 4, "LightBrown", 37350 },
						   { 5, "DarkBrown", 37350 },
					   }
			   },
			   {
				   "female", 74775,
					   {
						   { 0, "Melanistic", 25 },
						   { 1, "Leucistic", 25 },
						   { 3, "Albino", 25 },
						   { 4, "LightBrown", 37350 },
						   { 5, "DarkBrown", 37350 },
					   }
			   }
		   }
	   },

		{ AT_Goldeneye ,
		   {
			   {
				   "male", 75050,
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
				   "female", 75000,
					   {
						   { 2, "Dark", 200 },
						   { 6, "Leucistic", 50 },
						   { 7, "Leucistic", 50 },
						   { 1, "Grey", 74700 },
					   }
			   }
		   }
	   },

		{ AT_GreylagGoose ,
		   {
			   {
				   "male", 200150,
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
				   "female", 200150,
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
			   }
		   }
	   },

		{ AT_IberianWolf ,
		   {
			   {
				   "male", 100001,
					   {
						   { 0, "Pristine", 67 },
						   { 1, "Olive", 67 },
						   { 2, "Albino", 50 },
						   { 3, "Winter", 67 },
						   { 4, "Sombra", 0 },
						   { 5, "Melanistic", 50 },
						   { 6, "Fantasma", 0 },
						   { 7, "GrayBrown", 74700 },
						   { 8, "Ogro", 0 },
						   { 9, "Grey", 25000 },
					   }
			   },
			   {
				   "female", 100001,
					   {
						   { 0, "Pristine", 67 },
						   { 1, "Olive", 67 },
						   { 2, "Albino", 50 },
						   { 3, "Winter", 67 },
						   { 4, "Sombra", 0 },
						   { 5, "Melanistic", 50 },
						   { 6, "Fantasma", 0 },
						   { 7, "GrayBrown", 74700 },
						   { 8, "Ogro", 0 },
						   { 9, "Grey", 25000 },
					   }
			   }
		   }
	   },

		{ AT_RioGrandeTurkey ,
		   {
			   {
				   "male", 100000,
					   {
						   { 2, "LightBrown", 12500 },
						   { 3, "Leucistic", 200 },
						   { 5, "Buff", 37350 },
						   { 4, "Melanistic", 50 },
						   { 6, "Lightbuff", 12500 },
						   { 0, "Brown", 37350 },
						   { 1, "Albino", 50 },
					   }
			   },
			   {
				   "female", 100000,
					   {
						   { 2, "LightBrown", 12500 },
						   { 3, "Leucistic", 200 },
						   { 5, "Buff", 37350 },
						   { 4, "Melanistic", 50 },
						   { 6, "Lightbuff", 12500 },
						   { 0, "Brown", 37350 },
						   { 1, "Albino", 50 },
					   }
			   }
		   }
	   },
	};

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
		static FurEntry* GetFurEntryFromDB(const AnimalType animal_type, const std::string& gender);

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
			//if (m_gender == "male")
			//	return 32.f;
			//else if (m_gender == "female")
			//	return 25.f;
			//return 0.f;
			return m_gender == "male" ? 32.f : 25.f;
		}

		float GetMaxWeight()
		{
			if (m_gender == "male")
				return 240.f;
			else if (m_gender == "female")
				return 168.f;
			return 0.f;
		}

		float GetMinScore()
		{
			if (m_gender == "male")
				return 7.f;
			else if (m_gender == "female")
				return 7.f;
			return 0.f;
		}

		float GetMaxScore()
		{
			if (m_gender == "male")
				return 159.5f;
			else if (m_gender == "female")
				return 81.5f;
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
				return 160.f;
			else if (m_gender == "female")
				return 120.f;
			return 0.f;
		}

		float GetMaxWeight()
		{
			if (m_gender == "male")
				return 240.f;
			else if (m_gender == "female")
				return 170.f;
			return 0.f;
		}

		float GetMinScore()
		{
			if (m_gender == "male")
				return 44.626953125f;
			else if (m_gender == "female")
				return 0.f;
			return 0.f;
		}

		float GetMaxScore()
		{
			if (m_gender == "male")
				return 274.014526367187f;
			else if (m_gender == "female")
				return 0.f;
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
