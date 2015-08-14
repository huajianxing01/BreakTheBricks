#ifndef __PAUSE_H__
#define __PAUSE_H__
#include "cocos2d.h"
USING_NS_CC;
class Pause : public Layer
{
	static int _index;
public:
	static Scene* createScene(int index);
	virtual bool init();
	//void menuCloseCallback(Ref* pSender);
	CREATE_FUNC(Pause);
	void call1(Ref* pSender);
	void call2(Ref* pSender);
	void call3(Ref* pSender);
};

#endif // __HELLOWORLD_SCENE_H__