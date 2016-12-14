/*
 * StatateManager.cpp
 *
 *  Created on: Dec 7, 2016
 *      Author: lukier
 */

#include "../Include/StateManager.h"
#include "../Include/SystemManager.h"

#include <SFML/Graphics.hpp>
namespace AngryZPR {

StateManager::StateManager()  : mGameState(GameState::BUILD){
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

}

} /* namespace AngryZPR */
