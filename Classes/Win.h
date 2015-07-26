#ifndef __WIN_H__
#define __WIN_H__
#include "cocos2d.h"
USING_NS_CC;

class Win : public Layer{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Win);
	void callbackFunc(Ref* pSender);
};

#endif 