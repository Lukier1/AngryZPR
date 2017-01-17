#ifndef __WORLDOBJECT_H__
#define __WORLDOBJECT_H__

#include "World.h"

namespace AngryZPR {
	class WorldObject {
	protected:
		float mX, mY;
	public:
		enum class OBJECT_EVENT{
			DESTROY_ITSELF_ADDPOINT,
			DESTROY_ITSELF,
			NONE
		};

		virtual void draw(const World::Camera &camera) = 0;
		virtual OBJECT_EVENT update(float time);
		float getX() const;

		float getY() const;
	};
}

#endif
