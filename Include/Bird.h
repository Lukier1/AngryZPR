/*
 * Bird.h
 *
 *  Created on: Jan 10, 2017
 *      Author: �ukasz Kowalczyk
 */

#ifndef INCLUDE_BIRD_H_
#define INCLUDE_BIRD_H_

#include "PhysicObject.h"

namespace AngryZPR {
/*
 * Klasa pocisku wyrzucanego przez katapulte.
 */
class Bird: public PhysicObject {
private:
	Bird(b2Body * body);
	float mTimeNoSpeed;
protected:

public:
	virtual void draw(const World::Camera &camera) const;

	WorldObject::ObjectEvent update(float time);

	/*
	 * Metoda służąc do tworzenia obiektów Bird
	 * \param world refrencja do obiektu świata
	 * \param x pozycja
	 * \param y pozycja
	 */
	static Bird * createBird(b2World &world, float x, float y);
};

} /* namespace AngryZPR */

#endif /* INCLUDE_BIRD_H_ */
