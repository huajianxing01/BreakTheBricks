#include "Tests.h"
USING_NS_CC;

Scene* Tests::createScene()
{
	auto scene = Scene::create();
	auto layer = Tests::create();
	scene->addChild(layer);
	return scene;
}

bool Tests::init()
{
	if(!Layer::init())
	{
		return false;
	}
	
	//auto NewGame = MenuItemImage::create("MainMenu/btn_start.png","MainMenu/btn_start_selected.png",CC_CALLBACK_1());
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto slider = Sprite::create();
	addChild(slider);
	slider->setPosition(visibleSize/2);
	auto m = slider->getContentSize();
	//auto texture = TextureCache::sharedTextureCache()->addImage("Game/level_1/paddle_short.png");
	auto texture = TextureCache::sharedTextureCache()->addImage("Game/level_1/paddle_short.png");
	auto r = slider->getTextureRect();
	slider->setTexture(texture);
	//slider->setScaleX(2.0);
	auto rm = slider->getContentSize();
	return true;
}