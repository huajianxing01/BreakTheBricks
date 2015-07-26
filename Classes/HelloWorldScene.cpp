#include "HelloWorldScene.h"
#include "LevelSelectLayer.h"
#include "Music.h"
#include "extensions/cocos-ext.h"
USING_NS_CC_EXT;
USING_NS_CC;

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

	auto sprite = Sprite::create("ss.jpg");
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(sprite, 0);

	auto item1 = MenuItemFont::create("Grades",CC_CALLBACK_1(HelloWorld::menuCallBack1,this));
	item1->setPosition(visibleSize.width / 2, visibleSize.height / 2+100);

	auto item2 = MenuItemFont::create("Help", CC_CALLBACK_1(HelloWorld::menuCallBack2, this));
	item2->setPosition(visibleSize.width / 2, visibleSize.height / 2);

	auto item3 = MenuItemFont::create("Select", CC_CALLBACK_1(HelloWorld::menuCallBack3, this));
	item3->setPosition(visibleSize.width / 2, visibleSize.height / 2-100);

	auto item4 = MenuItemFont::create("Music", CC_CALLBACK_1(HelloWorld::menuCallBack4, this));
	item4->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 200);
	
	auto menu = Menu::create(item3, item2, item1,item4,NULL);
	menu->setPosition(Vec2::ZERO);
	addChild(menu,0);

    return true;
}

void HelloWorld::menuCallBack1(Ref* pSender)
{
	//Director::getInstance()->replaceScene(LevelSelectLayer::createScene());
}
void HelloWorld::menuCallBack2(Ref* pSender)
{
	//Director::getInstance()->replaceScene(LevelSelectLayer::createScene());
}
void HelloWorld::menuCallBack3(Ref* pSender)
{
	Director::getInstance()->replaceScene(LevelSelectLayer::createScene());
}

void HelloWorld::menuCallBack4(Ref* pSender)
{
	Director::getInstance()->replaceScene(Music::createScene());
}