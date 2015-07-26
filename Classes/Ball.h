#ifndef __BALL_H__
#define __BALL_H__
#include "cocos2d.h"
USING_NS_CC;

class Ball : public Node{
public:
	Ball();
	~Ball();
	Sprite* getSprite();
	void bindSprite(Sprite* sprite);
	CREATE_FUNC(Ball);
	virtual bool init();

private:
	Sprite* m_sprite;

};

#endif