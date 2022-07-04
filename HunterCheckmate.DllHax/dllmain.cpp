#include "Windows.h"
#include <iostream>
#include <thread>
#include <boost/interprocess/managed_shared_memory.hpp>

[[noreturn]] void WINAPI Hax(HMODULE hModule)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	AllocConsole();

	freopen_s(reinterpret_cast<FILE**>stdout, "CONOUT$", "w", stdout);
	std::cout << "[*] Henlo!\n";

	namespace shm = boost::interprocess;

	shm::managed_shared_memory segment(shm::open_only, "MySHM");

	std::pair<int*, shm::managed_shared_memory::size_type> summin = segment.find<int>("GIBINT");

	std::cout << "Got " << *summin.first << " from shared mem";

	segment.destroy<int>("GIBINT");

	while(!GetAsyncKeyState(VK_END))
		std::this_thread::sleep_for(std::chrono::seconds(1));

	fclose(stdout);
	FreeConsole();
	FreeLibraryAndExitThread(hModule, 0);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    	CloseHandle(CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(Hax), hModule, 0, nullptr));
    case DLL_THREAD_ATTACH:
		break;
    case DLL_THREAD_DETACH:
		break;
    case DLL_PROCESS_DETACH:
		break;
    }
    return TRUE;
}