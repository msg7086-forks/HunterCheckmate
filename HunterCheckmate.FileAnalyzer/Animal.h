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
		AnimalType m_animal_type;
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

		Animal(AnimalType animal_type, std::string gender, std::string weight, std::string score, std::string is_great_one, std::string visual_variation_seed);
		Animal(AnimalType animal_type, std::string gender, std::string weight, std::string score, std::string is_great_one, std::string visual_variation_seed, std::string idx);
		virtual ~Animal() = default;
		Animal(const Animal& src) = default;
		Animal(Animal&& src) = default;
		Animal& operator=(const Animal& rhs) = default;
		Animal& operator=(Animal&& rhs) = default;

		static std::shared_ptr<Animal> Create(AnimalType animal_type, std::string gender, std::string weight, std::string score, std::string is_great_one, std::string visual_variation_seed);
		std::vector<char> GetBytes();
		bool IsValid() const;

		friend std::ostream& operator<<(std::ostream& out, const Animal& data);
	};

#pragma region Animals
	class WildBoar : public Animal
	{
	public:
		WildBoar(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
				: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "wild_boar";
			m_valid = Verify();
		}
		~WildBoar() override = default;
	};

	class FallowDeer : public Animal
	{
	public:
		FallowDeer(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "fallow_deer";
			m_valid = Verify();
		}
		~FallowDeer() override = default;
	};

	class EuroBison : public Animal
	{
	public:
		EuroBison(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "euro_bison";
			m_valid = Verify();
		}
		~EuroBison() override = default;
	};

	class RoeDeer : public Animal
	{
	public:
		RoeDeer(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "roe_deer";
			
			m_valid = Verify();
		}
		~RoeDeer() override = default;
	};

	class RedFox : public Animal
	{
	public:
		RedFox(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "red_fox";
			
			m_valid = Verify();
		}
		~RedFox() override = default;
	};

	class CanadaGoose : public Animal
	{
	public:
		CanadaGoose(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "canada_goose";
			m_valid = Verify();
		}
		~CanadaGoose() override = default;
	};

	class RedDeer : public Animal
	{
	public:
		RedDeer(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "red_deer";
			m_valid = Verify();
		}
		~RedDeer() override = default;
	};

	class EuroRabbit : public Animal
	{
	public:
		EuroRabbit(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "euro_rabbit";
			m_valid = Verify();
		}
		~EuroRabbit() override = default;
	};

	class Moose : public Animal
	{
	public:
		Moose(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "moose";
			m_valid = Verify();
		}
		~Moose() override = default;
	};

	class Jackrabbit : public Animal
	{
	public:
		Jackrabbit(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "jackrabbit";
			
			m_valid = Verify();
		}
		~Jackrabbit() override = default;
	};

	class Mallard : public Animal
	{
	public:
		Mallard(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "mallard";
			
			m_valid = Verify();
		}
		~Mallard() override = default;
	};

	class BlackBear : public Animal
	{
	public:
		BlackBear(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "black_bear";
			
			m_valid = Verify();
		}
		~BlackBear() override = default;
	};

	class RooseveltElk : public Animal
	{
	public:
		RooseveltElk(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "roosevelt_elk";
			
			m_valid = Verify();
		}
		~RooseveltElk() override = default;
	};

	class Coyote : public Animal
	{
	public:
		Coyote(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "coyote";
			
			m_valid = Verify();
		}
		~Coyote() override = default;
	};

	class BlacktailDeer : public Animal
	{
	public:
		BlacktailDeer(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "blacktail_deer";
			
			m_valid = Verify();
		}
		~BlacktailDeer() override = default;
	};

	class WhitetailDeer : public Animal
	{
	public:
		WhitetailDeer(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "whitetail_deer";
			m_valid = Verify();
		}
		~WhitetailDeer() override = default;
	};

	class MuskDeer : public Animal
	{
	public:
		MuskDeer(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "blacktail_deer";
			
			m_valid = Verify();
		}
		~MuskDeer() override = default;
	};

	class Reindeer : public Animal
	{
	public:
		Reindeer(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "reindeer";
			
			m_valid = Verify();
		}
		~Reindeer() override = default;
	};

	class EurasianLynx : public Animal
	{
	public:
		EurasianLynx(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "eurasian_lynx";
			
			m_valid = Verify();
		}
		~EurasianLynx() override = default;
	};

	class BrownBear : public Animal
	{
	public:
		BrownBear(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "brown_bear";
			
			m_valid = Verify();
		}
		~BrownBear() override = default;
	};

	class BlueWildebeest : public Animal
	{
	public:
		BlueWildebeest(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "blue_wildebeest";
			
			m_valid = Verify();
		}
		~BlueWildebeest() override = default;
	};

	class SideStripedJackal : public Animal
	{
	public:
		SideStripedJackal(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "sidestriped_jackal";
			
			m_valid = Verify();
		}
		~SideStripedJackal() override = default;
	};

	class Gemsbok : public Animal
	{
	public:
		Gemsbok(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "gemsbok";
			
			m_valid = Verify();
		}
		~Gemsbok() override = default;
	};

	class LesserKudu : public Animal
	{
	public:
		LesserKudu(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "lesser_kudu";
			
			m_valid = Verify();
		}
		~LesserKudu() override = default;
	};

	class ScrubHare : public Animal
	{
	public:
		ScrubHare(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "scrub_hare";
			
			m_valid = Verify();
		}
		~ScrubHare() override = default;
	};

	class Lion : public Animal
	{
	public:
		Lion(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "lion";
			
			m_valid = Verify();
		}
		~Lion() override = default;
	};

	class Warthog : public Animal
	{
	public:
		Warthog(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "warthog";
			
			m_valid = Verify();
		}
		~Warthog() override = default;
	};

	class CapeBuffalo : public Animal
	{
	public:
		CapeBuffalo(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "cape_buffalo";
			
			m_valid = Verify();
		}
		~CapeBuffalo() override = default;
	};

	class Springbok : public Animal
	{
	public:
		Springbok(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "springbok";
			
			m_valid = Verify();
		}
		~Springbok() override = default;
	};

	class WaterBuffalo : public Animal
	{
	public:
		WaterBuffalo(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			
			m_name = "water_buffalo";
			
			m_valid = Verify();
		}
		~WaterBuffalo() override = default;
	};

	class Puma : public Animal
	{
	public:
		Puma(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "puma";
			
			m_valid = Verify();
		}
		~Puma() override = default;
	};

	class Blackbuck : public Animal
	{
	public:
		Blackbuck(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "blackbuck";
			
			m_valid = Verify();
		}
		~Blackbuck() override = default;
	};

	class CinnamonTeal : public Animal
	{
	public:
		CinnamonTeal(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "cinnamon_teal";
			
			m_valid = Verify();
		}
		~CinnamonTeal() override = default;
	};

	class MuleDeer : public Animal
	{
	public:
		MuleDeer(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "mule_deer";
			
			m_valid = Verify();
		}
		~MuleDeer() override = default;
	};

	class AxisDeer : public Animal
	{
	public:
		AxisDeer(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "axis_deer";
			
			m_valid = Verify();
		}
		~AxisDeer() override = default;
	};

	class HarlequinDuck : public Animal
	{
	public:
		HarlequinDuck(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "harlequin_duck";
			
			m_valid = Verify();
		}
		~HarlequinDuck() override = default;
	};

	class Caribou : public Animal
	{
	public:
		Caribou(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "caribou";
			
			m_valid = Verify();
		}
		~Caribou() override = default;
	};

	class GrizzlyBear : public Animal
	{
	public:
		GrizzlyBear(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "grizzly_bear";
			
			m_valid = Verify();
		}
		~GrizzlyBear() override = default;
	};

	class GrayWolf : public Animal
	{
	public:
		GrayWolf(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "gray_wolf";
			
			m_valid = Verify();
		}
		~GrayWolf() override = default;
	};

	class PlainsBison : public Animal
	{
	public:
		PlainsBison(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "plains_bison";
			
			m_valid = Verify();
		}
		~PlainsBison() override = default;
	};

	class SoutheasternSpanishIbex : public Animal
	{
	public:
		SoutheasternSpanishIbex(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "southeastern_spanish_ibex";
			
			m_valid = Verify();
		}
		~SoutheasternSpanishIbex() override = default;
	};

	class IberianWolf : public Animal
	{
	public:
		IberianWolf(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "iberian_wolf";
			
			m_valid = Verify();
		}
		~IberianWolf() override = default;
	};

	class IberianMuflon : public Animal
	{
	public:
		IberianMuflon(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "iberian_muflon";
			
			m_valid = Verify();
		}
		~IberianMuflon() override = default;
	};

	class BeceiteIbex : public Animal
	{
	public:
		BeceiteIbex(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "beceite_ibex";
			
			m_valid = Verify();
		}
		~BeceiteIbex() override = default;
	};

	class EuroHare : public Animal
	{
	public:
		EuroHare(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "euro_hare";
			
			m_valid = Verify();
		}
		~EuroHare() override = default;
	};

	class RondaIbex : public Animal
	{
	public:
		RondaIbex(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "ronda_ibex";
			
			m_valid = Verify();
		}
		~RondaIbex() override = default;
	};

	class GredosIbex : public Animal
	{
	public:
		GredosIbex(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "gredos_ibex";
			
			m_valid = Verify();
		}
		~GredosIbex() override = default;
	};

	class Pronghorn : public Animal
	{
	public:
		Pronghorn(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "pronghorn";
			
			m_valid = Verify();
		}
		~Pronghorn() override = default;
	};

	class MountainLion : public Animal
	{
	public:
		MountainLion(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "mountain_lion";
			
			m_valid = Verify();
		}
		~MountainLion() override = default;
	};

	class MountainGoat : public Animal
	{
	public:
		MountainGoat(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "mountain_goat";
			
			m_valid = Verify();
		}
		~MountainGoat() override = default;
	};

	class BighornSheep : public Animal
	{
	public:
		BighornSheep(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "bighorn_sheep";
			
			m_valid = Verify();
		}
		~BighornSheep() override = default;
	};

	class Turkey : public Animal
	{
	public:
		Turkey(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "turkey";
			
			m_valid = Verify();
		}
		~Turkey() override = default;
	};

	class RockyMountainElk : public Animal
	{
	public:
		RockyMountainElk(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "rockymountain_elk";
			
			m_valid = Verify();
		}
		~RockyMountainElk() override = default;
	};

	class SikaDeer : public Animal
	{
	public:
		SikaDeer(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "sika_deer";
			
			m_valid = Verify();
		}
		~SikaDeer() override = default;
	};

	class Chamois : public Animal
	{
	public:
		Chamois(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "chamois";
			
			m_valid = Verify();
		}
		~Chamois() override = default;
	};

	class FeralPig : public Animal
	{
	public:
		FeralPig(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "feral_pig";
			
			m_valid = Verify();
		}
		~FeralPig() override = default;
	};

	class FeralGoat : public Animal
	{
	public:
		FeralGoat(AnimalType animal_type, std::string& gender, std::string weight, std::string& score, std::string& is_great_one, std::string& visual_variation_seed)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed)
		{
			 
			m_name = "feral_goat";
			
			m_valid = Verify();
		}
		~FeralGoat() override = default;
	};
#pragma endregion
}
