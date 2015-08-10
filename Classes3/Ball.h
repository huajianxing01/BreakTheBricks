#ifndef _BALL_H
#define _BALL_H

#include "cocos2d.h"
#include "slider.h"
#include "Brick.h"
USING_NS_CC;

class Ball : public Sprite 
{
private:
	Vec2 _direction;//小球方向
	Vec2 _location; //小球位置
	int _speed;//小球速度
	float _radius;//小球半径
	Size _visibleSize; //屏幕尺寸
	//static Vector<Ball*>* balls;
public:
	Ball();
	~Ball();
	void set_location(Vec2 position);
	//控制小球方向
	void set_direction(Vec2 direction);
	Vec2 get_direction();
	//控制小球速度
	void set_speed(int speed);
	int get_speed();
	//小球移动
	void BallMove();
	//与边界，滑板，砖块的碰撞
	bool collideWithSlider(Slider* slider);
	bool collideWithEdges();
	void collideWithBricks(Brick* brick);
	bool isCollideWithBrick(Brick* brick);
	virtual bool init();
	CREATE_FUNC(Ball);

};
#endif