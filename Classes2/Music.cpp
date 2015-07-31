#include "Music.h"
#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;

Scene* Music::createScene()
{
	auto scene = Scene::create();
	auto layer = Music::create();
	scene->addChild(layer);
	return scene;
}

bool Music::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	isPause = false;

	auto sprite = Sprite::create("scene1.jpg");
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(sprite);

	MenuItemImage *_turnOn, *_turnOff;
	_turnOn = MenuItemImage::create("button_voi_on.png","button_voi_on.png");
	_turnOff = MenuItemImage::create("button_voi_off.png", "button_voi_off.png");
	MenuItemToggle *toggleItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(Music::menuMusicCallback, this), _turnOn, _turnOff, NULL);
	toggleItem->setScale(0.3f);
	toggleItem->setPosition(Point(visibleSize.width / 7*6, visibleSize.height / 2-300));

	MenuItemImage* closeItem = MenuItemImage::create(
		"CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(Music::menuCloseCallback, this));

	auto menu = Menu::create(closeItem, toggleItem, NULL);
	menu->alignItemsVertically();
	menu->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(menu, 2);

	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/back_music.mp3", true);
	// boolÀàÐÍ£¬ÅÐ¶Ï±³¾°ÒôÀÖÊÇ·ñÔÝÍ£
	
	//SimpleAudioEngine::sharedEngine()->end();
	return true;
}

void Music::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->replaceScene(HelloWorld::createScene());
}

void Music::menuMusicCallback(Ref* pSender)
{
	if (isPause == false)
	{
		SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
		isPause = true;
	}
	else
	{
		SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
		isPause = false;
	}
}
