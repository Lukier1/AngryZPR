#include <iostream>

#include "../Include/Root.h"
#include "../Include/SystemManager.h"
#include "../Include/StateManager.h"

using namespace AngryZPR;
Root::Root() {
	std::cout << "Root created" << std::endl;

	initSingleton();
}

void Root::initSingleton() {
	 SystemManager::getSingleton();
}

bool Root::run() {
	SystemManager& sysMgr = SystemManager::getSingleton();
	sysMgr.eventPoll();

	mStateManager.update();

	sysMgr.beginDraw();
	mStateManager.draw();
	sysMgr.endDraw();



	return sysMgr.isOpen();
}

