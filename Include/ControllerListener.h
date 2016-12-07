/*
 * ControllerListener.h
 *
 *  Created on: Dec 7, 2016
 *      Author: lukier
 */

#ifndef INCLUDE_CONTROLLERLISTENER_H_
#define INCLUDE_CONTROLLERLISTENER_H_

#include <SFML/Window/Event.hpp>
namespace AngryZPR {
	class ControllerListener {
	public:
		virtual void accept(const sf::Event &event) = 0;
	};
}

#endif /* INCLUDE_CONTROLLERLISTENER_H_ */
