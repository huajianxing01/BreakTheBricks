#include "Win.h"
#include "LevelMenuScene.h"
#include "GameScene_01.h"
#include "cocos2d.h"

USING_NS_CC;

Scene* Win::createScene()
{
	auto scene = Scene::create();
	auto layer = Win::create();
	scene->addChild(layer);
	return scene;
}

bool Win::init()
{
	if (!Layer::init())
	{

		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("Game/Level_1/background.png");
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(sprite, 0);

	auto sprite0 = Sprite::create("Game/panel.png");
	sprite0->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 30));
	addChild(sprite0, 1);

	auto success_txt = Label::createWithTTF("Success", "fonts/MarkerFelt.ttf", 48);
	success_txt->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 100));
	addChild(success_txt, 3);

	auto sprite1 = Sprite::create("Game/btn_success.png");
	sprite1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 100));
	addChild(sprite1, 2);

	auto item1 = MenuItemImage::create("Game/btn_level_menu.png","Game/btn_level_menu.png", CC_CALLBACK_1(Win:: call1, this));
	item1->setPosition(Vec2(visibleSize.width * 0.3, visibleSize.height / 2 + 15));

	auto item2 = MenuItemImage::create("Game/btn_restart.png", "Game/btn_restart_std.png", CC_CALLBACK_1(Win::call2, this));
	item2->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height / 2 + 15));

	auto item3 = MenuItemImage::create("Game/next_level.png", "Game/next_level_std.png", CC_CALLBACK_1(Win::call3, this));
	item3->setPosition(Vec2(visibleSize.width * 0.7, visibleSize.height / 2 + 15));

	auto menu = Menu::create(item1,item2,item3, NULL);
	menu->setPosition(Vec2::ZERO);
	addChild(menu, 4);
	return true;
}

void Win::call1(Ref* pSender)
{
	Director::getInstance()->replaceScene(LevelMenu::createScene());
}

void Win::call2(Ref* pSender)
{
	Director::getInstance()->replaceScene(GameScene_01::createScene());
}

void Win::call3(Ref* pSender)
{
	//Director::getInstance()->replaceScene(HelloWorld::createScene());
}