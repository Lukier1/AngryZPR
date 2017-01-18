/*
* Pig.h
*
*  Created on: Jan 10, 2017
*      Author: £ukasz Kowalczyk
*/

#ifndef INCLUDE_PIG_H_
#define INCLUDE_PIG_H_

#include "PhysicObject.h"

namespace AngryZPR {

	class Pig : public PhysicObject {
	private:
		Pig(b2Body * body, float pig_w, float pig_h);

	protected:
		float mPigW, mPigH;
	public:
		virtual ~Pig();

		virtual void draw(const World::Camera &camera);
		static Pig * create(b2World &world, float x, float y, float angle);
	};

} /* namespace AngryZPR */

#endif /* INCLUDE_PIG_H_ */
