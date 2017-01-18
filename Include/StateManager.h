/*
 * StatateManager.h
 *
 *  Created on: Dec 7, 2016
 *      Author: £ukasz Kowalczyk
 */

#ifndef StateMANAGER_H_
#define StateMANAGER_H_

#include <memory>
#include <chrono>

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

	void acceptMouseEvent(MouseEvent ev, int x, int y) { };
	void acceptKeyEvent(KeyEvent ev, sf::Keyboard::Key key) { };
private:
	GameState mGameState;
	std::shared_ptr<World> mWorld;

	std::chrono::steady_clock::time_point mLastFrameTime;

	bool mFirstFrame;


};

} /* namespace AngryZPR */

#endif /* StateMANAGER_H_ */
