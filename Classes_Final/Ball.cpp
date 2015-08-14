#include "Ball.h"
#include "math.h"
using namespace std;

bool Ball::isCollideWithBrick(Brick* brick)
{
	float MaxY, MidY, MinY, LeftX, RightX, MidX;
	auto brickRect = brick->getRect();
	MaxY = brickRect.getMaxY();
	MidY = brickRect.getMidY();
	MinY = brickRect.getMinY();
	LeftX = brickRect.getMinX();
	RightX = brickRect.getMaxX();
	MidX = brickRect.getMidX();
	//Åö×²¼ì²â
	if (_location.x>LeftX && _location.x<RightX && (_location.y>MinY-_radius && _location.y<MaxY+_radius) )
	{
		if (_location.y > MidY)
			setPositionY(MaxY + _radius);
		else
			setPositionY(MinY - _radius);
		_direction.y *= -1;
		return true;
	}
	else if ((_location.y>MinY && _location.y<MaxY) && (_location.x>LeftX-_radius && _location.x<RightX+_radius))
	{
		if (_location.x > MidX)
			setPositionX(RightX + _radius);
		else
			setPositionX(LeftX - _radius);
		_direction.x *= -1;
		return true;
	}

	return false;
}

/*******************************************************************************/

Ball::Ball()
{
	_direction.set(random(-10,10),random(5,10));
	_direction.normalize();
	_speed = 4;
	
}

Ball::~Ball()
{

}

void Ball::setballvisible(Slider* slider)
{
	auto _offset = slider->getoffset();
	if ( _offset != 0 && _offset % 1 == 0)
	{
		if(this->isVisible())
		{
			this->setVisible(false);
		}
		else
		{
			this->setVisible((true));
		}
		slider->set_timer(clock());
	}
}
void Ball::set_location(Vec2 postion)
{
	setPosition(postion);
	_location = postion;
}

void Ball::set_direction(Vec2 direction)
{
	direction.normalize();
	_direction = direction;
}

Vec2 Ball::get_direction()
{
	return _direction;
}

void Ball::set_speed(int speed)
{
	_speed = speed;
}

int Ball::get_speed()
{
	return _speed;
}


void Ball::BallMove()
{
	_location += _direction;
	setPosition(_location);
	//log("BallMoving! position x=%f, y=%f",_location.x,_location.y);
}

bool Ball::collideWithSlider(Slider* slider)
{
	float LeftX = slider->getPositionX() - slider->getTexture()->getContentSize().width/2;
	float RightX = slider->getPositionX() + slider->getTexture()->getContentSize().width/2;
	float MidX = slider->getPositionX();
	float MaxY = slider->getPositionY() + slider->getTexture()->getContentSize().height/2;
	float MinY = slider->getPositionY() - slider->getTexture()->getContentSize().height/2;
	float MidY = slider->getPositionY();
	if ( _location.x > LeftX && _location.x < RightX  )
	{
		if ( _location.y < MaxY + _radius && _location.y > MidY)
		{
			this->setPositionY(MaxY + _radius);
			float ratio = (_location.x - MidX) / (RightX - LeftX) / 2;
			float offset = ratio * M_PI / 3;
			_direction.y *= -1;
			float BallAngle = (_direction-Vec2::ZERO).getAngle();
			float lastAngle = BallAngle - offset;
			set_direction(Vec2(cos(lastAngle), sin(lastAngle)));
		}
		else if ( _location.y > MinY - _radius && _location.y < MidY)
		{
			this->setPositionY(MinY - _radius);
			float ratio = (_location.x - MidX) / (RightX - LeftX) / 2;
			float offset = ratio * M_PI;
			_direction.y *= -1;
			float BallAngle = (_direction-Vec2::ZERO).getAngle();
			float lastAngle = BallAngle - offset;
			set_direction(Vec2(cos(lastAngle), sin(lastAngle)));
		}
		
	}
	return true;
}

bool Ball::collideWithEdges()
{
	if (_location.x<_radius || _location.x > _visibleSize.width-_radius)
		_direction.x *= -1;
	else if (_location.y > _visibleSize.height-_radius)
		_direction.y *= -1;
	else if (_location.y < _radius)
	{
		return false;
	}
	return true;
}

void Ball::collideWithBricks( Brick* brick)
{
		//ÅÐ¶Ïbuff
		if(brick->getBf() == UP_SPEED && _speed <= 4)
		{
			_speed += 1;
		}
		else if(brick->getBf() == DOWN_SPEED && _speed > 2)
		{
			_speed -= 1;
		}
}

bool Ball::init()
{
	initWithFile("Game/Level_1/ball_1.png"); 
	_radius = this->getContentSize().height/2;
	_visibleSize = Director::getInstance()->getVisibleSize();
	auto animation = Animation::create();
	animation->addSpriteFrameWithFileName("Game/Level_1/ball_1.png");
	animation->addSpriteFrameWithFileName("Game/Level_1/ball_2.png");
	animation->addSpriteFrameWithFileName("Game/Level_1/ball_3.png");
	animation->addSpriteFrameWithFileName("Game/Level_1/ball_4.png");
	animation->setDelayPerUnit(0.2f);
	animation->setRestoreOriginalFrame(true);
	this->runAction(RepeatForever::create(Animate::create(animation)));
	return true;
}


