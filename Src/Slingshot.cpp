/*
 * Slingshot.cpp
 *
 *  Created on: Jan 10, 2017
 *      Author: £ukasz Kowalczyk
 */

#include <iostream>

#include <SFML/Graphics.hpp>
#include "../Include/Slingshot.h"
#include "../Include/SystemManager.h"
namespace AngryZPR {

Slingshot::Slingshot() {
	mX = 150.0f;
	mY = 400.0f;
}


void Slingshot::draw(const World::Camera &camera) {
	if(mState == State::PRELOADING)
	{
		float speed = getLengthVelocity();
		float angle = -getAngle(); 

		const float LINE_LENGHT = 50.0f;
		const float LINE_WIDTH = 2.0f;
		sf::RectangleShape line(sf::Vector2f(speed*LINE_LENGHT, LINE_WIDTH));

		line.setFillColor(sf::Color::Red);
		line.rotate(angle);
		line.setPosition(getX()+camera.x, getY()+camera.y);
		SystemManager::getSingleton().draw(line);

	}
	sf::RectangleShape shape(sf::Vector2f(WIDTH, HEIGHT));
	shape.setPosition(mX+camera.x, mY+camera.y);
	SystemManager::getSingleton().draw(shape);
}

void Slingshot::setBird(Bird* bird) {
	if(mBird == nullptr)
	{
		forceTime = 0.0f;
		mBird = bird;
	}
}

WorldObject::ObjectEvent Slingshot::update(float time) {


	if(mBird != nullptr)
	{
		const float STRENGTH_MULTIPLY = 2.0f;

		float angle = getAngle();
		float speed = getLengthVelocity()*2.0;
		if(mBird->getX() < getX())
			mBird->applyForce(angle, speed);
		else
			mBird = nullptr;
		forceTime += time;
	}
	return ObjectEvent::NONE;
}

bool Slingshot::isOverlapping(const World::Camera &camera, float x, float y)
{
	const float relX = x - camera.x, relY = y - camera.y;
	if(relX >= mX && relX <= mX+WIDTH &&
			relY >= mY && relY <= mY+HEIGHT)
		return true;
	else
		return false;
}

void Slingshot::setPreload(const World::Camera &camera, float x, float y) {
	if( mState == State::PRELOADING || mState == State::IDLE) {
		float relX = x+camera.x-getX();
		float relY = y+camera.y-getY();
		if(relX > -10)
			relX = -10;
		if(relY  < 0 )
			relY = 0;

		float sqL = sqrt(relX*relX + relY*relY);
		if(sqL > MAX_PRELOAD)
		{
			relX = relX * MAX_PRELOAD/sqL;
			relY = relY * MAX_PRELOAD/sqL; 
		}
		mPreX = relX;
		mPreY = relY;

		mState = State::PRELOADING;
	}
}

bool Slingshot::isPreloading()
{
	return mState == State::PRELOADING;
}
Slingshot::Shot Slingshot::fire() {
	Shot shot;
	if(mState == State::PRELOADING) {
		mState = State::IDLE;
		shot.x = mPreX+getX();
		shot.y = mPreY+getY();
		shot.done = true;
	}
	else
	{
		shot.done = false;
	}
	return shot;
}
float Slingshot::getAngle() const {
	return atan2(mPreY, -mPreX)*180.0f / 3.14f;
	
}

float Slingshot::getLengthVelocity() const {
	
	return sqrt(mPreX*mPreX + mPreY*mPreY);
}
} /* namespace AngryZPR */
