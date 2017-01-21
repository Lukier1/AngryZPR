/*
 * ControllerListener.h
 *
 *  Created on: Dec 7, 2016
 *      Author: lukier
 */

#ifndef INCLUDE_CONTROLLERLISTENER_H_
#define INCLUDE_CONTROLLERLISTENER_H_

#include <SFML/Window/Event.hpp>
namespace AngryZPR
	/*
	 * Interfejs dla obiektów nasłuchujących wydarzeń związanych z myszką i klawiaturą
	 */{
	class ControllerListener {
	public:
		enum class MouseEvent {
			MOUSE_LBUTTON_PRESS,
			MOUSE_RBUTTON_PRESS,
			MOUSE_LBUTTON_RELEASE,
			MOUSE_RBUTTON_RELEASE,
			MOUSE_MOVE
		};
		enum class KeyEvent {
			KEY_PRESS,
			KEY_RELASE
		};

		/*
		 * Czysta funkcja wirtualna akceptujaca wydarzenia
		 * \param ev - nazwa wydarzaenia
		 * \param x - pozycja dla wydarzenia X
		 * \param y - pozycja dla wydarzenia Y
		 */
		virtual void acceptMouseEvent(MouseEvent ev, int x, int y) = 0;
		/*
		 * Czysta funkcja wirtualna akceptujaca wydarzenia
		 * \param ev - nazwa wydarzaenia
		 * \param key - kod naciśnietego klawisza
		 */
		virtual void acceptKeyEvent(KeyEvent ev, sf::Keyboard::Key key) = 0;
	};
}

#endif /* INCLUDE_CONTROLLERLISTENER_H_ */
