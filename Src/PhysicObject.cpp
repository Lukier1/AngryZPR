/*
 * PhysicObject.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: �ukasz Kowalczyk
 */

#include "../Include/PhysicObject.h"
#include "../Include/Constants.h"
namespace AngryZPR {

PhysicObject::PhysicObject(b2Body * body) : mBody(body) {
	mBody->SetSleepingAllowed(false);
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

b2Body * PhysicObject::createBody(b2World &world, float x, float y, float angle, float density, float linear_damping, float angular_damping, float friction, float w, float h) {
	b2FixtureDef fixtureDef;
	b2PolygonShape dynamicBox;
	b2BodyDef bodyDef;

	const float BOX2D_REDUCTOR = 2.0f;

	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x*WORLD_SCALE, y*WORLD_SCALE);
	bodyDef.angle = angle;
	bodyDef.linearDamping = linear_damping;
	bodyDef.angularDamping = angular_damping;
	dynamicBox.SetAsBox(w*WORLD_SCALE / BOX2D_REDUCTOR, h*WORLD_SCALE / BOX2D_REDUCTOR);

	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = density;
	fixtureDef.friction = friction;

	b2Body * body = world.CreateBody(&bodyDef);

	body->CreateFixture(&fixtureDef);
	body->SetSleepingAllowed(false);

	return body;
}
PhysicObject::ObjectEvent AngryZPR::PhysicObject::update(float time) {
	mX = mBody->GetPosition().x/WORLD_SCALE;
	mY = mBody->GetPosition().y/WORLD_SCALE;

	return PhysicObject::ObjectEvent::NONE;
}

}
/* namespace AngryZPR */


