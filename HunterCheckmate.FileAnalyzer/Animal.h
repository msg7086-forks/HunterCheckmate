#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <iomanip>
#include "Windows.h"
#include <boost/algorithm/string.hpp>

#include "ReserveData.h"
#include "AnimalTypeEnum.h"

namespace bs = boost::algorithm;

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

		void SetGender(const uint8_t gender);
		void SetGender(const std::string& gender);
		void SetWeight(const float weight);
		void SetScore(const float score);
		void SetIsGreatOne(const bool is_great_one);
		void SetIdx(const uint32_t idx);
		void SetVisualVariationSeed(const uint32_t visual_variation_seed);
		uint32_t ResolveVisualVariationSeed(const uint32_t visual_variation_seed);
		static uint32_t ResolveVisualVariationSeed(const AnimalType animal_type, const std::string& str_gender, const uint32_t visual_variation_seed);
		std::string ResolveFurTypeId(const uint32_t fur_type_id);
		static std::string ResolveFurTypeId(const AnimalType animal_type, const uint32_t fur_type_id);

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
		bool m_valid;

		Animal(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx);
		virtual ~Animal() = default;
		Animal(const Animal& src) = default;
		Animal(Animal&& src) = default;
		Animal& operator=(const Animal& rhs) = default;
		Animal& operator=(Animal&& rhs) = default;

		static std::shared_ptr<Animal> Create(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx);

		static AnimalType ResolveAnimalType(std::string& name);
		static std::string ResolveGender(const uint8_t gender_id);
		static uint8_t ResolveGender(const std::string& gender);
		static uint32_t CreateVisualVariationSeed(const AnimalType animal_type, const std::string& str_gender, const std::string& fur_type);

		std::vector<char> GetByteStream();
		virtual float GetMaxWeight();
		virtual float GetMaxScore();

		bool IsValid() const;

		friend std::ostream& operator<<(std::ostream& out, const Animal& data);
	};

