#ifndef __Game1_H__
#define __Game1_H__
#include "Paddle.h"
#include "Ball.h"
#include "Block.h"
#include "cocos2d.h"
USING_NS_CC;
class Game1 : public Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void menuCloseCallback(Ref* pSender);
	void setPhyWorld(PhysicsWorld* world)
	{
		m_world = world;
	}
	CREATE_FUNC(Game1);
	void initKeyboard();
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
	void addBlock(Vec2 p);
	void onEnter();
	bool onContactBegin(const PhysicsContact& contact);
	bool win();
	bool fail();
	void callback4(float ft);
	void call(Ref* pSender);

private:
	Sprite* edgeSp;

	Paddle* pa;
	Sprite* paddle;
	
	Ball* ba;
	Sprite* ball;

	Block* bl;
	int padding;
	PhysicsWorld* m_world;
	int counts;
};

#endif // __HELLOWORLD_SCENE_H__