#include "HelpScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* HelpMenu::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelpMenu::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelpMenu::init()
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
		CC_CALLBACK_1(HelpMenu::menuBackCallback, this));

	closeItem->setPosition(visibleSize.width - 30, visibleSize.height - 30);

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
	level_panel->setPosition(visibleSize / 2);
	this->addChild(level_panel, 1);

	auto title = Sprite::create("LevelMenu/title.png");
	title->setPosition(Vec2(320, 840));
	this->addChild(title, 2);

	// create menu, it's an autorelease object
	auto levelMenu = Menu::create(closeItem, NULL);
	levelMenu->setPosition(Vec2::ZERO);
	this->addChild(levelMenu, 2);

	auto help = Sprite::create("HelpMenu/help.png");
	help->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(help, 3);

	return true;
}

void HelpMenu::menuBackCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(MainMenu::createScene());
}