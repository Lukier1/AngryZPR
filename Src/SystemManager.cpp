/*
 * SystemManager.cpp
 *
 *  Created on: Dec 6, 2016
 *      Author: �ukasz Kowalczyk
 */


#include <iostream>

#include "../Include/SystemManager.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
static const int BUG_FIX = 0;
#else
static const int BUG_FIX = 1;
#endif


using namespace sf;
using namespace AngryZPR;
SystemManager::SystemManager() : mWindowH(600), mWindowW(800), mWindow(new RenderWindow(VideoMode(mWindowW, mWindowH,32),"AngryZPR")){

}

SystemManager& SystemManager::getSingleton(){
	static SystemManager sysMgr;
	return sysMgr;
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
		std::cout << event.type << std::endl;
		switch (event.type + BUG_FIX) { // Wartośc zwieszkona o jeden w zwiazku z bugiem w SFML
			case (sf::Event::MouseMoved):
				updateMouseEvent(ControllerListener::MouseEvent::MOUSE_MOVE, event.mouseMove.x, event.mouseMove.y);

				break;
			case (sf::Event::MouseButtonReleased):

						if(event.mouseButton.button == sf::Mouse::Button::Left) {
							updateMouseEvent(ControllerListener::MouseEvent::MOUSE_LBUTTON_RELEASE, event.mouseButton.x, event.mouseButton.y);
						}
						if(event.mouseButton.button == sf::Mouse::Button::Right)
							updateMouseEvent(ControllerListener::MouseEvent::MOUSE_RBUTTON_RELEASE, event.mouseButton.x, event.mouseButton.y);

			break;
			case sf::Event::MouseButtonPressed:
					if(event.mouseButton.button == sf::Mouse::Button::Left)
						updateMouseEvent(ControllerListener::MouseEvent::MOUSE_LBUTTON_PRESS, event.mouseButton.x, event.mouseButton.y);
					if (event.mouseButton.button == sf::Mouse::Button::Right) 
						updateMouseEvent(ControllerListener::MouseEvent::MOUSE_RBUTTON_PRESS, event.mouseButton.x, event.mouseButton.y);

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
void SystemManager::draw(const Drawable& drawable, const RenderStates& render_states) {
	mWindow->draw(drawable, render_states);
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
