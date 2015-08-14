#ifndef __LEVELMENU_SCENE_H__
#define __LEVELMENU_SCENE_H__

#include "cocos2d.h"

class LevelMenu : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// a selector callback
	void menuBackCallback(cocos2d::Ref* pSender);
	void menuLastPageCallback(cocos2d::Ref* pSender);
	void menuNextPageCallback(cocos2d::Ref* pSender);
	void menuEnterLevel_01Callback(cocos2d::Ref* pSender);
	void menuEnterLevel_02Callback(cocos2d::Ref* pSender);
	void menuEnterLevel_03Callback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(LevelMenu);
};

#endif // __LEVELMENU_SCENE_H__