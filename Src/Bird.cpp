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
	mY = -mBody->GetPosition().y/WORLD_SCALE-WORLD_SCALE*10;
	float angle = mBody->GetAngle();
	sf::CircleShape circle(16.0f);
	sf::RectangleShape rect(sf::Vector2f(10.0f, 10.0f));
	rect.setRotation(angle*180/3.14);
	rect.setOrigin(sf::Vector2f(5.0f, 5.0f));
	rect.setPosition(mX, mY);
	SystemManager::getSingleton().draw(rect);
}

Bird * Bird::createBird(b2World &world, float x, float y, float forcePower, float angle)  {

	b2FixtureDef fixtureDef;
	b2PolygonShape dynamicBox;
	b2BodyDef bodyDef;

	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x*WORLD_SCALE, -y*WORLD_SCALE);

	dynamicBox.SetAsBox(5.0f,5.0f);

	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	b2Body * body = world.CreateBody(&bodyDef);

	body->CreateFixture(&fixtureDef);


	//body->SetAwake(true);
	//body->SetActive(true);
	//body->SetGravityScale(1.0f);

	b2Vec2 forceVec;
	forceVec.x = cos(angle/180*3.14);
	forceVec.y = sin(angle/180*3.14);

	forceVec*=forcePower;

	//body->ApplyForceToCenter(forceVec, true);

	return new Bird(body);
}


Bird * Bird::temp(b2Body * body) {
	return new Bird(body);
}
/*
b2PolygonShape PhysicObject::getPolygonShape() const {
	return mPolygonShape;
}

b2FixtureDef PhysicObject::getFixtureDef() const {
	return mFixtureDef;
}*/
} /* namespace AngryZPR */
