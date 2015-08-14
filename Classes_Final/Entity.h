#ifndef _OBJECT_H
#define _OBJECT_H

#include "cocos2d.h"
USING_NS_CC;


class Entity : public Sprite
{
public:
	Entity();
	~Entity();
	static Entity* create(const char* _Filename);
	
};

#endif