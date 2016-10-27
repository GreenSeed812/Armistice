#ifndef _soldiers_
#define _soldiers_
#include"cocos2d.h"
#include"soldiersAI.h"
#include"operation.h"
#include"GameData.h"
#include"CreateMap.h"
#include"bullet.h"
using namespace cocos2d;

class soldiers : public Node //创建士兵
{
public:

	virtual bool init();
	CREATE_FUNC(soldiers);
	virtual void update(float time);

	void setSoldiers(CreateMap * Map ,GameData * data, Soldiers_operation operation, Soldiers_enum  Soldiers, float x, float y); //设置初始化主角的位置
	void soldiers_walking();	//士兵行走
	void getMap(CreateMap * map){ m_Map = map; AI->m_Map = map; };	//获取地图指针
	void bullets(float time);	//发射子弹
	void death();	//死亡逻辑
	void attack();	//攻击判断

	soldiersAI * AI;


	Soldiers_operation m_operation;
	Soldiers_enum  m_Soldiers;
	GameData * m_data;
	CreateMap * m_Map;
	Sprite * soldiers_Spr; //士兵精灵
	int sprX;
	int sprY;
	int HP;
	bool Bullet;
};
#endif