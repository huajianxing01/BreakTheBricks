#include "Block.h"
#include "cocos2d.h"
USING_NS_CC;

Block::Block()
{
	m_sprite = NULL;
}
Block::~Block()
{

}
Sprite* Block::getSprite()
{
	return this->m_sprite;
}
void Block::bindSprite(Sprite* sprite)
{
	this->m_sprite = sprite;
	this->addChild(m_sprite);
}
bool Block::init()
{
	return true;
}