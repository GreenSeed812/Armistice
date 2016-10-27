#ifndef _Create_MAP_
#define _Create_MAP_
#include"cocos2d.h"
using namespace cocos2d;

enum Map_type //士兵类型枚举
{
	mapType1, //关卡类型1
};
class CreateMap : public Node
{
public:

	virtual bool init();
	CREATE_FUNC(CreateMap);

	void setMap(Map_type type); //创建一个关卡地图
	void getMap();	//获取地图块组成地图

	//int (*m_map)[6][30];	//地图数组
	int m_map[6][30];
	Vector<Sprite *> Map_spr1;	//
	Vector<Sprite *> Map_spr2;	//
	Vector<Sprite *> Map_spr3;	//
	Vector<Sprite *> Map_spr4;	//
	Vector<Sprite *> Map_spr5;	//
	Vector<Sprite *> Map_spr6;	//

};
#endif