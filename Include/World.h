#ifndef __WORLD_H__
#define __WORLD_H__

namespace AngryZPR {

class World : public ControllerListener {
public:
	virtual void acceptMouseEvent(MouseEvent ev, float x, float y) = 0;
	virtual void acceptKeyEvent(KeyEvent ev, sf::Keyboard::Key key) = 0;

	virtual void draw() = 0;
	virtual void update(float time) = 0;
};

}

#endif
