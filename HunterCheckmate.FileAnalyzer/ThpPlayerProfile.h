#pragma once
#include "AdfFile.h"
#include <boost/json.hpp>

namespace HunterCheckmate_FileAnalyzer
{
	struct PPWeaponData
	{
		uint32_t equipment_hash;
		uint32_t purchase_timestamp;
		uint32_t shots_fired;
		uint32_t shots_missed;
		uint32_t total_kills;
		uint32_t total_one_shot_kills;
		float record_kill_score;
		uint32_t record_kill_species;
		float furthest_vital_organ_shot;

		PPWeaponData() = default;
		PPWeaponData(uint32_t equipment_hash, uint32_t purchase_timestamp, uint32_t shots_fired, uint32_t shots_missed,
			uint32_t total_kills, uint32_t total_one_shot_kills, float record_kill_score, uint32_t record_kill_species,
			float furthest_vital_organ_shot);
		~PPWeaponData() = default;
	};
	
	class ThpPlayerProfile : public AdfFile
	{
	private:
		std::string *file_path;
		std::ifstream *ifstream;
		std::ofstream *ofstream;

		std::vector<uint32_t> equipment_back_pack;
		std::vector < std::vector<uint32_t>> inventory_slot;
	public:
		ThpPlayerProfile(std::shared_ptr<FileHandler> file_handler, std::string *file_path, std::ifstream *ifstream);
		~ThpPlayerProfile();
		
		bool SerializeJson();
		bool DeserializeJson();
		
		uint8_t GetIsSaveGameAvailable() const;
		uint8_t GetGender() const;
		uint32_t GetSkinToneHash() const;
		uint32_t GetOutfitVariantHash() const;
		uint32_t GetLevel() const;
		uint32_t GetXP() const;
		uint32_t GetSkillPoints() const;
		uint32_t GetPerkPoints() const;
		std::vector<uint32_t> GetSkillPointsSpent() const;
		std::vector<uint32_t> GetPerkPointsSpent() const;
		uint32_t GetCash() const;
		std::vector<uint32_t> GetWeaponLevel() const;
		std::vector<uint32_t> GetWeaponScore() const;
		std::vector<uint32_t> GetEquipmentUnlocked() const;
		std::vector<uint32_t> GetEquipmentOwned() const;
		std::vector<uint32_t> GetEquipmentAmount() const;
		std::vector<uint32_t> GetEquipmentBackPack() const;
		std::vector<uint32_t> GetSkills() const;
		std::vector<uint32_t> GetSkillLevel() const;
		uint32_t GetActiveSkill() const;
		std::vector<std::vector<uint32_t>> GetInventorySlot() const;
		uint32_t GetRestingCurrentCost() const;
		float GetRemainingTimeRestCostReduction() const;
		// GetVehicleData()
		std::vector<uint32_t> GetVehicleEquipmentStorage() const;
		uint8_t GetVehiclePreferedCameraThirdPerson() const;
		std::vector<uint32_t> GetGivenDLCItems() const;
		uint32_t GetEquippedBackpackHash() const;
		std::vector<uint32_t> GetUnlockedHuntClubEquipment() const;
		uint8_t GetHuntClubDisabled() const;
		float GetAnimalSensesMultiplier() const;
		// GetModifiedLockModes()
		uint8_t GetProfileIsNew() const;
		std::vector<PPWeaponData> GetWeaponData() const;
		// GetShownHuntClubOptIn()
		// GetHuntClubHash()
	};
}
