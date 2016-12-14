/*
 * SystemManager.h
 *
 *  Created on: Dec 6, 2016
 *      Author: lukier
 */

#ifndef INCLUDE_SYSTEMMANAGER_H_
#define INCLUDE_SYSTEMMANAGER_H_

#include <memory>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "ControllerListener.h"

namespace AngryZPR {

class SystemManager {
private:
	unsigned short mWindowH, mWindowW;

	std::unique_ptr<sf::RenderWindow> mWindow;
	SystemManager();
	std::vector<ControllerListener*> mContListeners;
	
	void updateMouseEvent(ControllerListener::MouseEvent ev, float x, float y);
	void updateKeyEvent(ControllerListener::KeyEvent ev, sf::Keyboard::Key key);

public:
	static SystemManager& getSingleton();
	virtual ~SystemManager();
	
	void setWindow(unsigned short w, unsigned short h);
	unsigned short getWindowH() const;
	unsigned short getWindowW() const;

	void eventPoll();

	void beginDraw();
	void endDraw();
	void draw(const sf::Drawable& drawable, const sf::RenderStates& renderStates=sf::RenderStates::Default);

	bool isOpen() const;

	void registerListener(ControllerListener * listener);
	void deregisterListener(ControllerListener * listener);

	unsigned int getListenersNum() const;
};

}
#endif /* INCLUDE_SYSTEMMANAGER_H_ */
