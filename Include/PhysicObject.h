/*
 * PhysicObject.h
 *
 *  Created on: Dec 14, 2016
 *      Author: lukier
 */

#ifndef SRC_PHYSICOBJECT_H_
#define SRC_PHYSICOBJECT_H_

#include "WorldObject.h"

namespace AngryZPR {

class PhysicObject: public WorldObject {
public:
	PhysicObject();
	virtual ~PhysicObject();


	virtual void draw(const World::Camera &camera) = 0;
};

} /* namespace AngryZPR */

#endif /* SRC_PHYSICOBJECT_H_ */
