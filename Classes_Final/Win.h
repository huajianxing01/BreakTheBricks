#ifndef __WIN_H__
#define __WIN_H__
#include "cocos2d.h"
USING_NS_CC;

class Win : public Layer{
	static int _index;
public:

	static Scene* createScene(int index);
	virtual bool init();
	CREATE_FUNC(Win);
	void call1(Ref* pSender);
	void call2(Ref* pSender);
	void call3(Ref* pSender);
};

#endif 