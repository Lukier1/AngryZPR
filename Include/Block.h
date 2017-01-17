/*
 * Block.h
 *
 *  Created on: Jan 10, 2017
 *      Author: lukier
 */

#ifndef INCLUDE_BLOCK_H_
#define INCLUDE_BLOCK_H_

#include "PhysicObject.h"

namespace AngryZPR {

class Block : public PhysicObject {
private:
	Block(b2Body * body, float mBlockW, float mBlockH);

protected:
	float mBlockW, mBlockH;
public:
	virtual ~Block();

	virtual void draw(const World::Camera &camera);
	static Block * create(b2World &world, float x, float y, float angle);
};

} /* namespace AngryZPR */

#endif /* INCLUDE_BLOCK_H_ */
