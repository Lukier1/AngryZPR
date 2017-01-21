/*
 * Root.h
 *
 *  Created on: Dec 4, 2016
 *      Author: �ukasz Kowalczyk
 */

#ifndef INCLUDE_ROOT_H_
#define INCLUDE_ROOT_H_

#include "../Include/StateManager.h"


namespace AngryZPR {
/*
 * Klasa będaca korzeniem aplikacji, w niej znajduje sie petla glowna, a a takze odpowiada za rejestrowanie
 * słuchaczy("Listenerów") zdarzeń.
 */

class Root {
public:

	Root();
	/*
	 * Metoda zawierająca ciało pętli głównej programu
	 * \return Zwraca true gdy pętla wciaż powinna działać
	 */
	bool run();

	StateManager mStateManager;
private:
	void initSingleton();
	void registerControlListener(ControllerListener  * listener);
	void deregisterControlListener(ControllerListener  * listener);
};
}

#endif /* INCLUDE_ROOT_H */
