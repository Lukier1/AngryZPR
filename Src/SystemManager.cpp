/*
 * SystemManager.cpp
 *
 *  Created on: Dec 6, 2016
 *      Author: lukier
 */

#include "../Include/SystemManager.h"

SystemManager::SystemManager() {
	// TODO Auto-generated constructor stub

}

SystemManager& SystemManager::getSingleton(){
	static SystemManager sysMgr;
	return sysMgr;
}

SystemManager::~SystemManager() {
	// TODO Auto-generated destructor stub
}

void SystemManager::SetWindow(unsigned short w, unsigned short h) {

}

unsigned short SystemManager::getWindowH() const {
	return mWindowH;
}

unsigned short SystemManager::getWindowW() const {
	return mWindowW;
}
