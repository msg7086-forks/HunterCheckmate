#include "Injector.h"

namespace fs = boost::filesystem;

int main(int argc, char *argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	constexpr LPCSTR path_dll = R"(C:\Users\oleSQL\source\repos\HunterCheckmate\Debug\HunterCheckmate.DllHax.dll)";
	std::string target = "notepad++.exe";

	const std::unique_ptr<Injector> injector = std::make_unique<Injector>(fs::path(path_dll), target);
	injector->run();

	return 0;
}