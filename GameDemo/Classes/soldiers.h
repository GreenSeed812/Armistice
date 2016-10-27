#ifndef _soldiers_
#define _soldiers_
#include"cocos2d.h"
#include"soldiersAI.h"
#include"operation.h"
#include"GameData.h"
#include"CreateMap.h"
#include"bullet.h"
using namespace cocos2d;

class soldiers : public Node //����ʿ��
{
public:

	virtual bool init();
	CREATE_FUNC(soldiers);
	virtual void update(float time);

	void setSoldiers(CreateMap * Map ,GameData * data, Soldiers_operation operation, Soldiers_enum  Soldiers, float x, float y); //���ó�ʼ�����ǵ�λ��
	void soldiers_walking();	//ʿ������
	void getMap(CreateMap * map){ m_Map = map; AI->m_Map = map; };	//��ȡ��ͼָ��
	void bullets(float time);	//�����ӵ�
	void death();	//�����߼�
	void attack();	//�����ж�

	soldiersAI * AI;


	Soldiers_operation m_operation;
	Soldiers_enum  m_Soldiers;
	GameData * m_data;
	CreateMap * m_Map;
	Sprite * soldiers_Spr; //ʿ������
	int sprX;
	int sprY;
	int HP;
	bool Bullet;
};
#endif