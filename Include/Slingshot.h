/*
 * Slingshot.h
 *
 *  Created on: Jan 10, 2017
 *      Author: lukier
 */

#ifndef INCLUDE_SLINGSHOT_H_
#define INCLUDE_SLINGSHOT_H_

#include "World.h"
#include "WorldObject.h"
#include "Bird.h"

namespace AngryZPR {

class Slingshot: public WorldObject {
public:
	struct Shot {
		float x, y; 
		bool done; 
	};

	Slingshot();
	virtual ~Slingshot();

	void draw(const World::Camera &camera);

	void setPreload(const World::Camera &camera, float x, float y);
	Shot fire();
	void setBird(Bird * bird);

	bool isPreloading();
	WorldObject::OBJECT_EVENT update(float time);
	bool isOverlapping(const World::Camera &camera, float x, float y);
private:
	enum class STATE {
		IDLE,
		PRELOADING,
		SHOOTING
	};

	const float WIDTH = 10.0f;
	const float HEIGHT = 100.0f;

	const float MAX_PRELOAD = 50.0f;

	Bird * mBird = nullptr;

	float forceTime = 0.0f;

	float mPreX = 0.0f, mPreY = 0.0f;

	STATE mState = STATE::IDLE;
};

} /* namespace AngryZPR */

#endif /* INCLUDE_SLINGSHOT_H_ */
