#ifndef __PADDLE_H__
#define __PADDLE_H__
#include "cocos2d.h"
USING_NS_CC;

class Paddle : public Node{
public:
	Paddle();
	~Paddle();
	Sprite* getSprite();
	void bindSprite(Sprite* sprite);
	CREATE_FUNC(Paddle);
	virtual bool init();

private:
	Sprite* m_sprite;
};

#endif