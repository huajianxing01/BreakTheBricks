#include "slider.h"

Slider::Slider()
{
	_state = kPaddleStateUngrabbed;
}

Slider::~Slider()
{

}

bool Slider::init()
{
	initWithFile("Game/Level_1/paddle.png");
	//setrect(Rect(p.x - s.width/2, p.y - s.height/2, s.width, s.height));
	return true;
}

Rect Slider::getRect()
{
	auto s = getTexture()->getContentSize();
	auto p = getPosition();
	//return Rect(-s.width / 2,-s.height / 2, s.width, s.height);
	return Rect(p.x - s.width/2, p.y - s.height/2, s.width, s.height);
}

/*void Slider::setSliderLength(brickIndex index)
{
	
}*/

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
	
	//return getRect().containsPoint(t->getLocation());//convertTouchToNodeSpaceAR(t));
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if (t->getLocation().x >= getRect().getMinX() &&
		t->getLocation().x <= getRect().getMaxX() &&
		t->getLocation().y <= visibleSize.height/3)
		return true;
	else
		return false;
}

bool Slider::onTouchBegan(Touch* t, Event* e)
{
	//CCLOG("Slider::onTouchbegan id = %d, x = %f, y = %f", t->getID(), t->getLocation().x, t->getLocation().y);

	if (_state != kPaddleStateUngrabbed) return false;
	if (!containsTouchLocation(t)) return false;

	_state = kPaddleStateGrabbed;
	//CCLOG("return true");
	return true;
}

void Slider::onTouchMoved(Touch* t, Event* e)
{
	//CCLOG("Slider::onTouchMoved id = %d, x = %f, y = %f", t->getID(), t->getLocation().x, t->getLocation().y);
	CCASSERT(_state == kPaddleStateGrabbed, "Slider - Unexpected state!");

	auto touchPoint = t->getLocation();
	setPosition( Vec2(touchPoint.x,this->getContentSize().height/2) );
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