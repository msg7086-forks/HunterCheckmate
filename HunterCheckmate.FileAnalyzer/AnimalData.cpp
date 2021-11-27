#include "AnimalData.h"

namespace HunterCheckmate_FileAnalyzer
{
	AnimalData::AnimalData(ReserveData *reserve_data)
	{
		this->reserve_data = reserve_data;
	}

	AnimalData::~AnimalData() = default;


	bool AnimalData::SetId(uint32_t id)
	{
		if (VerifyId(id))
		{
			this->id = id;
			return true;
		}
		return false;
	}

	bool AnimalData::SetId(const std::string &animal_name)
	{
		const uint32_t tmp_id = ResolveId(animal_name);
		this->id = tmp_id;
		return true;
	}

	std::vector<char> AnimalData::GetBytes()
	{
		std::vector<char> data;
		data.insert(data.end(), this->gender_bytes.begin(), this->gender_bytes.end());
		data.insert(data.end(), this->weight_bytes.begin(), this->weight_bytes.end());
		data.insert(data.end(), this->score_bytes.begin(), this->score_bytes.end());
		data.insert(data.end(), this->is_great_one_bytes.begin(), this->is_great_one_bytes.end());
		data.insert(data.end(), this->visual_variation_seed_bytes.begin(), this->visual_variation_seed_bytes.end());
		return data;
	}

	bool AnimalData::SetGender(uint8_t gender)
	{
		if (VerifyGender(gender))
		{
			this->gender = gender;
			this->str_gender = ResolveGender(gender);
			SetGenderBytes();
			return true;
		}
		return false;
	}

	bool AnimalData::SetGender(const std::string &gender)
	{
		const uint8_t tmp_gender = ResolveGender(gender);
		if (tmp_gender != 0)
		{
			this->gender = tmp_gender;
			this->str_gender = ResolveGender(tmp_gender);
			SetGenderBytes();
			return true;
		}
		return false;
	}

	bool AnimalData::SetWeight(float weight)
	{
		if (VerifyWeight(weight))
		{
			this->weight = weight;
			SetWeightBytes();
			return true;
		}
		return false;
	}

	bool AnimalData::SetWeight(std::string &weight)
	{
		const float fl_weight = ResolveWeight(weight);
		if (VerifyWeight(fl_weight))
		{
			this->weight = fl_weight;
			SetWeightBytes();
			return true;
		}
		return false;
	}

	bool AnimalData::SetScore(float score)
	{
		if (VerifyScore(score))
		{
			this->score = score;
			SetScoreBytes();
			return true;
		}
		return false;
	}

	bool AnimalData::SetScore(std::string& score)
	{
		const float fl_score = ResolveScore(score);
		if (VerifyScore(fl_score))
		{
			this->score = fl_score;
			SetScoreBytes();
			return true;
		}
		return false;
	}

	bool AnimalData::SetIsGreatOne(uint8_t is_great_one)
	{
		this->is_great_one = is_great_one;
		SetIsGreatOneBytes();
		return true;
	}

	bool AnimalData::SetIsGreatOne(std::string& is_great_one) 
	{
		this->is_great_one = ResolveIsGreatOne(is_great_one);
		SetIsGreatOneBytes();
		return true;
	}

	bool AnimalData::SetVisualVariationSeed(uint32_t visual_variation_seed)
	{
		if (VerifyVisualVariationSeed(visual_variation_seed))
		{
			this->visual_variation_seed = visual_variation_seed;
			SetVisualVariationSeedBytes();
			return true;
		}
		return false;
	}

	bool AnimalData::SetVisualVariationSeed(const std::string &visual_variation_seed)
	{
		const uint32_t ui_visual_variation_seed = ResolveVisualVariationSeed(visual_variation_seed);
		if (VerifyVisualVariationSeed(ui_visual_variation_seed))
		{
			this->visual_variation_seed = ui_visual_variation_seed;
			SetVisualVariationSeedBytes();
			return true;
		}
		return false;
	}

	uint32_t AnimalData::ResolveId(const std::string &name) const
	{
		const uint32_t id = this->reserve_data->GetNameHash(name);
		return id;
	}

	bool AnimalData::VerifyId(const uint32_t id) const
	{
		return this->reserve_data->Verify();
	}

	uint8_t AnimalData::ResolveGender(const std::string &name)
	{
		if (name == "male") return 1;
		if (name == "female") return 2;
		return 0;
	}

	std::string AnimalData::ResolveGender(const uint8_t gender)
	{
		if (gender == 1) return "male";
		if (gender == 2) return "female";
		return "none";
	}

	bool AnimalData::VerifyGender(const uint8_t gender) const
	{
		return (gender == 1 || gender == 2);
	}

	float AnimalData::ResolveWeight(std::string &weight)
	{
		const float fl_weight = std::stof(weight);
		return fl_weight;
	}

	float AnimalData::ResolveScore(std::string &score)
	{
		const float fl_score = std::stof(score);
		return fl_score;
	}

	uint8_t AnimalData::ResolveIsGreatOne(std::string& is_great_one) 
	{
		if (is_great_one == "true") return 1;
		if (is_great_one == "false") return 0;
		return 0;
	}

