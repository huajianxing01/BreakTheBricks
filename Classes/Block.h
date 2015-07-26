#ifndef __BLOCK_H__
#define __BLOCK_H__
#include "cocos2d.h"
USING_NS_CC;

class Block : public Node{
public:
	Block();
	~Block();
	Sprite* getSprite();
	void bindSprite(Sprite* sprite);
	CREATE_FUNC(Block);
	virtual bool init();

private:
	Sprite* m_sprite;

};

#endif