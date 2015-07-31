#include "Pause.h"
#include "Game1.h"
#include "LevelMenuScene.h"
USING_NS_CC;

Scene* Pause::createScene()
{
	auto scene = Scene::create();
	auto layer = Pause::create();
	scene->addChild(layer);
	return scene;
}

bool Pause::init()
{
	if(!Layer::init())
	{
		return false;
	}

	//The Size seting.
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("Game/Level_1/background.png");
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(sprite,0);

	auto sprite0 = Sprite::create("Game/panel.png");
	sprite0->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 30));
	addChild(sprite0,1);

	auto pause_txt = Label::createWithTTF("Paused", "fonts/Forte.ttf", 48);
	pause_txt->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 95));
	addChild(pause_txt,3);

	auto sprite1 = Sprite::create("Game/btn_paused.png");
	sprite1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 100));
	addChild(sprite1,2);

	auto item1 = MenuItemImage::create("Game/btn_play.png","Game/btn_play.png", CC_CALLBACK_1(Pause::call1,this));
	item1->setPosition(Vec2(visibleSize.width * 0.3, visibleSize.height / 2 + 15));

	auto item2 = MenuItemImage::create("Game/btn_restart.png", "Game/btn_restart.png", CC_CALLBACK_1(Pause::call2, this));
	item2->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height / 2 + 15));

	auto item3 = MenuItemImage::create("Game/btn_level_menu.png", "Game/btn_level_menu.png", CC_CALLBACK_1(Pause::call3, this));
	item3->setPosition(Vec2(visibleSize.width * 0.7, visibleSize.height / 2 + 15));
	
	auto menu = Menu::create(item1, item2, item3, NULL);
	menu->setPosition(Vec2::ZERO);
	addChild(menu, 4);
	return true;
}

void Pause::call1(Ref* pSender)
{
	Director::sharedDirector()->popScene();
}

void Pause::call2(Ref* pSender)
{
	Director::getInstance()->replaceScene(Game1::createScene());
}

void Pause::call3(Ref* pSender)
{
	Director::getInstance()->replaceScene(LevelMenu::createScene());
}