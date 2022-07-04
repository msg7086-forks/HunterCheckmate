#include "Animal.h"

namespace HunterCheckmate_FileAnalyzer
{
	Animal::Animal(AnimalType animal_type, std::string gender, std::string weight, std::string score, std::string is_great_one, std::string visual_variation_seed)
	{
		m_animal_type = animal_type;
		m_name = {};
		m_gender = ResolveGender(gender);
		m_str_gender = ResolveGender(m_gender);
		m_weight = ResolveWeight(weight);
		m_score = ResolveScore(score);
		m_is_great_one = ResolveIsGreatOne(is_great_one);
		m_visual_variation_seed = std::stoul(visual_variation_seed);
		m_fur_type_id = ResolveVisualVariationSeed(visual_variation_seed);
		m_fur_type = ResolveFurTypeId(m_fur_type_id);
		m_idx = 0;
		m_valid = false;
		SetGenderBytes();
		SetWeightBytes();
		SetScoreBytes();
		SetIsGreatOneBytes();
		SetVisualVariationSeedBytes();
	}

	Animal::Animal(AnimalType animal_type, std::string gender, std::string weight, std::string score, std::string is_great_one, std::string visual_variation_seed, std::string idx)
	{
		m_animal_type = animal_type;
		m_name = {};
		m_gender = ResolveGender(gender);
		m_str_gender = ResolveGender(m_gender);
		m_weight = ResolveWeight(weight);
		m_score = ResolveScore(score);
		m_is_great_one = ResolveIsGreatOne(is_great_one);
		m_visual_variation_seed = std::stoul(visual_variation_seed);
		m_fur_type_id = ResolveVisualVariationSeed(visual_variation_seed);
		m_fur_type = ResolveFurTypeId(m_fur_type_id);
		m_idx = ResolveIdx(idx);
		m_valid = false;
		SetGenderBytes();
		SetWeightBytes();
		SetScoreBytes();
		SetIsGreatOneBytes();
		SetVisualVariationSeedBytes();
	}