	// TODO: collect data
	bool AnimalData::VerifyWeight(float weight) const
	{
		switch (this->reserve_data->id)
		{
		case 0:
		case 1:
		{
			switch (id)
			{
			case 0:
				return true;
			default:
				return true;
			}
		}
		case 2: // Medved
			{
				switch(id)
				{
				case 155298792: //Moose
					{
					if (this->str_gender == "male") return weight >= 400.f && weight <= 620.f;
					if (this->str_gender == "female") return weight >= 320.f && weight <= 440.f;
					return false;
					}
				case 1923623595: //Brown Bear
				{
					if (this->str_gender == "male") return weight >= 195.f && weight <= 482.f;
					if (this->str_gender == "female") return weight >= 110.f && weight <= 340.f;
					return false;
				}
				case 1779251800: //Reindeer
				{
					if (this->str_gender == "male") return weight >= 159.f && weight <= 182.f;
					if (this->str_gender == "female") return weight >= 80.f && weight <= 120.f;
					return false;
				}
				case 74472795: //Musk Deer
				{
					if (this->str_gender == "male") return weight >= 7.f && weight <= 17.f;
					if (this->str_gender == "female") return weight >= 7.f && weight <= 17.f;
					return false;
				}
				case 1814015872: //Lynx
				{
					if (this->str_gender == "male") return weight >= 18.f && weight <= 45.f;
					if (this->str_gender == "female") return weight >= 8.f && weight <= 21.f;
					return false;
				}
				case 1570854601: //Wild Boar
				{
					if (this->str_gender == "male") return weight >= 32.f && weight <= 240.f;
					if (this->str_gender == "female") return weight >= 25.f && weight <= 168.f;
					return false;
				}
				default:
					return false;
				}
			}
		default:
			return false;
		}
	}

	// TODO: collect data
	bool AnimalData::VerifyScore(float score) const
	{
		{
			switch (this->reserve_data->id)
			{
			case 0:
			case 1:
			{
				switch (this->id)
				{
				case 0:
					return true;
				default:
					return true;
				}
			}
			case 2: // Medved
			{
				switch (id)
				{
				case 155298792: //Moose
				{
					if (this->str_gender == "male") return score >= 32.296f && score <= 301.959f;
					if (this->str_gender == "female") return score == 0.f;
					return false;
				}
				case 1923623595: //Brown Bear
				{
					if (this->str_gender == "male") return score >= 195.f && score <= 482.f;
					if (this->str_gender == "female") return score >= 16.f && score <= 24.038f;
					return false;
				}
				case 1779251800: //Reindeer
				{
					if (this->str_gender == "male") return score >= 73.194f && score <= 469.903f;
					if (this->str_gender == "female") return score >= 73.194f && score <= 158.f;
					return false;
				}
				case 74472795: //Musk Deer
				{
					if (this->str_gender == "male") return score >= 6.f && score <= 276.f;
					if (this->str_gender == "female") return score == 0.f;
					return false;
				}
				case 1814015872: //Lynx
				{
					if (this->str_gender == "male") return score >= 19.501f && score <= 28.98f;
					if (this->str_gender == "female") return score >= 15.99f && score <= 20.554f;
					return false;
				}
				case 1570854601: //Wild Boar
				{
					if (this->str_gender == "male") return score >= 7.f && score <= 159.5f;
					if (this->str_gender == "female") return score >= 7.f && score <= 81.5f;
					return false;
				}
				default:
					return false;
				}
			}
			default:
				return false;
			}
		}
	}

	uint32_t AnimalData::ResolveVisualVariationSeed(const std::string &visual_variation_seed) const
	{
		switch (this->reserve_data->id)
		{
		case 0:
		{
			switch (this->id)
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
			switch (this->id)
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
			switch (this->id)
			{
			case 74472795: // musk deer
				{
					if (this->str_gender == "male")
					{
						if (visual_variation_seed == "melanistic") return 420;
						if (visual_variation_seed == "albino") return 420;
						if (visual_variation_seed == "piebald") return 420;
						if (visual_variation_seed == "common2") return 32243;
						if (visual_variation_seed == "common3") return 18419;
					}
					else if (this->str_gender == "female")
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
					if (this->str_gender == "male")
					{
						if (visual_variation_seed == "melanistic") return 420;
						if (visual_variation_seed == "albino") return 420;
						if (visual_variation_seed == "piebald") return 10045;
						if (visual_variation_seed == "common2") return 2819;
						if (visual_variation_seed == "common3") return 14949;
						if (visual_variation_seed == "common4") return 420;
						if (visual_variation_seed == "common5") return 29225;
					}
					else if (this->str_gender == "female")
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
			switch (this->id)
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
			switch (this->id)
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
			switch (this->id)
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
			switch (this->id)
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
			switch (this->id)
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
		}
	}

	bool AnimalData::VerifyVisualVariationSeed(uint32_t visual_variation_seed)
	{
		return (visual_variation_seed > 15 && visual_variation_seed < 35000);
	}

	void AnimalData::SetGenderBytes()
	{
		std::vector<char> data(sizeof(int32_t));
		std::memcpy(data.data(), &this->gender, sizeof(gender));
		this->gender_bytes = data;
	}

	void AnimalData::SetWeightBytes()
	{
		std::vector<char> data(sizeof(int32_t));
		std::memcpy(data.data(), &this->weight, sizeof(weight));
		this->weight_bytes = data;
	}

	void AnimalData::SetScoreBytes()
	{
		std::vector<char> data(sizeof(int32_t));
		std::memcpy(data.data(), &this->score, sizeof(score));
		this->score_bytes = data;
	}

	void AnimalData::SetIsGreatOneBytes()
	{
		std::vector<char> data(sizeof(int32_t));
		std::memcpy(data.data(), &this->is_great_one, sizeof(is_great_one));
		this->is_great_one_bytes = data;
	}

	void AnimalData::SetVisualVariationSeedBytes()
	{
		std::vector<char> data(sizeof(int32_t));
		std::memcpy(data.data(), &this->visual_variation_seed, sizeof(visual_variation_seed));
		this->visual_variation_seed_bytes = data;
	}
}