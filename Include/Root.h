/*
 * Root.h
 *
 *  Created on: Dec 4, 2016
 *      Author: £ukasz Kowalczyk
 */

#ifndef INCLUDE_ROOT_H_
#define INCLUDE_ROOT_H_

#include "../Include/StateManager.h"


namespace AngryZPR {


class Root {
public:
	Root();
	bool run();

	StateManager mStateManager;
private:
	void initSingleton();
	void registerControlListener(ControllerListener  * listener);
	void deregisterControlListener(ControllerListener  * listener);
};
}

#endif /* INCLUDE_ROOT_H */