	std::shared_ptr<Animal> Animal::Create(AnimalType animal_type, std::string gender, std::string weight, std::string score, std::string is_great_one, std::string visual_variation_seed, std::string idx)
	{
		switch (animal_type)
		{
		case AT_WildBoar:
			return std::make_shared<WildBoar>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_FallowDeer:
			return std::make_shared<FallowDeer>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_EuroBison:
			return std::make_shared<EuroBison>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_RoeDeer:
			return std::make_shared<RoeDeer>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_RedFox:
			return std::make_shared<RedFox>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_CanadaGoose:
			return std::make_shared<CanadaGoose>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_RedDeer:
			return std::make_shared<RedDeer>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_EuroRabbit:
			return std::make_shared<EuroRabbit>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_Moose:
			return std::make_shared<Moose>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_Jackrabbit:
			return std::make_shared<Jackrabbit>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_Mallard:
			return std::make_shared<Mallard>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_BlackBear:
			return std::make_shared<BlackBear>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_RooseveltElk:
			return std::make_shared<RooseveltElk>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_Coyote:
			return std::make_shared<Coyote>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_BlacktailDeer:
			return std::make_shared<BlacktailDeer>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_WhitetailDeer:
			return std::make_shared<WhitetailDeer>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_MuskDeer:
			return std::make_shared<MuskDeer>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_Reindeer:
			return std::make_shared<Reindeer>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_EurasianLynx:
			return std::make_shared<EurasianLynx>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_BrownBear:
			return std::make_shared<BrownBear>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_BlueWildebeest:
			return std::make_shared<BlueWildebeest>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_SideStripedJackal:
			return std::make_shared<SideStripedJackal>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_Gemsbok:
			return std::make_shared<Gemsbok>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_LesserKudu:
			return std::make_shared<LesserKudu>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_ScrubHare:
			return std::make_shared<ScrubHare>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_Lion:
			return std::make_shared<Lion>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_Warthog:
			return std::make_shared<Warthog>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_CapeBuffalo:
			return std::make_shared<CapeBuffalo>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_Springbok:
			return std::make_shared<Springbok>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_WaterBuffalo:
			return std::make_shared<WaterBuffalo>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_Puma:
			return std::make_shared<Puma>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_Blackbuck:
			return std::make_shared<Blackbuck>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_CinnamonTeal:
			return std::make_shared<CinnamonTeal>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_MuleDeer:
			return std::make_shared<MuleDeer>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_AxisDeer:
			return std::make_shared<AxisDeer>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_HarlequinDuck:
			return std::make_shared<HarlequinDuck>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_Caribou:
			return std::make_shared<Caribou>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_GrizzlyBear:
			return std::make_shared<GrizzlyBear>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_GrayWolf:
			return std::make_shared<GrayWolf>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_PlainsBison:
			return std::make_shared<PlainsBison>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_SoutheasternSpanishIbex:
			return std::make_shared<SoutheasternSpanishIbex>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_IberianWolf:
			return std::make_shared<IberianWolf>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_IberianMuflon:
			return std::make_shared<IberianMuflon>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_BeceiteIbex:
			return std::make_shared<BeceiteIbex>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_EuroHare:
			return std::make_shared<EuroHare>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_RondaIbex:
			return std::make_shared<RondaIbex>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_GredosIbex:
			return std::make_shared<GredosIbex>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_Pronghorn:
			return std::make_shared<Pronghorn>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_MountainLion:
			return std::make_shared<MountainLion>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_MountainGoat:
			return std::make_shared<MountainGoat>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_BighornSheep:
			return std::make_shared<BighornSheep>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_MerriamTurkey:
			return std::make_shared<MerriamTurkey>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_RockyMountainElk:
			return std::make_shared<RockyMountainElk>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_SikaDeer:
			return std::make_shared<SikaDeer>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_Chamois:
			return std::make_shared<Chamois>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_FeralPig:
			return std::make_shared<FeralPig>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_FeralGoat:
			return std::make_shared<FeralGoat>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_CollaredPeccary:
			return std::make_shared<CollaredPeccary>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_MexicanBobcat:
			return std::make_shared<MexicanBobcat>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_RioGrandeTurkey:
			return std::make_shared<RioGrandeTurkey>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_RingNeckedPheasant:
			return std::make_shared<RingNeckedPheasant>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_AntelopeJackrabbit:
			return std::make_shared<AntelopeJackrabbit>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_AmericanAlligator:
			return std::make_shared<AmericanAlligator>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_WildHog:
			return std::make_shared<WildHog>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_GrayFox:
			return std::make_shared<GrayFox>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_CommonRaccoon:
			return std::make_shared<CommonRaccoon>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_EasternWildTurkey:
			return std::make_shared<EasternWildTurkey>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_EasternCottontailRabbit:
			return std::make_shared<EasternCottontailRabbit>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_BobwhiteQuail:
			return std::make_shared<BobwhiteQuail>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_RaccoonDog:
			return std::make_shared<RaccoonDog>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_EurasianWigeon:
			return std::make_shared<EurasianWigeon>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_TundraBeanGoose:
			return std::make_shared<TundraBeanGoose>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_EurasianTeal:
			return std::make_shared<EurasianTeal>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_BlackGrouse:
			return std::make_shared<BlackGrouse>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_Goldeneye:
			return std::make_shared<Goldeneye>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_HazelGrouse:
			return std::make_shared<HazelGrouse>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_WesternCapercaillie:
			return std::make_shared<WesternCapercaillie>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_TuftedDuck:
			return std::make_shared<TuftedDuck>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_RockPtarmigan:
			return std::make_shared<RockPtarmigan>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_WillowPtarmigan:
			return std::make_shared<WillowPtarmigan>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_GreylagGoose:
			return std::make_shared<GreylagGoose>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_MountainHare:
			return std::make_shared<MountainHare>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		case AT_None:
		default:
			return std::make_shared<Animal>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx);
		}
	}

	std::vector<char> Animal::GetBytes()
	{
		std::vector<char> data;
		data.insert(data.end(), this->gender_bytes.begin(), this->gender_bytes.end());
		data.insert(data.end(), this->weight_bytes.begin(), this->weight_bytes.end());
		data.insert(data.end(), this->score_bytes.begin(), this->score_bytes.end());
		data.insert(data.end(), this->is_great_one_bytes.begin(), this->is_great_one_bytes.end());
		data.insert(data.end(), this->visual_variation_seed_bytes.begin(), this->visual_variation_seed_bytes.end());
		return data;
	}

	bool Animal::IsValid() const
	{
		return m_valid;
	}

	uint8_t Animal::ResolveGender(const std::string &name)
	{
		if (name == "male") return 1;
		if (name == "female") return 2;
		return 0;
	}

	std::string Animal::ResolveGender(const uint8_t gender)
	{
		if (gender == 1) return "male";
		if (gender == 2) return "female";
		return "foomale";
	}

	float Animal::ResolveWeight(const std::string &weight)
	{
		return std::stof(weight);
	}

	float Animal::ResolveScore(const std::string &score)
	{
		return std::stof(score);
	}

	uint8_t Animal::ResolveIsGreatOne(const std::string& is_great_one) 
	{
		if (is_great_one == "true") return 1;
		if (is_great_one == "false") return 0;
		return 0;
	}

	uint32_t Animal::ResolveIdx(const std::string& idx)
	{
		return std::stoi(idx);
	}

	// old
	//uint64_t seed = std::stoul(visual_variation_seed);
	//uint32_t seed_32 = seed;
	//uint64_t converted_probability = (((0x343FD * seed + 0x269EC6) >> 16) | 0x3F8000) << 8;
	uint32_t Animal::ResolveVisualVariationSeed(const std::string &visual_variation_seed)
	{
		uint32_t seed = std::stoul(visual_variation_seed);
		uint32_t converted_probability = (((0x343FD * seed + 0x269EC3) >> 16) | 0x3F8000) << 8;
		float fl_probability;
		std::memcpy(&fl_probability, &converted_probability, sizeof(float));
		switch (m_animal_type)
		{
		case AT_RedDeer:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0005069099834587268555573341870765)
					return 2;
				if (fl_probability >= -0.00101381996691745371111466837415)
					return 3;
				if (fl_probability >= -0.00301478042793874393041993490209)
					return 4;
				if (fl_probability >= -0.33517421695747292033509417853903)
					return 5;
				if (fl_probability >= -0.66733365348700709673976842217598)
					return 6;
				if (fl_probability >= -0.99949309001654127314444266581292)
					return 8;
				if (fl_probability >= -1.0)
					return 9;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0005069099834587268555573341870765)
					return 2;
				if (fl_probability <= 0.00101381996691745371111466837415)
					return 3;
				if (fl_probability <= 0.00301478042793874393041993490209)
					return 4;
				if (fl_probability <= 0.33517421695747292033509417853903)
					return 5;
				if (fl_probability <= 0.66733365348700709673976842217598)
					return 6;
				if (fl_probability <= 0.99949309001654127314444266581292)
					return 8;
				if (fl_probability <= 1.0)
					return 9;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.33232789685823345701091743853936)
					return 0;
				if (fl_probability >= -0.66465579371646691402183487707872)
					return 1;
				if (fl_probability >= -0.6651629607879774711048234257801)
					return 2;
				if (fl_probability >= -0.66567012785948802818781197448149)
					return 3;
				if (fl_probability >= -0.66767210314176654298908256146064)
					return 4;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.33232789685823345701091743853936)
					return 0;
				if (fl_probability <= 0.66465579371646691402183487707872)
					return 1;
				if (fl_probability <= 0.6651629607879774711048234257801)
					return 2;
				if (fl_probability <= 0.66567012785948802818781197448149)
					return 3;
				if (fl_probability <= 0.66767210314176654298908256146064)
					return 4;
				if (fl_probability <= 1.0)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_WildBoar:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0005071670715105571)
					return 2;
				if (fl_probability >= -0.0010143341430211142)
					return 3;
				if (fl_probability >= -0.003016309425299629)
					return 4;
				if (fl_probability >= -0.33534420628353306)
					return 5;
				if (fl_probability >= -0.6676721031417665)
					return 6;
				if (fl_probability >= -1.0)
					return 8;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0005071670715105571)
					return 2;
				if (fl_probability <= 0.0010143341430211142)
					return 3;
				if (fl_probability <= 0.003016309425299629)
					return 4;
				if (fl_probability <= 0.33534420628353306)
					return 5;
				if (fl_probability <= 0.6676721031417665)
					return 6;
				if (fl_probability <= 1.0)
					return 8;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.33232789685823344)
					return 0;
				if (fl_probability >= -0.6646557937164669)
					return 1;
				if (fl_probability >= -0.6651629607879774)
					return 2;
				if (fl_probability >= -0.665670127859488)
					return 3;
				if (fl_probability >= -0.6676721031417665)
					return 4;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.33232789685823344)
					return 0;
				if (fl_probability <= 0.6646557937164669)
					return 1;
				if (fl_probability <= 0.6651629607879774)
					return 2;
				if (fl_probability <= 0.665670127859488)
					return 3;
				if (fl_probability <= 0.6676721031417665)
					return 4;
				if (fl_probability <= 1.0)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_FallowDeer:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.002001975282278515)
					return 0;
				if (fl_probability >= -0.2013987133972186)
					return 1;
				if (fl_probability >= -0.4007954515121587)
					return 3;
				if (fl_probability >= -0.6001921896270987)
					return 5;
				if (fl_probability >= -0.6006993566986093)
					return 9;
				if (fl_probability >= -0.8000960948135494)
					return 10;
				if (fl_probability >= -0.8006032618850599)
					return 11;
				if (fl_probability >= -1.0)
					return 12;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.002001975282278515)
					return 0;
				if (fl_probability <= 0.2013987133972186)
					return 1;
				if (fl_probability <= 0.4007954515121587)
					return 3;
				if (fl_probability <= 0.6001921896270987)
					return 5;
				if (fl_probability <= 0.6006993566986093)
					return 9;
				if (fl_probability <= 0.8000960948135494)
					return 10;
				if (fl_probability <= 0.8006032618850599)
					return 11;
				if (fl_probability <= 1.0)
					return 12;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.384164403850901)
					return 2;
				if (fl_probability >= -0.768328807701802)
					return 4;
				if (fl_probability >= -0.9988274500123426)
					return 6;
				if (fl_probability >= -0.9994137250061713)
					return 7;
				if (fl_probability >= -1.0)
					return 8;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.384164403850901)
					return 2;
				if (fl_probability <= 0.768328807701802)
					return 4;
				if (fl_probability <= 0.9988274500123426)
					return 6;
				if (fl_probability <= 0.9994137250061713)
					return 7;
				if (fl_probability <= 1.0)
					return 8;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_EuroBison:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0005071670715105571)
					return 2;
				if (fl_probability >= -0.0010143341430211142)
					return 3;
				if (fl_probability >= -0.003016309425299629)
					return 4;
				if (fl_probability >= -0.33534420628353306)
					return 5;
				if (fl_probability >= -0.6676721031417665)
					return 6;
				if (fl_probability >= -1.0)
					return 8;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0005071670715105571)
					return 2;
				if (fl_probability <= 0.0010143341430211142)
					return 3;
				if (fl_probability <= 0.003016309425299629)
					return 4;
				if (fl_probability <= 0.33534420628353306)
					return 5;
				if (fl_probability <= 0.6676721031417665)
					return 6;
				if (fl_probability <= 1.0)
					return 8;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.33232789685823344)
					return 0;
				if (fl_probability >= -0.6646557937164669)
					return 1;
				if (fl_probability >= -0.6651629607879774)
					return 2;
				if (fl_probability >= -0.665670127859488)
					return 3;
				if (fl_probability >= -0.6676721031417665)
					return 4;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.33232789685823344)
					return 0;
				if (fl_probability <= 0.6646557937164669)
					return 1;
				if (fl_probability <= 0.6651629607879774)
					return 2;
				if (fl_probability <= 0.665670127859488)
					return 3;
				if (fl_probability <= 0.6676721031417665)
					return 4;
				if (fl_probability <= 1.0)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_RoeDeer:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0005071670715105571)
					return 2;
				if (fl_probability >= -0.0010143341430211142)
					return 3;
				if (fl_probability >= -0.003016309425299629)
					return 4;
				if (fl_probability >= -0.33534420628353306)
					return 5;
				if (fl_probability >= -0.6676721031417665)
					return 6;
				if (fl_probability >= -1.0)
					return 8;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0005071670715105571)
					return 2;
				if (fl_probability <= 0.0010143341430211142)
					return 3;
				if (fl_probability <= 0.003016309425299629)
					return 4;
				if (fl_probability <= 0.33534420628353306)
					return 5;
				if (fl_probability <= 0.6676721031417665)
					return 6;
				if (fl_probability <= 1.0)
					return 8;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.33232789685823344)
					return 0;
				if (fl_probability >= -0.6646557937164669)
					return 1;
				if (fl_probability >= -0.6651629607879774)
					return 2;
				if (fl_probability >= -0.665670127859488)
					return 3;
				if (fl_probability >= -0.6676721031417665)
					return 4;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.33232789685823344)
					return 0;
				if (fl_probability <= 0.6646557937164669)
					return 1;
				if (fl_probability <= 0.6651629607879774)
					return 2;
				if (fl_probability <= 0.665670127859488)
					return 3;
				if (fl_probability <= 0.6676721031417665)
					return 4;
				if (fl_probability <= 1.0)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_RedFox:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0005071670715105571)
					return 2;
				if (fl_probability >= -0.0010143341430211142)
					return 3;
				if (fl_probability >= -0.003016309425299629)
					return 4;
				if (fl_probability >= -0.33534420628353306)
					return 5;
				if (fl_probability >= -0.6676721031417665)
					return 6;
				if (fl_probability >= -1.0)
					return 8;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0005071670715105571)
					return 2;
				if (fl_probability <= 0.0010143341430211142)
					return 3;
				if (fl_probability <= 0.003016309425299629)
					return 4;
				if (fl_probability <= 0.33534420628353306)
					return 5;
				if (fl_probability <= 0.6676721031417665)
					return 6;
				if (fl_probability <= 1.0)
					return 8;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.33232789685823344)
					return 0;
				if (fl_probability >= -0.6646557937164669)
					return 1;
				if (fl_probability >= -0.6651629607879774)
					return 2;
				if (fl_probability >= -0.665670127859488)
					return 3;
				if (fl_probability >= -0.6676721031417665)
					return 4;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.33232789685823344)
					return 0;
				if (fl_probability <= 0.6646557937164669)
					return 1;
				if (fl_probability <= 0.6651629607879774)
					return 2;
				if (fl_probability <= 0.665670127859488)
					return 3;
				if (fl_probability <= 0.6676721031417665)
					return 4;
				if (fl_probability <= 1.0)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_EuroRabbit:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.3735)
					return 0;
				if (fl_probability >= -0.374)
					return 1;
				if (fl_probability >= -0.375)
					return 2;
				if (fl_probability >= -0.5)
					return 3;
				if (fl_probability >= -0.501)
					return 4;
				if (fl_probability >= -0.626)
					return 5;
				if (fl_probability >= -0.6265)
					return 6;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.3735)
					return 0;
				if (fl_probability <= 0.374)
					return 1;
				if (fl_probability <= 0.375)
					return 2;
				if (fl_probability <= 0.5)
					return 3;
				if (fl_probability <= 0.501)
					return 4;
				if (fl_probability <= 0.626)
					return 5;
				if (fl_probability <= 0.6265)
					return 6;
				if (fl_probability <= 1.0)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_CanadaGoose:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.25000250002500024)
					return 0;
				if (fl_probability >= -0.25200252002520024)
					return 1;
				if (fl_probability >= -0.25233252332523326)
					return 2;
				if (fl_probability >= -0.2526625266252663)
					return 3;
				if (fl_probability >= -0.9996699966999669)
					return 4;
				if (fl_probability >= -0.9999999999999999)
					return 5;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.25000250002500024)
					return 0;
				if (fl_probability <= 0.25200252002520024)
					return 1;
				if (fl_probability <= 0.25233252332523326)
					return 2;
				if (fl_probability <= 0.2526625266252663)
					return 3;
				if (fl_probability <= 0.9996699966999669)
					return 4;
				if (fl_probability <= 0.9999999999999999)
					return 5;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_RooseveltElk:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0005071670715105571)
					return 2;
				if (fl_probability >= -0.0010143341430211142)
					return 3;
				if (fl_probability >= -0.003016309425299629)
					return 4;
				if (fl_probability >= -0.33534420628353306)
					return 5;
				if (fl_probability >= -0.6676721031417665)
					return 6;
				if (fl_probability >= -1.0)
					return 8;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0005071670715105571)
					return 2;
				if (fl_probability <= 0.0010143341430211142)
					return 3;
				if (fl_probability <= 0.003016309425299629)
					return 4;
				if (fl_probability <= 0.33534420628353306)
					return 5;
				if (fl_probability <= 0.6676721031417665)
					return 6;
				if (fl_probability <= 1.0)
					return 8;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.33232789685823344)
					return 0;
				if (fl_probability >= -0.6646557937164669)
					return 1;
				if (fl_probability >= -0.6651629607879774)
					return 2;
				if (fl_probability >= -0.665670127859488)
					return 3;
				if (fl_probability >= -0.6676721031417665)
					return 4;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.33232789685823344)
					return 0;
				if (fl_probability <= 0.6646557937164669)
					return 1;
				if (fl_probability <= 0.6651629607879774)
					return 2;
				if (fl_probability <= 0.665670127859488)
					return 3;
				if (fl_probability <= 0.6676721031417665)
					return 4;
				if (fl_probability <= 1.0)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_Moose:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0005071670715105571)
					return 2;
				if (fl_probability >= -0.0010143341430211142)
					return 3;
				if (fl_probability >= -0.003016309425299629)
					return 4;
				if (fl_probability >= -0.33534420628353306)
					return 5;
				if (fl_probability >= -0.6676721031417665)
					return 6;
				if (fl_probability >= -1.0)
					return 8;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0005071670715105571)
					return 2;
				if (fl_probability <= 0.0010143341430211142)
					return 3;
				if (fl_probability <= 0.003016309425299629)
					return 4;
				if (fl_probability <= 0.33534420628353306)
					return 5;
				if (fl_probability <= 0.6676721031417665)
					return 6;
				if (fl_probability <= 1.0)
					return 8;
			}
			else if (fl_probability == 0.0)
			{
				return 9;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.33232789685823344)
					return 0;
				if (fl_probability >= -0.6646557937164669)
					return 1;
				if (fl_probability >= -0.6651629607879774)
					return 2;
				if (fl_probability >= -0.665670127859488)
					return 3;
				if (fl_probability >= -0.6676721031417665)
					return 4;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.33232789685823344)
					return 0;
				if (fl_probability <= 0.6646557937164669)
					return 1;
				if (fl_probability <= 0.6651629607879774)
					return 2;
				if (fl_probability <= 0.665670127859488)
					return 3;
				if (fl_probability <= 0.6676721031417665)
					return 4;
				if (fl_probability <= 1.0)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_BlackBear:
		{
			// Check if GO fur affects this
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.000505628442930516)
					return 2;
				if (fl_probability >= -0.001011256885861032)
					return 3;
				if (fl_probability >= -0.0030071586342709637)
					return 4;
				if (fl_probability >= -0.3343268488703196)
					return 5;
				if (fl_probability >= -0.6656465391063682)
					return 6;
				if (fl_probability >= -0.9969662293424169)
					return 8;
				if (fl_probability >= -0.9974718577853474)
					return 2;
				if (fl_probability >= -0.997977486228278)
					return 3;
				if (fl_probability >= -0.9984831146712085)
					return 4;
				if (fl_probability >= -0.9989887431141391)
					return 5;
				if (fl_probability >= -0.9994943715570697)
					return 6;
				if (fl_probability >= -1.0000000000000002) // sus
					return 8;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.000505628442930516)
					return 2;
				if (fl_probability <= 0.001011256885861032)
					return 3;
				if (fl_probability <= 0.0030071586342709637)
					return 4;
				if (fl_probability <= 0.3343268488703196)
					return 5;
				if (fl_probability <= 0.6656465391063682)
					return 6;
				if (fl_probability <= 0.9969662293424169)
					return 8;
				if (fl_probability <= 0.9974718577853474)
					return 2;
				if (fl_probability <= 0.997977486228278)
					return 3;
				if (fl_probability <= 0.9984831146712085)
					return 4;
				if (fl_probability <= 0.9989887431141391)
					return 5;
				if (fl_probability <= 0.9994943715570697)
					return 6;
				if (fl_probability <= 1.0000000000000002) // sus x2
					return 8;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.33232789685823344)
					return 0;
				if (fl_probability >= -0.6646557937164669)
					return 1;
				if (fl_probability >= -0.6651629607879774)
					return 2;
				if (fl_probability >= -0.665670127859488)
					return 3;
				if (fl_probability >= -0.6676721031417665)
					return 4;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.33232789685823344)
					return 0;
				if (fl_probability <= 0.6646557937164669)
					return 1;
				if (fl_probability <= 0.6651629607879774)
					return 2;
				if (fl_probability <= 0.665670127859488)
					return 3;
				if (fl_probability <= 0.6676721031417665)
					return 4;
				if (fl_probability <= 1.0)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_WhitetailDeer:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0005048894557823129)
					return 2;
				if (fl_probability >= -0.0010097789115646259)
					return 3;
				if (fl_probability >= -0.0030027636054421767)
					return 4;
				if (fl_probability >= -0.3351668792517007)
					return 5;
				if (fl_probability >= -0.6673309948979592)
					return 6;
				if (fl_probability >= -0.9994951105442178)
					return 8;
				if (fl_probability >= -1.0000000000000002)
					return 9;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0005048894557823129)
					return 2;
				if (fl_probability <= 0.0010097789115646259)
					return 3;
				if (fl_probability <= 0.0030027636054421767)
					return 4;
				if (fl_probability <= 0.3351668792517007)
					return 5;
				if (fl_probability <= 0.6673309948979592)
					return 6;
				if (fl_probability <= 0.9994951105442178)
					return 8;
				if (fl_probability <= 1.0000000000000002)
					return 9;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.3323319065216813)
					return 0;
				if (fl_probability >= -0.6646638130433626)
					return 1;
				if (fl_probability >= -0.6651689575412756)
					return 2;
				if (fl_probability >= -0.6656741020391885)
					return 3;
				if (fl_probability >= -0.6676680934783186)
					return 4;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.3323319065216813)
					return 0;
				if (fl_probability <= 0.6646638130433626)
					return 1;
				if (fl_probability <= 0.6651689575412756)
					return 2;
				if (fl_probability <= 0.6656741020391885)
					return 3;
				if (fl_probability <= 0.6676680934783186)
					return 4;
				if (fl_probability <= 1.0)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_BlacktailDeer:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0005071670715105571)
					return 2;
				if (fl_probability >= -0.0010143341430211142)
					return 3;
				if (fl_probability >= -0.003016309425299629)
					return 4;
				if (fl_probability >= -0.33534420628353306)
					return 5;
				if (fl_probability >= -0.6676721031417665)
					return 6;
				if (fl_probability >= -1.0)
					return 8;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0005048894557823129)
					return 2;
				if (fl_probability <= 0.0010097789115646259)
					return 3;
				if (fl_probability <= 0.0030027636054421767)
					return 4;
				if (fl_probability <= 0.3351668792517007)
					return 5;
				if (fl_probability <= 0.6673309948979592)
					return 6;
				if (fl_probability <= 1.0)
					return 8;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.33232789685823344)
					return 0;
				if (fl_probability >= -0.6646557937164669)
					return 1;
				if (fl_probability >= -0.6651629607879774)
					return 2;
				if (fl_probability >= -0.665670127859488)
					return 3;
				if (fl_probability >= -0.6676721031417665)
					return 4;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.33232789685823344)
					return 0;
				if (fl_probability <= 0.6646557937164669)
					return 1;
				if (fl_probability <= 0.6651629607879774)
					return 2;
				if (fl_probability <= 0.665670127859488)
					return 3;
				if (fl_probability <= 0.6676721031417665)
					return 4;
				if (fl_probability <= 1.0)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_Coyote:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0005071670715105571)
					return 2;
				if (fl_probability >= -0.0010143341430211142)
					return 3;
				if (fl_probability >= -0.003016309425299629)
					return 4;
				if (fl_probability >= -0.33534420628353306)
					return 5;
				if (fl_probability >= -0.6676721031417665)
					return 6;
				if (fl_probability >= -1.0)
					return 8;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0005048894557823129)
					return 2;
				if (fl_probability <= 0.0010097789115646259)
					return 3;
				if (fl_probability <= 0.0030027636054421767)
					return 4;
				if (fl_probability <= 0.3351668792517007)
					return 5;
				if (fl_probability <= 0.6673309948979592)
					return 6;
				if (fl_probability <= 1.0)
					return 8;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.33232789685823344)
					return 0;
				if (fl_probability >= -0.6646557937164669)
					return 1;
				if (fl_probability >= -0.6651629607879774)
					return 2;
				if (fl_probability >= -0.665670127859488)
					return 3;
				if (fl_probability >= -0.6676721031417665)
					return 4;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.33232789685823344)
					return 0;
				if (fl_probability <= 0.6646557937164669)
					return 1;
				if (fl_probability <= 0.6651629607879774)
					return 2;
				if (fl_probability <= 0.665670127859488)
					return 3;
				if (fl_probability <= 0.6676721031417665)
					return 4;
				if (fl_probability <= 1.0)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_Mallard:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.001001001001001001)
					return 0;
				if (fl_probability >= -0.12612612612612614)
					return 1;
				if (fl_probability >= -0.12712712712712715)
					return 3;
				if (fl_probability >= -0.8748748748748749)
					return 4;
				if (fl_probability >= -1.0)
					return 5;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.001001001001001001)
					return 0;
				if (fl_probability <= 0.12612612612612614)
					return 1;
				if (fl_probability <= 0.12712712712712715)
					return 3;
				if (fl_probability <= 0.8748748748748749)
					return 4;
				if (fl_probability <= 1.0)
					return 5;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.001001001001001001)
					return 0;
				if (fl_probability >= -0.12612612612612614)
					return 1;
				if (fl_probability >= -0.12712712712712715)
					return 2;
				if (fl_probability >= -0.8748748748748749)
					return 4;
				if (fl_probability >= -1.0)
					return 5;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.001001001001001001)
					return 0;
				if (fl_probability <= 0.12612612612612614)
					return 1;
				if (fl_probability <= 0.12712712712712715)
					return 2;
				if (fl_probability <= 0.8748748748748749)
					return 4;
				if (fl_probability <= 1.0)
					return 5;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_Jackrabbit:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.24974924774322968)
					return 0;
				if (fl_probability >= -0.49949849548645936)
					return 1;
				if (fl_probability >= -0.5005015045135406)
					return 2;
				if (fl_probability >= -0.7502507522567703)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.24974924774322968)
					return 0;
				if (fl_probability <= 0.49949849548645936)
					return 1;
				if (fl_probability <= 0.5005015045135406)
					return 2;
				if (fl_probability <= 0.7502507522567703)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_BrownBear:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.002)
					return 0;
				if (fl_probability >= -0.052000000000000005)
					return 3;
				if (fl_probability >= -0.10200000000000001)
					return 4;
				if (fl_probability >= -0.351)
					return 6;
				if (fl_probability >= -0.352)
					return 7;
				if (fl_probability >= -0.601)
					return 8;
				if (fl_probability >= -0.651)
					return 9;
				if (fl_probability >= -0.7010000000000001)
					return 10;
				if (fl_probability >= -0.7510000000000001)
					return 11;
				if (fl_probability >= -1.0)
					return 12;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.002)
					return 0;
				if (fl_probability <= 0.052000000000000005)
					return 3;
				if (fl_probability <= 0.10200000000000001)
					return 4;
				if (fl_probability <= 0.351)
					return 6;
				if (fl_probability <= 0.352)
					return 7;
				if (fl_probability <= 0.601)
					return 8;
				if (fl_probability <= 0.651)
					return 9;
				if (fl_probability <= 0.7010000000000001)
					return 10;
				if (fl_probability <= 0.7510000000000001)
					return 11;
				if (fl_probability <= 1.0)
					return 12;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.002)
					return 0;
				if (fl_probability >= -0.052000000000000005)
					return 1;
				if (fl_probability >= -0.301)
					return 2;
				if (fl_probability >= -0.351)
					return 3;
				if (fl_probability >= -0.40099999999999997)
					return 4;
				if (fl_probability >= -0.6499999999999999)
					return 6;
				if (fl_probability >= -0.6509999999999999)
					return 7;
				if (fl_probability >= -0.8999999999999999)
					return 8;
				if (fl_probability >= -0.95)
					return 9;
				if (fl_probability >= -1.0)
					return 10;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.002)
					return 0;
				if (fl_probability <= 0.052000000000000005)
					return 1;
				if (fl_probability <= 0.301)
					return 2;
				if (fl_probability <= 0.351)
					return 3;
				if (fl_probability <= 0.40099999999999997)
					return 4;
				if (fl_probability <= 0.6499999999999999)
					return 6;
				if (fl_probability <= 0.6509999999999999)
					return 7;
				if (fl_probability <= 0.8999999999999999)
					return 8;
				if (fl_probability <= 0.95)
					return 9;
				if (fl_probability <= 1.0)
					return 10;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_Reindeer:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0005071670715105571)
					return 2;
				if (fl_probability >= -0.0010143341430211142)
					return 3;
				if (fl_probability >= -0.0020153217841603717)
					return 4;
				if (fl_probability >= -0.003016309425299629)
					return 5;
				if (fl_probability >= -0.5015081547126499)
					return 6;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0005071670715105571)
					return 2;
				if (fl_probability <= 0.0010143341430211142)
					return 3;
				if (fl_probability <= 0.0020153217841603717)
					return 4;
				if (fl_probability <= 0.003016309425299629)
					return 5;
				if (fl_probability <= 0.5015081547126499)
					return 6;
				if (fl_probability <= 1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.4984918452873502)
					return 0;
				if (fl_probability >= -0.9969836905747004)
					return 1;
				if (fl_probability >= -0.9974908576462109)
					return 2;
				if (fl_probability >= -0.9979980247177215)
					return 3;
				if (fl_probability >= -0.9989990123588607)
					return 4;
				if (fl_probability >= -0.9999999999999999) // ???
					return 5;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.4984918452873502)
					return 0;
				if (fl_probability <= 0.9969836905747004)
					return 1;
				if (fl_probability <= 0.9974908576462109)
					return 2;
				if (fl_probability <= 0.9979980247177215)
					return 3;
				if (fl_probability <= 0.9989990123588607)
					return 4;
				if (fl_probability <= 0.9999999999999999)
					return 5;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_EurasianLynx:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0005071670715105571)
					return 2;
				if (fl_probability >= -0.0010143341430211142)
					return 3;
				if (fl_probability >= -0.003016309425299629)
					return 4;
				if (fl_probability >= -0.5015081547126499)
					return 5;
				if (fl_probability >= -1.0)
					return 6;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0005071670715105571)
					return 2;
				if (fl_probability <= 0.0010143341430211142)
					return 3;
				if (fl_probability <= 0.003016309425299629)
					return 4;
				if (fl_probability <= 0.5015081547126499)
					return 5;
				if (fl_probability <= 1.0)
					return 6;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.4984918452873502)
					return 0;
				if (fl_probability >= -0.9969836905747004)
					return 1;
				if (fl_probability >= -0.9974908576462109)
					return 2;
				if (fl_probability >= -0.9979980247177215)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.4984918452873502)
					return 0;
				if (fl_probability <= 0.9969836905747004)
					return 1;
				if (fl_probability <= 0.9974908576462109)
					return 2;
				if (fl_probability <= 0.9979980247177215)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_MuskDeer:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0005071670715105571)
					return 2;
				if (fl_probability >= -0.0010143341430211142)
					return 3;
				if (fl_probability >= -0.003016309425299629)
					return 4;
				if (fl_probability >= -0.5015081547126499)
					return 5;
				if (fl_probability >= -1.0)
					return 6;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0005071670715105571)
					return 2;
				if (fl_probability <= 0.0010143341430211142)
					return 3;
				if (fl_probability <= 0.003016309425299629)
					return 4;
				if (fl_probability <= 0.5015081547126499)
					return 5;
				if (fl_probability <= 1.0)
					return 6;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.4984918452873502)
					return 0;
				if (fl_probability >= -0.9969836905747004)
					return 1;
				if (fl_probability >= -0.9974908576462109)
					return 2;
				if (fl_probability >= -0.9979980247177215)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.4984918452873502)
					return 0;
				if (fl_probability <= 0.9969836905747004)
					return 1;
				if (fl_probability <= 0.9974908576462109)
					return 2;
				if (fl_probability <= 0.9979980247177215)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_Lion:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.001)
					return 0;
				if (fl_probability >= -0.002)
					return 1;
				if (fl_probability >= -0.003)
					return 2;
				if (fl_probability >= -0.75)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.001)
					return 0;
				if (fl_probability <= 0.002)
					return 1;
				if (fl_probability <= 0.003)
					return 2;
				if (fl_probability <= 0.75)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_CapeBuffalo:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.37451118018650353)
					return 0;
				if (fl_probability >= -0.3750125338413717)
					return 1;
				if (fl_probability >= -0.3755138874962398)
					return 2;
				if (fl_probability >= -0.7500250676827434)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.37451118018650353)
					return 0;
				if (fl_probability <= 0.3750125338413717)
					return 1;
				if (fl_probability <= 0.3755138874962398)
					return 2;
				if (fl_probability <= 0.7500250676827434)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_Gemsbok:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.001001001001001001)
					return 0;
				if (fl_probability >= -0.002002002002002002)
					return 1;
				if (fl_probability >= -0.003003003003003003)
					return 2;
				if (fl_probability >= -0.5015015015015015)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.001001001001001001)
					return 0;
				if (fl_probability <= 0.002002002002002002)
					return 1;
				if (fl_probability <= 0.003003003003003003)
					return 2;
				if (fl_probability <= 0.5015015015015015)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_BlueWildebeest:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.250501002004008)
					return 0;
				if (fl_probability >= -0.251503006012024)
					return 2;
				if (fl_probability >= -0.625751503006012)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.250501002004008)
					return 0;
				if (fl_probability <= 0.251503006012024)
					return 2;
				if (fl_probability <= 0.625751503006012)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0026666666666666666)
					return 1;
				if (fl_probability >= -0.004)
					return 2;
				if (fl_probability >= -0.502)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0026666666666666666)
					return 1;
				if (fl_probability <= 0.004)
					return 2;
				if (fl_probability <= 0.502)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_Warthog:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.2500376109523093)
					return 0;
				if (fl_probability >= -0.2507898299984956)
					return 2;
				if (fl_probability >= -0.6253949149992478)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.2500376109523093)
					return 0;
				if (fl_probability <= 0.2507898299984956)
					return 2;
				if (fl_probability <= 0.6253949149992478)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.2499122850984913)
					return 0;
				if (fl_probability >= -0.2504135131071124)
					return 1;
				if (fl_probability >= -0.25116535512004406)
					return 2;
				if (fl_probability >= -0.625582677560022)
					return 3;
				if (fl_probability >= -0.9999999999999999)
					return 4;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.2499122850984913)
					return 0;
				if (fl_probability <= 0.2504135131071124)
					return 1;
				if (fl_probability <= 0.25116535512004406)
					return 2;
				if (fl_probability <= 0.625582677560022)
					return 3;
				if (fl_probability <= 0.9999999999999999)
					return 4;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_LesserKudu:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0007353629350340272)
					return 3;
				if (fl_probability >= -0.001243431871966628)
					return 4;
				if (fl_probability >= -1.0)
					return 5;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0007353629350340272)
					return 3;
				if (fl_probability <= 0.001243431871966628)
					return 4;
				if (fl_probability <= 1.0)
					return 5;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.4986316000267005)
					return 0;
				if (fl_probability >= -0.4996328682998465)
					return 1;
				if (fl_probability >= -0.5006341365729925)
					return 2;
				if (fl_probability >= -0.5013683999732995)
					return 3;
				if (fl_probability >= -1.0)
					return 6;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.4986316000267005)
					return 0;
				if (fl_probability <= 0.4996328682998465)
					return 1;
				if (fl_probability <= 0.5006341365729925)
					return 2;
				if (fl_probability <= 0.5013683999732995)
					return 3;
				if (fl_probability <= 1.0)
					return 6;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_Springbok:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0010030090270812437)
					return 2;
				if (fl_probability >= -0.5005015045135406)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0010030090270812437)
					return 2;
				if (fl_probability <= 0.5005015045135406)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.1997192701022659)
					return 0;
				if (fl_probability >= -0.4002406256266292)
					return 1;
				if (fl_probability >= -0.4008421896932023)
					return 2;
				if (fl_probability >= -0.7004210948466012)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.1997192701022659)
					return 0;
				if (fl_probability <= 0.4002406256266292)
					return 1;
				if (fl_probability <= 0.4008421896932023)
					return 2;
				if (fl_probability <= 0.7004210948466012)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_SideStripedJackal:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.2500601829561868)
					return 0;
				if (fl_probability >= -0.25039118921521425)
					return 1;
				if (fl_probability >= -0.2507221954742417)
					return 3;
				if (fl_probability >= -0.6253610977371209)
					return 4;
				if (fl_probability >= -1.0)
					return 5;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.2500601829561868)
					return 0;
				if (fl_probability <= 0.25039118921521425)
					return 1;
				if (fl_probability <= 0.2507221954742417)
					return 3;
				if (fl_probability <= 0.6253610977371209)
					return 4;
				if (fl_probability <= 1.0)
					return 5;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_ScrubHare:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.03229974160206718)
					return 0;
				if (fl_probability >= -0.03488372093023256)
					return 1;
				if (fl_probability >= -0.5174418604651163)
					return 2;
				if (fl_probability >= -1.0)
					return 3;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.03229974160206718)
					return 0;
				if (fl_probability <= 0.03488372093023256)
					return 1;
				if (fl_probability <= 0.5174418604651163)
					return 2;
				if (fl_probability <= 1.0)
					return 3;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_WaterBuffalo:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0025806451612903226)
					return 0;
				if (fl_probability >= -0.003870967741935484)
					return 2;
				if (fl_probability >= -0.967741935483871)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0025806451612903226)
					return 0;
				if (fl_probability <= 0.003870967741935484)
					return 2;
				if (fl_probability <= 0.967741935483871)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0017414018284719198)
					return 0;
				if (fl_probability >= -0.326948193295603)
					return 1;
				if (fl_probability >= -0.32781889420983895)
					return 2;
				if (fl_probability >= -0.9782324771441011)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0017414018284719198)
					return 0;
				if (fl_probability <= 0.326948193295603)
					return 1;
				if (fl_probability <= 0.32781889420983895)
					return 2;
				if (fl_probability <= 0.9782324771441011)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_MuleDeer:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.3735)
					return 0;
				if (fl_probability >= -0.3755)
					return 1;
				if (fl_probability >= -0.37575)
					return 2;
				if (fl_probability >= -0.62575)
					return 3;
				if (fl_probability >= -0.626)
					return 4;
				if (fl_probability >= -0.62625)
					return 5;
				if (fl_probability >= -0.9997499999999999)
					return 6;
				if (fl_probability >= -0.9999999999999999)
					return 7;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.3735)
					return 0;
				if (fl_probability <= 0.3755)
					return 1;
				if (fl_probability <= 0.37575)
					return 2;
				if (fl_probability <= 0.62575)
					return 3;
				if (fl_probability <= 0.626)
					return 4;
				if (fl_probability <= 0.62625)
					return 5;
				if (fl_probability <= 0.9997499999999999)
					return 6;
				if (fl_probability <= 0.9999999999999999)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_Puma:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.1249874661586283)
					return 0;
				if (fl_probability >= -0.12548881981349644)
					return 1;
				if (fl_probability >= -0.12599017346836458)
					return 2;
				if (fl_probability >= -0.8750125338413717)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.1249874661586283)
					return 0;
				if (fl_probability <= 0.12548881981349644)
					return 1;
				if (fl_probability <= 0.12599017346836458)
					return 2;
				if (fl_probability <= 0.8750125338413717)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_Blackbuck:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.499001996007984)
					return 0;
				if (fl_probability >= -0.5)
					return 1;
				if (fl_probability >= -0.500998003992016)
					return 2;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.499001996007984)
					return 0;
				if (fl_probability <= 0.5)
					return 1;
				if (fl_probability <= 0.500998003992016)
					return 2;
				if (fl_probability <= 1.0)
					return 4;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.250501002004008)
					return 0;
				if (fl_probability >= -0.251002004008016)
					return 1;
				if (fl_probability >= -0.25150300601202397)
					return 2;
				if (fl_probability >= -1.0)
					return 3;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.250501002004008)
					return 0;
				if (fl_probability <= 0.251002004008016)
					return 1;
				if (fl_probability <= 0.25150300601202397)
					return 2;
				if (fl_probability <= 1.0)
					return 3;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_AxisDeer:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.14285714285714285)
					return 1;
				if (fl_probability >= -0.14514285714285713)
					return 2;
				if (fl_probability >= -0.1457142857142857)
					return 3;
				if (fl_probability >= -0.9994285714285714)
					return 4;
				if (fl_probability >= -1.0)
					return 5;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.14285714285714285)
					return 1;
				if (fl_probability <= 0.14514285714285713)
					return 2;
				if (fl_probability <= 0.1457142857142857)
					return 3;
				if (fl_probability <= 0.9994285714285714)
					return 4;
				if (fl_probability <= 1.0)
					return 5;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.14285714285714285)
					return 0;
				if (fl_probability >= -0.14514285714285713)
					return 2;
				if (fl_probability >= -0.1457142857142857)
					return 3;
				if (fl_probability >= -0.9994285714285714)
					return 4;
				if (fl_probability >= -1.0)
					return 5;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.14285714285714285)
					return 0;
				if (fl_probability <= 0.14514285714285713)
					return 2;
				if (fl_probability <= 0.1457142857142857)
					return 3;
				if (fl_probability <= 0.9994285714285714)
					return 4;
				if (fl_probability <= 1.0)
					return 5;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_CinnamonTeal:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.001002004008016032)
					return 0;
				if (fl_probability >= -0.12625250501002003)
					return 1;
				if (fl_probability >= -0.874749498997996)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.001002004008016032)
					return 0;
				if (fl_probability <= 0.12625250501002003)
					return 1;
				if (fl_probability <= 0.874749498997996)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0020028612303290413)
					return 2;
				if (fl_probability >= -0.8569384835479256)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0020028612303290413)
					return 2;
				if (fl_probability <= 0.8569384835479256)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_PlainsBison:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.28546861564918313)
					return 0;
				if (fl_probability >= -0.4995700773860705)
					return 1;
				if (fl_probability >= -0.4998566924620235)
					return 2;
				if (fl_probability >= -0.5001433075379765)
					return 3;
				if (fl_probability >= -0.5004299226139295)
					return 4;
				if (fl_probability >= -0.7145313843508169)
					return 5;
				if (fl_probability >= -1.0)
					return 6;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.28546861564918313)
					return 0;
				if (fl_probability <= 0.4995700773860705)
					return 1;
				if (fl_probability <= 0.4998566924620235)
					return 2;
				if (fl_probability <= 0.5001433075379765)
					return 3;
				if (fl_probability <= 0.5004299226139295)
					return 4;
				if (fl_probability <= 0.7145313843508169)
					return 5;
				if (fl_probability <= 1.0)
					return 6;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_GrizzlyBear:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0005071670715105571)
					return 0;
				if (fl_probability >= -0.0010143341430211142)
					return 1;
				if (fl_probability >= -0.9979980247177215)
					return 2;
				if (fl_probability >= -1.0)
					return 3;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0005071670715105571)
					return 0;
				if (fl_probability <= 0.0010143341430211142)
					return 1;
				if (fl_probability <= 0.9979980247177215)
					return 2;
				if (fl_probability <= 1.0)
					return 3;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0005071670715105571)
					return 0;
				if (fl_probability >= -0.0010143341430211142)
					return 1;
				if (fl_probability >= -0.9979980247177215)
					return 2;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0005071670715105571)
					return 0;
				if (fl_probability <= 0.0010143341430211142)
					return 1;
				if (fl_probability <= 0.9979980247177215)
					return 2;
				if (fl_probability <= 1.0)
					return 4;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_Caribou:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.000333667000333667)
					return 0;
				if (fl_probability >= -0.000667334000667334)
					return 1;
				if (fl_probability >= -0.002669336002669336)
					return 2;
				if (fl_probability >= -0.003003003003003003)
					return 3;
				if (fl_probability >= -0.5015015015015015)
					return 4;
				if (fl_probability >= -1.0)
					return 5;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.000333667000333667)
					return 0;
				if (fl_probability <= 0.000667334000667334)
					return 1;
				if (fl_probability <= 0.002669336002669336)
					return 2;
				if (fl_probability <= 0.003003003003003003)
					return 3;
				if (fl_probability <= 0.5015015015015015)
					return 4;
				if (fl_probability <= 1.0)
					return 5;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.00033433634236041456)
					return 0;
				if (fl_probability >= -0.0006686726847208291)
					return 1;
				if (fl_probability >= -0.0010030090270812437)
					return 3;
				if (fl_probability >= -0.5005015045135406)
					return 4;
				if (fl_probability >= -1.0)
					return 5;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.00033433634236041456)
					return 0;
				if (fl_probability <= 0.0006686726847208291)
					return 1;
				if (fl_probability <= 0.0010030090270812437)
					return 3;
				if (fl_probability <= 0.5005015045135406)
					return 4;
				if (fl_probability <= 1.0)
					return 5;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_GrayWolf:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0005071670715105571)
					return 0;
				if (fl_probability >= -0.0010143341430211142)
					return 1;
				if (fl_probability >= -0.0016816592371139524)
					return 2;
				if (fl_probability >= -0.002348984331206791)
					return 3;
				if (fl_probability >= -0.9993326749059072)
					return 4;
				if (fl_probability >= -1.0)
					return 5;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0005071670715105571)
					return 0;
				if (fl_probability <= 0.0010143341430211142)
					return 1;
				if (fl_probability <= 0.0016816592371139524)
					return 2;
				if (fl_probability <= 0.002348984331206791)
					return 3;
				if (fl_probability <= 0.9993326749059072)
					return 4;
				if (fl_probability <= 1.0)
					return 5;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_HarlequinDuck:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.250501002004008)
					return 1;
				if (fl_probability >= -0.251002004008016)
					return 2;
				if (fl_probability >= -0.25150300601202397)
					return 3;
				if (fl_probability >= -1.0)
					return 5;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.250501002004008)
					return 1;
				if (fl_probability <= 0.251002004008016)
					return 2;
				if (fl_probability <= 0.25150300601202397)
					return 3;
				if (fl_probability <= 1.0)
					return 5;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.001335850669706469)
					return 0;
				if (fl_probability >= -0.001781134226275292)
					return 3;
				if (fl_probability >= -0.002119549729267598)
					return 4;
				if (fl_probability >= -0.6673731832430893)
					return 5;
				if (fl_probability >= -1.0)
					return 6;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.001335850669706469)
					return 0;
				if (fl_probability <= 0.001781134226275292)
					return 3;
				if (fl_probability <= 0.002119549729267598)
					return 4;
				if (fl_probability <= 0.6673731832430893)
					return 5;
				if (fl_probability <= 1.0)
					return 6;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_IberianWolf:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0006699933000669994)
					return 0;
				if (fl_probability >= -0.0013399866001339987)
					return 1;
				if (fl_probability >= -0.0018399816001839983)
					return 2;
				if (fl_probability >= -0.0025099749002509978)
					return 3;
				if (fl_probability >= -0.0030099699003009973)
					return 5;
				if (fl_probability >= -0.7500024999750002)
					return 7;
				if (fl_probability >= -1.0)
					return 9;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0006699933000669994)
					return 0;
				if (fl_probability <= 0.0013399866001339987)
					return 1;
				if (fl_probability <= 0.0018399816001839983)
					return 2;
				if (fl_probability <= 0.0025099749002509978)
					return 3;
				if (fl_probability <= 0.0030099699003009973)
					return 5;
				if (fl_probability <= 0.7500024999750002)
					return 7;
				if (fl_probability <= 1.0)
					return 9;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_SoutheasternSpanishIbex:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.24974590777789665)
					return 0;
				if (fl_probability >= -0.2502540922221034)
					return 1;
				if (fl_probability >= -0.5)
					return 2;
				if (fl_probability >= -0.5005081844442067)
					return 3;
				if (fl_probability >= -0.7502540922221034)
					return 6;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.24974590777789665)
					return 0;
				if (fl_probability <= 0.2502540922221034)
					return 1;
				if (fl_probability <= 0.5)
					return 2;
				if (fl_probability <= 0.5005081844442067)
					return 3;
				if (fl_probability <= 0.7502540922221034)
					return 6;
				if (fl_probability <= 1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0006773497798613215)
					return 1;
				if (fl_probability >= -0.001354699559722643)
					return 3;
				if (fl_probability >= -0.3342364663731484)
					return 4;
				if (fl_probability >= -0.6671182331865741)
					return 5;
				if (fl_probability >= -1.0)
					return 6;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0006773497798613215)
					return 1;
				if (fl_probability <= 0.001354699559722643)
					return 3;
				if (fl_probability <= 0.3342364663731484)
					return 4;
				if (fl_probability <= 0.6671182331865741)
					return 5;
				if (fl_probability <= 1.0)
					return 6;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_RondaIbex:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.24974590777789665)
					return 0;
				if (fl_probability >= -0.2502540922221034)
					return 1;
				if (fl_probability >= -0.5)
					return 2;
				if (fl_probability >= -0.5005081844442067)
					return 3;
				if (fl_probability >= -0.7502540922221034)
					return 6;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.24974590777789665)
					return 0;
				if (fl_probability <= 0.2502540922221034)
					return 1;
				if (fl_probability <= 0.5)
					return 2;
				if (fl_probability <= 0.5005081844442067)
					return 3;
				if (fl_probability <= 0.7502540922221034)
					return 6;
				if (fl_probability <= 1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0006773497798613215)
					return 1;
				if (fl_probability >= -0.001354699559722643)
					return 3;
				if (fl_probability >= -0.3342364663731484)
					return 4;
				if (fl_probability >= -0.6671182331865741)
					return 5;
				if (fl_probability >= -1.0)
					return 6;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0006773497798613215)
					return 1;
				if (fl_probability <= 0.001354699559722643)
					return 3;
				if (fl_probability <= 0.3342364663731484)
					return 4;
				if (fl_probability <= 0.6671182331865741)
					return 5;
				if (fl_probability <= 1.0)
					return 6;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_BeceiteIbex:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.24974590777789665)
					return 1;
				if (fl_probability >= -0.2502540922221034)
					return 2;
				if (fl_probability >= -0.5)
					return 3;
				if (fl_probability >= -0.5005081844442067)
					return 4;
				if (fl_probability >= -0.7502540922221034)
					return 5;
				if (fl_probability >= -1.0)
					return 6;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.24974590777789665)
					return 1;
				if (fl_probability <= 0.2502540922221034)
					return 2;
				if (fl_probability <= 0.5)
					return 3;
				if (fl_probability <= 0.5005081844442067)
					return 4;
				if (fl_probability <= 0.7502540922221034)
					return 5;
				if (fl_probability <= 1.0)
					return 6;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.36323321322810753)
					return 0;
				if (fl_probability >= -0.36378754503945965)
					return 2;
				if (fl_probability >= -0.36434187685081176)
					return 4;
				if (fl_probability >= -0.6367667867718925)
					return 6;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.36323321322810753)
					return 0;
				if (fl_probability <= 0.36378754503945965)
					return 2;
				if (fl_probability <= 0.36434187685081176)
					return 4;
				if (fl_probability <= 0.6367667867718925)
					return 6;
				if (fl_probability <= 1.0)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_GredosIbex:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.24974590777789665)
					return 0;
				if (fl_probability >= -0.2502540922221034)
					return 1;
				if (fl_probability >= -0.5)
					return 2;
				if (fl_probability >= -0.5005081844442067)
					return 3;
				if (fl_probability >= -0.7502540922221034)
					return 6;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.24974590777789665)
					return 0;
				if (fl_probability <= 0.2502540922221034)
					return 1;
				if (fl_probability <= 0.5)
					return 2;
				if (fl_probability <= 0.5005081844442067)
					return 3;
				if (fl_probability <= 0.7502540922221034)
					return 6;
				if (fl_probability <= 1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0006773497798613215)
					return 1;
				if (fl_probability >= -0.001354699559722643)
					return 3;
				if (fl_probability >= -0.3342364663731484)
					return 4;
				if (fl_probability >= -0.6671182331865741)
					return 5;
				if (fl_probability >= -1.0)
					return 6;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0006773497798613215)
					return 1;
				if (fl_probability <= 0.001354699559722643)
					return 3;
				if (fl_probability <= 0.3342364663731484)
					return 4;
				if (fl_probability <= 0.6671182331865741)
					return 5;
				if (fl_probability <= 1.0)
					return 6;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_IberianMuflon:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.33232789685823344)
					return 0;
				if (fl_probability >= -0.33432987214051196)
					return 1;
				if (fl_probability >= -0.3348370392120225)
					return 2;
				if (fl_probability >= -0.667164936070256)
					return 3;
				if (fl_probability >= -0.9994928329284893)
					return 4;
				if (fl_probability >= -0.9999999999999999)
					return 5;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.33232789685823344)
					return 0;
				if (fl_probability <= 0.33432987214051196)
					return 1;
				if (fl_probability <= 0.3348370392120225)
					return 2;
				if (fl_probability <= 0.667164936070256)
					return 3;
				if (fl_probability <= 0.9994928329284893)
					return 4;
				if (fl_probability <= 0.9999999999999999)
					return 5;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.002998440810778395)
					return 1;
				if (fl_probability >= -0.0037580458161755887)
					return 2;
				if (fl_probability >= -0.5014992204053892)
					return 3;
				if (fl_probability >= -0.9992403949946028)
					return 4;
				if (fl_probability >= -1.0)
					return 5;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.002998440810778395)
					return 1;
				if (fl_probability <= 0.0037580458161755887)
					return 2;
				if (fl_probability <= 0.5014992204053892)
					return 3;
				if (fl_probability <= 0.9992403949946028)
					return 4;
				if (fl_probability <= 1.0)
					return 5;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_EuroHare:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.24974590777789665)
					return 0;
				if (fl_probability >= -0.4994918155557933)
					return 1;
				if (fl_probability >= -0.5)
					return 2;
				if (fl_probability >= -0.5005081844442067)
					return 3;
				if (fl_probability >= -0.7502540922221034)
					return 4;
				if (fl_probability >= -1.0)
					return 5;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.24974590777789665)
					return 0;
				if (fl_probability <= 0.4994918155557933)
					return 1;
				if (fl_probability <= 0.5)
					return 2;
				if (fl_probability <= 0.5005081844442067)
					return 3;
				if (fl_probability <= 0.7502540922221034)
					return 4;
				if (fl_probability <= 1.0)
					return 5;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_RockyMountainElk:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.3735)
					return 0;
				if (fl_probability >= -0.6234999999999999)
					return 1;
				if (fl_probability >= -0.6244999999999999)
					return 2;
				if (fl_probability >= -0.6255)
					return 3;
				if (fl_probability >= -0.6265)
					return 4;
				if (fl_probability >= -1.0)
					return 5;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.3735)
					return 0;
				if (fl_probability <= 0.6234999999999999)
					return 1;
				if (fl_probability <= 0.6244999999999999)
					return 2;
				if (fl_probability <= 0.6255)
					return 3;
				if (fl_probability <= 0.6265)
					return 4;
				if (fl_probability <= 1.0)
					return 5;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_MountainLion:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.1249874661586283)
					return 0;
				if (fl_probability >= -0.12548881981349644)
					return 1;
				if (fl_probability >= -0.12599017346836458)
					return 2;
				if (fl_probability >= -0.8750125338413717)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.1249874661586283)
					return 0;
				if (fl_probability <= 0.12548881981349644)
					return 1;
				if (fl_probability <= 0.12599017346836458)
					return 2;
				if (fl_probability <= 0.8750125338413717)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_Pronghorn:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.3735)
					return 0;
				if (fl_probability >= -0.6234999999999999)
					return 1;
				if (fl_probability >= -0.6239999999999999)
					return 2;
				if (fl_probability >= -0.6249999999999999)
					return 3;
				if (fl_probability >= -0.6259999999999999)
					return 4;
				if (fl_probability >= -0.6264999999999998)
					return 5;
				if (fl_probability >= -0.9999999999999998)
					return 6;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.3735)
					return 0;
				if (fl_probability <= 0.6234999999999999)
					return 1;
				if (fl_probability <= 0.6239999999999999)
					return 2;
				if (fl_probability <= 0.6249999999999999)
					return 3;
				if (fl_probability <= 0.6259999999999999)
					return 4;
				if (fl_probability <= 0.6264999999999998)
					return 5;
				if (fl_probability <= 0.9999999999999998)
					return 6;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.3738738738738739)
					return 0;
				if (fl_probability >= -0.6241241241241242)
					return 1;
				if (fl_probability >= -0.6246246246246248)
					return 2;
				if (fl_probability >= -0.6256256256256257)
					return 3;
				if (fl_probability >= -0.6261261261261263)
					return 5;
				if (fl_probability >= -1.0000000000000002)
					return 6;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.3738738738738739)
					return 0;
				if (fl_probability <= 0.6241241241241242)
					return 1;
				if (fl_probability <= 0.6246246246246248)
					return 2;
				if (fl_probability <= 0.6256256256256257)
					return 3;
				if (fl_probability <= 0.6261261261261263)
					return 5;
				if (fl_probability <= 1.0000000000000002)
					return 6;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_MountainGoat:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.24974924774322968)
					return 0;
				if (fl_probability >= -0.49949849548645936)
					return 1;
				if (fl_probability >= -0.749247743229689)
					return 2;
				if (fl_probability >= -0.7497492477432296)
					return 3;
				if (fl_probability >= -0.7502507522567702)
					return 4;
				if (fl_probability >= -0.9999999999999999)
					return 5;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.24974924774322968)
					return 0;
				if (fl_probability <= 0.49949849548645936)
					return 1;
				if (fl_probability <= 0.749247743229689)
					return 2;
				if (fl_probability <= 0.7497492477432296)
					return 3;
				if (fl_probability <= 0.7502507522567702)
					return 4;
				if (fl_probability <= 0.9999999999999999)
					return 5;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_BighornSheep:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.08349783063958556)
					return 0;
				if (fl_probability >= -0.16699566127917112)
					return 1;
				if (fl_probability >= -0.2504934919187567)
					return 2;
				if (fl_probability >= -0.25149550596699366)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.08349783063958556)
					return 0;
				if (fl_probability <= 0.16699566127917112)
					return 1;
				if (fl_probability <= 0.2504934919187567)
					return 2;
				if (fl_probability <= 0.25149550596699366)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_MerriamTurkey:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.5976)
					return 0;
				if (fl_probability >= -0.598)
					return 1;
				if (fl_probability >= -0.798)
					return 2;
				if (fl_probability >= -0.7996000000000001)
					return 3;
				if (fl_probability >= -0.8)
					return 4;
				if (fl_probability >= -1.0)
					return 5;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.5976)
					return 0;
				if (fl_probability <= 0.598)
					return 1;
				if (fl_probability <= 0.798)
					return 2;
				if (fl_probability <= 0.7996000000000001)
					return 3;
				if (fl_probability <= 0.8)
					return 4;
				if (fl_probability <= 1.0)
					return 5;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_SikaDeer:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.3735)
					return 0;
				if (fl_probability >= -0.4985)
					return 1;
				if (fl_probability >= -0.5005)
					return 2;
				if (fl_probability >= -0.6255)
					return 3;
				if (fl_probability >= -0.9989999999999999)
					return 4;
				if (fl_probability >= -0.9999999999999999)
					return 5;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.3735)
					return 0;
				if (fl_probability <= 0.4985)
					return 1;
				if (fl_probability <= 0.5005)
					return 2;
				if (fl_probability <= 0.6255)
					return 3;
				if (fl_probability <= 0.9989999999999999)
					return 4;
				if (fl_probability <= 0.9999999999999999)
					return 5;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_FeralPig:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.001)
					return 0;
				if (fl_probability >= -0.003)
					return 1;
				if (fl_probability >= -0.128)
					return 2;
				if (fl_probability >= -0.253)
					return 3;
				if (fl_probability >= -0.3775)
					return 4;
				if (fl_probability >= -0.502)
					return 5;
				if (fl_probability >= -0.6265000000000001)
					return 6;
				if (fl_probability >= -0.7510000000000001)
					return 7;
				if (fl_probability >= -0.8755000000000002)
					return 8;
				if (fl_probability >= -1.0000000000000002)
					return 9;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.001)
					return 0;
				if (fl_probability <= 0.003)
					return 1;
				if (fl_probability <= 0.128)
					return 2;
				if (fl_probability <= 0.253)
					return 3;
				if (fl_probability <= 0.3775)
					return 4;
				if (fl_probability <= 0.502)
					return 5;
				if (fl_probability <= 0.6265000000000001)
					return 6;
				if (fl_probability <= 0.7510000000000001)
					return 7;
				if (fl_probability <= 0.8755000000000002)
					return 8;
				if (fl_probability <= 1.0000000000000002)
					return 9;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.007936507936507936)
					return 1;
				if (fl_probability >= -0.503968253968254)
					return 2;
				if (fl_probability >= -1.0)
					return 3;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.007936507936507936)
					return 1;
				if (fl_probability <= 0.503968253968254)
					return 2;
				if (fl_probability <= 1.0)
					return 3;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_FeralGoat:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0005000050000500005)
					return 0;
				if (fl_probability >= -0.08383083830838309)
					return 1;
				if (fl_probability >= -0.08433084330843309)
					return 2;
				if (fl_probability >= -0.16766167661676618)
					return 3;
				if (fl_probability >= -0.35441354413544135)
					return 4;
				if (fl_probability >= -0.5411654116541165)
					return 5;
				if (fl_probability >= -0.7279172791727917)
					return 6;
				if (fl_probability >= -0.9146691466914669)
					return 7;
				if (fl_probability >= -0.9156691566915669)
					return 8;
				if (fl_probability >= -0.9166691666916669)
					return 9;
				if (fl_probability >= -1.0)
					return 10;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0005000050000500005)
					return 0;
				if (fl_probability <= 0.08383083830838309)
					return 1;
				if (fl_probability <= 0.08433084330843309)
					return 2;
				if (fl_probability <= 0.16766167661676618)
					return 3;
				if (fl_probability <= 0.35441354413544135)
					return 4;
				if (fl_probability <= 0.5411654116541165)
					return 5;
				if (fl_probability <= 0.7279172791727917)
					return 6;
				if (fl_probability <= 0.9146691466914669)
					return 7;
				if (fl_probability <= 0.9156691566915669)
					return 8;
				if (fl_probability <= 0.9166691666916669)
					return 9;
				if (fl_probability <= 1.0)
					return 10;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.0010921084245243868)
					return 0;
				if (fl_probability >= -0.1831028984557587)
					return 1;
				if (fl_probability >= -0.1841950068802831)
					return 2;
				if (fl_probability >= -0.5920975034401416)
					return 6;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.0010921084245243868)
					return 0;
				if (fl_probability <= 0.1831028984557587)
					return 1;
				if (fl_probability <= 0.1841950068802831)
					return 2;
				if (fl_probability <= 0.5920975034401416)
					return 6;
				if (fl_probability <= 1.0)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_Chamois:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.125)
					return 0;
				if (fl_probability >= -0.4985)
					return 1;
				if (fl_probability >= -0.6234999999999999)
					return 2;
				if (fl_probability >= -0.6255)
					return 3;
				if (fl_probability >= -0.6259999999999999)
					return 4;
				if (fl_probability >= -0.6264999999999998)
					return 5;
				if (fl_probability >= -0.9999999999999998)
					return 6;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.125)
					return 0;
				if (fl_probability <= 0.4985)
					return 1;
				if (fl_probability <= 0.6234999999999999)
					return 2;
				if (fl_probability <= 0.6255)
					return 3;
				if (fl_probability <= 0.6259999999999999)
					return 4;
				if (fl_probability <= 0.6264999999999998)
					return 5;
				if (fl_probability <= 0.9999999999999998)
					return 6;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_CollaredPeccary:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.3735)
					return 0;
				if (fl_probability >= -0.747)
					return 1;
				if (fl_probability >= -0.748)
					return 2;
				if (fl_probability >= -0.749)
					return 3;
				if (fl_probability >= -0.874)
					return 4;
				if (fl_probability >= -0.999)
					return 5;
				if (fl_probability >= -0.9994999999999999)
					return 6;
				if (fl_probability >= -0.9999999999999999)
					return 7;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.3735)
					return 0;
				if (fl_probability <= 0.747)
					return 1;
				if (fl_probability <= 0.748)
					return 2;
				if (fl_probability <= 0.749)
					return 3;
				if (fl_probability <= 0.874)
					return 4;
				if (fl_probability <= 0.999)
					return 5;
				if (fl_probability <= 0.9994999999999999)
					return 6;
				if (fl_probability <= 0.9999999999999999)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_MexicanBobcat:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.3735)
					return 0;
				if (fl_probability >= -0.374)
					return 1;
				if (fl_probability >= -0.376)
					return 2;
				if (fl_probability >= -0.501)
					return 3;
				if (fl_probability >= -0.5015)
					return 4;
				if (fl_probability >= -0.6265)
					return 5;
				if (fl_probability >= -1.0)
					return 6;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.3735)
					return 0;
				if (fl_probability <= 0.374)
					return 1;
				if (fl_probability <= 0.376)
					return 2;
				if (fl_probability <= 0.501)
					return 3;
				if (fl_probability <= 0.5015)
					return 4;
				if (fl_probability <= 0.6265)
					return 5;
				if (fl_probability <= 1.0)
					return 6;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_RioGrandeTurkey:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.3735)
					return 0;
				if (fl_probability >= -0.374)
					return 1;
				if (fl_probability >= -0.499)
					return 2;
				if (fl_probability >= -0.501)
					return 3;
				if (fl_probability >= -0.5015)
					return 4;
				if (fl_probability >= -0.875)
					return 5;
				if (fl_probability >= -1.0)
					return 6;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.3735)
					return 0;
				if (fl_probability <= 0.374)
					return 1;
				if (fl_probability <= 0.499)
					return 2;
				if (fl_probability <= 0.501)
					return 3;
				if (fl_probability <= 0.5015)
					return 4;
				if (fl_probability <= 0.875)
					return 5;
				if (fl_probability <= 1.0)
					return 6;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_RingNeckedPheasant:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.37446612259629847)
					return 0;
				if (fl_probability >= -0.49948868079645486)
					return 1;
				if (fl_probability >= -0.8739548033927533)
					return 2;
				if (fl_probability >= -0.8742956828617834)
					return 3;
				if (fl_probability >= -0.9993182410619398)
					return 4;
				if (fl_probability >= -0.9996591205309698)
					return 5;
				if (fl_probability >= -0.9999999999999999)
					return 6;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.37446612259629847)
					return 0;
				if (fl_probability <= 0.49948868079645486)
					return 1;
				if (fl_probability <= 0.8739548033927533)
					return 2;
				if (fl_probability <= 0.8742956828617834)
					return 3;
				if (fl_probability <= 0.9993182410619398)
					return 4;
				if (fl_probability <= 0.9996591205309698)
					return 5;
				if (fl_probability <= 0.9999999999999999)
					return 6;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.8798172053142372)
					return 0;
				if (fl_probability >= -0.8806181098652596)
					return 3;
				if (fl_probability >= -0.8814190144162819)
					return 5;
				if (fl_probability >= -0.8822199189673042)
					return 6;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.8798172053142372)
					return 0;
				if (fl_probability <= 0.8806181098652596)
					return 3;
				if (fl_probability <= 0.8814190144162819)
					return 5;
				if (fl_probability <= 0.8822199189673042)
					return 6;
				if (fl_probability <= 1.0)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_AntelopeJackrabbit:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.37451118018650353)
					return 0;
				if (fl_probability >= -0.7490223603730071)
					return 1;
				if (fl_probability >= -0.8740098265316354)
					return 2;
				if (fl_probability >= -0.9989972926902637)
					return 3;
				if (fl_probability >= -0.9994986463451319)
					return 4;
				if (fl_probability >= -1.0)
					return 5;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.37451118018650353)
					return 0;
				if (fl_probability <= 0.7490223603730071)
					return 1;
				if (fl_probability <= 0.8740098265316354)
					return 2;
				if (fl_probability <= 0.9989972926902637)
					return 3;
				if (fl_probability <= 0.9994986463451319)
					return 4;
				if (fl_probability <= 1.0)
					return 5;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_AmericanAlligator:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.7403369672943508)
					return 0;
				if (fl_probability >= -0.9881070366699702)
					return 1;
				if (fl_probability >= -0.9900891972249752)
					return 2;
				if (fl_probability >= -0.9920713577799802)
					return 3;
				if (fl_probability >= -0.9940535183349852)
					return 4;
				if (fl_probability >= -0.9960356788899902)
					return 5;
				if (fl_probability >= -0.9980178394449952)
					return 6;
				if (fl_probability >= -0.9990089197224977)
					return 7;
				if (fl_probability >= -1.0000000000000002)
					return 8;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.7403369672943508)
					return 0;
				if (fl_probability <= 0.9881070366699702)
					return 1;
				if (fl_probability <= 0.9900891972249752)
					return 2;
				if (fl_probability <= 0.9920713577799802)
					return 3;
				if (fl_probability <= 0.9940535183349852)
					return 4;
				if (fl_probability <= 0.9960356788899902)
					return 5;
				if (fl_probability <= 0.9980178394449952)
					return 6;
				if (fl_probability <= 0.9990089197224977)
					return 7;
				if (fl_probability <= 1.0000000000000002)
					return 8;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_WildHog:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.001)
					return 0;
				if (fl_probability >= -0.003)
					return 1;
				if (fl_probability >= -0.128)
					return 2;
				if (fl_probability >= -0.253)
					return 3;
				if (fl_probability >= -0.3775)
					return 4;
				if (fl_probability >= -0.502)
					return 5;
				if (fl_probability >= -0.6265000000000001)
					return 6;
				if (fl_probability >= -0.7510000000000001)
					return 7;
				if (fl_probability >= -0.8755000000000002)
					return 8;
				if (fl_probability >= -1.0000000000000002)
					return 9;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.001)
					return 0;
				if (fl_probability <= 0.003)
					return 1;
				if (fl_probability <= 0.128)
					return 2;
				if (fl_probability <= 0.253)
					return 3;
				if (fl_probability <= 0.3775)
					return 4;
				if (fl_probability <= 0.502)
					return 5;
				if (fl_probability <= 0.6265000000000001)
					return 6;
				if (fl_probability <= 0.7510000000000001)
					return 7;
				if (fl_probability <= 0.8755000000000002)
					return 8;
				if (fl_probability <= 1.0000000000000002)
					return 9;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.007936507936507936)
					return 1;
				if (fl_probability >= -0.503968253968254)
					return 2;
				if (fl_probability >= -1.0)
					return 3;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.007936507936507936)
					return 1;
				if (fl_probability <= 0.503968253968254)
					return 2;
				if (fl_probability <= 1.0)
					return 3;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_GrayFox:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.7469925300746992)
					return 0;
				if (fl_probability >= -0.8719912800871992)
					return 1;
				if (fl_probability >= -0.996990030099699)
					return 2;
				if (fl_probability >= -0.997490025099749)
					return 3;
				if (fl_probability >= -0.9979900200997991)
					return 4;
				if (fl_probability >= -0.9986600133998661)
					return 5;
				if (fl_probability >= -0.9993300066999331)
					return 6;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.7469925300746992)
					return 0;
				if (fl_probability <= 0.8719912800871992)
					return 1;
				if (fl_probability <= 0.996990030099699)
					return 2;
				if (fl_probability <= 0.997490025099749)
					return 3;
				if (fl_probability <= 0.9979900200997991)
					return 4;
				if (fl_probability <= 0.9986600133998661)
					return 5;
				if (fl_probability <= 0.9993300066999331)
					return 6;
				if (fl_probability <= 1.0)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_CommonRaccoon:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.3735)
					return 0;
				if (fl_probability >= -0.6234999999999999)
					return 1;
				if (fl_probability >= -0.9969999999999999)
					return 2;
				if (fl_probability >= -0.9979999999999999)
					return 3;
				if (fl_probability >= -0.9989999999999999)
					return 4;
				if (fl_probability >= -0.9994999999999998)
					return 5;
				if (fl_probability >= -0.9999999999999998)
					return 6;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.3735)
					return 0;
				if (fl_probability <= 0.6234999999999999)
					return 1;
				if (fl_probability <= 0.9969999999999999)
					return 2;
				if (fl_probability <= 0.9979999999999999)
					return 3;
				if (fl_probability <= 0.9989999999999999)
					return 4;
				if (fl_probability <= 0.9994999999999998)
					return 5;
				if (fl_probability <= 0.9999999999999998)
					return 6;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.596169193934557)
					return 0;
				if (fl_probability >= -0.9952114924181963)
					return 1;
				if (fl_probability >= -0.9968076616121309)
					return 3;
				if (fl_probability >= -0.9984038308060654)
					return 4;
				if (fl_probability >= -0.9992019154030327)
					return 5;
				if (fl_probability >= -1.0)
					return 6;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.596169193934557)
					return 0;
				if (fl_probability <= 0.9952114924181963)
					return 1;
				if (fl_probability <= 0.9968076616121309)
					return 3;
				if (fl_probability <= 0.9984038308060654)
					return 4;
				if (fl_probability <= 0.9992019154030327)
					return 5;
				if (fl_probability <= 1.0)
					return 6;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_EasternWildTurkey:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.3735)
					return 0;
				if (fl_probability >= -0.374)
					return 1;
				if (fl_probability >= -0.499)
					return 2;
				if (fl_probability >= -0.501)
					return 3;
				if (fl_probability >= -0.5015)
					return 4;
				if (fl_probability >= -0.875)
					return 5;
				if (fl_probability >= -1.0)
					return 6;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.3735)
					return 0;
				if (fl_probability <= 0.374)
					return 1;
				if (fl_probability <= 0.499)
					return 2;
				if (fl_probability <= 0.501)
					return 3;
				if (fl_probability <= 0.5015)
					return 4;
				if (fl_probability <= 0.875)
					return 5;
				if (fl_probability <= 1.0)
					return 6;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_EasternCottontailRabbit:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.3735)
					return 0;
				if (fl_probability >= -0.4985)
					return 1;
				if (fl_probability >= -0.872)
					return 2;
				if (fl_probability >= -0.873)
					return 3;
				if (fl_probability >= -0.874)
					return 4;
				if (fl_probability >= -0.999)
					return 5;
				if (fl_probability >= -0.9994999999999999)
					return 6;
				if (fl_probability >= -0.9999999999999999)
					return 7;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.3735)
					return 0;
				if (fl_probability <= 0.4985)
					return 1;
				if (fl_probability <= 0.872)
					return 2;
				if (fl_probability <= 0.873)
					return 3;
				if (fl_probability <= 0.874)
					return 4;
				if (fl_probability <= 0.999)
					return 5;
				if (fl_probability <= 0.9994999999999999)
					return 6;
				if (fl_probability <= 0.9999999999999999)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_BobwhiteQuail:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.3333243548995313)
					return 0;
				if (fl_probability >= -0.6666487097990627)
					return 1;
				if (fl_probability >= -0.999973064698594)
					return 2;
				if (fl_probability >= -1.0)
					return 3;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.3333243548995313)
					return 0;
				if (fl_probability <= 0.6666487097990627)
					return 1;
				if (fl_probability <= 0.999973064698594)
					return 2;
				if (fl_probability <= 1.0)
					return 3;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.9999191984486102)
					return 0;
				if (fl_probability >= -1.0)
					return 3;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.9999191984486102)
					return 0;
				if (fl_probability <= 1.0)
					return 3;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_EurasianWigeon:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.4980066400885345)
					return 1;
				if (fl_probability >= -0.996013280177069)
					return 2;
				if (fl_probability >= -0.9986799823997653)
					return 3;
				if (fl_probability >= -0.9991199882665102)
					return 4;
				if (fl_probability >= -0.999559994133255)
					return 7;
				if (fl_probability >= -0.9999999999999999)
					return 8;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.4980066400885345)
					return 1;
				if (fl_probability <= 0.996013280177069)
					return 2;
				if (fl_probability <= 0.9986799823997653)
					return 3;
				if (fl_probability <= 0.9991199882665102)
					return 4;
				if (fl_probability <= 0.999559994133255)
					return 7;
				if (fl_probability <= 0.9999999999999999)
					return 8;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.005316886431305828)
					return 5;
				if (fl_probability >= -0.9982454274776691)
					return 6;
				if (fl_probability >= -0.9991227137388345)
					return 7;
				if (fl_probability >= -1.0)
					return 8;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.005316886431305828)
					return 5;
				if (fl_probability <= 0.9982454274776691)
					return 6;
				if (fl_probability <= 0.9991227137388345)
					return 7;
				if (fl_probability <= 1.0)
					return 8;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_TundraBeanGoose:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.7477627179723317)
					return 0;
				if (fl_probability >= -0.8728903481551182)
					return 1;
				if (fl_probability >= -0.9980179783379046)
					return 2;
				if (fl_probability >= -0.9986786522252697)
					return 3;
				if (fl_probability >= -0.9993393261126349)
					return 4;
				if (fl_probability >= -1.0)
					return 5;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.7477627179723317)
					return 0;
				if (fl_probability <= 0.8728903481551182)
					return 1;
				if (fl_probability <= 0.9980179783379046)
					return 2;
				if (fl_probability <= 0.9986786522252697)
					return 3;
				if (fl_probability <= 0.9993393261126349)
					return 4;
				if (fl_probability <= 1.0)
					return 5;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_EurasianTeal:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.49933155080213903)
					return 0;
				if (fl_probability >= -0.9986631016042781)
					return 2;
				if (fl_probability >= -0.9989973262032086)
					return 3;
				if (fl_probability >= -0.9993315508021391)
					return 4;
				if (fl_probability >= -0.9996657754010696)
					return 5;
				if (fl_probability >= -1.0)
					return 6;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.49933155080213903)
					return 0;
				if (fl_probability <= 0.9986631016042781)
					return 2;
				if (fl_probability <= 0.9989973262032086)
					return 3;
				if (fl_probability <= 0.9993315508021391)
					return 4;
				if (fl_probability <= 0.9996657754010696)
					return 5;
				if (fl_probability <= 1.0)
					return 6;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.9986631016042781)
					return 1;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.9986631016042781)
					return 1;
				if (fl_probability <= 1.0)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_BlackGrouse:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.9986631016042781)
					return 0;
				if (fl_probability >= -0.9989304812834224)
					return 5;
				if (fl_probability >= -0.9991978609625668)
					return 6;
				if (fl_probability >= -0.9994652406417112)
					return 7;
				if (fl_probability >= -0.9997326203208555)
					return 8;
				if (fl_probability >= -0.9999999999999999)
					return 9;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.9986631016042781)
					return 0;
				if (fl_probability <= 0.9989304812834224)
					return 5;
				if (fl_probability <= 0.9991978609625668)
					return 6;
				if (fl_probability <= 0.9994652406417112)
					return 7;
				if (fl_probability <= 0.9997326203208555)
					return 8;
				if (fl_probability <= 0.9999999999999999)
					return 9;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.7477477477477478)
					return 1;
				if (fl_probability >= -0.7487487487487487)
					return 2;
				if (fl_probability >= -0.998998998998999)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.7477477477477478)
					return 1;
				if (fl_probability <= 0.7487487487487487)
					return 2;
				if (fl_probability <= 0.998998998998999)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_Goldeneye:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.9953364423717521)
					return 0;
				if (fl_probability >= -0.9980013324450366)
					return 3;
				if (fl_probability >= -0.9983344437041972)
					return 4;
				if (fl_probability >= -0.9986675549633578)
					return 5;
				if (fl_probability >= -0.999333777481679)
					return 6;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.9953364423717521)
					return 0;
				if (fl_probability <= 0.9980013324450366)
					return 3;
				if (fl_probability <= 0.9983344437041972)
					return 4;
				if (fl_probability <= 0.9986675549633578)
					return 5;
				if (fl_probability <= 0.999333777481679)
					return 6;
				if (fl_probability <= 1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.996)
					return 1;
				if (fl_probability >= -0.9986666666666667)
					return 2;
				if (fl_probability >= -0.9993333333333334)
					return 6;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.996)
					return 1;
				if (fl_probability <= 0.9986666666666667)
					return 2;
				if (fl_probability <= 0.9993333333333334)
					return 6;
				if (fl_probability <= 1.0)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_HazelGrouse:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.5444606413994169)
					return 0;
				if (fl_probability >= -0.8166909620991253)
					return 1;
				if (fl_probability >= -0.9989067055393586)
					return 2;
				if (fl_probability >= -0.999271137026239)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.5444606413994169)
					return 0;
				if (fl_probability <= 0.8166909620991253)
					return 1;
				if (fl_probability <= 0.9989067055393586)
					return 2;
				if (fl_probability <= 0.999271137026239)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.747)
					return 0;
				if (fl_probability >= -0.748)
					return 4;
				if (fl_probability >= -0.873)
					return 5;
				if (fl_probability >= -0.875)
					return 6;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.747)
					return 0;
				if (fl_probability <= 0.748)
					return 4;
				if (fl_probability <= 0.873)
					return 5;
				if (fl_probability <= 0.875)
					return 6;
				if (fl_probability <= 1.0)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_WesternCapercaillie:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.9982360487491982)
					return 1;
				if (fl_probability >= -0.9991180243745992)
					return 2;
				if (fl_probability >= -0.9995590121872996)
					return 3;
				if (fl_probability >= -1.0)
					return 4;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.9982360487491982)
					return 1;
				if (fl_probability <= 0.9991180243745992)
					return 2;
				if (fl_probability <= 0.9995590121872996)
					return 3;
				if (fl_probability <= 1.0)
					return 4;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.7487520798668885)
					return 0;
				if (fl_probability >= -0.7494136278892609)
					return 2;
				if (fl_probability >= -0.8747068139446305)
					return 5;
				if (fl_probability >= -1.0)
					return 6;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.7487520798668885)
					return 0;
				if (fl_probability <= 0.7494136278892609)
					return 2;
				if (fl_probability <= 0.8747068139446305)
					return 5;
				if (fl_probability <= 1.0)
					return 6;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_TuftedDuck:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.9973430886927729)
					return 0;
				if (fl_probability >= -0.9986782200029373)
					return 2;
				if (fl_probability >= -0.9991188133352915)
					return 4;
				if (fl_probability >= -0.9995594066676458)
					return 5;
				if (fl_probability >= -1.0)
					return 6;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.9973430886927729)
					return 0;
				if (fl_probability <= 0.9986782200029373)
					return 2;
				if (fl_probability <= 0.9991188133352915)
					return 4;
				if (fl_probability <= 0.9995594066676458)
					return 5;
				if (fl_probability <= 1.0)
					return 6;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.9977827050997783)
					return 1;
				if (fl_probability >= -0.999118424919189)
					return 3;
				if (fl_probability >= -0.9995592124595946)
					return 4;
				if (fl_probability >= -1.0)
					return 5;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.9977827050997783)
					return 1;
				if (fl_probability <= 0.999118424919189)
					return 3;
				if (fl_probability <= 0.9995592124595946)
					return 4;
				if (fl_probability <= 1.0)
					return 5;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_RockPtarmigan:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.19925310428531418)
					return 0;
				if (fl_probability >= -0.5977593128559425)
					return 3;
				if (fl_probability >= -0.9962655214265709)
					return 4;
				if (fl_probability >= -1.0)
					return 5;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.19925310428531418)
					return 0;
				if (fl_probability <= 0.5977593128559425)
					return 3;
				if (fl_probability <= 0.9962655214265709)
					return 4;
				if (fl_probability <= 1.0)
					return 5;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.16614766605424594)
					return 1;
				if (fl_probability >= -0.3322953321084919)
					return 2;
				if (fl_probability >= -0.6645906642169838)
					return 3;
				if (fl_probability >= -0.9968859963254757)
					return 4;
				if (fl_probability >= -1.0)
					return 5;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.16614766605424594)
					return 1;
				if (fl_probability <= 0.3322953321084919)
					return 2;
				if (fl_probability <= 0.6645906642169838)
					return 3;
				if (fl_probability <= 0.9968859963254757)
					return 4;
				if (fl_probability <= 1.0)
					return 5;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_WillowPtarmigan:
		{
			if (m_str_gender == "male" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.33067729083665337)
					return 0;
				if (fl_probability >= -0.9920318725099602)
					return 3;
				if (fl_probability >= -0.99734395750332)
					return 5;
				if (fl_probability >= -1.0)
					return 6;
			}
			else if (m_str_gender == "male" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.33067729083665337)
					return 0;
				if (fl_probability <= 0.9920318725099602)
					return 3;
				if (fl_probability <= 0.99734395750332)
					return 5;
				if (fl_probability <= 1.0)
					return 6;
			}
			else if (m_str_gender == "female" && fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.19935948759007205)
					return 1;
				if (fl_probability >= -0.3987189751801441)
					return 2;
				if (fl_probability >= -0.7974379503602882)
					return 3;
				if (fl_probability >= -0.9967974379503602)
					return 4;
				if (fl_probability >= -1.0)
					return 5;
			}
			else if (m_str_gender == "female" && fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.19935948759007205)
					return 1;
				if (fl_probability <= 0.3987189751801441)
					return 2;
				if (fl_probability <= 0.7974379503602882)
					return 3;
				if (fl_probability <= 0.9967974379503602)
					return 4;
				if (fl_probability <= 1.0)
					return 5;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_GreylagGoose:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.7494379215588308)
					return 0;
				if (fl_probability >= -0.9992505620784411)
					return 1;
				if (fl_probability >= -0.999375468398701)
					return 2;
				if (fl_probability >= -0.9995003747189608)
					return 3;
				if (fl_probability >= -0.9996252810392207)
					return 4;
				if (fl_probability >= -0.9997501873594805)
					return 5;
				if (fl_probability >= -0.9998750936797404)
					return 6;
				if (fl_probability >= -1.0000000000000002)
					return 7;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.7494379215588308)
					return 0;
				if (fl_probability <= 0.9992505620784411)
					return 1;
				if (fl_probability <= 0.999375468398701)
					return 2;
				if (fl_probability <= 0.9995003747189608)
					return 3;
				if (fl_probability <= 0.9996252810392207)
					return 4;
				if (fl_probability <= 0.9997501873594805)
					return 5;
				if (fl_probability <= 0.9998750936797404)
					return 6;
				if (fl_probability <= 1.0000000000000002)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_MountainHare:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.24900498009960198)
					return 0;
				if (fl_probability >= -0.49800996019920396)
					return 1;
				if (fl_probability >= -0.747014940298806)
					return 2;
				if (fl_probability >= -0.997019940398808)
					return 3;
				if (fl_probability >= -0.997679953599072)
					return 4;
				if (fl_probability >= -0.998339966799336)
					return 5;
				if (fl_probability >= -0.9989999799996)
					return 6;
				if (fl_probability >= -1.0)
					return 7;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.24900498009960198)
					return 0;
				if (fl_probability <= 0.49800996019920396)
					return 1;
				if (fl_probability <= 0.747014940298806)
					return 2;
				if (fl_probability <= 0.997019940398808)
					return 3;
				if (fl_probability <= 0.997679953599072)
					return 4;
				if (fl_probability <= 0.998339966799336)
					return 5;
				if (fl_probability <= 0.9989999799996)
					return 6;
				if (fl_probability <= 1.0)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		case AT_RaccoonDog:
		{
			if (fl_probability <= -1.0 && fl_probability >= -2.0)
			{
				fl_probability += 1.0;
				if (fl_probability >= -0.4259905563539314)
					return 0;
				if (fl_probability >= -0.8519811127078628)
					return 1;
				if (fl_probability >= -0.9945482333082415)
					return 2;
				if (fl_probability >= -0.9968293072378476)
					return 3;
				if (fl_probability >= -0.9991103811674537)
					return 4;
				if (fl_probability >= -0.9994069207783024)
					return 5;
				if (fl_probability >= -0.9997034603891511)
					return 6;
				if (fl_probability >= -0.9999999999999999)
					return 7;
			}
			else if (fl_probability >= 1.0 && fl_probability <= 2.0)
			{
				fl_probability -= 1.0;
				if (fl_probability <= 0.4259905563539314)
					return 0;
				if (fl_probability <= 0.8519811127078628)
					return 1;
				if (fl_probability <= 0.9945482333082415)
					return 2;
				if (fl_probability <= 0.9968293072378476)
					return 3;
				if (fl_probability <= 0.9991103811674537)
					return 4;
				if (fl_probability <= 0.9994069207783024)
					return 5;
				if (fl_probability <= 0.9997034603891511)
					return 6;
				if (fl_probability <= 0.9999999999999999)
					return 7;
			}
			return std::stoul(visual_variation_seed);
		}
		default:
			return std::stoul(visual_variation_seed);
		};
	}

	std::string Animal::ResolveFurTypeId(const uint32_t visual_variation_seed)
	{
		switch (m_animal_type)
		{
		case AT_RedDeer:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Dark Brown";
			case 1:
				return "Brown";
			case 2:
				return "Melanistic";
			case 3:
				return "Albino";
			case 4:
				return "Piebald";
			case 5:
				return "Brown";
			case 6:
				return "Light Brown";
			case 7:
				return "Grey";
			case 8:
				return "Dark Brown";
			case 9:
				return "Great One";
			default:
				return "FoorType";
			}
		}
		case AT_WildBoar:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Brown";
			case 1:
				return "Light Brown";
			case 2:
				return "Melanistic";
			case 3:
				return "Albino";
			case 4:
				return "Black Gold";
			case 5:
				return "Light Brown";
			case 6:
				return "Brown";
			case 7:
				return "Dark Brown";
			case 8:
				return "Light Brown";
			default:
				return "FoorType";
			}
		}
		case AT_FallowDeer:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Piebald";
			case 1:
				return "Dark";
			case 2:
				return "Spotted";
			case 3:
				return "Spotted";
			case 4:
				return "Spotted Red";
			case 5:
				return "Spotted Dark";
			case 6:
				return "Spotted Dark";
			case 7:
				return "Melanistic";
			case 8:
				return "Albino";
			case 9:
				return "Albino";
			case 10:
				return "Dark";
			case 11:
				return "Melanistic";
			case 12:
				return "Spotted";
			default:
				return "FoorType";
			}
		}
		case AT_EuroBison:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Brown";
			case 1:
				return "Dark Brown";
			case 2:
				return "Melanistic";
			case 3:
				return "Albino";
			case 4:
				return "Piebald";
			case 5:
				return "Light Brown";
			case 6:
				return "Brown";
			case 7:
				return "Light Brown";
			case 8:
				return "Dark Brown";
			default:
				return "FoorType";
			}
		}
		case AT_RoeDeer:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Tan";
			case 1:
				return "Orange";
			case 2:
				return "Melanistic";
			case 3:
				return "Albino";
			case 4:
				return "Piebald";
			case 5:
				return "Dark Grey";
			case 6:
				return "Brown";
			case 7:
				return "Brown";
			case 8:
				return "Dark Brown";
			default:
				return "FoorType";
			}
		}
		case AT_RedFox:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Red";
			case 1:
				return "Orange";
			case 2:
				return "Melanistic";
			case 3:
				return "Albino";
			case 4:
				return "Piebald";
			case 5:
				return "Dark Red";
			case 6:
				return "Red";
			case 7:
				return "Dark Red";
			case 8:
				return "Orange";
			default:
				return "FoorType";
			}
		}
		case AT_EuroRabbit:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Dark Brown";
			case 1:
				return "Leucistic";
			case 2:
				return "Melanistic";
			case 3:
				return "Light Brown";
			case 4:
				return "Light Grey";
			case 5:
				return "Brown";
			case 6:
				return "Albino";
			case 7:
				return "Tan";
			default:
				return "FoorType";
			}
		}
		case AT_CanadaGoose:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Brown Hybrid";
			case 1:
				return "Grey";
			case 2:
				return "Light Grey Leucistic";
			case 3:
				return "Melanistic";
			case 4:
				return "Gray Brown";
			case 5:
				return "Bald Leucistic";
			default:
				return "FoorType";
			}
		}
		case AT_RooseveltElk:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Tan";
			case 1:
				return "Orange";
			case 2:
				return "Melanistic";
			case 3:
				return "Albino";
			case 4:
				return "Piebald";
			case 5:
				return "Brown";
			case 6:
				return "Tan";
			case 7:
				return "Brown";
			case 8:
				return "Orange";
			default:
				return "FoorType";
			}
		}
		case AT_Moose:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Tan";
			case 1:
				return "Brown";
			case 2:
				return "Melanistic";
			case 3:
				return "Albino";
			case 4:
				return "Piebald";
			case 5:
				return "Light Brown";
			case 6:
				return "Tan";
			case 7:
				return "Dark Brown";
			case 8:
				return "Brown";
			case 9:
				return "Moccha";
			default:
				return "FoorType";
			}
		}
		case AT_BlackBear:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Black";
			case 1:
				return "Dusky";
			case 2:
				return "Brown";
			case 3:
				return "Blonde";
			case 4:
				return "Cinnamon";
			case 5:
				return "Dark";
			case 6:
				return "Black";
			case 7:
				return "Dark";
			case 8:
				return "Dusky";
			case 9:
				return "Fabled Glacier"; // DO NOT ASK
			case 10:
				return "Fabled Glacier"; // WHY DOUBLE
			case 11:
				return "Fabled Cream";
			case 12:
				return "Fabled Spotted";
			case 13:
				return "Fabled Spirit";
			case 14:
				return "Fabled Chestnut";
			default:
				return "FoorType";
			}
		}
		case AT_WhitetailDeer:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Brown";
			case 1:
				return "Dark Brown";
			case 2:
				return "Melanistic";
			case 3:
				return "Albino";
			case 4:
				return "Piebald";
			case 5:
				return "Tan";
			case 6:
				return "Brown";
			case 7:
				return "Red Brown";
			case 8:
				return "Dark Brown";
			case 9:
				return "Fabled Piebald";
			default:
				return "FoorType";
			}
		}
		case AT_BlacktailDeer:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Tan";
			case 1:
				return "Grey";
			case 2:
				return "Melanistic";
			case 3:
				return "Albino";
			case 4:
				return "Piebald";
			case 5:
				return "Gray Brown";
			case 6:
				return "Grey";
			case 7:
				return "Gray Brown";
			case 8:
				return "Dark Grey";
			default:
				return "FoorType";
			}
		}
		case AT_Coyote:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Gray Brown";
			case 1:
				return "Orange";
			case 2:
				return "Melanistic";
			case 3:
				return "Albino";
			case 4:
				return "Piebald";
			case 5:
				return "Gray Brown";
			case 6:
				return "Orange";
			case 7:
				return "Light Grey";
			case 8:
				return "Dark Grey";
			default:
				return "FoorType";
			}
		}
		case AT_Mallard:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Melanistic";
			case 1:
				return "Piebald";
			case 2:
				return "Blonde";
			case 3:
				return "Leucistic";
			case 4:
				return "Black Brown";
			case 5:
				return "Brown Hybrid";
			default:
				return "FoorType";
			}
		}
		case AT_Jackrabbit:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Grey";
			case 1:
				return "Beige";
			case 2:
				return "Albino";
			case 3:
				return "Light Brown";
			case 4:
				return "Brown";
			default:
				return "FoorType";
			}
		}
		case AT_BrownBear:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Melanistic";
			case 1:
				return "Dark Brown";
			case 2:
				return "Light Brown";
			case 3:
				return "Spirit";
			case 4:
				return "Blonde";
			case 5:
				return "Legendary";
			case 6:
				return "Red Brown";
			case 7:
				return "Albino";
			case 8:
				return "Cinnamon";
			case 9:
				return "Gold";
			case 10:
				return "Dark Brown";
			case 11:
				return "Grey";
			case 12:
				return "Light Brown";
			default:
				return "FoorType";
			}
		}
		case AT_Reindeer:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Tan";
			case 1:
				return "Brown";
			case 2:
				return "Melanistic";
			case 3:
				return "Albino";
			case 4:
				return "Leucistic";
			case 5:
				return "Piebald";
			case 6:
				return "Light Brown";
			case 7:
				return "Dark Brown";
			default:
				return "FoorType";
			}
		}
		case AT_EurasianLynx:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Grey";
			case 1:
				return "Light Brown";
			case 2:
				return "ALbino";
			case 3:
				return "Melanistic";
			case 4:
				return "Piebald";
			case 5:
				return "Grey";
			case 6:
				return "Light Brown";
			default:
				return "FoorType";
			}
		}
		case AT_MuskDeer:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Gray Brown";
			case 1:
				return "Orange";
			case 2:
				return "Melanistic";
			case 3:
				return "Albino";
			case 4:
				return "Piebald";
			case 5:
				return "Gray Brown";
			case 6:
				return "Dark Brown";
			default:
				return "FoorType";
			}
		}
		case AT_Lion:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Dark Brown";
			case 1:
				return "Blonde";
			case 2:
				return "Albino";
			case 3:
				return "Tan";
			case 4:
				return "Light Brown";
			default:
				return "FoorType";
			}
		}
		case AT_CapeBuffalo:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Grey";
			case 1:
				return "Leucistic";
			case 2:
				return "Albino";
			case 3:
				return "Black";
			case 4:
				return "Brown";
			default:
				return "FoorType";
			}
		}
		case AT_Gemsbok:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Dark";
			case 1:
				return "Beige";
			case 2:
				return "Gold";
			case 3:
				return "Light Grey";
			case 4:
				return "Grey";
			default:
				return "FoorType";
			}
		}
		case AT_BlueWildebeest:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Gold";
			case 1:
				return "Crowned";
			case 2:
				return "Albino";
			case 3:
				return "Grey";
			case 4:
				return "Dark Grey";
			default:
				return "FoorType";
			}
		}
		case AT_Warthog:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Red Brown";
			case 1:
				return "Red";
			case 2:
				return "Albino";
			case 3:
				return "Grey";
			case 4:
				return "Dark";
			default:
				return "FoorType";
			}
		}
		case AT_LesserKudu:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Dark Brown";
			case 1:
				return "Dusky";
			case 2:
				return "Red Brown";
			case 3:
				return "Albino";
			case 4:
				return "Melanistic";
			case 5:
				return "Grey";
			case 6:
				return "Grey";
			default:
				return "FoorType";
			}
		}
		case AT_Springbok:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Black Brown";
			case 1:
				return "Black Brown";
			case 2:
				return "Albino";
			case 3:
				return "Tan";
			case 4:
				return "Orange";
			default:
				return "FoorType";
			}
		}
		case AT_SideStripedJackal:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Grey";
			case 1:
				return "Albino";
			case 2:
				return "Ghost";
			case 3:
				return "Melanistic";
			case 4:
				return "Light Brown";
			case 5:
				return "Gray Brown";
			default:
				return "FoorType";
			}
		}
		case AT_ScrubHare:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Grey";
			case 1:
				return "Light Grey";
			case 2:
				return "Brown";
			case 3:
				return "Chestnut";
			default:
				return "FoorType";
			}
		}
		case AT_WaterBuffalo:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Orange";
			case 1:
				return "Brown";
			case 2:
				return "Albino";
			case 3:
				return "Grey";
			case 4:
				return "Black";
			default:
				return "FoorType";
			}
		}
		case AT_MuleDeer:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Blonde";
			case 1:
				return "Dilute";
			case 2:
				return "Melanistic";
			case 3:
				return "Grey";
			case 4:
				return "Piebald";
			case 5:
				return "Piebald";
			case 6:
				return "Brown";
			case 7:
				return "Albino";
			default:
				return "FoorType";
			}
		}
		case AT_Puma:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Dark Red";
			case 1:
				return "Albino";
			case 2:
				return "Melanistic";
			case 3:
				return "Light Brown";
			case 4:
				return "Grey";
			default:
				return "FoorType";
			}
		}
		case AT_Blackbuck:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Dark";
			case 1:
				return "Leucistic";
			case 2:
				return "Melanistic";
			case 3:
				return "Brown";
			case 4:
				return "Black";
			default:
				return "FoorType";
			}
		}
		case AT_AxisDeer:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Orange";
			case 1:
				return "Dark";
			case 2:
				return "Piebald";
			case 3:
				return "Melanistic";
			case 4:
				return "Spotted";
			case 5:
				return "Albino";
			default:
				return "FoorType";
			}
		}
		case AT_CinnamonTeal:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Melanistic";
			case 1:
				return "Piebald";
			case 2:
				return "Beige";
			case 3:
				return "Cinnamon";
			case 4:
				return "Red";
			default:
				return "FoorType";
			}
		}
		case AT_PlainsBison:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Light Grey";
			case 1:
				return "Dark";
			case 2:
				return "Leucistic";
			case 3:
				return "Albino";
			case 4:
				return "Melanistic";
			case 5:
				return "Brown";
			case 6:
				return "Light Brown";
			default:
				return "FoorType";
			}
		}
		case AT_GrizzlyBear:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Melanistic";
			case 1:
				return "Albino";
			case 2:
				return "Gray Brown";
			case 3:
				return "Brown";
			case 4:
				return "Brown";
			default:
				return "FoorType";
			}
		}
		case AT_Caribou:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Melanistic";
			case 1:
				return "Leucistic";
			case 2:
				return "Piebald";
			case 3:
				return "Albino";
			case 4:
				return "Light Brown";
			case 5:
				return "Dark Brown";
			default:
				return "FoorType";
			}
		}
		case AT_GrayWolf:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Melanistic";
			case 1:
				return "Albino";
			case 2:
				return "Eggwhite";
			case 3:
				return "Red Brown";
			case 4:
				return "Grey";
			case 5:
				return "Dark Grey";
			default:
				return "FoorType";
			}
		}
		case AT_HarlequinDuck:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Dark";
			case 1:
				return "Piebald";
			case 2:
				return "Melanistic";
			case 3:
				return "Albino";
			case 4:
				return "Grey";
			case 5:
				return "Dark Grey";
			case 6:
				return "Dark Brown";
			default:
				return "FoorType";
			}
		}
		case AT_IberianWolf:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Pristine";
			case 1:
				return "Olive";
			case 2:
				return "Albino";
			case 3:
				return "Winter";
			case 4:
				return "Sombra";
			case 5:
				return "Melanistic";
			case 6:
				return "Fantasma";
			case 7:
				return "Gray Brown";
			case 8:
				return "Ogro";
			case 9:
				return "Grey";
			default:
				return "FoorType";
			}
		}
		case AT_SoutheasternSpanishIbex:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Gray Brown";
			case 1:
				return "Albino";
			case 2:
				return "Light Grey";
			case 3:
				return "Melanistic";
			case 4:
				return "Light Brown";
			case 5:
				return "Buff";
			case 6:
				return "Brown Hybrid";
			case 7:
				return "Orange";
			default:
				return "FoorType";
			}
		}
		case AT_RondaIbex:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Gray Brown";
			case 1:
				return "Albino";
			case 2:
				return "Brown Hybrid";
			case 3:
				return "Melanistic";
			case 4:
				return "Buff";
			case 5:
				return "Light Brown";
			case 6:
				return "Brown";
			case 7:
				return "Grey";
			default:
				return "FoorType";
			}
		}
		case AT_BeceiteIbex:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Buff";
			case 1:
				return "Grey";
			case 2:
				return "Albino";
			case 3:
				return "Orange";
			case 4:
				return "Melanistic";
			case 5:
				return "Brown Hybrid";
			case 6:
				return "Gray Brown";
			case 7:
				return "Light Brown";
			default:
				return "FoorType";
			}
		}
		case AT_GredosIbex:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Gray Brown";
			case 1:
				return "Albino";
			case 2:
				return "Brown Hybrid";
			case 3:
				return "Melanistic";
			case 4:
				return "Light Brown";
			case 5:
				return "Buff";
			case 6:
				return "Light Grey";
			case 7:
				return "Grey";
			default:
				return "FoorType";
			}
		}
		case AT_IberianMuflon:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Light Brown";
			case 1:
				return "Grey";
			case 2:
				return "Albino";
			case 3:
				return "Brown";
			case 4:
				return "Brown";
			case 5:
				return "Melanistic";
			default:
				return "FoorType";
			}
		}
		case AT_EuroHare:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Dark Brown";
			case 1:
				return "Grey";
			case 2:
				return "Albino";
			case 3:
				return "Melanistic";
			case 4:
				return "Brown";
			case 5:
				return "Light Brown";
			default:
				return "FoorType";
			}
		}
		case AT_RockyMountainElk:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Brown";
			case 1:
				return "Light Grey";
			case 2:
				return "Piebald";
			case 3:
				return "Piebald";
			case 4:
				return "Albino";
			case 5:
				return "Light Brown";
			default:
				return "FoorType";
			}
		}
		case AT_MountainLion:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Dark Red";
			case 1:
				return "Albino";
			case 2:
				return "Melanistic";
			case 3:
				return "Light Brown";
			case 4:
				return "Grey";
			default:
				return "FoorType";
			}
		}
		case AT_Pronghorn:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Tan";
			case 1:
				return "Dark";
			case 2:
				return "Leucistic";
			case 3:
				return "Piebald";
			case 4:
				return "Piebald";
			case 5:
				return "Albino";
			case 6:
				return "Brown";
			default:
				return "FoorType";
			}
		}
		case AT_MountainGoat:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Beige";
			case 1:
				return "Light Brown";
			case 2:
				return "White";
			case 3:
				return "Melanistic";
			case 4:
				return "Albino";
			case 5:
				return "Light Grey";
			default:
				return "FoorType";
			}
		}
		case AT_BighornSheep:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Black";
			case 1:
				return "Bronze";
			case 2:
				return "Gray Brown";
			case 3:
				return "Albino";
			case 4:
				return "Brown";
			default:
				return "FoorType";
			}
		}
		case AT_MerriamTurkey:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Brown";
			case 1:
				return "Albino";
			case 2:
				return "Light Brown";
			case 3:
				return "Leucistic";
			case 4:
				return "Melanistic";
			case 5:
				return "Dark Brown";
			default:
				return "FoorType";
			}
		}
		case AT_SikaDeer:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Black";
			case 1:
				return "Spotted Dark";
			case 2:
				return "Spotted Red";
			case 3:
				return "Spotted";
			case 4:
				return "Brown";
			case 5:
				return "Albino";
			default:
				return "FoorType";
			}
		}
		case AT_FeralPig:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Albino";
			case 1:
				return "Pink";
			case 2:
				return "Black Spots";
			case 3:
				return "Black Spots";
			case 4:
				return "Dark Brown";
			case 5:
				return "Brown Hybrid";
			case 6:
				return "Brown Hybrid";
			case 7:
				return "Black Gold";
			case 8:
				return "Brown";
			case 9:
				return "Brown";
			default:
				return "FoorType";
			}
		}
		case AT_FeralGoat:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Black";
			case 1:
				return "Black White";
			case 2:
				return "Albino";
			case 3:
				return "Black Brown";
			case 4:
				return "Blonde";
			case 5:
				return "Dark Brown";
			case 6:
				return "White";
			case 7:
				return "Brown";
			case 8:
				return "Mixed";
			case 9:
				return "Mixed";
			case 10:
				return "White Brown";
			default:
				return "FoorType";
			}
		}
		case AT_Chamois:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Brown";
			case 1:
				return "Gray Brown";
			case 2:
				return "Honeytones";
			case 3:
				return "Leucistic";
			case 4:
				return "Melanistic";
			case 5:
				return "Albino";
			case 6:
				return "Dark Brown";
			default:
				return "FoorType";
			}
		}
		case AT_CollaredPeccary:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Grey";
			case 1:
				return "Brown";
			case 2:
				return "Leucistic";
			case 3:
				return "Ochre";
			case 4:
				return "Dark Brown";
			case 5:
				return "Dark Grey";
			case 6:
				return "Albino";
			case 7:
				return "Melanistic";
			default:
				return "FoorType";
			}
		}
		case AT_MexicanBobcat:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Grey";
			case 1:
				return "Albino";
			case 2:
				return "Blue";
			case 3:
				return "Brown";
			case 4:
				return "Melanistic";
			case 5:
				return "Red";
			case 6:
				return "Tan";
			default:
				return "FoorType";
			}
		}
		case AT_RioGrandeTurkey:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Brown";
			case 1:
				return "Albino";
			case 2:
				return "Brown";
			case 3:
				return "Leucistic";
			case 4:
				return "Melanistic";
			case 5:
				return "Buff";
			case 6:
				return "Light Buff";
			default:
				return "FoorType";
			}
		}
		case AT_RingNeckedPheasant:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Brown";
			case 1:
				return "Grey";
			case 2:
				return "White Brown";
			case 3:
				return "Leucistic";
			case 4:
				return "Molting";
			case 5:
				return "Albino";
			case 6:
				return "Melanistic";
			case 7:
				return "Grey";
			default:
				return "FoorType";
			}
		}
		case AT_AntelopeJackrabbit:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Brown";
			case 1:
				return "Grey";
			case 2:
				return "Dark Brown";
			case 3:
				return "Mottled";
			case 4:
				return "Albino";
			case 5:
				return "Melanistic";
			default:
				return "FoorType";
			}
		}
		case AT_AmericanAlligator:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Olive";
			case 1:
				return "Dark Brown";
			case 2:
				return "Piebald";
			case 3:
				return "Piebald";
			case 4:
				return "Piebald";
			case 5:
				return "Piebald";
			case 6:
				return "Piebald";
			case 7:
				return "Melanistic";
			case 8:
				return "Albino";
			default:
				return "FoorType";
			}
		}
		case AT_WildHog:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Albino";
			case 1:
				return "Pink";
			case 2:
				return "Black Spots";
			case 3:
				return "Black Spots";
			case 4:
				return "Dark Brown";
			case 5:
				return "Brown Hybrid";
			case 6:
				return "Brown Hybrid";
			case 7:
				return "Black Gold";
			case 8:
				return "Brown";
			case 9:
				return "Brown";
			default:
				return "FoorType";
			}
		}
		case AT_GrayFox:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Grey";
			case 1:
				return "Red";
			case 2:
				return "Two Tone";
			case 3:
				return "Albino";
			case 4:
				return "Melanistic";
			case 5:
				return "Leucistic";
			case 6:
				return "Piebald";
			case 7:
				return "Piebald";
			default:
				return "FoorType";
			}
		}
		case AT_CommonRaccoon:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Brown";
			case 1:
				return "Blonde";
			case 2:
				return "Grey";
			case 3:
				return "Blonde";
			case 4:
				return "Piebald Grey";
			case 5:
				return "Albino";
			case 6:
				return "Melanistic";
			default:
				return "FoorType";
			}
		}
		case AT_EasternWildTurkey:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Brown";
			case 1:
				return "Albino";
			case 2:
				return "Light Brown";
			case 3:
				return "Leucistic";
			case 4:
				return "Melanistic";
			case 5:
				return "Bronze";
			case 6:
				return "Light Bronze";
			default:
				return "FoorType";
			}
		}
		case AT_EasternCottontailRabbit:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Brown";
			case 1:
				return "Light Brown";
			case 2:
				return "Grey";
			case 3:
				return "Leucistic";
			case 4:
				return "Leucistic";
			case 5:
				return "Light Grey";
			case 6:
				return "Melanistic";
			case 7:
				return "Albino";
			default:
				return "FoorType";
			}
		}
		case AT_BobwhiteQuail:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Brown";
			case 1:
				return "Red Brown";
			case 2:
				return "Grey";
			case 3:
				return "Albino";
			case 4:
			default:
				return "FoorType";
			}
		}
		case AT_EurasianWigeon:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Brown";
			case 1:
				return "Grey";
			case 2:
				return "Brown";
			case 3:
				return "Eclipse";
			case 4:
				return "Hybrid";
			case 5:
				return "Dark";
			case 6:
				return "Grey";
			case 7:
				return "Leucistic";
			case 8:
				return "Leucistic";
			default:
				return "FoorType";
			}
		}
		case AT_TundraBeanGoose:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Brown";
			case 1:
				return "Dark Grey";
			case 2:
				return "Light Grey";
			case 3:
				return "Leucistic";
			case 4:
				return "Leucistic";
			case 5:
				return "Leucistic";
			default:
				return "FoorType";
			}
		}
		case AT_EurasianTeal:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Light Green";
			case 1:
				return "Brown";
			case 2:
				return "Dark Green";
			case 3:
				return "Hybrid Blue";
			case 4:
				return "Hybrid Green";
			case 5:
				return "Leucistic";
			case 6:
				return "Leucistic";
			case 7:
				return "Leucistic";
			default:
				return "FoorType";
			}
		}
		case AT_BlackGrouse:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Dark";
			case 1:
				return "Brown";
			case 2:
				return "Gold";
			case 3:
				return "Dark";
			case 4:
				return "Orange";
			case 5:
				return "Leucistic";
			case 6:
				return "Leucistic";
			case 7:
				return "Leucistic";
			case 8:
				return "Melanistic";
			case 9:
				return "Melanistic";
			default:
				return "FoorType";
			}
		}
		case AT_Goldeneye:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Black";
			case 1:
				return "Grey";
			case 2:
				return "Dark";
			case 3:
				return "Eclipse";
			case 4:
				return "Hybrid";
			case 5:
				return "Hybrid";
			case 6:
				return "Leucistic";
			case 7:
				return "Leucistic";
			default:
				return "FoorType";
			}
		}
		case AT_HazelGrouse:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Brown";
			case 1:
				return "Grey";
			case 2:
				return "Dark";
			case 3:
				return "Hybrid";
			case 4:
				return "Pale";
			case 5:
				return "Ochre";
			case 6:
				return "Dark";
			case 7:
				return "Light Brown";
			default:
				return "FoorType";
			}
		}
		case AT_WesternCapercaillie:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Brown";
			case 1:
				return "Dark";
			case 2:
				return "Leucistic";
			case 3:
				return "Leucistic";
			case 4:
				return "Pale";
			case 5:
				return "Bright";
			case 6:
				return "Ochre";
			default:
				return "FoorType";
			}
		}
		case AT_TuftedDuck:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Black";
			case 1:
				return "Brown";
			case 2:
				return "Eclipse";
			case 3:
				return "Cream";
			case 4:
				return "Leucistic";
			case 5:
				return "Leucistic";
			case 6:
				return "Albino";
			default:
				return "FoorType";
			}
		}
		case AT_RockPtarmigan:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Bicolor";
			case 1:
				return "Mottled";
			case 2:
				return "Mottled";
			case 3:
				return "Molting";
			case 4:
				return "Molting";
			case 5:
				return "White";
			default:
				return "FoorType";
			}
		}
		case AT_WillowPtarmigan:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Bicolor";
			case 1:
				return "Bicolor";
			case 2:
				return "Brown";
			case 3:
				return "Molting";
			case 4:
				return "Molting";
			case 5:
				return "White";
			case 6:
				return "Red";
			default:
				return "FoorType";
			}
		}
		case AT_GreylagGoose:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Brown";
			case 1:
				return "Grey";
			case 2:
				return "Hybrid";
			case 3:
				return "Leucistic";
			case 4:
				return "Leucistic";
			case 5:
				return "Leucistic";
			case 6:
				return "Leucistic";
			case 7:
				return "Leucistic";
			default:
				return "FoorType";
			}
		}
		case AT_MountainHare:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Dark Grey";
			case 1:
				return "Dark Brown";
			case 2:
				return "Light Grey";
			case 3:
				return "Light Brown";
			case 4:
				return "Molting";
			case 5:
				return "Molting";
			case 6:
				return "White";
			case 7:
				return "Albino";
			default:
				return "FoorType";
			}
		}
		case AT_RaccoonDog:
		{
			switch (m_fur_type_id)
			{
			case 0:
				return "Light Brown";
			case 1:
				return "Grey";
			case 2:
				return "Black White";
			case 3:
				return "Orange";
			case 4:
				return "Dark Brown";
			case 5:
				return "Piebald";
			case 6:
				return "Piebald";
			case 7:
				return "Albino";
			default:
				return "FoorType";
			}
		}
		default:
			return "FoorType";
		};
	}

	bool Animal::VerifyGender() const
	{
		return (m_gender == 1 && m_str_gender == "male") || (m_gender == 2 && m_str_gender == "female");
	}

	bool Animal::VerifyWeight() const
	{
		return true;
	}

	bool Animal::VerifyScore() const
	{
		return true;
	}

	bool Animal::VerifyVisualVariationSeed()
	{
		return true;
	}

	bool Animal::Verify() const
	{
		return VerifyGender() && VerifyWeight() && VerifyScore() && VerifyVisualVariationSeed();
	}

	void Animal::SetGenderBytes()
	{
		std::vector<char> data(sizeof(int32_t));
		std::memcpy(data.data(), &this->m_gender, sizeof(m_gender));
		this->gender_bytes = data;
	}

	void Animal::SetWeightBytes()
	{
		std::vector<char> data(sizeof(int32_t));
		std::memcpy(data.data(), &this->m_weight, sizeof(m_weight));
		this->weight_bytes = data;
	}

	void Animal::SetScoreBytes()
	{
		std::vector<char> data(sizeof(int32_t));
		std::memcpy(data.data(), &this->m_score, sizeof(m_score));
		this->score_bytes = data;
	}

	void Animal::SetIsGreatOneBytes()
	{
		std::vector<char> data(sizeof(int32_t));
		std::memcpy(data.data(), &this->m_is_great_one, sizeof(m_is_great_one));
		this->is_great_one_bytes = data;
	}

	void Animal::SetVisualVariationSeedBytes()
	{
		std::vector<char> data(sizeof(int32_t));
		std::memcpy(data.data(), &this->m_visual_variation_seed, sizeof(m_visual_variation_seed));
		this->visual_variation_seed_bytes = data;
	}

	std::ostream& operator<<(std::ostream& out, const Animal& data)
	{
		out << "[ " << std::setw(2) << data.m_idx
			<< " | " << std::setw(6) << data.m_str_gender
			<< " | " << std::setw(7) << data.m_weight
			<< " | " << std::setw(8) << data.m_score
			<< " | " << std::setw(1) << static_cast<int>(data.m_is_great_one)
			<< " | " << std::setw(15) << data.m_fur_type
			<< " | " << std::setw(2) << static_cast<unsigned int>(data.m_fur_type_id)
			<< " ]\n";
		return out;
	}
}
