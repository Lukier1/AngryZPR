/*
 * PhysicObject.h
 *
 *  Created on: Dec 14, 2016
 *      Author: �ukasz Kowalczyk
 */

#ifndef SRC_PHYSICOBJECT_H_
#define SRC_PHYSICOBJECT_H_

#include <Box2D/Box2D.h>
#include "WorldObject.h"

namespace AngryZPR {
/*
 * Rodzic wszystkich obiektów na mapie dla których symulowana jest fizyka
 */

class PhysicObject: public WorldObject {
protected:
	PhysicObject(b2Body * body);
	b2Body * mBody;
	static b2Body * createBody(b2World &world, float x, float y, float angle, float density, float linearDamping, float angularDamping, float friction, float w, float h);
public:

	virtual ~PhysicObject();
	
	virtual void draw(const World::Camera &camera) const = 0;
	virtual ObjectEvent update(float time);

	/*
	 * Urzyj pewnej siły na obiekcie
	 */
	virtual void applyForce(float angle, float power);
};

} /* namespace AngryZPR */

#endif /* SRC_PHYSICOBJECT_H_ */
