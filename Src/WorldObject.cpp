/*
 * WorldObject.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: lukier
 */

#include "../Include/WorldObject.h"

namespace AngryZPR {
		float WorldObject::getX() const {
			return mX;
		}

		float WorldObject::getY() const {
			return mY;
		}
		WorldObject::OBJECT_EVENT WorldObject::update(float time) {
			return OBJECT_EVENT::NONE;
		}
}

