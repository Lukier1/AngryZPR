/*
* World.h
*
*  Created on: Jan 10, 2017
*      Author: �ukasz Kowalczyk
*/

#ifndef __WORLD_H__
#define __WORLD_H__


#include "ControllerListener.h"

namespace AngryZPR {

class World : public ControllerListener {

public:
	struct Camera {
		float x, y;
		float w, h;
		Camera() { x = 0; y = 0; w = 0; h = 0; }
	};
	virtual void acceptMouseEvent(MouseEvent ev, int x, int y) = 0;
	virtual void acceptKeyEvent(KeyEvent ev, sf::Keyboard::Key key) = 0;

	/*
	 * Metoda rysujaca
	 */
	virtual void draw() = 0;
	/*
	 * Metoda aktulizacja logike
	 * \param time różnica czasu miedzy klatkami
	 */
	virtual void update(float time) = 0;

};

}

#endif
