#include "ThpPlayerProfile.h"

namespace HunterCheckmate_FileAnalyzer
{
	PPWeaponData::PPWeaponData(uint32_t equipment_hash, uint32_t purchase_timestamp, uint32_t shots_fired,
		uint32_t shots_missed, uint32_t total_kills, uint32_t total_one_shot_kills, float record_kill_score,
		uint32_t record_kill_species, float furthest_vital_organ_shot)
	{
		this->equipment_hash = equipment_hash;
		this->purchase_timestamp = purchase_timestamp;
		this->shots_fired = shots_fired;
		this->shots_missed = shots_missed;
		this->total_kills = total_kills;
		this->total_one_shot_kills = total_one_shot_kills;
		this->record_kill_score = record_kill_score;
		this->record_kill_species = record_kill_species;
		this->furthest_vital_organ_shot = furthest_vital_organ_shot;
	}

	ThpPlayerProfile::ThpPlayerProfile(Utility* utility, LoadoutData *loadout_data) : AdfFile(utility)
	{
		this->loadout_data = loadout_data;
	}

	
	uint8_t ThpPlayerProfile::GetIsSaveGameAvailable() const
	{
		auto* data = this->instances->at(0).members->at(1).data;
		return *reinterpret_cast<uint8_t*>(data);
	}

	uint8_t ThpPlayerProfile::GetGender() const
	{
		auto* data = this->instances->at(0).members->at(2).data;
		return *reinterpret_cast<uint8_t*>(data);
	}

	uint32_t ThpPlayerProfile::GetSkinToneHash() const
	{
		auto* data = this->instances->at(0).members->at(3).data;
		return *reinterpret_cast<uint32_t*>(data);
	}

	uint32_t ThpPlayerProfile::GetOutfitVariantHash() const
	{
		auto* data = this->instances->at(0).members->at(4).data;
		return *reinterpret_cast<uint32_t*>(data);
	}

	uint32_t ThpPlayerProfile::GetLevel() const
	{
		auto* data = this->instances->at(0).members->at(5).data;
		return *reinterpret_cast<uint32_t*>(data);
	}

	uint32_t ThpPlayerProfile::GetXP() const
	{
		auto* data = this->instances->at(0).members->at(6).data;
		return *reinterpret_cast<uint32_t*>(data);
	}

	uint32_t ThpPlayerProfile::GetSkillPoints() const
	{
		auto* data = this->instances->at(0).members->at(7).data;
		return *reinterpret_cast<uint32_t*>(data);
	}

	uint32_t ThpPlayerProfile::GetPerkPoints() const
	{
		auto* data = this->instances->at(0).members->at(8).data;
		return *reinterpret_cast<uint32_t*>(data);
	}

	std::vector<uint32_t> ThpPlayerProfile::GetSkillPointsSpent() const
	{
		std::vector<uint32_t> buffer(16);
		std::vector<Member> *instance_members = this->instances->at(0).members->at(9).sub_members;
		for (auto it = instance_members->begin(); it != instance_members->end(); ++it)
		{
			uint32_t idx = it - instance_members->begin();
			buffer.at(idx) = *reinterpret_cast<uint32_t*>(it->data);
		}
		return buffer;
	}

	std::vector<uint32_t> ThpPlayerProfile::GetPerkPointsSpent() const
	{
		std::vector<uint32_t> buffer(16);
		std::vector<Member> *instance_members = this->instances->at(0).members->at(10).sub_members;
		for (auto it = instance_members->begin(); it != instance_members->end(); ++it)
		{
			uint32_t idx = it - instance_members->begin();
			buffer.at(idx) = *reinterpret_cast<uint32_t*>(it->data);
		}
		return buffer;
	}

	uint32_t ThpPlayerProfile::GetCash() const
	{
		auto* data = this->instances->at(0).members->at(11).data;
		return *reinterpret_cast<uint32_t*>(data);
	}

	std::vector<uint32_t> ThpPlayerProfile::GetWeaponLevel() const
	{
		std::vector<uint32_t> buffer(4);
		std::vector<Member> *instance_members = this->instances->at(0).members->at(12).sub_members;
		for (auto it = instance_members->begin(); it != instance_members->end(); ++it)
		{
			uint32_t idx = it - instance_members->begin();
			buffer.at(idx) = *reinterpret_cast<uint32_t*>(it->data);
		}
		return buffer;
	}

