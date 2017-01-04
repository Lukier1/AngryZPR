/*
 * StatateManager.cpp
 *
 *  Created on: Dec 7, 2016
 *      Author: lukier
 */

#include "../Include/StateManager.h"
#include "../Include/SystemManager.h"
#include "../Include/WorldImpl.h"

#include <SFML/Graphics.hpp>
namespace AngryZPR {

StateManager::StateManager()  : mGameState(GameState::BUILD), mWorld(new WorldImpl()) {
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
		mWorld->draw();
		shape.setFillColor(sf::Color::Cyan);
		SystemManager::getSingleton().draw(shape);
		break;
	case GameState::DESTROY:
		break;
	}
}

void StateManager::update() {
	switch(mGameState)
	{
	case GameState::BUILD:
		break;
	case GameState::DESTROY:
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
