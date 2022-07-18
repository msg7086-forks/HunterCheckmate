#include "Animal.h"

namespace HunterCheckmate_FileAnalyzer
{
	Animal::Animal(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
	{
		m_animal_type = animal_type;
		m_name = "Unknown";
		SetGender(gender);
		SetWeight(weight);
		SetScore(score);
		SetIsGreatOne(is_great_one);
		SetVisualVariationSeed(visual_variation_seed);
		SetFurType(visual_variation_seed);
		SetIdx(idx);
		m_grp_idx = grp_idx;
		m_valid = false;
		SetGenderBytes();
		SetWeightBytes();
		SetScoreBytes();
		SetIsGreatOneBytes();
		SetVisualVariationSeedBytes();
	}

	std::shared_ptr<Animal> Animal::Create(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx, uint32_t grp_idx)
	{
		switch (animal_type)
		{
		case AT_WildBoar:
			return std::make_shared<WildBoar>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_FallowDeer:
			return std::make_shared<FallowDeer>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_EuBison:
			return std::make_shared<EuroBison>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_RoeDeer:
			return std::make_shared<RoeDeer>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_RedFox:
			return std::make_shared<RedFox>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_CanadaGoose:
			return std::make_shared<CanadaGoose>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_RedDeer:
			return std::make_shared<RedDeer>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_EuRabbit:
			return std::make_shared<EuroRabbit>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_Moose:
			return std::make_shared<Moose>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_Jackrabbit:
			return std::make_shared<Jackrabbit>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_Mallard:
			return std::make_shared<Mallard>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_BlackBear:
			return std::make_shared<BlackBear>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_RooseveltElk:
			return std::make_shared<RooseveltElk>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_Coyote:
			return std::make_shared<Coyote>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_Blacktail:
			return std::make_shared<BlacktailDeer>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_Whitetail:
			return std::make_shared<WhitetailDeer>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_SiberianMuskDeer:
			return std::make_shared<MuskDeer>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_Reindeer:
			return std::make_shared<Reindeer>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_EurasianLynx:
			return std::make_shared<EurasianLynx>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_EurasianBrownBear:
			return std::make_shared<BrownBear>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_BlueWildebeest:
			return std::make_shared<BlueWildebeest>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_SidestripedJackal:
			return std::make_shared<SideStripedJackal>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_Gemsbok:
			return std::make_shared<Gemsbok>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_LesserKudu:
			return std::make_shared<LesserKudu>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_ScrubHare:
			return std::make_shared<ScrubHare>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_Lion:
			return std::make_shared<Lion>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_Warthog:
			return std::make_shared<Warthog>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_CapeBuffalo:
			return std::make_shared<CapeBuffalo>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_Springbok:
			return std::make_shared<Springbok>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_WaterBuffalo:
			return std::make_shared<WaterBuffalo>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_Puma:
			return std::make_shared<Puma>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_Blackbuck:
			return std::make_shared<Blackbuck>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_CinnamonTeal:
			return std::make_shared<CinnamonTeal>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_MuleDeer:
			return std::make_shared<MuleDeer>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_AxisDeer:
			return std::make_shared<AxisDeer>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_HarlequinDuck:
			return std::make_shared<HarlequinDuck>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_Caribou:
			return std::make_shared<Caribou>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_GrizzlyBear:
			return std::make_shared<GrizzlyBear>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_GrayWolf:
			return std::make_shared<GrayWolf>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_PlainsBison:
			return std::make_shared<PlainsBison>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_SoutheasternIbex:
			return std::make_shared<SoutheasternSpanishIbex>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_IberianWolf:
			return std::make_shared<IberianWolf>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_IberianMouflon:
			return std::make_shared<IberianMuflon>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_BeceiteIbex:
			return std::make_shared<BeceiteIbex>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_EuHare:
			return std::make_shared<EuroHare>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_RondaIbex:
			return std::make_shared<RondaIbex>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_GredosIbex:
			return std::make_shared<GredosIbex>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_ProngHorn:
			return std::make_shared<Pronghorn>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_MountainLion:
			return std::make_shared<MountainLion>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_MountainGoat:
			return std::make_shared<MountainGoat>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_BighornSheep:
			return std::make_shared<BighornSheep>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_WildTurkey:
			return std::make_shared<MerriamTurkey>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_RockymountainElk:
			return std::make_shared<RockyMountainElk>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_SikaDeer:
			return std::make_shared<SikaDeer>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_Chamois:
			return std::make_shared<Chamois>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_FeralPig:
			return std::make_shared<FeralPig>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_FeralGoat:
			return std::make_shared<FeralGoat>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_CollaredPeccary:
			return std::make_shared<CollaredPeccary>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_MexicanBobcat:
			return std::make_shared<MexicanBobcat>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_RioGrandeTurkey:
			return std::make_shared<RioGrandeTurkey>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_Pheasant:
			return std::make_shared<RingNeckedPheasant>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_AntelopeJackrabbit:
			return std::make_shared<AntelopeJackrabbit>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_AmericanAlligator:
			return std::make_shared<AmericanAlligator>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_WildHog:
			return std::make_shared<WildHog>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_GrayFox:
			return std::make_shared<GrayFox>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_Raccoon:
			return std::make_shared<CommonRaccoon>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_EasternWildTurkey:
			return std::make_shared<EasternWildTurkey>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_EasternCottontailRabbit:
			return std::make_shared<EasternCottontailRabbit>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_NorthernBobwhiteQuail:
			return std::make_shared<BobwhiteQuail>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_RaccoonDog:
			return std::make_shared<RaccoonDog>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_EurasianWigeon:
			return std::make_shared<EurasianWigeon>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_TundraBeanGoose:
			return std::make_shared<TundraBeanGoose>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_EurasianTeal:
			return std::make_shared<EurasianTeal>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_BlackGrouse:
			return std::make_shared<BlackGrouse>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_Goldeneye:
			return std::make_shared<Goldeneye>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_HazelGrouse:
			return std::make_shared<HazelGrouse>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_WesternCapercaillie:
			return std::make_shared<WesternCapercaillie>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_TuftedDuck:
			return std::make_shared<TuftedDuck>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_RockPtarmigan:
			return std::make_shared<RockPtarmigan>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_WillowPtarmigan:
			return std::make_shared<WillowPtarmigan>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_GreylagGoose:
			return std::make_shared<GreylagGoose>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_MountainHare:
			return std::make_shared<MountainHare>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		case AT_None:
		default:
			return std::make_shared<Animal>(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx, grp_idx);
		}
	}

	std::vector<char> Animal::GetByteStream()
	{
		std::vector<char> data;
		data.insert(data.end(), this->gender_bytes.begin(), this->gender_bytes.end());
		data.insert(data.end(), this->weight_bytes.begin(), this->weight_bytes.end());
		data.insert(data.end(), this->score_bytes.begin(), this->score_bytes.end());
		data.insert(data.end(), this->is_great_one_bytes.begin(), this->is_great_one_bytes.end());
		data.insert(data.end(), this->visual_variation_seed_bytes.begin(), this->visual_variation_seed_bytes.end());
		return data;
	}

	float Animal::GetMaxWeight()
	{
		return 0.0f;
	}

	float Animal::GetMaxScore()
	{
		return 0.0f;
	}

	float Animal::GetMinWeight()
	{
		return 0.f;
	}

	float Animal::GetMinScore()
	{
		return 0.f;
	}
	
	AnimalType Animal::ResolveAnimalType(std::string& name)
	{
		bs::to_lower(name);
		if (name.find("boar") != std::string::npos) return AT_WildBoar;
		if (name.find("fallow") != std::string::npos) return AT_FallowDeer;
		if (name.find("eu") != std::string::npos && name.find("bison") != std::string::npos) return AT_EuBison;
		if (name.find("roe") != std::string::npos) return AT_RoeDeer;
		if (name.find("red") != std::string::npos && name.find("fox") != std::string::npos) return AT_RedFox;
		if (name.find("goose") != std::string::npos && !(name.find("bean") != std::string::npos) && !(name.find("tundra") != std::string::npos)) return AT_CanadaGoose;
		if (name.find("red") != std::string::npos && name.find("deer") != std::string::npos) return AT_RedDeer;
		if (name.find("eu") != std::string::npos && name.find("rabbit") != std::string::npos) return AT_EuRabbit;
		if (name.find("moose") != std::string::npos) return AT_Moose;
		if (name.find("jackrabbit") != std::string::npos && !(name.find("antelope") != std::string::npos)) return AT_Jackrabbit;
		if (name.find("mallard") != std::string::npos) return AT_Mallard;
		if (name.find("black") != std::string::npos && name.find("bear") != std::string::npos) return AT_BlackBear;
		if (name.find("roosevelt") != std::string::npos) return AT_RooseveltElk;
		if (name.find("coyote") != std::string::npos) return AT_Coyote;
		if (name.find("blacktail") != std::string::npos) return AT_Blacktail;
		if (name.find("whitetail") != std::string::npos) return AT_Whitetail;
		if (name.find("musk") != std::string::npos) return AT_SiberianMuskDeer;
		if (name.find("reindeer") != std::string::npos) return AT_Reindeer;
		if (name.find("lynx") != std::string::npos) return AT_EurasianLynx;
		if (name.find("brown") != std::string::npos && name.find("bear") != std::string::npos) return AT_EurasianBrownBear;
		if (name.find("wildebeest") != std::string::npos) return AT_BlueWildebeest;
		if (name.find("jackal") != std::string::npos) return AT_SidestripedJackal;
		if (name.find("gemsbok") != std::string::npos) return AT_Gemsbok;
		if (name.find("kudu") != std::string::npos) return AT_LesserKudu;
		if (name.find("hare") != std::string::npos && name.find("scrub") != std::string::npos) return AT_ScrubHare;
		if (name.find("lion") != std::string::npos && !(name.find("mountain") != std::string::npos)) return AT_Lion;
		if (name.find("warthog") != std::string::npos) return AT_Warthog;
		if (name.find("cape") != std::string::npos && name.find("buffalo") != std::string::npos) return AT_CapeBuffalo;
		if (name.find("springbok") != std::string::npos) return AT_Springbok;
		if (name.find("water") != std::string::npos) return AT_WaterBuffalo;
		if (name.find("puma") != std::string::npos) return AT_Puma;
		if (name.find("blackbuck") != std::string::npos) return AT_Blackbuck;
		if (name.find("cinnamon") != std::string::npos) return AT_CinnamonTeal;
		if (name.find("mule") != std::string::npos) return AT_MuleDeer;
		if (name.find("axis") != std::string::npos) return AT_AxisDeer;
		if (name.find("harlequin") != std::string::npos) return AT_HarlequinDuck;
		if (name.find("caribou") != std::string::npos) return AT_Caribou;
		if (name.find("grizzly") != std::string::npos) return AT_GrizzlyBear;
		if (name.find("gray") != std::string::npos && name.find("wolf") != std::string::npos) return AT_GrayWolf;
		if (name.find("plains") != std::string::npos) return AT_PlainsBison;
		if (name.find("south") != std::string::npos && name.find("ibex") != std::string::npos) return AT_SoutheasternIbex;
		if (name.find("iberian") != std::string::npos && name.find("wolf") != std::string::npos) return AT_IberianWolf;
		if (name.find("muflon") != std::string::npos) return AT_IberianMouflon;
		if (name.find("beceite") != std::string::npos) return AT_BeceiteIbex;
		if (name.find("eu") != std::string::npos && name.find("hare") != std::string::npos) return AT_EuHare;
		if (name.find("ronda") != std::string::npos) return AT_RondaIbex;
		if (name.find("gredos") != std::string::npos) return AT_GredosIbex;
		if (name.find("pronghorn") != std::string::npos) return AT_ProngHorn;
		if (name.find("mountain") != std::string::npos && name.find("lion") != std::string::npos) return AT_MountainLion;
		if (name.find("mountain") != std::string::npos && name.find("goat") != std::string::npos) return AT_MountainGoat;
		if (name.find("bighorn") != std::string::npos) return AT_BighornSheep;
		if (name.find("merriam") != std::string::npos && name.find("turkey") != std::string::npos) return AT_WildTurkey;
		if (name.find("rocky") != std::string::npos) return AT_RockymountainElk;
		if (name.find("sika") != std::string::npos) return AT_SikaDeer;
		if (name.find("chamois") != std::string::npos) return AT_Chamois;
		if (name.find("pig") != std::string::npos) return AT_FeralPig;
		if (name.find("feral") != std::string::npos && name.find("goat") != std::string::npos) return AT_FeralGoat;
		if (name.find("peccary") != std::string::npos || name.find("collared") != std::string::npos) return AT_CollaredPeccary;
		if (name.find("bobcat") != std::string::npos) return AT_MexicanBobcat;
		if (name.find("rio") != std::string::npos && name.find("turkey") != std::string::npos) return AT_RioGrandeTurkey;
		if (name.find("pheasant") != std::string::npos) return AT_Pheasant;
		if (name.find("antelope") != std::string::npos && name.find("jackrabbit") != std::string::npos) return AT_AntelopeJackrabbit;
		if (name.find("alligator") != std::string::npos) return AT_AmericanAlligator;
		if (name.find("wild") != std::string::npos && name.find("hog") != std::string::npos) return AT_WildHog;
		if (name.find("gray") != std::string::npos && name.find("fox") != std::string::npos) return AT_GrayFox;
		if (name.find("raccoon") != std::string::npos && !(name.find("dog") != std::string::npos)) return AT_Raccoon;
		if (name.find("eastern") != std::string::npos && name.find("turkey") != std::string::npos) return AT_EasternWildTurkey;
		if (name.find("cottontail") != std::string::npos && name.find("rabbit") != std::string::npos) return AT_EasternCottontailRabbit;
		if (name.find("quail") != std::string::npos) return AT_NorthernBobwhiteQuail;
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

	bool Animal::IsValid() const
	{
		return m_valid;
	}

	void Animal::SetGender(const std::string& gender)
	{
		if (gender == "male")
		{
			m_gender_id = 1;
			m_gender = "male";
		}
		else if (gender == "female")
		{
			m_gender_id = 2;
			m_gender = "female";
		}
		else
		{
			m_gender_id = MAXINT8;
			m_gender = "foomale";
		}
	}

	void Animal::SetGender(const uint8_t gender)
	{
		if (gender == 1)
		{
			m_gender_id = 1;
			m_gender = "male";
		}
		if (gender == 2)
		{
			m_gender_id = 2;
			m_gender = "female";
		}
	}

	void Animal::SetWeight(const float weight)
	{
		m_weight = weight;
	}

	void Animal::SetScore(const float score)
	{
		m_score = score;
	}

	void Animal::SetIsGreatOne(const bool is_great_one) 
	{
		if (is_great_one == true || is_great_one == 1)
		{
			m_is_great_one = 1;
		}
		else if (is_great_one == false || is_great_one == 0)
		{
			m_is_great_one = 0;
		}
		else
		{
			m_is_great_one = MAXUINT8;
		}
	}

	void Animal::SetIdx(const uint32_t idx)
	{
		m_idx = idx;
	}

	void Animal::SetVisualVariationSeed(const uint32_t visual_variation_seed)
	{
		m_visual_variation_seed = visual_variation_seed;
	}

	FurEntry* Animal::GetFurEntryFromDB(const AnimalType animal_type, const std::string& gender)
	{
		FurEntry* fur_entry = nullptr;
		if (gender == "male")
			fur_entry = &fur_db.at(animal_type).at(0);
		else if (gender == "female")
			fur_entry = &fur_db.at(animal_type).at(1);

		return fur_entry;
	}

	void Animal::SetFurType(const uint32_t visual_variation_seed)
	{
		uint32_t converted_probability = (((0x343FD * visual_variation_seed + 0x269EC3) >> 16) | 0x3F8000) << 8;
		float fl_probability;
		std::memcpy(&fl_probability, &converted_probability, sizeof(float));
		fl_probability = abs(fl_probability);
		fl_probability -= 1.f;

		std::shared_ptr<FurEntry> fur_entry;
		if (m_gender == "male")
			fur_entry = std::make_shared<FurEntry>(fur_db.at(m_animal_type).at(0));
		else if (m_gender == "female")
			fur_entry = std::make_shared<FurEntry>(fur_db.at(m_animal_type).at(1));

		if (fur_entry != nullptr)
		{
			float sum = 0.f;
			auto it_fur_type = fur_entry->fur_types.begin();
			for (; it_fur_type != fur_entry->fur_types.end(); ++it_fur_type)
			{
				sum += (static_cast<float>(it_fur_type->fur_probability) / static_cast<float>(fur_entry->max_probability));
				if (sum >= fl_probability)
				{
					m_fur_type_id = it_fur_type->fur_idx;
					m_fur_type = it_fur_type->fur_name;
					return;
				}
			}
		}

		m_fur_type_id = 69;
		m_fur_type = "FoorType";
	}
	
	uint32_t Animal::CreateVisualVariationSeed(const AnimalType animal_type, const std::string& str_gender, const std::string& fur_type) 
	{
		uint32_t visual_variation_seed = 10000000;
		FurEntry* fe = GetFurEntryFromDB(animal_type, str_gender);
		if (fe == nullptr)
			return 0;

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distr(10000000, 4000000000);
		while (true)
		{
			visual_variation_seed = distr(gen);
			uint32_t converted_probability = (((0x343FD * visual_variation_seed + 0x269EC3) >> 16) | 0x3F8000) << 8;
			float fl_probability;
			std::memcpy(&fl_probability, &converted_probability, sizeof(float));
			fl_probability = abs(fl_probability);
			fl_probability -= 1.f;
			float sum = 0.f;

			auto it_fur_type = fe->fur_types.begin();
			for (; it_fur_type != fe->fur_types.end(); ++it_fur_type)
			{
				sum += (static_cast<float>(it_fur_type->fur_probability) / static_cast<float>(fe->max_probability));
				if (sum >= fl_probability)
				{
					if (it_fur_type->fur_name == fur_type)
						return visual_variation_seed;
					else
						break;
				}
			}
		}

		return visual_variation_seed;
	}
	
	std::string Animal::ResolveGender(const uint8_t gender_id)
	{
		if (gender_id == 1)
			return "male";
		if (gender_id == 2)
			return "female";
		return "foomale";
	}
	
	uint8_t Animal::ResolveGender(const std::string& gender)
	{
		if (gender == "male")
			return 1;
		if (gender == "female")
			return 2;
		return MAXUINT8;
	}

	bool Animal::VerifyGender() const
	{
		return (m_gender_id == 1 && m_gender == "male") || (m_gender_id == 2 && m_gender == "female");
	}

	bool Animal::VerifyWeight() const
	{
		return true;
	}

	bool Animal::VerifyScore() const
	{
		return true;
	}

	bool Animal::VerifyVisualVariationSeed() const
	{
		return (m_visual_variation_seed > 0 && m_visual_variation_seed < MAXUINT32);
	}

	bool Animal::Verify() const
	{
		return VerifyGender() && VerifyWeight() && VerifyScore() && VerifyVisualVariationSeed();
	}

	void Animal::SetGenderBytes()
	{
		std::vector<char> data(sizeof(int32_t));
		std::memcpy(data.data(), &this->m_gender_id, sizeof(m_gender_id));
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
			<< " | " << std::setw(6) << data.m_gender
			<< " | " << std::setw(7) << data.m_weight
			<< " | " << std::setw(8) << data.m_score
			<< " | " << std::setw(1) << static_cast<int>(data.m_is_great_one)
			<< " | " << std::setw(15) << data.m_fur_type
			<< " | " << std::setw(2) << static_cast<unsigned int>(data.m_fur_type_id)
			<< " | " << std::setw(10) << data.m_visual_variation_seed
			<< " ]\n";
		return out;
	}
}
