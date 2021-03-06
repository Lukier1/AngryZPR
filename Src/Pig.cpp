/*
* Pig.cpp
*
*  Created on: Jan 10, 2017
*      Author: �ukasz Kowalczyk
*/
#include <iostream>

#include <SFML/Graphics.hpp>
#include "../Include/SystemManager.h"

#include "../Include/Pig.h"
#include "../Include/Constants.h"
namespace AngryZPR {

	Pig::Pig(b2Body * _body, float pig_w, float pig_h) : PhysicObject(_body) {
		mPigH = pig_h;
		mPigW = pig_w;
	}

	void Pig::draw(const World::Camera &camera) const {


		float angle = mBody->GetAngle();

		sf::RectangleShape rect(sf::Vector2f(mPigW, mPigH));
		rect.setRotation((float)(angle*180.0f / 3.14f));
		rect.setFillColor(sf::Color(242,157,244)); // Pink color
		rect.setOrigin(sf::Vector2f(mPigW / 2.0f, mPigH / 2.0f));
		rect.setPosition(mX, mY);

		SystemManager::getSingleton().draw(rect);
	}
	
	Pig * Pig::create(b2World &world, float x, float y, float angle)  {
		const float DEF_W = 20.0f, DEF_H = 20.0f;

		b2Body * body = PhysicObject::createBody(world, x, y, angle, 2.0f, 0.0f, 0.0f, 0.8f, DEF_W, DEF_H);

		return new Pig(body, DEF_W, DEF_H);
		
	}

} /* namespace AngryZPR */
