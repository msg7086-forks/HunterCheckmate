#pragma once
#include <cstdint>
#include <string>
#include <vector>

#include "ReserveData.h"

namespace HunterCheckmate_FileAnalyzer
{
	class AnimalData
	{
	private:
		ReserveData *reserve_data;
		uint32_t id;
		std::string name;
		uint8_t gender;
		std::string str_gender;
		float weight;
		float score;
		uint8_t is_great_one;
		uint32_t visual_variation_seed;
		std::string str_visual_variation_seed;

		std::vector<char> gender_bytes;
		std::vector<char> weight_bytes;
		std::vector<char> score_bytes;
		std::vector<char> is_great_one_bytes;
		std::vector<char> visual_variation_seed_bytes;

		uint32_t ResolveId(const std::string &name) const;
		bool VerifyId(const uint32_t id) const;
		uint8_t ResolveGender(const std::string &name);
		std::string ResolveGender(const uint8_t gender);
		bool VerifyGender(const uint8_t gender) const;
		float ResolveWeight(std::string& weight);
		float ResolveScore(std::string& score);
		bool VerifyWeight(float weight) const;
		bool VerifyScore(float score) const;
		uint32_t ResolveVisualVariationSeed(const std::string &visual_variation_seed) const;
		bool VerifyVisualVariationSeed(uint32_t visual_variation_seed);

		void SetGenderBytes();
		void SetWeightBytes();
		void SetScoreBytes();
		void SetIsGreatOneBytes();
		void SetVisualVariationSeedBytes();
	public:
		AnimalData(ReserveData *reserve_data);
		bool SetId(uint32_t id);
		bool SetId(const std::string& animal_name);
		~AnimalData();

		std::vector<char> *GetBytes();
		bool SetGender(uint8_t gender);
		bool SetGender(const std::string &gender);
		bool SetWeight(float weight);
		bool SetWeight(std::string& weight);
		bool SetScore(float score);
		bool SetScore(std::string &score);
		bool SetIsGreatOne(uint8_t is_great_one);
		bool SetVisualVariationSeed(uint32_t visual_variation_seed);
		bool SetVisualVariationSeed(const std::string &visual_variation_seed);
	};
}
