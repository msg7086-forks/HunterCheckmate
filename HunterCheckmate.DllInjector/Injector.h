#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

class Injector
{
private:
	fs::path m_dll_path;
	std::string m_target;
	DWORD get_pid() const;
public:
	Injector(fs::path dll, std::string target)
		: m_dll_path(std::move(dll)), m_target(std::move(target)) {}
	~Injector() = default;

	void run();
};