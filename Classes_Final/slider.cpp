#include "slider.h"

Slider::Slider()
{
	_state = kPaddleStateUngrabbed;
	_timer = 0;
	_isTimerkeeping = false;
}

Slider::~Slider()
{

}

void Slider::update(float delta)
{
	_offset = (clock() - _timer)/1000;
	moveSliderUp();
	

}

void Slider::startTimer()
{
	if(!_isTimerkeeping)
	{
		_timer = clock();
		_isTimerkeeping = true;
		scheduleUpdate();
	}

}

void Slider::endTimer()
{
	if(_isTimerkeeping)
	{
		_isTimerkeeping = false;
	}
}

void Slider::moveSliderUp()
{
	if(_offset != 0 && _offset%10 == 0)
	{
		_timer = clock();
		setsliderHeight(_height + 30);
		auto moveup = MoveBy::create(0.3f,Vec2(0,30));
		this->runAction(moveup);
	}
}
bool Slider::init()
{
	initWithFile("Game/Level_1/paddle.png");
	setsliderHeight(this->getContentSize().height/2);
	
	return true;
}

Rect Slider::getRect()
{
	auto s = getTexture()->getContentSize();
	auto p = getPosition();
	return Rect(p.x - s.width/2, p.y - s.height/2, s.width, s.height);
}

void Slider::onEnter()
{
	Sprite::onEnter();
	// Register Touch Event
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(Slider::onTouchBegan,this);
	listener->onTouchMoved = CC_CALLBACK_2(Slider::onTouchMoved,this);
	listener->onTouchEnded = CC_CALLBACK_2(Slider::onTouchEnded,this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Slider::onExit()
{
	Sprite::onExit();
}

bool Slider::containsTouchLocation(Touch* t)
{
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if (t->getLocation().x >= getRect().getMinX() &&
		t->getLocation().x <= getRect().getMaxX() &&
		t->getLocation().y <= this->getPositionY() + 300)
		return true;
	else
		return false;
}

bool Slider::onTouchBegan(Touch* t, Event* e)
{
	if (_state != kPaddleStateUngrabbed) return false;
	if (!containsTouchLocation(t)) return false;

	_state = kPaddleStateGrabbed;
	return true;
}

void Slider::onTouchMoved(Touch* t, Event* e)
{
	CCASSERT(_state == kPaddleStateGrabbed, "Slider - Unexpected state!");

	auto touchPoint = t->getLocation();
	setPosition( Vec2(touchPoint.x,_height) );
}

void Slider::onTouchEnded(Touch* t, Event* e)
{
	CCASSERT(_state == kPaddleStateGrabbed, "Slider - Unexpected state!");
	_state = kPaddleStateUngrabbed;
	auto vs = Director::getInstance()->getVisibleSize();
	if(getRect().getMinX() < 0)
		setPosition(getContentSize().width/2,getPositionY());
	else if (getRect().getMaxX() > vs.width)
		setPosition(vs.width - getContentSize().width/2,getPositionY());
}