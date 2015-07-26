//
//  LevelSelectLayer.cpp
//  PageTest
//
//  Created by wx5 on 12/31/14.
//
//

#include "LevelSelectLayer.h"
#include "GameConstants.h"
#include "GameUtils.h"

LevelSelectLayer::LevelSelectLayer() :_currentPage(0){
	float maxPage = g_maxLevel / g_EachPageCount;
	_maxPage = g_maxLevel / g_EachPageCount;
	if (maxPage > _maxPage){
		_maxPage = _maxPage + 1;
	}
}
LevelSelectLayer::~LevelSelectLayer(){

}

Scene* LevelSelectLayer::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = LevelSelectLayer::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool LevelSelectLayer::init(){
	if (!Layer::init()){
		return false;
	}
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/startUI.plist", "res/startUI.png");

	auto colorLayer = LayerColor::create(Color4B(0x24, 0x2c, 0x3c, 255));
	this->addChild(colorLayer, 0);


	initAllLevels();
	initNavigation();

	return true;
}




void LevelSelectLayer::initNavigation(){


	auto leftMenuSpriteNor = Sprite::createWithSpriteFrameName("prePage.png");
	auto leftMenuSpritePre = Sprite::createWithSpriteFrameName("prePagePre.png");
	auto leftMenuItem = MenuItemSprite::create(leftMenuSpriteNor, leftMenuSpritePre, CC_CALLBACK_1(LevelSelectLayer::prePageBack, this));
	_leftMenu = Menu::create(leftMenuItem, NULL);
	this->addChild(_leftMenu);
	_leftMenu->setPosition(100, VISIBLE_HEIGHT * 0.5);

	auto rightMenuSpriteNor = Sprite::createWithSpriteFrameName("nextPage.png");
	auto rightMenuSpritePre = Sprite::createWithSpriteFrameName("nextPagePre.png");
	auto rightMenuItem = MenuItemSprite::create(rightMenuSpriteNor, rightMenuSpritePre, CC_CALLBACK_1(LevelSelectLayer::nextPageBack, this));
	_rightMenu = Menu::create(rightMenuItem, NULL);
	this->addChild(_rightMenu);
	_rightMenu->setPosition(VISIBLE_WIDTH - 100, VISIBLE_HEIGHT * 0.5);

	if (_currentPage == 0){
		_leftMenu->setVisible(false);
	}
	if (_currentPage == (_maxPage - 1)){
		_rightMenu->setVisible(false);
	}
}


void LevelSelectLayer::initAllLevels(){
	UserDefault *save = UserDefault::getInstance();
	g_passLevelCount = save->getIntegerForKey(PlayerPassLevelCountKey, 0);
	log("g_passLevelCount:%d", g_passLevelCount);

	//just for test, in real game, comment the below code
	g_passLevelCount = 5;

	levelSelectContent = LevelSelectContent::create();
	this->addChild(levelSelectContent);
	_currentPage = g_passLevelCount / g_EachPageCount;
	if (_currentPage >= _maxPage){
		_currentPage = _maxPage - 1;
	}
	levelSelectContent->initAllLevels(_currentPage);
}



void LevelSelectLayer::nextPageBack(Ref* sender){
	if (_currentPage < _maxPage - 1){
		_currentPage = _currentPage + 1;

		levelSelectContent->initAllLevels(_currentPage);

		if (_currentPage == (_maxPage - 1)){
			_rightMenu->setVisible(false);
		}
		_leftMenu->setVisible(true);
	}
}
void LevelSelectLayer::prePageBack(Ref* sender){
	if (_currentPage >= 1){
		_currentPage = _currentPage - 1;

		levelSelectContent->initAllLevels(_currentPage);

		if (_currentPage == 0){
			_leftMenu->setVisible(false);
		}
		_rightMenu->setVisible(true);
	}
}


