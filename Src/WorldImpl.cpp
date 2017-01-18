/*
 * WorldImpl.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: £ukasz Kowalczyk
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

	const int SCREEN_W = SystemManager::getSingleton().getWindowW();
	const int SCREEN_H = SystemManager::getSingleton().getWindowH();
	const int GROUND_Y = SCREEN_H - 100;
	const int GROUND_X = 0;
	const int GROUND_H = 10;
	//Creting physic ground body

	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set((float32)GROUND_X, GROUND_Y*WORLD_SCALE);

	b2PolygonShape groundBox;
	groundBox.SetAsBox(SCREEN_W*WORLD_SCALE, GROUND_H*WORLD_SCALE);

	mGroundBody = mWorld.CreateBody(&groundBodyDef);
	mGroundBody->CreateFixture(&groundBox, 0.0f);

	//Adding slinghsot to world
	mObjects.push_back(mSlingshot);

	//Creating map
	mObjects.push_back(Block::create(mWorld, 600.0f, 480.0f,0));
	mObjects.push_back(Block::create(mWorld, 640.0f, 480.0f,0));
	mObjects.push_back(Block::create(mWorld, 650.0f, 480.0f, 0));
	mObjects.push_back(Block::create(mWorld, 690.0f, 480.0f, 0));


	mObjects.push_back(Block::create(mWorld, 620.0f, 400.0f, 3.14f/2.0f));
	mObjects.push_back(Block::create(mWorld, 672.0f, 400.0f, 3.14f/2.0f));
	
	
	mObjects.push_back(Pig::create(mWorld, 620.0f, 390.f, 3.14f / 2.0f));
	mObjects.push_back(Pig::create(mWorld, 672.5f, 390.f, 3.14f / 2.0f));
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
	const int DRAW_GRASS_WIDE = 150;

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


void WorldImpl::update(float timeapp) {
	const int32 VELOCITY_ITERATIONS = 6;
	const int32 POSTION_ITERATIONS = 2;

	std::vector<WorldObject*> safeCopy(mObjects.size());
	std::copy(mObjects.begin(), mObjects.end(), safeCopy.begin());
	for (WorldObject * object : safeCopy) {
		WorldObject::ObjectEvent ev = object->update(timeapp);
		if (ev != WorldObject::ObjectEvent::NONE)
		{
			processEvent(object, ev);
		}
	}
	mWorld.Step(timeapp, VELOCITY_ITERATIONS, POSTION_ITERATIONS);
}

void WorldImpl::processEvent(WorldObject * object, WorldObject::ObjectEvent obj_event) {
	switch (obj_event)
	{
	case WorldObject::ObjectEvent::DESTROY_ITSELF:
		deleteObject(object);
		break;
	case WorldObject::ObjectEvent::DESTROY_ITSELF_ADDPOINT:
		deleteObject(object);
		break;
	default:
		break;
	}
}

void WorldImpl::deleteObject(WorldObject * obj)
{
	for (int i = 0; i < mObjects.size(); ++i)
	{
		if (mObjects[i] == obj)
		{
			delete mObjects[i];
			mObjects.erase(mObjects.begin()+i);
			break;
		}
	}
}
} /* namespace AngryZPR */
