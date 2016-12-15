/*
 * WorldImpl.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: lukier
 */

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "../Include/WorldImpl.h"
#include "../Include/SystemManager.h"

namespace AngryZPR {

WorldImpl::WorldImpl() : mGravity(0.0f, -10.0f), mWorld(mGravity) {
	// TODO Auto-generated constructor stub

}

WorldImpl::~WorldImpl() {
	// TODO Auto-generated destructor stub
}

void WorldImpl::acceptMouseEvent(MouseEvent ev, float x, float y) {
}

void WorldImpl::acceptKeyEvent(KeyEvent ev, sf::Keyboard::Key key) {
}

void WorldImpl::draw() {
	sf::RectangleShape shape(sf::Vector2f(100, 100));

	shape.setFillColor(sf::Color::Cyan);
	SystemManager::getSingleton().draw(shape);
}


void WorldImpl::addPhyicObject() {

}

void WorldImpl::update(float time) {
}

} /* namespace AngryZPR */
