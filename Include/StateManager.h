/*
 * StatateManager.h
 *
 *  Created on: Dec 7, 2016
 *      Author: lukier
 */

#ifndef STATEMANAGER_H_
#define STATEMANAGER_H_


#include "../Include/ControllerListener.h"


namespace AngryZPR {

class StateManager : public ControllerListener {
private:
	enum class GameState {
		DESTROY,
		BUILD
	};

	GameState mGameState;

public:
	StateManager();
	virtual ~StateManager();

	void draw();
	void update();
	void accept(const sf::Event &event);
};

} /* namespace AngryZPR */

#endif /* STATEMANAGER_H_ */
