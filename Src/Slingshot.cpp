/*
 * Slingshot.cpp
 *
 *  Created on: Jan 10, 2017
 *      Author: lukier
 */

#include <iostream>

#include <SFML/Graphics.hpp>
#include "../Include/Slingshot.h"
#include "../Include/SystemManager.h"
namespace AngryZPR {

Slingshot::Slingshot() {
	// TODO Auto-generated constructor stub
	mX = 150.0f;
	mY = 400.0f;
}

Slingshot::~Slingshot() {
	// TODO Auto-generated destructor stub
}

void Slingshot::draw(const World::Camera &camera) {
	if(mState == STATE::PRELOADING)
	{
		float speed = (mPreX*mPreX + mPreY*mPreY)/1000.0f;
		float angle = atan2(-mPreY, -mPreX)*180.0f/3.14f; // TODO: Przeniesc to do jednej funkcji

		sf::RectangleShape line(sf::Vector2f(speed*50.0f, 2));

		line.setFillColor(sf::Color::Red);
		line.rotate(angle);
		line.setPosition(getX(), getY());
		SystemManager::getSingleton().draw(line);

	}
	sf::RectangleShape shape(sf::Vector2f(WIDTH, HEIGHT));
	shape.setPosition(mX, mY);
	SystemManager::getSingleton().draw(shape);
}

Bird* Slingshot::setBird(Bird* bird) {
	if(mBird == nullptr)
	{
		forceTime = 0.0f;
		mBird = bird;
	}
}

float Slingshot::update(float time) {


	if(mBird != nullptr)
	{
		float angle = atan2(mPreY, -mPreX)*180.0f/3.14f;
		float speed = (mPreX*mPreX + mPreY*mPreY)/1000.0f;
		if(forceTime < 100.0f)
			mBird->applyForce(angle, speed);
		else
			mBird = nullptr;
		forceTime += time;
	}
}

bool Slingshot::isOverlapping(const World::Camera &camera, float x, float y)
{
	const float relX = x - camera.X, relY = y - camera.Y;
	if(relX >= mX && relX <= mX+WIDTH &&
			relY >= mY && relY <= mY+HEIGHT)
		return true;
	else
		return false;
}

void Slingshot::setPreload(const World::Camera &camera, float x, float y) {
	if( mState == STATE::PRELOADING || mState == STATE::IDLE) {
		float relX = x+camera.X-getX();
		float relY = y+camera.Y-getY();
		float sqL = sqrt(relX*relX + relY*relY);
		if(sqL > MAX_PRELOAD)
		{
			relX = relX * MAX_PRELOAD/sqL;
			relY = relY * MAX_PRELOAD/sqL; 
		}
		mPreX = relX;
		mPreY = relY;

		mState = STATE::PRELOADING;
	}

}

bool Slingshot::isPreloading()
{
	return mState == STATE::PRELOADING;
}
Slingshot::Shot Slingshot::fire() {
	Shot shot;
	if(mState == STATE::PRELOADING) {
		std::cout << "FIRE" << std::endl;
		mState = STATE::IDLE;
		shot.x = mPreX+getX();
		shot.y = mPreY+getY();
		shot.done = true;
		return shot;
	}
	else
	{
		shot.done = false;
		return shot;
	}
}

} /* namespace AngryZPR */
