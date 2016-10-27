#ifndef _soldiers_AI_
#define _soldiers_AI_
#include"cocos2d.h"
#include"CreateMap.h"
#include"game_enum.h"
using namespace cocos2d;

class soldiersAI : public Node //士兵自身AI 用于识别地图块 标记地图块 识别前方地图块是否有敌人
{
public:

	virtual bool init();
	CREATE_FUNC(soldiersAI);
	virtual void update(float time);

	void setMAP_state(); //设置士兵是否踩到某个图块
	void get_Soldiers(Soldiers_operation soldiers_operation, Soldiers_enum soldiers);
	void get_Map(CreateMap * Map){ m_Map = Map; };//获取地图指针
	void AI();

	int getMAP_state(int x, int y, int sprX, int sprY); //返回前方地图块状态

	int enemy_X;
	int stateX;
	int stateY;
	int SoldiersX;
	int SoldiersY;

	CreateMap * m_Map;
	Soldiers_operation  m_soldiers_operation;	//操作类型
	Soldiers_enum  m_soldiers;	//士兵类型
	Soldiers_state state;	//士兵当前状态
};
#endif