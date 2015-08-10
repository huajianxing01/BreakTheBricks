#ifndef _GAMESCENE_01_H
#define _GAMESCENE_01_H

#include "cocos2d.h"
#include "slider.h"
#include "Ball.h"
#include "Brick.h"

typedef enum collide {UP,LeftorRight,NoCollide} CollidePosition;

class GameScene_01 : public cocos2d::LayerColor
{
private:
	Size visibleSize;
	Vec2 _direction;
	Slider* slider; //滑块
	//Ball* ball; //小球
	Vector<Ball*>* balls; //小球队列
	Vector <Brick*>* bricks; //砖块队列
private:
	Sprite* breakBtn; //暂停按钮
	
public:
	//菜单
	void menuPause(Ref* pSender);
	//添加暂停按钮，小球，滑块，砖块到场景
	void createMenu();
	void createSlider();
	void createBall();
	void creatBricks();
	//额外添加小球
	void addBall();

public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	virtual void update(float delta); //update函数，每帧调用
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene_01);
};

#endif 
