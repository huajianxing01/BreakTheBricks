#include "HelloWorldScene.h"
#include "LevelMenuScene.h"
//#include "Music.h"
#include "SimpleAudioEngine.h"
#include "extensions/cocos-ext.h"
USING_NS_CC_EXT;
USING_NS_CC;
using namespace CocosDenshion;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
   
    auto layer = HelloWorld::create();

    scene->addChild(layer);

    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	isPause = false;

	auto BackgroundSprite = Sprite::create("MainMenu/background.png");
	BackgroundSprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(BackgroundSprite, 0);

	auto MainMenu_Title_Sprite = Sprite::create("MainMenu/txt_title.png");
	MainMenu_Title_Sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.85));
	addChild(MainMenu_Title_Sprite, 1);

	auto MainMenu_Start_Sprite = Sprite::create("MainMenu/btn_start.png");
	MainMenu_Start_Sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(MainMenu_Start_Sprite, 1);

	auto MainMenu_Start_Item = MenuItemImage::create("MainMenu/txt_start.png", "MainMenu/txt_start_shadow.png", CC_CALLBACK_1(HelloWorld::menuCallBack1, this));
	MainMenu_Start_Item->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.51));
	MainMenu_Start_Item->setScale(1.2);
	MainMenu_Start_Item->setRotation(-2);

	auto MainMenu_Help_Item = MenuItemImage::create("MainMenu/btn_help.png", "MainMenu/btn_help.png", CC_CALLBACK_1(HelloWorld::menuCallBack2, this));
	MainMenu_Help_Item->setPosition(Vec2(visibleSize.width * 0.9, visibleSize.height * 0.15));

	auto MainMenu_Setting_Item = MenuItemImage::create("MainMenu/btn_setting.png", "MainMenu/btn_setting.png", CC_CALLBACK_1(HelloWorld::menuCallBack3, this));
	MainMenu_Setting_Item->setPosition(Vec2(visibleSize.width * 0.9, visibleSize.height * 0.05));

	auto _turnOn = MenuItemImage::create("MainMenu/btn_sound.png", "MainMenu/btn_sound.png");
	auto _turnOff = MenuItemImage::create("MainMenu/btn_sound_pause.png", "MainMenu/btn_sound_pause.png");
	auto MainMenu_Sound_Item = MenuItemToggle::createWithCallback(CC_CALLBACK_1(HelloWorld::menuCallBack4, this), _turnOn, _turnOff, NULL);
	MainMenu_Sound_Item->setPosition(Vec2(visibleSize.width * 0.9, visibleSize.height *0.25));
	
	auto MainMenu_Exit_Item = MenuItemImage::create("MainMenu/btn_exit.png", "MainMenu/btn_exit.png", CC_CALLBACK_1(HelloWorld::menuCallBack5, this));
	MainMenu_Exit_Item->setPosition(Vec2(visibleSize.width * 0.95, visibleSize.height * 0.95));

	auto menu = Menu::create(MainMenu_Start_Item, MainMenu_Help_Item, MainMenu_Setting_Item, MainMenu_Sound_Item, MainMenu_Exit_Item, NULL);
	menu->setPosition(Vec2::ZERO);
	addChild(menu,2);

	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/back_music.mp3", true);

    return true;
}

void HelloWorld::menuCallBack1(Ref* pSender)
{
	Director::getInstance()->replaceScene(LevelMenu::createScene());
}
void HelloWorld::menuCallBack2(Ref* pSender)
{
	log("call help item");
}
void HelloWorld::menuCallBack3(Ref* pSender)
{
	log("call setting item");
}

void HelloWorld::menuCallBack4(Ref* pSender)
{
	//Director::getInstance()->replaceScene(Music::createScene());
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

void HelloWorld::menuCallBack5(Ref* pSender)
{
	Director::getInstance()->end();
}