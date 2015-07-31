#include "LevelMenuScene.h"
#include "HelloWorldScene.h"
#include "Game1.h"

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
		"LevelMenu/btn_exit.png",
		CC_CALLBACK_1(LevelMenu::menuBackCallback, this));

	closeItem->setPosition(Vec2(600, 920));

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	// position the label on the center of the screen

	// set up the background
	auto background = Sprite::create("LevelMenu/background.png");
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(background, 0);

	// set up the level select panel
	auto level_panel = Sprite::create("LevelMenu/level_panel.png");
	level_panel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	
	this->addChild(level_panel, 1);

	auto title = Sprite::create("LevelMenu/title.png");
	title->setPosition(Vec2(320, 840));
	this->addChild(title, 2);

	auto level_1 = Label::createWithTTF("1", "fonts/Forte.ttf", 72);
	level_1->setColor(Color3B(220, 167, 60));
	level_1->setPosition(Vec2(160, 700));
	this->addChild(level_1, 3);

	auto level = MenuItemImage::create("LevelMenu/level.png", "LevelMenu/level.png", CC_CALLBACK_1(LevelMenu::menuEnterLevelCallback, this));
	level->setScale(0.2);
	level->setPosition(Vec2(160, 700));

	auto last_page = MenuItemImage::create("LevelMenu/last_page.png", "LevelMenu/last_page.png", CC_CALLBACK_1(LevelMenu::menuLastPageCallback, this));
	last_page->setPosition(Vec2(190, 125));

	auto next_page = MenuItemImage::create("LevelMenu/next_page.png", "LevelMenu/next_page.png", CC_CALLBACK_1(LevelMenu::menuNextPageCallback, this));
	next_page->setPosition(Vec2(450, 125));

	// create menu, it's an autorelease object
	auto levelMenu = Menu::create(closeItem, level, last_page, next_page, NULL);
	levelMenu->setPosition(Vec2::ZERO);
	this->addChild(levelMenu, 2);

	return true;
}

void LevelMenu::menuBackCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(HelloWorld::createScene());
}

void LevelMenu::menuLastPageCallback(cocos2d::Ref* pSender)
{
	//Director::getInstance()->replaceScene(HelloWorld::createScene());
}

void LevelMenu::menuNextPageCallback(cocos2d::Ref* pSender)
{
	//Director::getInstance()->replaceScene(HelloWorld::createScene());
}

void LevelMenu::menuEnterLevelCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(Game1::createScene());
}