/*
 * WorldImpl.h
 *
 *  Created on: Dec 14, 2016
 *      Author: �ukasz Kowalczyk
 */

#ifndef INCLUDE_WORLDIMPL_H_
#define INCLUDE_WORLDIMPL_H_

#include <memory>

#include <Box2D/Box2D.h>
#include "World.h"
#include "WorldObject.h"
#include "Slingshot.h"
namespace AngryZPR {

	class WorldImpl : public World {
	private:
		b2Vec2 mGravity;
		b2World mWorld;

		World::Camera mCamera;

		std::vector<WorldObject*> mObjects;
		b2Body * mGroundBody;
		Slingshot * mSlingshot;


		void processEvent(WorldObject * object, WorldObject::ObjectEvent obj_event);

		void deleteObject(WorldObject * object);
	public:
		WorldImpl();
		virtual ~WorldImpl();

		void acceptMouseEvent(MouseEvent ev, int x, int y);
		void acceptKeyEvent(KeyEvent ev, sf::Keyboard::Key key);

		void draw();
		void update(float time);
	};

} /* namespace AngryZPR */

#endif /* INCLUDE_WORLDIMPL_H_ */
