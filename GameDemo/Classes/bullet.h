#ifndef _Bullet_
#define _Bullet_
#include"cocos2d.h"
#include"soldiersAI.h"
using namespace cocos2d;

class bullet : public Node	//子弹类
{
public:

	virtual bool init();
	CREATE_FUNC(bullet);

	void getBullet(Soldiers_operation , Soldiers_enum ,int x,int y,int enemyX);

	Sprite * spr_bullets;	//子弹精灵

	/*Soldiers_operation m_operation;
	Soldiers_enum  m_Soldiers;*/
	int damage;	//攻击力
};
#endif