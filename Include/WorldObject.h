#ifndef __WORLDOBJECT_H__
#define __WORLDOBJECT_H__

#include "World.h"

namespace AngryZPR {
/*
 * Klasa abstrakcyjna opisująca obikety które znajduja sie na mapie
 */
	class WorldObject {
	protected:
		float mX, mY;
	public:

		/*
		 * Wydarzanie przekazywane przez obikekt do obiektu klasy World
		 */
		enum class ObjectEvent {
			DESTROY_ITSELF_ADDPOINT,
			DESTROY_ITSELF,
			NONE
		};

		/*
		 * Rysuj obiekt
		 * \param camera  - obiekt kamery uzywany przez klase World
		 */
		virtual void draw(const World::Camera &camera) const = 0;
		/*
		 * Aktulizuj logike obiektu
		 * \param time - różnica czasu miedzy klatkami
		 */
		virtual ObjectEvent update(float time);

		float getX() const;
		float getY() const;

		virtual ~WorldObject() {} 
	};
}

#endif
