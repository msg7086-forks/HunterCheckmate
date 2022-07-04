#include "CLI.h"

#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif

#include <boost/interprocess/managed_shared_memory.hpp>

namespace shm = boost::interprocess;

int main(int argc, char *argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	using namespace HunterCheckmate_FileAnalyzer;
	const std::unique_ptr<CLI> cli = std::make_unique<CLI>(argc, argv);
	cli->run();

	struct shm_remove
	{
		shm_remove() { shm::shared_memory_object::remove("MySHM"); }
		~shm_remove() { shm::shared_memory_object::remove("MySHM"); }
	} remover;

	//Construct managed shared memory
	shm::managed_shared_memory segment(shm::create_only, "MySHM", 0x128);

	//Create an object of MyType initialized to {0.0, 0}
	int* instance = segment.construct<int>("GIBINT") (420);

	return 0;
}