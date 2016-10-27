#ifndef _Game_Data_
#define _Game_Data_
#include"cocos2d.h"
#include"bullet.h"
using namespace cocos2d;

class GameData : public Node
{
public:

	virtual bool init();
	CREATE_FUNC(GameData);

	Vector<bullet *> Player_bullet1;	//�洢����ӵ�
	Vector<bullet *> Player_bullet2;	//�洢����ӵ�
	Vector<bullet *> Player_bullet3;	//�洢����ӵ�
	Vector<bullet *> Player_bullet4;	//�洢����ӵ�
	Vector<bullet *> Player_bullet5;	//�洢����ӵ�
	Vector<bullet *> Player_bullet6;	//�洢����ӵ�



	Vector<bullet *> Cpu_bullet1;	//�洢�����ӵ�
	Vector<bullet *> Cpu_bullet2;	//�洢�����ӵ�
	Vector<bullet *> Cpu_bullet3;	//�洢�����ӵ�
	Vector<bullet *> Cpu_bullet4;	//�洢�����ӵ�
	Vector<bullet *> Cpu_bullet5;	//�洢�����ӵ�
	Vector<bullet *> Cpu_bullet6;	//�洢�����ӵ�

};
#endif