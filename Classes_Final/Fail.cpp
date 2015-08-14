#include "Fail.h"
#include "LevelMenuScene.h"
#include "GameScene_01.h"
#include "GameScene_02.h"
#include "GameScene_03.h"
#include "cocos2d.h"

USING_NS_CC;
int Fail::_index = 0;
Scene* Fail::createScene(int index)
{
	_index = index;
	auto scene = Scene::create();
	auto layer = Fail::create();
	scene->addChild(layer);
	return scene;
}

bool Fail::init()
{
	if (!Layer::init())
	{

		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("Game/Level_1/background.png");
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(sprite,0);

	auto sprite0 = Sprite::create("Game/panel.png");
	sprite0->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 30));
	addChild(sprite0, 1);

	auto fail_txt = Label::createWithTTF("Failed", "fonts/MarkerFelt.ttf", 48);
	fail_txt->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 100));
	addChild(fail_txt, 3);

	auto sprite1 = Sprite::create("Game/btn_fail.png");
	sprite1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 100));
	addChild(sprite1, 2);

	auto item1 = MenuItemImage::create("Game/btn_level_menu.png", "Game/btn_level_menu_std.png", CC_CALLBACK_1(Fail::call1, this));
	item1->setPosition(Vec2(visibleSize.width * 0.4, visibleSize.height / 2 + 15));

	auto item2 = MenuItemImage::create("Game/btn_restart.png", "Game/btn_restart_std.png", CC_CALLBACK_1(Fail::call2, this));
	item2->setPosition(Vec2(visibleSize.width * 0.6, visibleSize.height / 2 + 15));

	auto menu = Menu::create(item1,item2, NULL);
	menu->setPosition(Vec2::ZERO);
	addChild(menu, 4);
	return true;
}

void Fail::call1(Ref* pSender)
{
	Director::getInstance()->replaceScene(LevelMenu::createScene());
}
void Fail::call2(Ref* pSender)
{
	if(1 == _index)
	{
	Director::getInstance()->replaceScene(GameScene_01::createScene());
	}
	else if(2 == _index)
	{
		Director::getInstance()->replaceScene(GameScene_02::createScene());
	}
	else if (3 == _index)
	{
		Director::getInstance()->replaceScene(GameScene_03::createScene());
	}
	else
	{
		Director::getInstance()->replaceScene(LevelMenu::createScene());
	}
}
