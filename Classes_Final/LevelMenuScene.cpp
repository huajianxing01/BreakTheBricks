#include "LevelMenuScene.h"
#include "MainMenuScene.h"
#include "GameScene_01.h"
#include "GameScene_02.h"
#include "GameScene_03.h"

USING_NS_CC;

Scene* LevelMenu::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = LevelMenu::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool LevelMenu::init()
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
	auto closeItem = MenuItemImage::create(
		"LevelMenu/btn_exit.png",
		"LevelMenu/btn_exit_std.png",
		CC_CALLBACK_1(LevelMenu::menuBackCallback, this));

	closeItem->setPosition(visibleSize.width-30, visibleSize.height-30);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	// position the label on the center of the screen

	// set up the background
	auto background = Sprite::create("LevelMenu/background.png");
	background->setPosition(Vec2(320, 480));
	this->addChild(background, 0);

	// set up the level select panel
	auto level_panel = Sprite::create("LevelMenu/level_panel_1.png");
	level_panel->setPosition(visibleSize/2);
	this->addChild(level_panel, 1);

	auto title = Sprite::create("LevelMenu/title.png");
	title->setPosition(Vec2(320, 840));
	this->addChild(title, 2);
	auto level_01 = MenuItemImage::create("LevelMenu/level_1.png", "LevelMenu/level_1_std.png", CC_CALLBACK_1(LevelMenu::menuEnterLevel_01Callback, this));
	level_01->setPosition(100, visibleSize.height-100);

	auto level_02 = MenuItemImage::create("LevelMenu/level_2.png", "LevelMenu/level_2_std.png", CC_CALLBACK_1(LevelMenu::menuEnterLevel_02Callback, this));
	level_02->setPosition(250, visibleSize.height-100);

	auto level_03 = MenuItemImage::create("LevelMenu/level_3.png", "LevelMenu/level_3_std.png", CC_CALLBACK_1(LevelMenu::menuEnterLevel_03Callback, this));
	level_03->setPosition(400, visibleSize.height-100);
	/*auto last_page = MenuItemImage::create("LevelMenu/last_page.png", "LevelMenu/last_page_std.png", CC_CALLBACK_1(LevelMenu::menuLastPageCallback, this));
	last_page->setPosition(40, visibleSize.height/2);

	auto next_page = MenuItemImage::create("LevelMenu/next_page.png", "LevelMenu/next_page_std.png", CC_CALLBACK_1(LevelMenu::menuNextPageCallback, this));
	next_page->setPosition(visibleSize.width-40, visibleSize.height/2);*/

	// create menu, it's an autorelease object
	auto levelMenu = Menu::create(closeItem, level_01, level_02,level_03, NULL);
	levelMenu->setPosition(Vec2::ZERO);
	this->addChild(levelMenu, 2);

	return true;
}

void LevelMenu::menuBackCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(MainMenu::createScene());
}

void LevelMenu::menuLastPageCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(MainMenu::createScene());
}

void LevelMenu::menuNextPageCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(MainMenu::createScene());
}

void LevelMenu::menuEnterLevel_01Callback(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(GameScene_01::createScene());
}

void LevelMenu::menuEnterLevel_02Callback(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(GameScene_02::createScene());
}

void LevelMenu::menuEnterLevel_03Callback(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(GameScene_03::createScene());
}