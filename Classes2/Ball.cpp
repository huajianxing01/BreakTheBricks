#include "Ball.h"
#include "cocos2d.h"
USING_NS_CC;

Ball::Ball()
{
	m_sprite = NULL;
}
Ball::~Ball()
{

}
Sprite* Ball::getSprite()
{
	return this->m_sprite;
}
void Ball::bindSprite(Sprite* sprite)
{
	this->m_sprite = sprite;
	this->addChild(m_sprite);
}
bool Ball::init()
{
	return true;
}