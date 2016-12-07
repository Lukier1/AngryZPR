/*
 * SystemManager.cpp
 *
 *  Created on: Dec 6, 2016
 *      Author: lukier
 */

#include "../Include/SystemManager.h"
#include <iostream>
using namespace sf;
using namespace AngryZPR;
SystemManager::SystemManager() : mWindowH(600), mWindowW(800), mWindow(new RenderWindow(VideoMode(mWindowH, mWindowH,32),"AngryZPR")){
	// TODO Auto-generated constructor stub

}

SystemManager& SystemManager::getSingleton(){
	static SystemManager sysMgr;
	return sysMgr;
}

SystemManager::~SystemManager() {
	// TODO Auto-generated destructor stub
	std::cout << "SystemManager destroyed" << std::endl;
}

void SystemManager::setWindow(unsigned short w, unsigned short h) {
	mWindow->setSize(sf::Vector2u(w,h));
	mWindowW  = w;
	mWindowH = h;
}

unsigned short SystemManager::getWindowH() const {
	return mWindowH;
}

unsigned short SystemManager::getWindowW() const {
	return mWindowW;
}

void SystemManager::eventPoll() {
	sf::Event event;
	while (mWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mWindow->close();
	}
}

void SystemManager::beginDraw()
{
	mWindow->clear();
}

void SystemManager::endDraw() {
	mWindow->display();
}
void SystemManager::draw(const Drawable& drawable, const RenderStates& renderStates) {
	mWindow->draw(drawable, renderStates);
}


bool SystemManager::isOpen() const {
	return mWindow->isOpen();
}
