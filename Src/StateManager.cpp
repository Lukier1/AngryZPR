/*
 * StatateManager.cpp
 *
 *  Created on: Dec 7, 2016
 *      Author: lukier
 */

#include "../Include/StateManager.h"
#include "../Include/SystemManager.h"
#include "../Include/WorldImpl.h"

#include <iostream>
#include <SFML/Graphics.hpp>
namespace AngryZPR {

StateManager::StateManager()  : mGameState(GameState::DESTROY), mWorld(new WorldImpl()) {
	changeState(mGameState);

	mLastFrameTime = std::chrono::steady_clock::now();
	// TODO Auto-generated constructor stub
}

StateManager::~StateManager() {
	// TODO Auto-generated destructor stub
}

void StateManager::draw() {
	sf::RectangleShape shape(sf::Vector2f(100, 100));
	switch(mGameState)
	{
	case GameState::BUILD:

		break;
	case GameState::DESTROY:
		mWorld->draw();
		break;
	}
}

void StateManager::update() {
	std::chrono::steady_clock::time_point actualTime = std::chrono::steady_clock::now();
	int durationInMs = std::chrono::duration_cast<std::chrono::microseconds>(actualTime - mLastFrameTime).count();
	float durationInSec = (float)durationInMs/1.0f;
	mLastFrameTime = actualTime;
	switch(mGameState)
	{
	case GameState::BUILD:

		break;
	case GameState::DESTROY:
		mWorld->update(durationInSec);
		break;
	}
	
}

void StateManager::changeState(GameState state) {
	switch(mGameState)
	{
	case GameState::BUILD:
		SystemManager::getSingleton().deregisterListener(mWorld);
	break;
	case GameState::DESTROY:
		SystemManager::getSingleton().deregisterListener(mWorld);
	break;
	}
	switch(state)
	{
		case GameState::BUILD:
			SystemManager::getSingleton().registerListener(mWorld);
		break;
		case GameState::DESTROY:
			SystemManager::getSingleton().registerListener(mWorld);
		break;
	}

	mGameState = state;
}

} /* namespace AngryZPR */
