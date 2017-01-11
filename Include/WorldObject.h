#ifndef __WORLDOBJECT_H__
#define __WORLDOBJECT_H__

#include "World.h"

namespace AngryZPR {
	class WorldObject {
	protected:
		float mX, mY;
	public:
		virtual void draw(const World::Camera &camera) = 0;

		float getX() const;

		float getY() const;
	};
}

#endif
