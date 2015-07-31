#include "Fail.h"
#include "HelloWorldScene.h"
#include "LevelMenuScene.h"
#include "Game1.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"

USING_NS_CC_EXT;
USING_NS_CC;

Scene* Fail::createScene()
{
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

	auto BackgroundSprite = Sprite::create("Game/Level_1/background.png");
	BackgroundSprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(BackgroundSprite, 0);

	auto PanelSprite = Sprite::create("Game/panel.png");
	PanelSprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 30));
	addChild(PanelSprite, 1);

	auto fail_txt = Label::createWithTTF("Failed", "fonts/Forte.ttf", 48);
	fail_txt->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 95));
	addChild(fail_txt, 3);

	auto Fail = Sprite::create("Game/btn_fail.png");
	Fail->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 100));
	addChild(Fail, 2);

	auto item1 = MenuItemImage::create("Game/btn_level_menu.png", "Game/btn_level_menu.png", CC_CALLBACK_1(Fail::call1, this));
	item1->setPosition(Vec2(visibleSize.width * 0.4, visibleSize.height / 2 + 15));

	auto item2 = MenuItemImage::create("Game/btn_restart.png", "Game/btn_restart.png", CC_CALLBACK_1(Fail::call2, this));
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
	Director::getInstance()->replaceScene(Game1::createScene());
}
