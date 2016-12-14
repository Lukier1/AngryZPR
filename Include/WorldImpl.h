/*
 * WorldImpl.h
 *
 *  Created on: Dec 14, 2016
 *      Author: lukier
 */

#ifndef INCLUDE_WORLDIMPL_H_
#define INCLUDE_WORLDIMPL_H_

#include "World.h"

namespace AngryZPR {

	class WorldImpl : public World {
	private:
		World::Camera mCamera;
	public:
		WorldImpl();
		virtual ~WorldImpl();

		void acceptMouseEvent(MouseEvent ev, float x, float y);
		void acceptKeyEvent(KeyEvent ev, sf::Keyboard::Key key);

		void draw();
		void update(float time);
	};

} /* namespace AngryZPR */

#endif /* INCLUDE_WORLDIMPL_H_ */
