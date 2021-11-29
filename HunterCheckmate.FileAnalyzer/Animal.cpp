#include "Animal.h"

namespace HunterCheckmate_FileAnalyzer
{
	/*Animal::Animal(std::shared_ptr<ReserveData> reserve_data)
		: m_reserve_data(std::move(reserve_data)) {}

	Animal::Animal(std::shared_ptr<ReserveData> reserve_data, std::string& name, std::string& gender, std::string& weight,
		std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: m_reserve_data(std::move(reserve_data))
	{
		SetNameHash(name);
		SetName(name);
		SetGender(gender);
		SetWeight(weight);
		SetScore(score);
		SetIsGreatOne(is_great_one);
		SetVisualVariationSeed(visual_variation_seed);
		m_valid = true;
	}*/

	Animal::Animal(std::string gender, std::string weight, std::string score, std::string is_great_one, std::string visual_variation_seed)
	{
		m_name_hash = {};
		m_name = {};
		m_gender = ResolveGender(gender);
		m_str_gender = ResolveGender(m_gender);
		m_weight = ResolveWeight(weight);
		m_score = ResolveScore(score);
		m_is_great_one = ResolveIsGreatOne(is_great_one);
		m_visual_variation_seed = ResolveVisualVariationSeed(visual_variation_seed);
		m_str_visual_variation_seed = ResolveVisualVariationSeed(m_visual_variation_seed);
		m_idx = 0;
		m_valid = false;
		SetGenderBytes();
		SetWeightBytes();
		SetScoreBytes();
		SetIsGreatOneBytes();
	}

	Animal::Animal(std::string gender, std::string weight, std::string score, std::string is_great_one, std::string visual_variation_seed, std::string idx)
	{
		m_name_hash = {};
		m_name = {};
		m_gender = ResolveGender(gender);
		m_str_gender = ResolveGender(m_gender);
		m_weight = ResolveWeight(weight);
		m_score = ResolveScore(score);
		m_is_great_one = ResolveIsGreatOne(is_great_one);
		m_visual_variation_seed = {};
		m_str_visual_variation_seed = {};
		m_idx = ResolveIdx(idx);
		m_valid = false;
		SetGenderBytes();
		SetWeightBytes();
		SetScoreBytes();
		SetIsGreatOneBytes();
	}

