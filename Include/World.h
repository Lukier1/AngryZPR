#ifndef __WORLD_H__
#define __WORLD_H__


#include "ControllerListener.h"

namespace AngryZPR {

class World : public ControllerListener {

public:
	struct Camera {
		float X, Y;
		float W, H;
		Camera() { X = 0; Y = 0; W = 0; H = 0; }
	};
	virtual void acceptMouseEvent(MouseEvent ev, int x, int y) = 0;
	virtual void acceptKeyEvent(KeyEvent ev, sf::Keyboard::Key key) = 0;

	virtual void draw() = 0;
	virtual void update(float time) = 0;

	virtual void addPhyicObject() = 0;

};

}

#endif
