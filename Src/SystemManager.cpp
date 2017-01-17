/*
 * SystemManager.cpp
 *
 *  Created on: Dec 6, 2016
 *      Author: lukier
 */

#include <iostream>

#include "../Include/SystemManager.h"

using namespace sf;
using namespace AngryZPR;
SystemManager::SystemManager() : mWindowH(600), mWindowW(800), mWindow(new RenderWindow(VideoMode(mWindowW, mWindowH,32),"AngryZPR")){
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
		switch (event.type) {
			case sf::Event::EventType::MouseMoved:
				updateMouseEvent(ControllerListener::MouseEvent::MOUSE_MOVE, event.mouseMove.x, event.mouseMove.y);
				break;
			case sf::Event::EventType::MouseButtonPressed:
					if(event.mouseButton.button == sf::Mouse::Button::Left)
						updateMouseEvent(ControllerListener::MouseEvent::MOUSE_LBUTTON_PRESS, event.mouseButton.x, event.mouseButton.y);
					if (event.mouseButton.button == sf::Mouse::Button::Right) 
						updateMouseEvent(ControllerListener::MouseEvent::MOUSE_RBUTTON_PRESS, event.mouseButton.x, event.mouseButton.y);

			break;
			case sf::Event::EventType::MouseButtonReleased:

					if(event.mouseButton.button == sf::Mouse::Button::Left)
						updateMouseEvent(ControllerListener::MouseEvent::MOUSE_LBUTTON_RELEASE, event.mouseButton.x, event.mouseButton.y);
					if(event.mouseButton.button == sf::Mouse::Button::Right)
						updateMouseEvent(ControllerListener::MouseEvent::MOUSE_RBUTTON_RELEASE, event.mouseButton.x, event.mouseButton.y);

			break;
			default:
				break;
		}
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


void SystemManager::registerListener(std::shared_ptr<ControllerListener> listener) {
	if(listener != nullptr)
	{
		bool exist = false;
		for(auto it = mContListeners.begin(); it != mContListeners.end(); ++it)
		{
			if(*it == listener)
			{
				exist = true; 
				break;
			}
		}
		if(!exist)
			mContListeners.push_back(listener);
	}
}
void SystemManager::deregisterListener(std::shared_ptr<ControllerListener> listener) {
	if(listener != nullptr) {
		for(auto it = mContListeners.begin(); it != mContListeners.end(); ++it)
		{
			if(*it == listener)
			{
				mContListeners.erase(it);
				break;
			}
		}
	}
}

void AngryZPR::SystemManager::updateMouseEvent(ControllerListener::MouseEvent ev, int x, int y) {
	for(auto list : mContListeners)
	{
		list->acceptMouseEvent(ev, x, y);
	}
}

void AngryZPR::SystemManager::updateKeyEvent(ControllerListener::KeyEvent ev, sf::Keyboard::Key key) {
	for(auto list : mContListeners)
		{
			list->acceptKeyEvent(ev, key);
		}
}

unsigned int AngryZPR::SystemManager::getListenersNum() const {
	return mContListeners.size();
}
