/*
 * Bird.cpp
 *
 *  Created on: Jan 10, 2017
 *      Author: �ukasz Kowalczyk
 */
#include <iostream>

#include <SFML/Graphics.hpp>
#include "../Include/SystemManager.h"

#include "../Include/Bird.h"
#include "../Include/Constants.h"
namespace AngryZPR {

Bird::Bird(b2Body * _body) : PhysicObject(_body), mTimeNoSpeed(0) {
}

void Bird::draw(const World::Camera &camera) const {

	float angle = mBody->GetAngle();
	
	sf::RectangleShape rect(sf::Vector2f(10.0f, 10.0f));
	rect.setFillColor(sf::Color::Yellow);
	rect.setRotation(angle*180.0f/3.14f);
	rect.setOrigin(sf::Vector2f(5.0f, 5.0f));
	rect.setPosition(mX, mY);
	SystemManager::getSingleton().draw(rect);
}

Bird * Bird::createBird(b2World &world, float x, float y)  {
	const float DEF_W = 10.0f, DEF_H = 10.0f;

	b2Body * body = PhysicObject::createBody(world, x, y, 0.0f, 5.0f, 0.0f, 0.0f, 0.3f, DEF_W, DEF_H);

	return new Bird(body);
}


WorldObject::ObjectEvent Bird::update(float time) {
	mX = mBody->GetPosition().x/WORLD_SCALE;
	mY = mBody->GetPosition().y/WORLD_SCALE;
	
	if (mBody->GetLinearVelocity().Length() < 0.1f)
		mTimeNoSpeed += time;
	else
		mTimeNoSpeed = 0;
	if (mTimeNoSpeed > 0.5f)
		return WorldObject::ObjectEvent::DESTROY_ITSELF;
	return WorldObject::ObjectEvent::NONE;
}

} /* namespace AngryZPR */
