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
		if (tmp_id != 420)
		{
			this->id = tmp_id;
			return true;
		}
		return false;
	}

	std::vector<char>* AnimalData::GetBytes()
	{
		std::vector<char> *data = new std::vector<char>();
		data->insert(data->end(), this->gender_bytes.begin(), this->gender_bytes.end());
		data->insert(data->end(), this->weight_bytes.begin(), this->weight_bytes.end());
		data->insert(data->end(), this->score_bytes.begin(), this->score_bytes.end());
		data->insert(data->end(), this->is_great_one_bytes.begin(), this->is_great_one_bytes.end());
		data->insert(data->end(), this->visual_variation_seed_bytes.begin(), this->visual_variation_seed_bytes.end());
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
		if (VerifyWeight(fl_score))
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
		const uint32_t id = this->reserve_data->GetIndex(name);
		if (id >= this->reserve_data->animal_names.size()) return 420;
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
		if (VerifyWeight(fl_weight)) return fl_weight;
		return FLT_MAX;
	}

	float AnimalData::ResolveScore(std::string &score)
	{
		const float fl_score = std::stof(score);
		if (VerifyWeight(fl_score)) return fl_score;
		return FLT_MAX;
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
				switch (id)
				{
				case 0:
					return true;
				default:
					return true;
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
		case 1:
		{
			switch (this->id)
			{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			{
				if (visual_variation_seed == "common1") return 747;
				if (visual_variation_seed == "common2") return 32671;
				if (visual_variation_seed == "melanistic") return 24779;
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
		// TODO: check thresholds
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