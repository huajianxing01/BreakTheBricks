#ifndef BRICK_H
#define BRICK_H

#include "cocos2d.h"

USING_NS_CC;

typedef enum {
	NORMAL,UP_SPEED,DOWN_SPEED,ADD_LENGTH,SUB_LENGTH,ADD_BALL
} brickIndex;
class Brick : public Sprite
{
private:
	//brickIndex ballBf; //小球buff
	//bool addBall; //增加小球
public:
	/*void set_BallBf(brickIndex index); //砖块改变小球速度的buff
	brickIndex get_BallBf(); //得到小球速度改变方法
	*/
	CC_SYNTHESIZE(brickIndex,Bf,Bf);
	/*void set_AddBall(bool m); //设置是否增加小球
	bool get_AddBall(); //得到是否增加小球
	*/
	CC_SYNTHESIZE(bool,addBall,addBall);
	Rect getRect();
	virtual bool init();
	void setBrickBuff(brickIndex index);
	CREATE_FUNC(Brick);
};
#endif