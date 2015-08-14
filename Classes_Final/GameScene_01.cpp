#include "GameScene_01.h"
#include "MainMenuScene.h"
#include "DialogLayer.h"

USING_NS_CC;

void GameScene_01::createMenu()
{
	auto btn_Pause = MenuItemImage::create("Game/btn_pause.png","Game/btn_pause_std.png",
		CC_CALLBACK_1(GameScene_01::menuPause, this));
	auto menu = Menu::createWithItem(btn_Pause);
	menu->setPosition(50,visibleSize.height - 30);
	this->addChild(menu);
}

void GameScene_01::menuPause(Ref* pSender)
{
	Director::getInstance()->pushScene(Pause::createScene(1));
}

Scene* GameScene_01::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    // 'layer' is an autorelease object
    auto layer = GameScene_01::create();

    // add layer as a child to scene
    scene->addChild(layer);
    // return the scene
    return scene;
}

void GameScene_01::createSlider()
{
	slider = Slider::create();
	addChild(slider);
	Size S_size = slider->getContentSize();
	slider->setPosition(visibleSize.width / 2, S_size.height / 2);
}

void GameScene_01::createBall()
{
	balls = new Vector<Ball*>();
	auto ball = Ball::create();
	this->addChild(ball);
	Size B_size = ball->getContentSize();
	Size S_size = slider->getContentSize();
	ball->setContentSize(B_size);
	ball->setPosition(visibleSize.width / 2, B_size.height / 2 + S_size.height + 20);
	ball->set_location(ball->getPosition());
	balls->pushBack(ball);
	ball->autorelease();
}

void GameScene_01::addBall()
{
	auto ball = Ball::create();
	this->addChild(ball);
	ball->set_location(visibleSize/2);
	balls->pushBack(ball);
}

void GameScene_01::creatBricks()
{
	bricks = new Vector<Brick*>;
	auto brick = Brick::create();
	float b_w = brick->getContentSize().width;
	float b_h = brick->getContentSize().height;
	int num_line = visibleSize.width / b_w - 1;
	float offset = (visibleSize.width - num_line * b_w) / 2;
	int num_row = visibleSize.height / b_h / 2;
	int brickBf = random<int>(1, 6);
	for ( int i=0; i<num_line; i++)
	{
		for ( int j=0; j<num_row; j++)
		{
			brick->setPosition(offset + i*b_w + b_w/2, visibleSize.height - j*b_h - b_h/2 - 80 );
			int brickBf = random<int>(1, 6);
			switch (brickBf)
			{
			case 1:
				brick->setBrickBuff(NORMAL);
				break;
			case 2:
				brick->setBrickBuff(UP_SPEED);
				break;
			case 3:
				brick->setBrickBuff(DOWN_SPEED);
				break;
			case 4:
				brick->setBrickBuff(ADD_LENGTH);
				break;
			case 5:
				brick->setBrickBuff(SUB_LENGTH);
				break;
			case 6:
				brick->setBrickBuff(ADD_BALL);
			default:
				break;
			}
			bricks->pushBack(brick);
			brick->autorelease();
			brick = Brick::create();
		}
	}
	
	for (auto iter = bricks->begin(); iter!= bricks->end(); iter++)
	{
		this->addChild(*iter);
	}
}

// on "init" you need to initialize your instance
bool GameScene_01::init()
{
    if ( !LayerColor::initWithColor(Color4B(255,255,255,255)) )
    {
        return false;
    }
	visibleSize = Director::getInstance()->getVisibleSize();

	auto backGround = Sprite::create("Game/Level_1/background.png");
	addChild(backGround,0);
	backGround->setAnchorPoint(Vec2::ZERO);
	createMenu();
	createSlider();
	createBall();
	creatBricks();
	this->scheduleUpdate();

    return true;
}

void GameScene_01::update(float delta)
{
	int num = 0;
	int addBalls = 0;
	auto deleteBalls = new Vector<Ball*>();
	auto deleteBricks = new Vector<Brick*>();
	if (bricks->empty())
	{
		Director::getInstance()->replaceScene(Win::createScene(1));
		unscheduleUpdate();
	}
	else if (balls->empty())
	{
		Director::getInstance()->replaceScene(Fail::createScene(1));
		unscheduleUpdate();
	}
	//±éÀúÃ¿Ò»¸öÇò
	for( auto iter1 = balls->begin(); iter1 != balls->end(); iter1++)
	{
		for (int i=0; i<(*iter1)->get_speed(); i++)
		{
			if( !(*iter1)->collideWithEdges() )
			{
				deleteBalls->pushBack(*iter1);
				break;
			}
			(*iter1)->collideWithSlider(slider);
			for (auto iter = bricks->begin(); iter != bricks->end(); iter++)
			{
				if((*iter1)->isCollideWithBrick(*iter))
				{
					(*iter1)->collideWithBricks(*iter);
					if ( ADD_BALL == (*iter)->getBf() )
					{
						addBalls++;
					}
					if ( ADD_LENGTH == (*iter)->getBf())
					{
	
						slider->setTexture("Game/level_1/paddle_long.png");
					}
					if ( SUB_LENGTH == (*iter)->getBf())
					{
						slider->setTexture("Game/level_1/paddle_short.png");
					}
					deleteBricks->pushBack(*iter);
					break;
				}
			}
			(*iter1)->BallMove(); //move every ball
		}
	}
	for(int i = 0; i<addBalls; i++)
	{
		addBall();
	}
	//É¾³ý»º´æµÄÐ¡Çò
	if( !deleteBalls->empty()) {
		for (auto it = deleteBalls->begin(); it != deleteBalls->end(); it++)
		{
			this->removeChild(*it);
			balls->eraseObject(*it);
		}
	}
	//É¾³ý»º´æµÄ×©¿é
	if( !deleteBricks->empty()) {
		for (auto it = deleteBricks->begin(); it != deleteBricks->end(); it++)
		{
			this->removeChild(*it);
			bricks->eraseObject(*it);
		}
	}
}

void GameScene_01::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
