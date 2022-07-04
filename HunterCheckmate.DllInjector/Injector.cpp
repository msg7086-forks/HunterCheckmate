#include "Injector.h"

DWORD Injector::get_pid() const
{
	PROCESSENTRY32 proc_entry;
	proc_entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &proc_entry) == TRUE)
	{
		while (Process32Next(snapshot, &proc_entry) == TRUE)
		{
			if (_stricmp(proc_entry.szExeFile, m_target.c_str()) == 0)
			{
				return proc_entry.th32ProcessID;
			}
		}
	}

	return 0;
}

void Injector::run()
{
	std::cout << "[*] getting target pid";
	const DWORD pid_target = get_pid();

	if (pid_target)
	{
		std::cout << " => success!\n";
		std::cout << "[*] allocating memory in target";
		HANDLE h_proc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid_target);
		if (h_proc)
		{
			LPVOID addr_dll_path = VirtualAllocEx(h_proc, nullptr, _MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
			if (addr_dll_path)
			{
				std::cout << " => success!\n";
				std::cout << "[*] writing dll path in target memory";
				const std::string str_dll_path = m_dll_path.generic_string();
				const char* c_dll_path = str_dll_path.c_str();
				if (WriteProcessMemory(h_proc, addr_dll_path, c_dll_path, strlen(c_dll_path), nullptr))
				{
					std::cout << " => success!\n";
					std::cout << "[*] attempting to remote execute LoadLibraryA()";
					HANDLE h_thread = CreateRemoteThread(h_proc, nullptr, 0,
														 reinterpret_cast<LPTHREAD_START_ROUTINE>(GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA")),
														 addr_dll_path, 0, nullptr);
					if (h_thread)
					{
						std::cout << " => success!\n";
						WaitForSingleObject(h_thread, INFINITE);
						DWORD exit_code;
						GetExitCodeThread(h_thread, &exit_code);
						std::cout << "[*] proceeding with cleanup";
						CloseHandle(h_thread);
						VirtualFreeEx(h_proc, addr_dll_path, 0, MEM_RELEASE);
						std::cout << " => success!\n";
					}
					else std::cout << " => failed!\n";
				}
				else std::cout << "=> failed!\n";
			}
			else std::cout << " => failed!\n";

			CloseHandle(h_proc);
		}
		std::cout << "[*] injection done!\n";
	}
	else std::cout << " => failed!\n";
}