/*
 * Block.cpp
 *
 *  Created on: Jan 10, 2017
 *      Author: lukier
 */
#include <iostream>

#include <SFML/Graphics.hpp>
#include "../Include/SystemManager.h"

#include "../Include/Block.h"
#include "../Include/Constants.h"
namespace AngryZPR {

Block::Block(b2Body * _body)  : PhysicObject(_body) {
	// TODO Auto-generated constructor stub

}

Block::~Block() {
	// TODO Auto-generated destructor stub
}
void Block::draw(const World::Camera &camera) {
	mX = mBody->GetPosition().x/WORLD_SCALE;
	mY = -mBody->GetPosition().y/WORLD_SCALE-WORLD_SCALE*10;

	float angle = mBody->GetAngle();

	sf::RectangleShape rect(sf::Vector2f(10.0f, 50.0f));
	rect.setRotation(-angle*180/3.14);
	rect.setFillColor(sf::Color::Black);
	rect.setOrigin(sf::Vector2f(5.0f, 25.0f));
	rect.setPosition(mX, mY);

	SystemManager::getSingleton().draw(rect);
}

Block * Block::create(b2World &world, float x, float y, float angle)  {

	b2FixtureDef fixtureDef;
	b2PolygonShape dynamicBox;
	b2BodyDef bodyDef;

	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x*WORLD_SCALE, -y*WORLD_SCALE);
	bodyDef.angle = angle;
	bodyDef.linearDamping = 0.0f;
	dynamicBox.SetAsBox(5.0f,25.0f);

	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 3.0f;

	fixtureDef.friction = 0.8f;

	b2Body * body = world.CreateBody(&bodyDef);

	body->CreateFixture(&fixtureDef);

	return new Block(body);
}


} /* namespace AngryZPR */
