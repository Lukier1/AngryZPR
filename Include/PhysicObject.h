/*
 * PhysicObject.h
 *
 *  Created on: Dec 14, 2016
 *      Author: £ukasz Kowalczyk
 */

#ifndef SRC_PHYSICOBJECT_H_
#define SRC_PHYSICOBJECT_H_

#include <Box2D/Box2D.h>
#include "WorldObject.h"

namespace AngryZPR {

class PhysicObject: public WorldObject {
protected:

	b2Body * mBody;
	static b2Body * createBody(b2World &world, float x, float y, float angle, float density, float linearDamping, float angularDamping, float friction, float w, float h);
public:
	PhysicObject(b2Body * body);
	virtual ~PhysicObject();
	
	virtual void draw(const World::Camera &camera) = 0;

	virtual void applyForce(float angle, float power);
};

} /* namespace AngryZPR */

#endif /* SRC_PHYSICOBJECT_H_ */