#pragma region Animals
	class WildBoar : public Animal
	{
	public:
		WildBoar(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Wild Boar";
			m_valid = Verify();
		}
		~WildBoar() override = default;
	};

	class FallowDeer : public Animal
	{
	public:
		FallowDeer(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Fallow Deer";
			m_valid = Verify();
		}
		~FallowDeer() override = default;
	};

	class EuroBison : public Animal
	{
	public:
		EuroBison(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "European Bison";
			m_valid = Verify();
		}
		~EuroBison() override = default;
	};

	class RoeDeer : public Animal
	{
	public:
		RoeDeer(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Roe Deer";

			m_valid = Verify();
		}
		~RoeDeer() override = default;
	};

	class RedFox : public Animal
	{
	public:
		RedFox(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Red Fox";

			m_valid = Verify();
		}
		~RedFox() override = default;
	};

	class CanadaGoose : public Animal
	{
	public:
		CanadaGoose(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Canada Goose";
			m_valid = Verify();
		}
		~CanadaGoose() override = default;
	};

	class RedDeer : public Animal
	{
	public:
		RedDeer(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Red Deer";
			m_valid = Verify();
		}
		~RedDeer() override = default;
	};

	class EuroRabbit : public Animal
	{
	public:
		EuroRabbit(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "European Rabbit";
			m_valid = Verify();
		}
		~EuroRabbit() override = default;
	};

	class Moose : public Animal
	{
	public:
		Moose(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Moose";
			m_valid = Verify();
		}
		~Moose() override = default;
	};

	class Jackrabbit : public Animal
	{
	public:
		Jackrabbit(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Jackrabbit";

			m_valid = Verify();
		}
		~Jackrabbit() override = default;
	};

	class Mallard : public Animal
	{
	public:
		Mallard(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Mallard";

			m_valid = Verify();
		}
		~Mallard() override = default;
	};

	class BlackBear : public Animal
	{
	public:
		BlackBear(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Black Bear";

			m_valid = Verify();
		}
		~BlackBear() override = default;
	};

	class RooseveltElk : public Animal
	{
	public:
		RooseveltElk(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Roosevelt Elk";

			m_valid = Verify();
		}
		~RooseveltElk() override = default;
	};

	class Coyote : public Animal
	{
	public:
		Coyote(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Coyote";

			m_valid = Verify();
		}
		~Coyote() override = default;
	};

	class BlacktailDeer : public Animal
	{
	public:
		BlacktailDeer(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Blacktail Deer";

			m_valid = Verify();
		}
		~BlacktailDeer() override = default;
	};

	class WhitetailDeer : public Animal
	{
	public:
		WhitetailDeer(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Whitetail Deer";
			m_valid = Verify();
		}
		~WhitetailDeer() override = default;
	};

	class MuskDeer : public Animal
	{
	public:
		MuskDeer(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Musk Deer";

			m_valid = Verify();
		}
		~MuskDeer() override = default;
	};

	class Reindeer : public Animal
	{
	public:
		Reindeer(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Reindeer";

			m_valid = Verify();
		}
		~Reindeer() override = default;
	};

	class EurasianLynx : public Animal
	{
	public:
		EurasianLynx(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Eurasian Lynx";

			m_valid = Verify();
		}
		~EurasianLynx() override = default;
	};

	class BrownBear : public Animal
	{
	public:
		BrownBear(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Brown Bear";

			m_valid = Verify();
		}
		~BrownBear() override = default;
	};

	class BlueWildebeest : public Animal
	{
	public:
		BlueWildebeest(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Blue Wildebeest";

			m_valid = Verify();
		}
		~BlueWildebeest() override = default;
	};

	class SideStripedJackal : public Animal
	{
	public:
		SideStripedJackal(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Side-striped Jackal";

			m_valid = Verify();
		}
		~SideStripedJackal() override = default;
	};

	class Gemsbok : public Animal
	{
	public:
		Gemsbok(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Gemsbok";

			m_valid = Verify();
		}
		~Gemsbok() override = default;
	};

	class LesserKudu : public Animal
	{
	public:
		LesserKudu(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Lesser Kudu";

			m_valid = Verify();
		}
		~LesserKudu() override = default;
	};

	class ScrubHare : public Animal
	{
	public:
		ScrubHare(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Scrub Hare";

			m_valid = Verify();
		}
		~ScrubHare() override = default;
	};

	class Lion : public Animal
	{
	public:
		Lion(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Lion";

			m_valid = Verify();
		}
		~Lion() override = default;
	};

	class Warthog : public Animal
	{
	public:
		Warthog(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Warthog";

			m_valid = Verify();
		}
		~Warthog() override = default;
	};

	class CapeBuffalo : public Animal
	{
	public:
		CapeBuffalo(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Cape Buffalo";

			m_valid = Verify();
		}
		~CapeBuffalo() override = default;
	};

	class Springbok : public Animal
	{
	public:
		Springbok(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Springbok";

			m_valid = Verify();
		}
		~Springbok() override = default;
	};

	class WaterBuffalo : public Animal
	{
	public:
		WaterBuffalo(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Water Buffalo";

			m_valid = Verify();
		}
		~WaterBuffalo() override = default;
	};

	class Puma : public Animal
	{
	public:
		Puma(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Puma";

			m_valid = Verify();
		}
		~Puma() override = default;
	};

	class Blackbuck : public Animal
	{
	public:
		Blackbuck(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Blackbuck";

			m_valid = Verify();
		}
		~Blackbuck() override = default;
	};

	class CinnamonTeal : public Animal
	{
	public:
		CinnamonTeal(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Cinnamon Teal";

			m_valid = Verify();
		}
		~CinnamonTeal() override = default;
	};

	class MuleDeer : public Animal
	{
	public:
		MuleDeer(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Mule Deer";

			m_valid = Verify();
		}
		~MuleDeer() override = default;
	};

	class AxisDeer : public Animal
	{
	public:
		AxisDeer(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Axis Deer";

			m_valid = Verify();
		}
		~AxisDeer() override = default;
	};

	class HarlequinDuck : public Animal
	{
	public:
		HarlequinDuck(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Harlequin Duck";

			m_valid = Verify();
		}
		~HarlequinDuck() override = default;
	};

	class Caribou : public Animal
	{
	public:
		Caribou(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Caribou";

			m_valid = Verify();
		}
		~Caribou() override = default;
	};

	class GrizzlyBear : public Animal
	{
	public:
		GrizzlyBear(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Grizzly Bear";

			m_valid = Verify();
		}
		~GrizzlyBear() override = default;
	};

	class GrayWolf : public Animal
	{
	public:
		GrayWolf(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Gray Wolf";

			m_valid = Verify();
		}
		~GrayWolf() override = default;
	};

	class PlainsBison : public Animal
	{
	public:
		PlainsBison(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Plains Bison";

			m_valid = Verify();
		}
		~PlainsBison() override = default;
	};

	class SoutheasternSpanishIbex : public Animal
	{
	public:
		SoutheasternSpanishIbex(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Southeastern Spanish Ibex";

			m_valid = Verify();
		}
		~SoutheasternSpanishIbex() override = default;
	};

	class IberianWolf : public Animal
	{
	public:
		IberianWolf(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Iberian Wolf";

			m_valid = Verify();
		}
		~IberianWolf() override = default;
	};

	class IberianMuflon : public Animal
	{
	public:
		IberianMuflon(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Iberian Muflon";

			m_valid = Verify();
		}
		~IberianMuflon() override = default;
	};

	class BeceiteIbex : public Animal
	{
	public:
		BeceiteIbex(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Beceite Ibex";

			m_valid = Verify();
		}
		~BeceiteIbex() override = default;
	};

	class EuroHare : public Animal
	{
	public:
		EuroHare(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "European Hare";

			m_valid = Verify();
		}
		~EuroHare() override = default;
	};

	class RondaIbex : public Animal
	{
	public:
		RondaIbex(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Ronda Ibex";

			m_valid = Verify();
		}
		~RondaIbex() override = default;
	};

	class GredosIbex : public Animal
	{
	public:
		GredosIbex(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Gredos Ibex";

			m_valid = Verify();
		}
		~GredosIbex() override = default;
	};

	class Pronghorn : public Animal
	{
	public:
		Pronghorn(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Pronghorn";

			m_valid = Verify();
		}
		~Pronghorn() override = default;
	};

	class MountainLion : public Animal
	{
	public:
		MountainLion(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Mountain Lion";

			m_valid = Verify();
		}
		~MountainLion() override = default;
	};

	class MountainGoat : public Animal
	{
	public:
		MountainGoat(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Mountain Goat";

			m_valid = Verify();
		}
		~MountainGoat() override = default;
	};

	class BighornSheep : public Animal
	{
	public:
		BighornSheep(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Bighorn Sheep";

			m_valid = Verify();
		}
		~BighornSheep() override = default;
	};

	class MerriamTurkey : public Animal
	{
	public:
		MerriamTurkey(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Merriam Turkey";

			m_valid = Verify();
		}
		~MerriamTurkey() override = default;
	};

	class RockyMountainElk : public Animal
	{
	public:
		RockyMountainElk(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Rocky Mountain Elk";

			m_valid = Verify();
		}
		~RockyMountainElk() override = default;
	};

	class SikaDeer : public Animal
	{
	public:
		SikaDeer(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Sika Deer";

			m_valid = Verify();
		}
		~SikaDeer() override = default;
	};

	class Chamois : public Animal
	{
	public:
		Chamois(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Chamois";

			m_valid = Verify();
		}
		~Chamois() override = default;
	};

	class FeralPig : public Animal
	{
	public:
		FeralPig(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Feral Pig";

			m_valid = Verify();
		}
		~FeralPig() override = default;
	};

	class FeralGoat : public Animal
	{
	public:
		FeralGoat(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Feral Goat";

			m_valid = Verify();
		}
		~FeralGoat() override = default;
	};

	class CollaredPeccary : public Animal
	{
	public:
		CollaredPeccary(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Collared Peccary";

			m_valid = Verify();
		}
		~CollaredPeccary() override = default;
	};

	class MexicanBobcat : public Animal
	{
	public:
		MexicanBobcat(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Mexican Bobcat";

			m_valid = Verify();
		}
		~MexicanBobcat() override = default;
	};

	class RioGrandeTurkey : public Animal
	{
	public:
		RioGrandeTurkey(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Rio Grande Turkey";

			m_valid = Verify();
		}
		~RioGrandeTurkey() override = default;
	};

	class RingNeckedPheasant : public Animal
	{
	public:
		RingNeckedPheasant(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Ring-necked Pheasant";

			m_valid = Verify();
		}
		~RingNeckedPheasant() override = default;
	};

	class AntelopeJackrabbit : public Animal
	{
	public:
		AntelopeJackrabbit(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Antelope Jackrabbit";

			m_valid = Verify();
		}
		~AntelopeJackrabbit() override = default;
	};

	class AmericanAlligator : public Animal
	{
	public:
		AmericanAlligator(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "American Alligator";

			m_valid = Verify();
		}
		~AmericanAlligator() override = default;
	};

	class WildHog : public Animal
	{
	public:
		WildHog(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Wild Hog";

			m_valid = Verify();
		}
		~WildHog() override = default;
	};

	class GrayFox : public Animal
	{
	public:
		GrayFox(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Gray Fox";

			m_valid = Verify();
		}
		~GrayFox() override = default;
	};

	class CommonRaccoon : public Animal
	{
	public:
		CommonRaccoon(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Common Raccoon";

			m_valid = Verify();
		}
		~CommonRaccoon() override = default;
	};

	class EasternWildTurkey : public Animal
	{
	public:
		EasternWildTurkey(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Eastern Wild Turkey";

			m_valid = Verify();
		}
		~EasternWildTurkey() override = default;
	};

	class EasternCottontailRabbit : public Animal
	{
	public:
		EasternCottontailRabbit(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Eastern Cottontail Rabbit";

			m_valid = Verify();
		}
		~EasternCottontailRabbit() override = default;
	};

	class BobwhiteQuail : public Animal
	{
	public:
		BobwhiteQuail(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Bobwhite Quail";

			m_valid = Verify();
		}
		~BobwhiteQuail() override = default;
	};

	class RaccoonDog : public Animal
	{
	public:
		RaccoonDog(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Raccoon Dog";

			m_valid = Verify();
		}
		~RaccoonDog() override = default;
	};

	class EurasianWigeon : public Animal
	{
	public:
		EurasianWigeon(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Eurasian Wigeon";

			m_valid = Verify();
		}
		~EurasianWigeon() override = default;
	};

	class TundraBeanGoose : public Animal
	{
	public:
		TundraBeanGoose(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Tundra Bean Goose";

			m_valid = Verify();
		}
		~TundraBeanGoose() override = default;
	};

	class EurasianTeal : public Animal
	{
	public:
		EurasianTeal(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Eurasian Teal";

			m_valid = Verify();
		}
		~EurasianTeal() override = default;
	};

	class BlackGrouse : public Animal
	{
	public:
		BlackGrouse(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Black Grouse";

			m_valid = Verify();
		}
		~BlackGrouse() override = default;
	};

	class Goldeneye : public Animal
	{
	public:
		Goldeneye(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Goldeneye";

			m_valid = Verify();
		}
		~Goldeneye() override = default;
	};

	class HazelGrouse : public Animal
	{
	public:
		HazelGrouse(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Hazel Grouse";

			m_valid = Verify();
		}
		~HazelGrouse() override = default;
	};

	class WesternCapercaillie : public Animal
	{
	public:
		WesternCapercaillie(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Western Capercaillie";

			m_valid = Verify();
		}
		~WesternCapercaillie() override = default;
	};

	class TuftedDuck : public Animal
	{
	public:
		TuftedDuck(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Tufted Duck";

			m_valid = Verify();
		}
		~TuftedDuck() override = default;
	};

	class RockPtarmigan : public Animal
	{
	public:
		RockPtarmigan(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Rock Ptarmigan";

			m_valid = Verify();
		}
		~RockPtarmigan() override = default;
	};

	class WillowPtarmigan : public Animal
	{
	public:
		WillowPtarmigan(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Willow Ptarmigan";

			m_valid = Verify();
		}
		~WillowPtarmigan() override = default;
	};

	class GreylagGoose : public Animal
	{
	public:
		GreylagGoose(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Gerylag Goose";

			m_valid = Verify();
		}
		~GreylagGoose() override = default;
	};

	class MountainHare : public Animal
	{
	public:
		MountainHare(AnimalType animal_type, uint8_t gender, float weight, float score, bool is_great_one, uint32_t visual_variation_seed, uint32_t idx)
			: Animal(animal_type, gender, weight, score, is_great_one, visual_variation_seed, idx)
		{

			m_name = "Mountain Hare";

			m_valid = Verify();
		}
		~MountainHare() override = default;
	};
#pragma endregion
}
