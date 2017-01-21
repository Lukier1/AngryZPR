/*
 * StatateManager.h
 *
 *  Created on: Dec 7, 2016
 *      Author: �ukasz Kowalczyk
 */

#ifndef StateMANAGER_H_
#define StateMANAGER_H_

#include <memory>
#include <chrono>

#include "../Include/ControllerListener.h"
#include "../Include/World.h"

namespace AngryZPR {

class StateManager  {


public:
	enum class GameState {
		DESTROY,
		BUILD
	};

	StateManager();


	void draw();
	void update();
	
	/*
	 * Zmien na nowy stan
	 * \param state nowy stan
	 */
	void changeState(GameState state);
private:
	GameState mGameState;
	std::shared_ptr<World> mWorld;

	std::chrono::steady_clock::time_point mLastFrameTime;

	bool mFirstFrame;


};

} /* namespace AngryZPR */

#endif /* StateMANAGER_H_ */
