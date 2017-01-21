/*
 * Block.cpp
 *
 *  Created on: Jan 10, 2017
 *      Author: �ukasz Kowalczyk
 */
#include <iostream>

#include <SFML/Graphics.hpp>
#include "../Include/SystemManager.h"

#include "../Include/Block.h"
#include "../Include/Constants.h"
namespace AngryZPR {

/*
 *
 */

Block::Block(b2Body * _body, float block_w, float block_h) : PhysicObject(_body) {
	mBlockH = block_h;
	mBlockW = block_w;
}

void Block::draw(const World::Camera &camera) const {

	float angle = mBody->GetAngle();

	sf::RectangleShape rect(sf::Vector2f(mBlockW, mBlockH));
	rect.setRotation((float)(angle*180.0f/3.14f));
	rect.setFillColor(sf::Color::Black);
	rect.setOrigin(sf::Vector2f(mBlockW/2.0f, mBlockH/2.0f));
	rect.setPosition(mX, mY);

	SystemManager::getSingleton().draw(rect);
}

Block * Block::create(b2World &world, float x, float y, float angle)  {

	const float DEF_W = 10.0f, DEF_H = 50.0f;

	b2Body * body = PhysicObject::createBody(world, x, y, angle, 6.0f, 0.0f, 0.0f, 0.8f, DEF_W, DEF_H);

	return new Block(body, DEF_W, DEF_H);
}



} /* namespace AngryZPR */
