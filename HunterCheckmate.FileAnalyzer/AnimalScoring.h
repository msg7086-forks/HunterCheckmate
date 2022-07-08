#pragma once
#include "AdfFile.h"
#include "AnimalTypeEnum.h"
#include "AnimalSettings.h"

namespace HunterCheckmate_FileAnalyzer
{
	class AnimalScoring : public AdfFile
	{
	private:
	public:
		std::map<AnimalType, AnimalSettings> m_animal_settings;

		AnimalScoring(std::shared_ptr<FileHandler> file_handler);
		~AnimalScoring() = default;

		bool MapAnimalSettings();
	};

}