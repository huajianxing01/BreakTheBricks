#include "Game1.h"
#include "Win.h"
#include "Fail.h"
#include "pause.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"

USING_NS_CC_EXT;
USING_NS_CC;

Scene* Game1::createScene()
{
	auto scene = Scene::createWithPhysics();
	Vect gravity(0.0f, 0.0f);
	scene->getPhysicsWorld()->setGravity(gravity);
	auto layer = Game1::create();
	layer->setPhyWorld(scene->getPhysicsWorld());
	scene->addChild(layer);
	return scene;
}

bool Game1::init()
{
	if (!Layer::init())
	{
		return false;
	}
	padding = 70;
	counts = 25;
	flag = 0;

	//The Size seting.
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	//Keyboard seting.
	this->setKeyboardEnabled(true);
	this->setKeypadEnabled(true);

	//create the background
	auto BackgroundSprite = Sprite::create("Game/Level_1/background.png");
	BackgroundSprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(BackgroundSprite);

	//create the bound.
	edgeSp = Sprite::create();
	auto boundBody = PhysicsBody::createEdgeBox(visibleSize, PhysicsMaterial(1.0f, 1.0f, 0.0f), 3);
	edgeSp->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	edgeSp->setTag(0);
	edgeSp->setPhysicsBody(boundBody);
	this->addChild(edgeSp);

	//create the ball
	ba = Ball::create();
	ba->bindSprite(Sprite::create("Game/Level_1/ball.png"));
	this->addChild(ba);
	ball = ba->getSprite();
	ball->setPosition(100, 100);
	auto ballBody = PhysicsBody::createCircle(ball->getContentSize().width / 2, PhysicsMaterial(1.0f, 1.0f, 0.0f));
	ballBody->setGravityEnable(false);
	Vect force = Vect(40000.0f, 40000.0f);
	ballBody->applyImpulse(force);
	ballBody->setCategoryBitmask(0x0001);
	ballBody->setCollisionBitmask(0x0001);
	ballBody->setContactTestBitmask(0x0001);
	ball->setPhysicsBody(ballBody);
	ball->setTag(1);

	//create the paddle.
	pa = Paddle::create();
	pa->bindSprite(Sprite::create("Game/Level_1/paddle.png"));
	paddle = pa->getSprite();
	this->addChild(pa);
	auto paddleBody = PhysicsBody::createBox(paddle->getContentSize(), PhysicsMaterial(10.0f, 1.0f, 0.0f));
	paddleBody->setGravityEnable(false);
	paddleBody->setDynamic(false);
	paddle->setPhysicsBody(paddleBody);
	paddle->setTag(2);
	paddle->setPosition(visibleSize.width / 2, visibleSize.height * 0.05);

	//add the pink block.
	Sprite* block;
	bl = Block::create();
	bl->bindSprite(Sprite::create("block/block4.png"));
	this->addChild(bl);
	block = bl->getSprite();
	auto blockBody = PhysicsBody::createBox(block->getContentSize(), PhysicsMaterial(10.0f, 1.0f, 0.0f));
	blockBody->setDynamic(false);
	blockBody->setCategoryBitmask(0x0001);
	blockBody->setCollisionBitmask(0x0001);
	blockBody->setContactTestBitmask(0x0001);
	block->setPhysicsBody(blockBody);
	block->setTag(10);

	for (int j = 0; j < 5; j++)
	{
		int Xoffset = 120;
		for (int i = 0; i < 5; i++)
		{
			Xoffset = padding + Xoffset;
			if (j == 4 && i == 4)
			{
				block->setPosition(Vec2(Xoffset, visibleSize.height*0.8 - j * 70));
			}
			else
			{
				addBlock(Vec2(Xoffset, visibleSize.height*0.8 - j * 70));
			}
		}
	}

	this->schedule(schedule_selector(Game1::callback4));

	//add the pause btn.
	auto item1 = MenuItemImage::create("Game/btn_pause.png", "Game/btn_pause.png",CC_CALLBACK_1(Game1::call, this));
	auto menu = Menu::create(item1, NULL);
	menu->setPosition(Vec2(visibleSize.width * 0.9, visibleSize.height * 0.95));
	addChild(menu, 1);
	
	//eventlistener
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Game1::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
	
	return true;
}

//call pause function
void Game1::call(Ref* pSender)
{
	Director::sharedDirector()->pushScene(Pause::createScene());
}

//judge win or fail.
void Game1::callback4(float ft)
{
	if (win() == true)
	{
		Director::getInstance()->replaceScene(Win::createScene());
	}
	if (fail() == true)
	{
		Director::getInstance()->replaceScene(Fail::createScene());
	}
}

void Game1::initKeyboard()
{
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(Game1::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(Game1::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Game1::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_BACK)
	{
		int a = 1;
	}
	else
	{
		if (keyCode == EventKeyboard::KeyCode::KEY_A)
		{
			float x = paddle->getPositionX();
			x = x - 40;
			paddle->setPositionX(x);
		}
		else if (keyCode == EventKeyboard::KeyCode::KEY_D)
		{
			float x = paddle->getPositionX();
			x = x + 40;
			paddle->setPositionX(x);
		}
	}
}
void Game1::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_BACK)
	{
		int a = 1;
	}
}

