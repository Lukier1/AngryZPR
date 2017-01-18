/*
 * WorldObject.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: £ukasz Kowalczyk
 */

#include "../Include/WorldObject.h"

namespace AngryZPR {
		float WorldObject::getX() const {
			return mX;
		}

		float WorldObject::getY() const {
			return mY;
		}
		WorldObject::ObjectEvent WorldObject::update(float time) {
			return ObjectEvent::NONE;
		}
}

