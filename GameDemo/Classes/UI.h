#ifndef _Game_UI_
#define _Game_UI_
#include"cocos2d.h"
#include"game_enum.h"
using namespace cocos2d;

class UI : public Node
{
public:

	virtual bool init();
	CREATE_FUNC(UI);

	bool  onTouchBegan(Touch * touch, Event * event);  //回调响应鼠按下
	void  onTouchMoved(Touch * touch, Event * event);  //鼠标移动
	void  onTouchEnded(Touch * touch, Event * event);  //回调响应鼠抬起


	Sprite * Head_spr1;	//步兵UI头像
	Sprite * Head_spr2;
	Sprite * Head_spr3;
	Sprite * Head_spr4;

	Sprite * Map_green; //地图绿色选框

	Sprite * Soldiers_spr1;	//角色拖动时的精灵
	Soldiers_enum  Head;	//头像枚举
	Size visibleSize;
	Vec2 origin;

};
#endif