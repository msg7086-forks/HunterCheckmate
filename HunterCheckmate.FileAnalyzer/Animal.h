#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <iomanip>

#include "ReserveData.h"
#include "AnimalTypeEnum.h"

namespace HunterCheckmate_FileAnalyzer
{
	class Animal
	{
	protected:
		std::vector<char> gender_bytes;
		std::vector<char> weight_bytes;
		std::vector<char> score_bytes;
		std::vector<char> is_great_one_bytes;
		std::vector<char> visual_variation_seed_bytes;

		static uint8_t ResolveGender(const std::string &name);
		static std::string ResolveGender(const uint8_t gender);
		static float ResolveWeight(const std::string& weight);
		static float ResolveScore(const std::string& score);
		static uint8_t ResolveIsGreatOne(const std::string & is_great_one);
		static uint32_t ResolveIdx(const std::string& idx);
		static uint32_t ResolveVisualVariationSeed(const std::string &visual_variation_seed);
		static std::string ResolveVisualVariationSeed(const uint32_t visual_variation_seed);

		bool VerifyGender() const;
		virtual bool VerifyWeight() const;
		virtual bool VerifyScore() const;
		static bool VerifyVisualVariationSeed();
		bool Verify() const;

		void SetGenderBytes();
		void SetWeightBytes();
		void SetScoreBytes();
		void SetIsGreatOneBytes();
		void SetVisualVariationSeedBytes();

	public:
		uint32_t m_name_hash;
		std::string m_name;
		uint8_t m_gender;
		std::string m_str_gender;
		float m_weight;
		float m_score;
		uint8_t m_is_great_one;
		uint32_t m_visual_variation_seed;
		std::string m_str_visual_variation_seed;
		uint32_t m_idx;
		bool m_valid;

		Animal(std::string gender, std::string weight, std::string score, std::string is_great_one, std::string visual_variation_seed);
		Animal(std::string gender, std::string weight, std::string score, std::string is_great_one, std::string visual_variation_seed, std::string idx);
		virtual ~Animal() = default;
		Animal(const Animal& src) = default;
		Animal(Animal&& src) = default;
		Animal& operator=(const Animal& rhs) = default;
		Animal& operator=(Animal&& rhs) = default;

		static std::shared_ptr<Animal> Create(AnimalType animal_type, std::string gender, std::string weight, std::string score, std::string is_great_one, std::string visual_variation_seed);
		std::vector<char> GetBytes();

		friend std::ostream& operator<<(std::ostream& out, const Animal& data);
	};

	class WildBoar : public Animal
	{
	public:
		WildBoar(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
				: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~WildBoar() override = default;
	};

	class FallowDeer : public Animal
	{
	public:
		FallowDeer(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770;
			m_name = "fallow_deer";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~FallowDeer() override = default;
	};

	class EuroBison : public Animal
	{
	public:
		EuroBison(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~EuroBison() override = default;
	};

	class RoeDeer : public Animal
	{
	public:
		RoeDeer(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~RoeDeer() override = default;
	};

	class RedFox : public Animal
	{
	public:
		RedFox(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~RedFox() override = default;
	};

	class CanadaGoose : public Animal
	{
	public:
		CanadaGoose(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~CanadaGoose() override = default;
	};

	class RedDeer : public Animal
	{
	public:
		RedDeer(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~RedDeer() override = default;
	};

	class EuroRabbit : public Animal
	{
	public:
		EuroRabbit(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~EuroRabbit() override = default;
	};

	class Moose : public Animal
	{
	public:
		Moose(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~Moose() override = default;
	};

	class Jackrabbit : public Animal
	{
	public:
		Jackrabbit(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~Jackrabbit() override = default;
	};

	class Mallard : public Animal
	{
	public:
		Mallard(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~Mallard() override = default;
	};

	class BlackBear : public Animal
	{
	public:
		BlackBear(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~BlackBear() override = default;
	};

	class RooseveltElk : public Animal
	{
	public:
		RooseveltElk(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~RooseveltElk() override = default;
	};

	class Coyote : public Animal
	{
	public:
		Coyote(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~Coyote() override = default;
	};

	class BlacktailDeer : public Animal
	{
	public:
		BlacktailDeer(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~BlacktailDeer() override = default;
	};

	class WhitetailDeer : public Animal
	{
	public:
		WhitetailDeer(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770;
			m_name = "whitetail_deer";
			m_visual_variation_seed = 1337;
			m_str_visual_variation_seed = "TODO";
			m_idx = 0;
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~WhitetailDeer() override = default;
	};

	class MuskDeer : public Animal
	{
	public:
		MuskDeer(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~MuskDeer() override = default;
	};

	class Reindeer : public Animal
	{
	public:
		Reindeer(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~Reindeer() override = default;
	};

	class EurasianLynx : public Animal
	{
	public:
		EurasianLynx(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~EurasianLynx() override = default;
	};

	class BrownBear : public Animal
	{
	public:
		BrownBear(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~BrownBear() override = default;
	};

	class BlueWildebeest : public Animal
	{
	public:
		BlueWildebeest(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~BlueWildebeest() override = default;
	};

	class SideStripedJackal : public Animal
	{
	public:
		SideStripedJackal(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~SideStripedJackal() override = default;
	};

	class Gemsbok : public Animal
	{
	public:
		Gemsbok(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~Gemsbok() override = default;
	};

	class LesserKudu : public Animal
	{
	public:
		LesserKudu(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~LesserKudu() override = default;
	};

	class ScrubHare : public Animal
	{
	public:
		ScrubHare(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~ScrubHare() override = default;
	};

	class Lion : public Animal
	{
	public:
		Lion(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~Lion() override = default;
	};

	class Warthog : public Animal
	{
	public:
		Warthog(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~Warthog() override = default;
	};

	class CapeBuffalo : public Animal
	{
	public:
		CapeBuffalo(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~CapeBuffalo() override = default;
	};

	class Springbok : public Animal
	{
	public:
		Springbok(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~Springbok() override = default;
	};

	class WaterBuffalo : public Animal
	{
	public:
		WaterBuffalo(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~WaterBuffalo() override = default;
	};

	class Puma : public Animal
	{
	public:
		Puma(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~Puma() override = default;
	};

	class Blackbuck : public Animal
	{
	public:
		Blackbuck(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~Blackbuck() override = default;
	};

	class CinnamonTeal : public Animal
	{
	public:
		CinnamonTeal(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~CinnamonTeal() override = default;
	};

	class MuleDeer : public Animal
	{
	public:
		MuleDeer(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "wild_boar";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~MuleDeer() override = default;
	};

	class AxisDeer : public Animal
	{
	public:
		AxisDeer(std::string& gender, std::string& weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(gender, weight, score, is_great_one, visual_variation_seed)
		{
			m_name_hash = 147581770; // TODO
			m_name = "axis_deer";
			SetVisualVariationSeedBytes();
			m_valid = Verify();
		}
		~AxisDeer() override = default;
	};

}
