#ifndef SLIDER_H
#define SLIDER_H

#include "cocos2d.h"
#include "Brick.h"
USING_NS_CC;
typedef enum tagPaddleState 
{
	kPaddleStateGrabbed,
	kPaddleStateUngrabbed
} PaddleState; 

class Slider : public Sprite
{
	PaddleState        _state  ;
public:
	Slider();
	~Slider();
	virtual bool init();
	CREATE_FUNC(Slider);
	Rect getRect();
	//CC_SYNTHESIZE(Rect,rect,rect);
	//void setSliderLength(brickIndex index);
	virtual void onEnter() override;
	virtual void onExit() override;
	bool containsTouchLocation(Touch* t);
	bool onTouchBegan(Touch* t, Event* e);
	void onTouchMoved(Touch* t, Event* e);
	void onTouchEnded(Touch* t, Event* e);
	
};

#endif