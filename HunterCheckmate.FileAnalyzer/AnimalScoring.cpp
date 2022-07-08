#include "AnimalScoring.h"

namespace HunterCheckmate_FileAnalyzer
{
	AnimalScoring::AnimalScoring(std::shared_ptr<FileHandler> file_handler)
		: AdfFile(file_handler) {}

	bool MapAnimalSettings()
	{
		return true;
	}
}