#include <iostream>

#include "../Include/Root.h"
#include "../Include/SystemManager.h"

Root::Root() {
	std::cout << "Root created";

	InitSingleton();
}

void Root::InitSingleton() {
	 SystemManager::getSingleton();
}
