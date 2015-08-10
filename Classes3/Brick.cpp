#include "Brick.h"

bool Brick::init()
{
	initWithFile("Game/brick_blue.png");
	Bf = NORMAL;
	addBall = false;
	return true;
}

/*void Brick::set_BallSpeed(brickIndex speed)
{
	ballSpeed = speed;
}

brickIndex Brick::get_BallSpeed()
{
	return ballSpeed;
}

void Brick::set_AddBall(bool m)
{
	addBall = m;
}

bool Brick::get_AddBall()
{
	return addBall;
}
*/
Rect Brick::getRect()
{
	auto s = getTexture()->getContentSize();
	Vec2 position = getPosition();
	auto visibaleSize = Director::getInstance()->getVisibleSize();
	return Rect(position.x-s.width/2, position.y-s.height/2, s.width, s.height);
}

void Brick::setBrickBuff(brickIndex index)
{
	setBf(index);
	Texture2D* texture;
	switch (index)
	{
	case NORMAL:
		texture = TextureCache::sharedTextureCache()->addImage("Game/brick_blue.png");
		break;
	case UP_SPEED: 
		texture = TextureCache::sharedTextureCache()->addImage("Game/brick_pink.png");
		break;
	case DOWN_SPEED:
		texture = TextureCache::sharedTextureCache()->addImage("Game/brick_black.png");
		break;
	case ADD_LENGTH:
		texture = TextureCache::sharedTextureCache()->addImage("Game/brick_red.png");
		break;
	case SUB_LENGTH:
		texture = TextureCache::sharedTextureCache()->addImage("Game/brick_yellow.png");
		break;
	case ADD_BALL:
		texture = TextureCache::sharedTextureCache()->addImage("Game/brick_green.png");
		break;
	default:
		break;
	}
	setTexture(texture);
	//CC_SAFE_DELETE(texture);
	//this->setDisplayFrame(frame);
}