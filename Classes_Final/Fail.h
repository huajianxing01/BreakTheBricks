#ifndef __FAIL_H__
#define __FAIL_H__
#include "cocos2d.h"
USING_NS_CC;

class Fail : public Layer{
	static int _index;
public:
	static Scene* createScene(int index);
	virtual bool init();
	CREATE_FUNC(Fail);
	void call1(Ref* pSender);
	void call2(Ref* pSender);
};

#endif 