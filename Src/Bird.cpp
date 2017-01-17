/*
 * Bird.cpp
 *
 *  Created on: Jan 10, 2017
 *      Author: lukier
 */
#include <iostream>

#include <SFML/Graphics.hpp>
#include "../Include/SystemManager.h"

#include "../Include/Bird.h"
#include "../Include/Constants.h"
namespace AngryZPR {

Bird::Bird(b2Body * _body)  : PhysicObject(_body) {
	// TODO Auto-generated constructor stub

}

Bird::~Bird() {
	// TODO Auto-generated destructor stub
}
void Bird::draw(const World::Camera &camera) {
	mX = mBody->GetPosition().x/WORLD_SCALE;
	mY = mBody->GetPosition().y/WORLD_SCALE;
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

	//return new Block(body, DEF_W, DEF_H);
	return new Bird(body);
}


Bird * Bird::temp(b2Body * body) {
	return new Bird(body);
}

} /* namespace AngryZPR */
