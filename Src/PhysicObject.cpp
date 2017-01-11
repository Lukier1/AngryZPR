/*
 * PhysicObject.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: lukier
 */

#include "../Include/PhysicObject.h"

namespace AngryZPR {

PhysicObject::PhysicObject(b2Body * body) : mBody(body) {
	mBody->SetSleepingAllowed(false);
	//Body->SetAwake(false);
	// TODO Auto-generated constructor stub

}

PhysicObject::~PhysicObject() {
	// TODO Auto-generated destructor stub
}

void PhysicObject::applyForce(float angle, float power) {
	b2Vec2 forceVec;
	forceVec.x = cos(angle/180*3.14);
	forceVec.y = sin(angle/180*3.14);

	forceVec*=power;

	mBody->ApplyForceToCenter(forceVec,true);

}

} /* namespace AngryZPR */
