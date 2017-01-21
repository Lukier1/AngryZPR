/*
* Pig.h
*
*  Created on: Jan 10, 2017
*      Author: �ukasz Kowalczyk
*/

#ifndef INCLUDE_PIG_H_
#define INCLUDE_PIG_H_

#include "PhysicObject.h"

namespace AngryZPR {
/*
 * Klasa odpoweidzialna za tworzenie bloków o koloerze różowym.
 * W zamysle byly to bloki które użytkownik miał niszczyć mu uzyskac punkty.
 */
	class Pig : public PhysicObject {
	private:
		Pig(b2Body * body, float pig_w, float pig_h);

	protected:
		float mPigW, mPigH;
	public:
		virtual void draw(const World::Camera &camera) const;
		/*
		 * Tworzenie nowego obiektu
		 * \param world refrencja do obiektu świata
		 * \param x pozycja
		 * \param y pozycja
		 * \param angle kat
		 */
		static Pig * create(b2World &world, float x, float y, float angle);
	};

} /* namespace AngryZPR */

#endif /* INCLUDE_PIG_H_ */
