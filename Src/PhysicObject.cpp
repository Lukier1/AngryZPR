/*
 * PhysicObject.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: lukier
 */

#include "../Include/PhysicObject.h"
#include "../Include/Constants.h"
namespace AngryZPR {

PhysicObject::PhysicObject(b2Body * body) : mBody(body) {
	mBody->SetSleepingAllowed(false);
	//Body->SetAwake(false);
	// TODO Auto-generated constructor stub

}

PhysicObject::~PhysicObject() {
	mBody->SetActive(false);
}

void PhysicObject::applyForce(float angle, float power) {
	b2Vec2 forceVec;
	forceVec.x = (float)cos(angle/180*3.14);
	forceVec.y = (float)-sin(angle/180*3.14);

	forceVec*=power;

	mBody->ApplyForceToCenter(forceVec,true);

}

b2Body * PhysicObject::createBody(b2World &world, float x, float y, float angle, float density, float linearDamping, float angularDamping, float friction, float w, float h) {
	b2FixtureDef fixtureDef;
	b2PolygonShape dynamicBox;
	b2BodyDef bodyDef;

	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x*WORLD_SCALE, y*WORLD_SCALE);
	bodyDef.angle = angle;
	bodyDef.linearDamping = linearDamping;
	bodyDef.angularDamping = angularDamping;
	dynamicBox.SetAsBox(w*WORLD_SCALE/2.0f, h*WORLD_SCALE/2.0f);

	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = density;
	fixtureDef.friction = friction;

	b2Body * body = world.CreateBody(&bodyDef);

	body->CreateFixture(&fixtureDef);
	body->SetSleepingAllowed(false);

	return body;
}
} /* namespace AngryZPR */
