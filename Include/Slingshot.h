/*
 * Slingshot.h
 *
 *  Created on: Jan 10, 2017
 *      Author: �ukasz Kowalczyk
 */

#ifndef INCLUDE_SLINGSHOT_H_
#define INCLUDE_SLINGSHOT_H_

#include "World.h"
#include "WorldObject.h"
#include "Bird.h"

namespace AngryZPR {
/*
 * Klasa opsiująca obiekt procy
 */
class Slingshot: public WorldObject {
public:
	/*
	 * Struktura która przekazuję w jakiej pozycji powstaje pocisk
	 * podczas strzału
	 */
	struct Shot {
		float x, y; 
		bool done; 
	};

	Slingshot();

	void draw(const World::Camera &camera) const;

	/*
	 * Ustawia naładowanie procy
	 * \param camera - obiekt kamery
	 * \param x - pozycja myszki wzgledem okna
	 * \param y - pozycja myszki wzgledem okna
	 */
	void setPreload(const World::Camera &camera, float x, float y) ;
	/*
	 * Wystrzeliwuje pocisk
	 * \return jeśli pocisk został poprawnie wystrzelony zwraza w strukurze done==true i pozycje wystrzału
	 */
	Shot fire();
	/*
	 * W tej funkcji jest podawany aktualnie przyspieszany pocisk
	 * przez proce
	 * \param wskaznik na obiekt pocisku
	 */
	void setBird(Bird * bird);

	/*
	 * Czy aktualnie jest przeladowywana
	 */
	bool isPreloading();

	WorldObject::ObjectEvent update(float time);

	/*
	 * Sprawdza czy podany x,y miesci sie wenwtarz procy
	 * \param obiekt kamery
	 * \param x - pozcyja
	 * \param y - pozycja
	 */

	bool isOverlapping(const World::Camera &camera, float x, float y) const;
private:
	enum class State {
		IDLE,
		PRELOADING,
		SHOOTING
	};

	const float WIDTH = 10.0f;
	const float HEIGHT = 100.0f;
	const float MAX_RANGE = 10.0f;
	const float MAX_PRELOAD = 50.0f;

	Bird * mBird = nullptr;

	float forceTime = 0.0f;

	float mPreX = 0.0f, mPreY = 0.0f;

	State mState = State::IDLE;

	float getAngle() const;

	float getLengthVelocity() const;
};

} /* namespace AngryZPR */

#endif /* INCLUDE_SLINGSHOT_H_ */
