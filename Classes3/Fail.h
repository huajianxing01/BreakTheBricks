#ifndef __FAIL_H__
#define __FAIL_H__
#include "cocos2d.h"
USING_NS_CC;

class Fail : public Layer{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Fail);
	void call1(Ref* pSender);
	void call2(Ref* pSender);
};

#endif 