void Game1::addBlock(Vec2 p)
{

	int N = 3 + rand() % 3;

	if (N == 3)
	{
		Sprite* block;
		bl = Block::create();
		bl->bindSprite(Sprite::create("block/block1.png"));
		this->addChild(bl);
		block = bl->getSprite();
		auto blockBody = PhysicsBody::createBox(block->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT);
		blockBody->getShape(0)->setDensity(10.0f);
		blockBody->getShape(0)->setFriction(0.0f);
		blockBody->getShape(0)->setRestitution(1.f);
		blockBody->setDynamic(false);
		blockBody->setCategoryBitmask(0x0001);
		blockBody->setCollisionBitmask(0x0001);
		blockBody->setContactTestBitmask(0x0001);
		block->setPosition(p);
		block->setPhysicsBody(blockBody);
		block->setTag(3);
	}
	else if (N == 4)
	{
		Sprite* block;
		bl = Block::create();
		bl->bindSprite(Sprite::create("block/block2.png"));
		this->addChild(bl);
		block = bl->getSprite();
		auto blockBody = PhysicsBody::createBox(block->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT);
		blockBody->getShape(0)->setDensity(10.0f);
		blockBody->getShape(0)->setFriction(0.0f);
		blockBody->getShape(0)->setRestitution(1.f);
		blockBody->setDynamic(false);
		blockBody->setCategoryBitmask(0x0001);
		blockBody->setCollisionBitmask(0x0001);
		blockBody->setContactTestBitmask(0x0001);
		block->setPosition(p);
		block->setPhysicsBody(blockBody);
		block->setTag(4);
	}
	else
	{
		Sprite* block;
		bl = Block::create();
		bl->bindSprite(Sprite::create("block/block3.png"));
		this->addChild(bl);
		block = bl->getSprite();
		auto blockBody = PhysicsBody::createBox(block->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT);
		blockBody->getShape(0)->setDensity(10.0f);
		blockBody->getShape(0)->setFriction(0.0f);
		blockBody->getShape(0)->setRestitution(1.f);
		blockBody->setDynamic(false);
		blockBody->setCategoryBitmask(0x0001);
		blockBody->setCollisionBitmask(0x0001);
		blockBody->setContactTestBitmask(0x0001);
		block->setPosition(p);
		block->setPhysicsBody(blockBody);
		block->setTag(5);
	}
}

void Game1::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void Game1::onEnter()
{
	Layer::onEnter();

}

bool Game1::onContactBegin(const PhysicsContact& contact)
{
	Sprite* spriteA = (Sprite*)contact.getShapeA()->getBody()->getNode();
	Sprite* spriteB = (Sprite*)contact.getShapeB()->getBody()->getNode();
	int tagA = spriteA->getTag();
	int tagB = spriteB->getTag();
	if (tagA >= 3)
	{
		spriteA->removeFromParentAndCleanup(true);
		counts--;
		if (tagA == 3)
		{
			paddle->setScale(1.35f);
		}
		if (tagA == 4)
		{
			paddle->setScale(0.8f);
		}
		if (tagA == 5)
		{
			paddle->setScale(1.2f);
		}
		if (tagA == 10)
		{
			flag = 1;
			ba2 = Ball::create();
			ba2->bindSprite(Sprite::create("Game/Level_1/ball.png"));
			this->addChild(ba2);
			ball2 = ba2->getSprite();
			ball2->setPosition(100, 100);
			auto ballBody = PhysicsBody::createCircle(ball->getContentSize().width / 2.);
			ballBody->getShape(0)->setRestitution(1.0f);
			ballBody->getShape(0)->setFriction(0.0f);
			ballBody->getShape(0)->setDensity(1.0f);
			ballBody->setGravityEnable(false);
			Vect force = Vect(40000.0f, 40000.0f);
			ballBody->applyImpulse(force);
			ballBody->setCategoryBitmask(0x0001);
			ballBody->setCollisionBitmask(0x0001);
			ballBody->setContactTestBitmask(0x0001);
			ball2->setPhysicsBody(ballBody);
			ball2->setTag(1);
			ball2->setScale(1.1f);
		}
	}
	if (tagB >= 3)
	{
		spriteB->removeFromParentAndCleanup(true);
		counts--;
		if (tagB == 3)
		{
			paddle->setScale(1.35f);
		}
		if (tagB == 4)
		{
			paddle->setScale(0.8f);
		}
		if (tagB == 5)
		{
			paddle->setScale(1.2f);
		}
		if (tagB == 10)
		{
			flag = 1;
			ba2 = Ball::create();
			ba2->bindSprite(Sprite::create("Game/Level_1/ball.png"));
			this->addChild(ba2);
			ball2 = ba2->getSprite();
			ball2->setPosition(100, 100);
			auto ballBody = PhysicsBody::createCircle(ball->getContentSize().width / 2.);
			ballBody->getShape(0)->setRestitution(1.0f);
			ballBody->getShape(0)->setFriction(0.0f);
			ballBody->getShape(0)->setDensity(1.0f);
			ballBody->setGravityEnable(false);
			Vect force = Vect(40000.0f, 40000.0f);
			ballBody->applyImpulse(force);
			ballBody->setCategoryBitmask(0x0001);
			ballBody->setCollisionBitmask(0x0001);
			ballBody->setContactTestBitmask(0x0001);
			ball2->setPhysicsBody(ballBody);
			ball2->setTag(1);
			ball2->setScale(1.1f);
		}
	}
	return true;
}
bool Game1::fail()
{
	if (flag == 0)
	return (ball->getPositionY() < 40);
	else
	{
		return (ball->getPositionY() < 40 || ball2->getPositionY() < 40);
	}
}
bool Game1::win()
{
	return (counts == 0);
}