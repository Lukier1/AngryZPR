/*
 * Bird.h
 *
 *  Created on: Jan 10, 2017
 *      Author: lukier
 */

#ifndef INCLUDE_BIRD_H_
#define INCLUDE_BIRD_H_

#include "PhysicObject.h"

namespace AngryZPR {

class Bird: public PhysicObject {
private:
	Bird(b2Body * body);

protected:

public:
	virtual ~Bird();

	virtual void draw(const World::Camera &camera);
	static Bird * createBird(b2World &world, float x, float y);
	static Bird * temp(b2Body * body);
};

} /* namespace AngryZPR */

#endif /* INCLUDE_BIRD_H_ */
