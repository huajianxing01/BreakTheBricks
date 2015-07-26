#include "Game1.h"
#include "Win.h"
#include "Fail.h"
#include "cocos2d.h"
#include "LevelSelectLayer.h"
#include "extensions/cocos-ext.h"

USING_NS_CC_EXT;
USING_NS_CC;

Scene* Game1::createScene()
{
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
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
	padding = 32;
	counts = 290;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();//The Size seting.

	this->setKeyboardEnabled(true);
	this->setKeypadEnabled(true);//Keyboard seting.

	auto sprite = Sprite::create("Scene.jpg");
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(sprite);//create a sprite.

	edgeSp = Sprite::create();
	auto boundBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	boundBody->getShape(0)->setRestitution(1.0f);
	boundBody->getShape(0)->setFriction(0.0f);
	boundBody->getShape(0)->setDensity(1.0f);
	edgeSp->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	edgeSp->setPhysicsBody(boundBody);
	this->addChild(edgeSp);
	edgeSp->setTag(0);//create the bound.

	ba = Ball::create();
	ba->bindSprite(Sprite::create("Ball.png"));
	this->addChild(ba);
	ball = ba->getSprite();
	ball->setPosition(100, 100);
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
	ball->setPhysicsBody(ballBody);
	ball->setTag(1);
	//create the ball.

	pa = Paddle::create();
	pa->bindSprite(Sprite::create("PP1.png"));
	paddle = pa->getSprite();
	this->addChild(pa);
	auto paddleBody = PhysicsBody::createBox(paddle->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT);
	paddleBody->getShape(0)->setRestitution(1.0f);
	paddleBody->getShape(0)->setFriction(0.0f);
	paddleBody->getShape(0)->setDensity(10.0f);
	paddleBody->setGravityEnable(false);
	paddleBody->setDynamic(false);
	paddle->setPhysicsBody(paddleBody);
	paddle->setTag(2);
	paddle->setPosition(visibleSize.width / 2, 50);
	paddle->setScale(0.5f);
	//create the paddle.

	for (int j = 0; j < 7; j++)
	{
		int Xoffset = 0;
		for (int i = 0; i < 29; i++)
		{
			Xoffset = padding + Xoffset;
			addBlock(Vec2(Xoffset, (600 - j * 40)));
		}
	}//add the block.

	this->schedule(schedule_selector(Game1::callback4));


	auto item1 = MenuItemImage::create("home.png", "home.png",CC_CALLBACK_1(Game1::call, this));
	auto menu = Menu::create(item1, NULL);
	menu->setPosition(Vec2(visibleSize.width / 50*49, visibleSize.height / 30));
	addChild(menu, 1);
	return true;
}

void Game1::call(Ref* pSender)
{
	Director::getInstance()->replaceScene(LevelSelectLayer::createScene());
}

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
	Sprite* block;
	bl = Block::create();
	bl->bindSprite(Sprite::create("blocks1.png"));
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
	block->setScale(0.4f);
	block->setTag(3);
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
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Game1::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

}

bool Game1::onContactBegin(const PhysicsContact& contact)
{
	Sprite* spriteA = (Sprite*)contact.getShapeA()->getBody()->getNode();
	Sprite* spriteB = (Sprite*)contact.getShapeB()->getBody()->getNode();
	int tagA = spriteA->getTag();
	int tagB = spriteB->getTag();
	if (tagA == 3)
	{
		spriteA->removeFromParentAndCleanup(true);
		counts--;
	}
	if (tagB == 3)
	{
		spriteB->removeFromParentAndCleanup(true);
		counts--;
	}
	return true;
}
bool Game1::fail()
{
	return (ball->getPositionY() < 40);
}
bool Game1::win()
{
	return (counts == 0);
}