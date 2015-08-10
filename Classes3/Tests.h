#ifndef TESTS_H
#define TESTS_H

#include "cocos2d.h"

USING_NS_CC;

class Tests :public Layer
{
public:
	Tests()
	{
	}

	~Tests()
	{
	}
	CC_SYNTHESIZE(int,hp,Hp);
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Tests);
	void menuCloseCallBack(Ref* pSender);

private:

};


#endif