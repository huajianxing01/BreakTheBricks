#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
	void menuCallBack1(Ref* pSender);
	void menuCallBack2(Ref* pSender);
	void menuCallBack3(Ref* pSender);
	void menuCallBack4(Ref* pSender);
	void menuCallBack5(Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
private:
	bool isPause;
};

#endif // __HELLOWORLD_SCENE_H__
