#ifndef _soldiers_AI_
#define _soldiers_AI_
#include"cocos2d.h"
#include"CreateMap.h"
#include"game_enum.h"
using namespace cocos2d;

class soldiersAI : public Node //ʿ������AI ����ʶ���ͼ�� ��ǵ�ͼ�� ʶ��ǰ����ͼ���Ƿ��е���
{
public:

	virtual bool init();
	CREATE_FUNC(soldiersAI);
	virtual void update(float time);

	void setMAP_state(); //����ʿ���Ƿ�ȵ�ĳ��ͼ��
	void get_Soldiers(Soldiers_operation soldiers_operation, Soldiers_enum soldiers);
	void get_Map(CreateMap * Map){ m_Map = Map; };//��ȡ��ͼָ��
	void AI();

	int getMAP_state(int x, int y, int sprX, int sprY); //����ǰ����ͼ��״̬

	int enemy_X;
	int stateX;
	int stateY;
	int SoldiersX;
	int SoldiersY;

	CreateMap * m_Map;
	Soldiers_operation  m_soldiers_operation;	//��������
	Soldiers_enum  m_soldiers;	//ʿ������
	Soldiers_state state;	//ʿ����ǰ״̬
};
#endif