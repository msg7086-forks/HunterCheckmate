#include "CLI.h"

#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif

int main(int argc, char *argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	using namespace HunterCheckmate_FileAnalyzer;
	const std::unique_ptr<CLI> cli = std::make_unique<CLI>(argc, argv);
	cli->run();

	return 0;
}