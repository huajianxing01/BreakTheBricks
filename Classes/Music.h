#ifndef __MUSIC_H__
#define __MUSIC_H__
#include "cocos2d.h"

USING_NS_CC;

class Music : public Layer{
public:
	virtual bool init();
	static Scene* createScene();
	CREATE_FUNC(Music);
	void menuMusicCallback(Ref* pSender);
	void menuCloseCallback(Ref* pSender);

private:
	bool isPause;
};


#endif