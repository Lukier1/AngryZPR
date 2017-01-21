/*
 * SystemManager.h
 *
 *  Created on: Dec 6, 2016
 *      Author: �ukasz Kowalczyk
 */

#ifndef INCLUDE_SYSTEMMANAGER_H_
#define INCLUDE_SYSTEMMANAGER_H_

#include <memory>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "ControllerListener.h"

namespace AngryZPR {

class SystemManager {
private:
	unsigned short mWindowH, mWindowW;

	std::unique_ptr<sf::RenderWindow> mWindow;
	SystemManager();
	std::vector<std::shared_ptr<ControllerListener>> mContListeners;
	
	void updateMouseEvent(ControllerListener::MouseEvent ev, int x, int y);
	void updateKeyEvent(ControllerListener::KeyEvent ev, sf::Keyboard::Key key);

public:
	static SystemManager& getSingleton();
	

	unsigned short getWindowH() const;
	unsigned short getWindowW() const;

	/*
	 * Pobierz wydarzania i rozporwadz po sluchaczach
	 */
	void eventPoll();


	/*
	 * Metoda czysczaca ekran przed rysowaniem
	 */
	void beginDraw();
	/*
	 * Metoda konczaca rysowanie, która wrzuca rysowane obiekty na ekran
	 */
	void endDraw();
	/*
	 * Rysuj podany element
	 * \param drawable - rysowany element
	 * \param render_status - http://www.sfml-dev.org/documentation/2.4.1/classsf_1_1RenderStates.php
	 */
	void draw(const sf::Drawable& drawable, const sf::RenderStates& render_states=sf::RenderStates::Default);

	/*
	 *\return zwraca czy okno jest wciaz otwarte
	 */
	bool isOpen() const;

	/*
	 * Zarejestru nowego słuychacza
	 * \param listener wskaznik na sluchacza
	 */
	void registerListener(std::shared_ptr<ControllerListener> listener);
	/*
	 * Wyrejestruj słuychacza
	 * \param listener wskaznik na sluchacza
	 */
	void deregisterListener(std::shared_ptr<ControllerListener> listener);

	/*
	 * Podaj aktualna liczbe sluchaczy
	 * \return liczba sluchaczy
	 */
	unsigned int getListenersNum() const;
};

}
#endif /* INCLUDE_SYSTEMMANAGER_H_ */
