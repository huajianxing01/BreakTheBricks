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
	bool _isTimerkeeping;
public:
	Slider();
	~Slider();
	virtual void update(float delta);
	void startTimer();
	void endTimer();
	void moveSliderUp();
	virtual bool init();
	CREATE_FUNC(Slider);
	Rect getRect();
	CC_SYNTHESIZE(long,_offset,offset);
	CC_SYNTHESIZE(long,_timer,_timer);
	CC_SYNTHESIZE(float,_height,sliderHeight);
	virtual void onEnter() override;
	virtual void onExit() override;
	bool containsTouchLocation(Touch* t);
	bool onTouchBegan(Touch* t, Event* e);
	void onTouchMoved(Touch* t, Event* e);
	void onTouchEnded(Touch* t, Event* e);
	
};

#endif