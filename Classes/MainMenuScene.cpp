#include "MainMenuScene.h"
#include "LevelMenuScene.h"
#include "GameScene_01.h"

USING_NS_CC;
#define POSX 430

Scene* MainMenu::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MainMenu::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object

	/////////////////////////////
	// 3. add your codes below...

	// set up the background image
	auto background = Sprite::create("MainMenu/background_01.png");
	background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	//background->setFlippedX(true);
	this->addChild(background, 0);

	// set up the title
	auto title = Sprite::create("MainMenu/txt_title_shadow.png");
	title->setPosition(Vec2(visibleSize.width/2,visibleSize.height-60) + origin);
	this->addChild(title, 1);

	auto start = MenuItemImage::create("MainMenu/btn_start_01.png", "MainMenu/btn_start_01_selected.png", CC_CALLBACK_1(MainMenu::menuStartCallback, this));
	start->setPosition(Vec2(150, 450) + origin);

	auto btn_sound = MenuItemImage::create("MainMenu/btn_sound.png", "MainMenu/btn_sound.png", CC_CALLBACK_1(MainMenu::menuSoundCallback, this));
	btn_sound->setPosition(Vec2(POSX, 240) + origin);

	auto btn_help = MenuItemImage::create("MainMenu/btn_help.png", "MainMenu/btn_help.png", CC_CALLBACK_1(MainMenu::menuHelpCallback, this));
	btn_help->setPosition(Vec2(POSX, 150) + origin);

	auto btn_setting = MenuItemImage::create("MainMenu/btn_setting.png", "MainMenu/btn_setting.png", CC_CALLBACK_1(MainMenu::menuSettingCallback, this));
	btn_setting->setPosition(Vec2(POSX, 60) + origin);

	//create menu, it's an autorelease object
	auto menu = Menu::create( start, btn_sound, btn_help, btn_setting, NULL);
	menu->setPosition(0,0);
	this->addChild(menu);

	return true;
}


void MainMenu::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void MainMenu::menuStartCallback(cocos2d::Ref* pSender)
{
	// replace the scene with level scene
	Director::getInstance()->replaceScene(LevelMenu::createScene());
}

void MainMenu::menuHelpCallback(cocos2d::Ref* pSender)
{
	// replace the scene with help scene
	//Director::getInstance()->replaceScene(HelloWorld::createScene());
}

void MainMenu::menuSettingCallback(cocos2d::Ref* pSender)
{
	// replace the scene with setting scene
	//Director::getInstance()->replaceScene(HelloWorld::createScene());
}

void MainMenu::menuSoundCallback(cocos2d::Ref* pSender)
{
	// open or close the background music
	//Director::getInstance()->replaceScene(HelloWorld::createScene());
}