	std::vector<uint32_t> ThpPlayerProfile::GetWeaponScore() const
	{
		std::vector<uint32_t> buffer(4);
		std::vector<Member> *instance_members = this->instances->at(0).members->at(13).sub_members;
		for (auto it = instance_members->begin(); it != instance_members->end(); ++it)
		{
			uint32_t idx = it - instance_members->begin();
			buffer.at(idx) = *reinterpret_cast<uint32_t*>(it->data);
		}
		return buffer;
	}

	std::vector<uint32_t> ThpPlayerProfile::GetEquipmentUnlocked() const
	{
		std::vector<uint32_t> buffer(512);
		std::vector<Member> *instance_members = this->instances->at(0).members->at(14).sub_members;
		for (auto it = instance_members->begin(); it != instance_members->end(); ++it)
		{
			uint32_t idx = it - instance_members->begin();
			buffer.at(idx) = *reinterpret_cast<uint32_t*>(it->data);
		}
		return buffer;
	}

	std::vector<uint32_t> ThpPlayerProfile::GetEquipmentOwned() const
	{
		std::vector<uint32_t> buffer(512);
		std::vector<Member> *instance_members = this->instances->at(0).members->at(15).sub_members;
		for (auto it = instance_members->begin(); it != instance_members->end(); ++it)
		{
			uint32_t idx = it - instance_members->begin();
			buffer.at(idx) = *reinterpret_cast<uint32_t*>(it->data);
		}
		return buffer;
	}

	std::vector<uint32_t> ThpPlayerProfile::GetEquipmentAmount() const
	{
		std::vector<uint32_t> buffer(512);
		std::vector<Member> *instance_members = this->instances->at(0).members->at(16).sub_members;
		for (auto it = instance_members->begin(); it != instance_members->end(); ++it)
		{
			uint32_t idx = it - instance_members->begin();
			buffer.at(idx) = *reinterpret_cast<uint32_t*>(it->data);
		}
		return buffer;
	}

	std::vector<uint32_t> ThpPlayerProfile::GetEquipmentBackPack() const
	{
		std::vector<uint32_t> buffer(512);
		std::vector<Member> *instance_members = this->instances->at(0).members->at(17).sub_members;
		for (auto it = instance_members->begin(); it != instance_members->end(); ++it)
		{
			uint32_t idx = it - instance_members->begin();
			buffer.at(idx) = *reinterpret_cast<uint32_t*>(it->data);
		}
		return buffer;
	}

	std::vector<uint32_t> ThpPlayerProfile::GetSkills() const
	{
		std::vector<uint32_t> buffer(128);
		std::vector<Member> *instance_members = this->instances->at(0).members->at(18).sub_members;
		for (auto it = instance_members->begin(); it != instance_members->end(); ++it)
		{
			uint32_t idx = it - instance_members->begin();
			buffer.at(idx) = *reinterpret_cast<uint32_t*>(it->data);
		}
		return buffer;
	}

	std::vector<uint32_t> ThpPlayerProfile::GetSkillLevel() const
	{
		std::vector<uint32_t> buffer(128);
		std::vector<Member> *instance_members = this->instances->at(0).members->at(19).sub_members;
		for (auto it = instance_members->begin(); it != instance_members->end(); ++it)
		{
			uint32_t idx = it - instance_members->begin();
			buffer.at(idx) = *reinterpret_cast<uint32_t*>(it->data);
		}
		return buffer;
	}

	uint32_t ThpPlayerProfile::GetActiveSkill() const
	{
		auto* data = this->instances->at(0).members->at(20).data;
		return *reinterpret_cast<uint32_t*>(data);
	}

	std::vector<std::vector<uint32_t>> ThpPlayerProfile::GetInventorySlot() const
	{
		std::vector<std::vector<uint32_t>> buffer(16);
		std::vector<Member> *instance_members = this->instances->at(0).members->at(21).sub_members;
		for (auto it = instance_members->begin(); it != instance_members->end(); ++it)
		{
			uint32_t idx = it - instance_members->begin();
			uint32_t size = it->sub_members->at(0).sub_members->size();
			std::vector<uint32_t> arr(size);
			buffer.at(idx) = arr;
			for (uint32_t i = 0; i < arr.size(); i++)
			{
				buffer.at(idx).at(i) = *reinterpret_cast<uint32_t*>(it->sub_members->at(0).sub_members->at(i).data);
			}
		}
		return buffer;
	}

