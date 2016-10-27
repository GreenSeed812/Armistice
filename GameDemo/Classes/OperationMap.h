#ifndef _Operation_Map_
#define _Operation_Map_
#include"cocos2d.h"
#include"CreateMap.h"
#include <vector>
using namespace cocos2d;

class OperationMap : public Node	//地图操作类
{
public:

	virtual bool init();
	CREATE_FUNC(OperationMap);
	void onTouchesBegan(const std::vector<Touch*> touches, Event * event);  //回调响应鼠按下
	void onTouchesMoved(const std::vector<Touch*> touches, Event * event);  //鼠标移动
	void onTouchesEnded(const std::vector<Touch*> touches, Event * event);  //回调响应鼠抬起

	void getMap(CreateMap * map){ m_Map = map; };	//获取地图指针
	void setGear();	//初始化齿轮


	Size visibleSize;
	Vec2 origin;
	Rect Gear_rec;	//齿轮矩形
	CreateMap * m_Map;	//地图指针

	Sprite * Gear_spr;	//齿轮精灵

	int tc_x;	//鼠标点击坐标
	int tc_y;
	int distance;	//地图移动距离
};

#endif