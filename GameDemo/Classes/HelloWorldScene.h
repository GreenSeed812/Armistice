#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include"soldiers.h"
#include"UI.h"
#include"CreateMap.h"
#include"GameData.h"
#include"OperationMap.h"
#include"MapPit.h"
#include "cocos2d.h"
using namespace cocos2d;

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	bool  onTouchBegan(Touch * touch, Event * event);  //回调响应鼠按下
	void  onTouchMoved(Touch * touch, Event * event);  //鼠标移动
	void  onTouchEnded(Touch * touch, Event * event);  //回调响应鼠抬起

	void  setSoldiers(int x,int y);	//创建敌人位置和种类

	Size visibleSize;
	Vec2 origin;

	GameData * m_data;
	CreateMap * m_Map;
	OperationMap * m_OperationMap;
	UI * Ui;
	MapPit * m_Pit;
	Camera * m_mainCamera;			// 系统默认相机

};

#endif // __HELLOWORLD_SCENE_H__
