/*
 * StatateManager.h
 *
 *  Created on: Dec 7, 2016
 *      Author: lukier
 */

#ifndef STATEMANAGER_H_
#define STATEMANAGER_H_


#include "../Include/ControllerListener.h"
#include "../Include/World.h"

namespace AngryZPR {

class StateManager : public ControllerListener {


public:
	enum class GameState {
		DESTROY,
		BUILD
	};

	StateManager();
	virtual ~StateManager();

	void draw();
	void update();
	
	void changeState(GameState state);

	void acceptMouseEvent(MouseEvent ev, float x, float y) { };
	void acceptKeyEvent(KeyEvent ev, sf::Keyboard::Key key) { };
private:
	GameState mGameState;
	World * mWorld;

};

} /* namespace AngryZPR */

#endif /* STATEMANAGER_H_ */
