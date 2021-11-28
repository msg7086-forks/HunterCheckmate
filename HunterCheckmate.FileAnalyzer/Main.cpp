#include "CLI.h"

// TODO: - add -rep -preset presets
// TODO: - add preset cli (print available presets upon asking user which animal presets to print)
// 
// TODO: - make exception class for e.g. if (!initialized) return 0 in AdfFile.cpp;

int main(int argc, char *argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

#pragma region CLI
	using namespace HunterCheckmate_FileAnalyzer;
	const std::unique_ptr<CLI> cli = std::make_unique<CLI>(argc, argv);
	cli->run();
#pragma endregion

	return 0;
}