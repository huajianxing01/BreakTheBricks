#include "Paddle.h"
#include "cocos2d.h"
USING_NS_CC;

Paddle::Paddle()
{
	m_sprite = NULL;
}
Paddle::~Paddle()
{

}
Sprite* Paddle::getSprite()
{
	return this->m_sprite;
}
void Paddle::bindSprite(Sprite* sprite)
{
	this->m_sprite = sprite;
	this->addChild(m_sprite);
}
bool Paddle::init()
{
	return true;
}