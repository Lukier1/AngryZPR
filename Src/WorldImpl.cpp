/*
 * WorldImpl.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: lukier
 */
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "../Include/WorldImpl.h"
#include "../Include/SystemManager.h"
#include "../Include/Slingshot.h"
#include "../Include/Bird.h"
namespace AngryZPR {

WorldImpl::WorldImpl() :
		mGravity(0.0f, -0.001f), mWorld(mGravity), mSlingshot(new Slingshot()) {
	mWorld.SetAllowSleeping(true);
	std::cout << mWorld.GetGravity().y << std::endl;
	//Creting physic ground body

	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(-100.0f, -600.0f);

	b2PolygonShape groundBox;
	groundBox.SetAsBox(5000.0f, 100.0f);

	mGroundBody = mWorld.CreateBody(&groundBodyDef);
	mGroundBody->CreateFixture(&groundBox, 0.0f);

	//Adding slinghsot to world
	mObjects.push_back(mSlingshot);
}

WorldImpl::~WorldImpl() {

	for (WorldObject * object : mObjects) {
		delete object;
	}
	mObjects.clear();
}

void WorldImpl::acceptMouseEvent(MouseEvent ev, float x, float y) {

	switch (ev) {
	case MouseEvent::MOUSE_LBUTTON_PRESS:

		if (mSlingshot->isOverlapping(mCamera, x, y)) {
			mSlingshot->setPreload(mCamera, x, y);
		}
		break;
	case MouseEvent::MOUSE_MOVE:
		if (mSlingshot->isPreloading())
			mSlingshot->setPreload(mCamera, x, y);
		break;
	case MouseEvent::MOUSE_LBUTTON_RELEASE:

		if (mSlingshot->fire()) {
			Bird * bird = Bird::createBird(mWorld, x,
					y, 0, 0);
			mSlingshot->setBird(bird);
			mObjects.push_back(bird);
		}

		break;
	}
}

void WorldImpl::acceptKeyEvent(KeyEvent ev, sf::Keyboard::Key key) {
}

void WorldImpl::draw() {
	//background drawing
	const int GRASS_WIDE = 150;

	sf::RectangleShape grass(
			sf::Vector2f(SystemManager::getSingleton().getWindowW(),
					SystemManager::getSingleton().getWindowH()));

	grass.setFillColor(sf::Color::Green);
	SystemManager::getSingleton().draw(grass);

	sf::RectangleShape sky(
			sf::Vector2f(SystemManager::getSingleton().getWindowW(),
					SystemManager::getSingleton().getWindowH() - GRASS_WIDE));
	sky.setFillColor(sf::Color::Blue);
	SystemManager::getSingleton().draw(sky);

	for (WorldObject * object : mObjects) {
		object->draw(mCamera);
	}
}

void WorldImpl::addPhyicObject() {

}

void WorldImpl::update(float timeapp) {

	mSlingshot->update(timeapp / 1000.0f);
	mWorld.Step(timeapp / 1000.0f, VELOCITY_ITERATIONS, POSTION_ITERATIONS);
}

} /* namespace AngryZPR */
