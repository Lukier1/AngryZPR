/*
 * SystemManager.h
 *
 *  Created on: Dec 6, 2016
 *      Author: lukier
 */

#ifndef INCLUDE_SYSTEMMANAGER_H_
#define INCLUDE_SYSTEMMANAGER_H_

#include <memory>
#include <SFML/Window.hpp>

class SystemManager {
private:
	unsigned short mWindowH, mWindowW;

	std::unique_ptr<sf::Window> window;
	SystemManager();

	
public:
	static SystemManager& getSingleton();
	virtual ~SystemManager();
	
	void SetWindow(unsigned short w, unsigned short h);
	unsigned short getWindowH() const;
	unsigned short getWindowW() const;
};

#endif /* INCLUDE_SYSTEMMANAGER_H_ */