	std::shared_ptr<Animal> Animal::Create(AnimalType animal_type, std::string gender, std::string weight, std::string score, std::string is_great_one, std::string visual_variation_seed)
	{
		switch (animal_type)
		{
		case AT_WildBoar:
			return std::make_shared<WildBoar>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_FallowDeer:
			return std::make_shared<FallowDeer>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_EuroBison:
			return std::make_shared<EuroBison>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_RoeDeer:
			return std::make_shared<RoeDeer>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_RedFox:
			return std::make_shared<RedFox>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_CanadaGoose:
			return std::make_shared<CanadaGoose>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_RedDeer:
			return std::make_shared<RedDeer>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_EuroRabbit:
			return std::make_shared<EuroRabbit>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_Moose:
			return std::make_shared<Moose>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_Jackrabbit:
			return std::make_shared<Jackrabbit>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_Mallard:
			return std::make_shared<Mallard>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_BlackBear:
			return std::make_shared<BlackBear>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_RooseveltElk:
			return std::make_shared<RooseveltElk>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_Coyote:
			return std::make_shared<Coyote>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_BlacktailDeer:
			return std::make_shared<BlacktailDeer>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_WhitetailDeer:
			return std::make_shared<WhitetailDeer>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_MuskDeer:
			return std::make_shared<MuskDeer>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_Reindeer:
			return std::make_shared<Reindeer>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_EurasianLynx:
			return std::make_shared<EurasianLynx>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_BrownBear:
			return std::make_shared<BrownBear>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_BlueWildebeest:
			return std::make_shared<BlueWildebeest>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_SideStripedJackal:
			return std::make_shared<SideStripedJackal>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_Gemsbok:
			return std::make_shared<Gemsbok>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_LesserKudu:
			return std::make_shared<LesserKudu>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_ScrubHare:
			return std::make_shared<ScrubHare>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_Lion:
			return std::make_shared<Lion>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_Warthog:
			return std::make_shared<Warthog>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_CapeBuffalo:
			return std::make_shared<CapeBuffalo>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_Springbok:
			return std::make_shared<Springbok>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_WaterBuffalo:
			return std::make_shared<WaterBuffalo>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_Puma:
			return std::make_shared<Puma>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_Blackbuck:
			return std::make_shared<Blackbuck>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_CinnamonTeal:
			return std::make_shared<CinnamonTeal>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_MuleDeer:
			return std::make_shared<MuleDeer>(gender, weight, score, is_great_one, visual_variation_seed);
		case AT_AxisDeer:
			return std::make_shared<AxisDeer>(gender, weight, score, is_great_one, visual_variation_seed);
		default:
			return std::make_shared<Animal>(gender, weight, score, is_great_one, visual_variation_seed);
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
		return "none";
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

	// TODO: collect data
	uint32_t Animal::ResolveVisualVariationSeed(const std::string &visual_variation_seed)
	{
		return 1337;
		/*switch (m_reserve_data->m_id)
		{
		case 0:
		{
			switch (m_name_hash)
			{
			case 147581770: // wild boar
			case 798672823: // fallow deer
			case 1056739115: // euro bison
			case 2052964502: // roe deer
			case 2105558160: // red fox
			case 3321523293: // canada goose
			case 3635849363: // red deer
			case 442307937: // euro rabbit
			{
				if (visual_variation_seed == "common1") return 747;
				if (visual_variation_seed == "common2") return 32671;
				if (visual_variation_seed == "melanistic") return 31378;
				if (visual_variation_seed == "albino") return 12076;
				if (visual_variation_seed == "piebald") return 14009;
				if (visual_variation_seed == "common3") return 26115;
				if (visual_variation_seed == "common4") return 17895;
				if (visual_variation_seed == "common5") return 19242;
				if (visual_variation_seed == "common6") return 30067;
			}
			default:
				return INT32_MAX;
			}
		}
		case 1:
		{
			switch (m_name_hash)
			{
			case 155298792: // moose
			case 1227103483: // jackrabbit
			case 1905502510: // mallard
			case 2434390669: // black bear
			case 2492964089: // roosevelt elk
			case 3041812107: // coyote
			case 3616431897: // blacktail deer
			case 3845994887: // whitetail deer
			{
				if (visual_variation_seed == "common1") return 747;
				if (visual_variation_seed == "common2") return 32671;
				if (visual_variation_seed == "melanistic") return 31378;
				if (visual_variation_seed == "albino") return 12076;
				if (visual_variation_seed == "piebald") return 14009;
				if (visual_variation_seed == "common3") return 26115;
				if (visual_variation_seed == "common4") return 17895;
				if (visual_variation_seed == "common5") return 19242;
				if (visual_variation_seed == "common6") return 30067;
			}
			default:
				return INT32_MAX;
			}
		}
		case 2:
		{
			switch (m_name_hash)
			{
			case 74472795: // musk deer
				{
					if (m_str_gender == "male")
					{
						if (visual_variation_seed == "melanistic") return 420;
						if (visual_variation_seed == "albino") return 420;
						if (visual_variation_seed == "piebald") return 420;
						if (visual_variation_seed == "common2") return 32243;
						if (visual_variation_seed == "common3") return 18419;
					}
					else if (m_str_gender == "female")
					{
						if (visual_variation_seed == "common0") return 10034;
						if (visual_variation_seed == "common1") return 420;
						if (visual_variation_seed == "melanistic") return 420;
						if (visual_variation_seed == "albino") return 420;
						if (visual_variation_seed == "piebald") return 420;
						if (visual_variation_seed == "common2") return 420;
						if (visual_variation_seed == "common3") return 420;
					}
					return INT32_MAX;
				}
			case 155298792: // moose
				{
					if (m_str_gender == "male")
					{
						if (visual_variation_seed == "melanistic") return 420;
						if (visual_variation_seed == "albino") return 420;
						if (visual_variation_seed == "piebald") return 10045;
						if (visual_variation_seed == "common2") return 2819;
						if (visual_variation_seed == "common3") return 14949;
						if (visual_variation_seed == "common4") return 420;
						if (visual_variation_seed == "common5") return 29225;
					}
					else if (m_str_gender == "female")
					{
						if (visual_variation_seed == "common0") return 13153;
						if (visual_variation_seed == "common1") return 4120;
						if (visual_variation_seed == "melanistic") return 420;
						if (visual_variation_seed == "albino") return 420;
						if (visual_variation_seed == "piebald") return 420;
						if (visual_variation_seed == "common2") return 420;
						if (visual_variation_seed == "common3") return 420;
						if (visual_variation_seed == "common4") return 16786;
						if (visual_variation_seed == "common5") return 420;
					}
					return INT32_MAX;
				}
			case 1570854601: // wild boar
			case 1814015872: // lynx
			case 1923623595: // brown bear
			case 1779251800: // reindeer
			{

			}
			default:
				return INT32_MAX;
			}
		}
		case 3:
		{
			switch (m_name_hash)
			{
			case 183848642: // wildebeest
			case 802991936: // jackal
			case 1148301097: // gemsbok
			case 1955191955: // lesser kudu
			case 1961213070: // scrub hare
			case 2188838277: // lion
			case 3080620210: // warthog
			case 3311120975: // cape buffalo
			case 4064523038: // springbok
			{
				if (visual_variation_seed == "common1") return 747;
				if (visual_variation_seed == "common2") return 32671;
				if (visual_variation_seed == "melanistic") return 31378;
				if (visual_variation_seed == "albino") return 12076;
				if (visual_variation_seed == "piebald") return 14009;
				if (visual_variation_seed == "common3") return 26115;
				if (visual_variation_seed == "common4") return 17895;
				if (visual_variation_seed == "common5") return 19242;
				if (visual_variation_seed == "common6") return 30067;
			}
			default:
				return INT32_MAX;
			}
		}
		case 4:
		{
			switch (m_name_hash)
			{
			case 429398428: // red deer
			case 743631237: // water buffalo
			case 769204555: // puma
			case 1729971715: // blackbuck
			case 1756552882: // cinnamon teal
			case 2953920016: // mule deer
			case 3406669569: // axis deer
			{
				if (visual_variation_seed == "common1") return 747;
				if (visual_variation_seed == "common2") return 32671;
				if (visual_variation_seed == "melanistic") return 31378;
				if (visual_variation_seed == "albino") return 12076;
				if (visual_variation_seed == "piebald") return 14009;
				if (visual_variation_seed == "common3") return 26115;
				if (visual_variation_seed == "common4") return 17895;
				if (visual_variation_seed == "common5") return 19242;
				if (visual_variation_seed == "common6") return 30067;
			}
			default:
				return INT32_MAX;
			}
		}
		case 6:
		{
			switch (m_name_hash)
			{
			case 155298792: // moose
			case 1227103483: // jackrabbit
			case 1905502510: // mallard
			case 2434390669: // black bear
			case 2492964089: // roosevelt elk
			case 3041812107: // coyote
			case 3616431897: // blacktail deer
			case 3845994887: // whitetail deer
			{
				if (visual_variation_seed == "common1") return 747;
				if (visual_variation_seed == "common2") return 32671;
				if (visual_variation_seed == "melanistic") return 31378;
				if (visual_variation_seed == "albino") return 12076;
				if (visual_variation_seed == "piebald") return 14009;
				if (visual_variation_seed == "common3") return 26115;
				if (visual_variation_seed == "common4") return 17895;
				if (visual_variation_seed == "common5") return 19242;
				if (visual_variation_seed == "common6") return 30067;
			}
			default:
				return INT32_MAX;
			}
		}
		case 8:
		{
			switch (m_name_hash)
			{
			case 155298792: // moose
			case 1227103483: // jackrabbit
			case 1905502510: // mallard
			case 2434390669: // black bear
			case 2492964089: // roosevelt elk
			case 3041812107: // coyote
			case 3616431897: // blacktail deer
			case 3845994887: // whitetail deer
			{
				if (visual_variation_seed == "common1") return 747;
				if (visual_variation_seed == "common2") return 32671;
				if (visual_variation_seed == "melanistic") return 31378;
				if (visual_variation_seed == "albino") return 12076;
				if (visual_variation_seed == "piebald") return 14009;
				if (visual_variation_seed == "common3") return 26115;
				if (visual_variation_seed == "common4") return 17895;
				if (visual_variation_seed == "common5") return 19242;
				if (visual_variation_seed == "common6") return 30067;
			}
			default:
				return INT32_MAX;
			}
		}
		case 9:
		{
			switch (m_name_hash)
			{
			case 155298792: // moose
			case 1227103483: // jackrabbit
			case 1905502510: // mallard
			case 2434390669: // black bear
			case 2492964089: // roosevelt elk
			case 3041812107: // coyote
			case 3616431897: // blacktail deer
			case 3845994887: // whitetail deer
			{
				if (visual_variation_seed == "common1") return 747;
				if (visual_variation_seed == "common2") return 32671;
				if (visual_variation_seed == "melanistic") return 31378;
				if (visual_variation_seed == "albino") return 12076;
				if (visual_variation_seed == "piebald") return 14009;
				if (visual_variation_seed == "common3") return 26115;
				if (visual_variation_seed == "common4") return 17895;
				if (visual_variation_seed == "common5") return 19242;
				if (visual_variation_seed == "common6") return 30067;
			}
			default:
				return INT32_MAX;
			}
		}
		default:
			return INT32_MAX;
		}*/
	}

	std::string Animal::ResolveVisualVariationSeed(const uint32_t visual_variation_seed)
	{
		return "SomeFurType";
	}

	bool Animal::VerifyGender() const
	{
		return (m_gender == 1 && m_str_gender == "male") || (m_gender == 2 && m_str_gender == "female");
	}

	// TODO: collect data
	bool Animal::VerifyWeight() const
	{
		return true;

		/*switch (m_reserve_data->m_id)
		{
		case 0:
		case 1:
		{
			switch (m_name_hash)
			{
			case 0:
				return true;
			default:
				return true;
			}
		}
		case 2: // Medved
			{
				switch(m_name_hash)
				{
				case 155298792: //Moose
					{
					if (m_str_gender == "male") return weight >= 400.f && weight <= 620.f;
					if (m_str_gender == "female") return weight >= 320.f && weight <= 440.f;
					return false;
					}
				case 1923623595: //Brown Bear
				{
					if (m_str_gender == "male") return weight >= 195.f && weight <= 482.f;
					if (m_str_gender == "female") return weight >= 110.f && weight <= 340.f;
					return false;
				}
				case 1779251800: //Reindeer
				{
					if (m_str_gender == "male") return weight >= 159.f && weight <= 182.f;
					if (m_str_gender == "female") return weight >= 80.f && weight <= 120.f;
					return false;
				}
				case 74472795: //Musk Deer
				{
					if (m_str_gender == "male") return weight >= 7.f && weight <= 17.f;
					if (m_str_gender == "female") return weight >= 7.f && weight <= 17.f;
					return false;
				}
				case 1814015872: //Lynx
				{
					if (m_str_gender == "male") return weight >= 18.f && weight <= 45.f;
					if (m_str_gender == "female") return weight >= 8.f && weight <= 21.f;
					return false;
				}
				case 1570854601: //Wild Boar
				{
					if (m_str_gender == "male") return weight >= 32.f && weight <= 240.f;
					if (m_str_gender == "female") return weight >= 25.f && weight <= 168.f;
					return false;
				}
				default:
					return false;
				}
			}
		default:
			return false;
		}*/
	}

	// TODO: collect data
	bool Animal::VerifyScore() const
	{
		return true;
		/*{
			switch (m_reserve_data->m_id)
			{
			case 0:
			case 1:
			{
				switch (m_name_hash)
				{
				case 0:
					return true;
				default:
					return true;
				}
			}
			case 2: // Medved
			{
				switch (m_name_hash)
				{
				case 155298792: //Moose
				{
					if (m_str_gender == "male") return score >= 32.296f && score <= 301.959f;
					if (m_str_gender == "female") return score == 0.f;
					return false;
				}
				case 1923623595: //Brown Bear
				{
					if (m_str_gender == "male") return score >= 195.f && score <= 482.f;
					if (m_str_gender == "female") return score >= 16.f && score <= 24.038f;
					return false;
				}
				case 1779251800: //Reindeer
				{
					if (m_str_gender == "male") return score >= 73.194f && score <= 469.903f;
					if (m_str_gender == "female") return score >= 73.194f && score <= 158.f;
					return false;
				}
				case 74472795: //Musk Deer
				{
					if (m_str_gender == "male") return score >= 6.f && score <= 276.f;
					if (m_str_gender == "female") return score == 0.f;
					return false;
				}
				case 1814015872: //Lynx
				{
					if (m_str_gender == "male") return score >= 19.501f && score <= 28.98f;
					if (m_str_gender == "female") return score >= 15.99f && score <= 20.554f;
					return false;
				}
				case 1570854601: //Wild Boar
				{
					if (m_str_gender == "male") return score >= 7.f && score <= 159.5f;
					if (m_str_gender == "female") return score >= 7.f && score <= 81.5f;
					return false;
				}
				default:
					return false;
				}
			}
			default:
				return false;
			}
		}*/
	}

	bool Animal::VerifyVisualVariationSeed()
	{
		return true;
		// return (visual_variation_seed > 15 && visual_variation_seed < 35000);
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
			<< " | " << std::setw(5) << data.m_visual_variation_seed
			<< " ]\n";
		return out;
	}
}
