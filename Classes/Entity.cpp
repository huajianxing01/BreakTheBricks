#include "Entity.h"

Entity::Entity()
{
	
}

Entity::~Entity()
{

}

Entity* Entity::create(const char* _Filename)
{
	Entity* newSprite = new Entity;
	if (newSprite && newSprite->initWithFile(_Filename))
	{
		newSprite->autorelease();
		return newSprite;
	}
	CC_SAFE_DELETE(newSprite);
	return nullptr;
}

