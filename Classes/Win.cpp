#include "Win.h"
#include "HelloWorldScene.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"

USING_NS_CC_EXT;
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
	auto sprite = Sprite::create("win.jpg");
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(sprite);

	auto item = MenuItemFont::create("Back", CC_CALLBACK_1(Win:: callbackFunc, this));
	//item->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 ));

	auto menu = Menu::create(item, NULL);
	menu->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
	addChild(menu, 1);
	return true;
}

void Win::callbackFunc(Ref* pSender)
{
	Director::getInstance()->replaceScene(HelloWorld::createScene());
}
