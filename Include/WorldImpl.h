/*
 * WorldImpl.h
 *
 *  Created on: Dec 14, 2016
 *      Author: lukier
 */

#ifndef INCLUDE_WORLDIMPL_H_
#define INCLUDE_WORLDIMPL_H_

#include <Box2D/Box2D.h>
#include "World.h"

namespace AngryZPR {

	class WorldImpl : public World {
	private:
		b2Vec2 mGravity;
		b2World mWorld;

		World::Camera mCamera;
	public:
		WorldImpl();
		virtual ~WorldImpl();

		void acceptMouseEvent(MouseEvent ev, float x, float y);
		void acceptKeyEvent(KeyEvent ev, sf::Keyboard::Key key);

		void draw();
		void update(float time);

		void addPhyicObject();
	};

} /* namespace AngryZPR */

#endif /* INCLUDE_WORLDIMPL_H_ */