	uint32_t ThpPlayerProfile::GetRestingCurrentCost() const
	{
		auto* data = this->instances->at(0).members->at(22).data;
		return *reinterpret_cast<uint32_t*>(data);
	}

	float ThpPlayerProfile::GetRemainingTimeRestCostReduction() const
	{
		auto* data = this->instances->at(0).members->at(23).data;
		return *reinterpret_cast<float*>(data);
	}

	// GetVehicleData()
	
	std::vector<uint32_t> ThpPlayerProfile::GetVehicleEquipmentStorage() const
	{
		std::vector<uint32_t> buffer(512);
		std::vector<Member> *instance_members = this->instances->at(0).members->at(25).sub_members;
		for (auto it = instance_members->begin(); it != instance_members->end(); ++it)
		{
			uint32_t idx = it - instance_members->begin();
			buffer.at(idx) = *reinterpret_cast<uint32_t*>(it->data);
		}
		return buffer;
	}

	uint8_t ThpPlayerProfile::GetVehiclePreferedCameraThirdPerson() const
	{
		auto* data = this->instances->at(0).members->at(26).data;
		return *reinterpret_cast<uint8_t*>(data);
	}

	std::vector<uint32_t> ThpPlayerProfile::GetGivenDLCItems() const
	{
		std::vector<uint32_t> buffer(11);
		std::vector<Member> *instance_members = this->instances->at(0).members->at(27).sub_members;
		for (auto it = instance_members->begin(); it != instance_members->end(); ++it)
		{
			uint32_t idx = it - instance_members->begin();
			buffer.at(idx) = *reinterpret_cast<uint32_t*>(it->data);
		}
		return buffer;
	}

	uint32_t ThpPlayerProfile::GetEquippedBackpackHash() const
	{
		auto* data = this->instances->at(0).members->at(28).data;
		return *reinterpret_cast<uint32_t*>(data);
	}

	std::vector<uint32_t> ThpPlayerProfile::GetUnlockedHuntClubEquipment() const
	{
		std::vector<uint32_t> buffer(2);
		std::vector<Member> *instance_members = this->instances->at(0).members->at(29).sub_members;
		for (auto it = instance_members->begin(); it != instance_members->end(); ++it)
		{
			uint32_t idx = it - instance_members->begin();
			buffer.at(idx) = *reinterpret_cast<uint32_t*>(it->data);
		}
		return buffer;
	}

	uint8_t ThpPlayerProfile::GetHuntClubDisabled() const
	{
		auto* data = this->instances->at(0).members->at(30).data;
		return *reinterpret_cast<uint8_t*>(data);
	}

	float ThpPlayerProfile::GetAnimalSensesMultiplier() const
	{
		auto* data = this->instances->at(0).members->at(31).data;
		return *reinterpret_cast<float*>(data);
	}

	// GetModifiedLockModes()
	
	uint8_t ThpPlayerProfile::GetProfileIsNew() const
	{
		auto* data = this->instances->at(0).members->at(33).data;
		return *reinterpret_cast<uint8_t*>(data);
	}

	std::vector<PPWeaponData> ThpPlayerProfile::GetWeaponData() const
	{
		std::vector<PPWeaponData> buffer(512);
		std::vector<Member> *instance_members = this->instances->at(0).members->at(34).sub_members;
		for (auto it = instance_members->begin(); it != instance_members->end(); ++it)
		{
			uint32_t idx = it - instance_members->begin();
			PPWeaponData *pp_weapon_data = new PPWeaponData(
				*reinterpret_cast<uint32_t*>(it->sub_members->at(0).data),
				*reinterpret_cast<uint32_t*>(it->sub_members->at(1).data),
				*reinterpret_cast<uint32_t*>(it->sub_members->at(2).data),
				*reinterpret_cast<uint32_t*>(it->sub_members->at(3).data),
				*reinterpret_cast<uint32_t*>(it->sub_members->at(4).data),
				*reinterpret_cast<uint32_t*>(it->sub_members->at(5).data),
				*reinterpret_cast<float*>(it->sub_members->at(6).data),
				*reinterpret_cast<uint32_t*>(it->sub_members->at(7).data),
				*reinterpret_cast<float*>(it->sub_members->at(8).data)
			);
			buffer.at(idx) = *pp_weapon_data;
			delete pp_weapon_data;
		}
		return buffer;
	}

	// GetShownHuntClubOptIn()
	// GetHuntClubHash()
}
