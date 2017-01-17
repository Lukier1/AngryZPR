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
#include "../Include/Block.h"
#include "../Include/Constants.h"
#include "../Include/Pig.h"

namespace AngryZPR {

//1.0m/25px

WorldImpl::WorldImpl() :
		mGravity(0.0f, 10.0f), mWorld(mGravity), mSlingshot(new Slingshot()) {
	mWorld.SetAllowSleeping(true);

	std::cout << mWorld.GetGravity().y << std::endl;
	//Creting physic ground body

	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0, 500.0f*WORLD_SCALE);

	b2PolygonShape groundBox;
	groundBox.SetAsBox(800.0f*WORLD_SCALE, 10.0f*WORLD_SCALE);

	mGroundBody = mWorld.CreateBody(&groundBodyDef);
	mGroundBody->CreateFixture(&groundBox, 0.0f);

	//Adding slinghsot to world
	mObjects.push_back(mSlingshot);
	mObjects.push_back(Block::create(mWorld, 600.0f, 480.0f,0));
	mObjects.push_back(Block::create(mWorld, 640.0f, 480.0f,0));
	mObjects.push_back(Block::create(mWorld, 650.0f, 480.0f, 0));
	mObjects.push_back(Block::create(mWorld, 690.0f, 480.0f, 0));
	//mObjects.push_back(Block::create(mWorld, 625.0f, 373.0f,0));
	//mObjects.push_back(Block::create(mWorld, 665.0f, 373.0f,0));

	mObjects.push_back(Block::create(mWorld, 620.0f, 400.0f, 3.14f/2.0f));
	mObjects.push_back(Block::create(mWorld, 672.0f, 400.0f, 3.14f/2.0f));
	mObjects.push_back(Block::create(mWorld, 620.0f, 415.0f, 3.14f/2.0f));
	mObjects.push_back(Block::create(mWorld, 672.0f, 415.0f, 3.14f/2.0f));
	
	mObjects.push_back(Pig::create(mWorld, 620.0f, 470.f, 3.14f / 2.0f));
	mObjects.push_back(Pig::create(mWorld, 672.5f, 470.f, 3.14f / 2.0f));
	//mObjects.push_back(Block::create(mWorld, 645.0f, 344.0f, 3.14f/2.0f));

}

WorldImpl::~WorldImpl() {

	for (WorldObject * object : mObjects) {
		delete object;
	}
	mObjects.clear();
}

void WorldImpl::acceptMouseEvent(MouseEvent ev, int x, int y) {

	switch (ev) {
	case MouseEvent::MOUSE_LBUTTON_PRESS:
		if (mSlingshot->isOverlapping(mCamera, (float)x, (float)y)) {
			mSlingshot->setPreload(mCamera, (float)x, (float)y);
		}
		break;
	case MouseEvent::MOUSE_MOVE:
		if (mSlingshot->isPreloading())
			mSlingshot->setPreload(mCamera, (float)x, (float)y);
		break;
	case MouseEvent::MOUSE_LBUTTON_RELEASE:
		Slingshot::Shot shot = mSlingshot->fire();
		if (shot.done) {
			Bird * bird = Bird::createBird(mWorld, shot.x,
					shot.y);
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
	sf::RectangleShape grass(
			sf::Vector2f(SystemManager::getSingleton().getWindowW(),
					SystemManager::getSingleton().getWindowH()));

	grass.setFillColor(sf::Color::Green);
	SystemManager::getSingleton().draw(grass);

	sf::RectangleShape sky(
			sf::Vector2f((float)SystemManager::getSingleton().getWindowW(),
			(float)SystemManager::getSingleton().getWindowH() - DRAW_GRASS_WIDE));
	sky.setFillColor(sf::Color::Blue);
	SystemManager::getSingleton().draw(sky);

	//Drawing objects on map
	for (WorldObject * object : mObjects) {
		object->draw(mCamera);
	}
}

void WorldImpl::addPhyicObject() {
	
}

void WorldImpl::update(float timeapp) {
	//std::cout << "timeapp" << timeapp << std::endl;
	for (WorldObject * object : mObjects) {
		WorldObject::OBJECT_EVENT ev = object->update(timeapp);
		if (ev != WorldObject::OBJECT_EVENT::NONE)
		{
			processEvent(object, ev);
		}
	}
	mWorld.Step(timeapp, VELOCITY_ITERATIONS, POSTION_ITERATIONS);
}

} /* namespace AngryZPR */
