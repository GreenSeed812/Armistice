#ifndef _Operation_Map_
#define _Operation_Map_
#include"cocos2d.h"
#include"CreateMap.h"
#include <vector>
using namespace cocos2d;

class OperationMap : public Node	//��ͼ������
{
public:

	virtual bool init();
	CREATE_FUNC(OperationMap);
	void onTouchesBegan(const std::vector<Touch*> touches, Event * event);  //�ص���Ӧ����
	void onTouchesMoved(const std::vector<Touch*> touches, Event * event);  //����ƶ�
	void onTouchesEnded(const std::vector<Touch*> touches, Event * event);  //�ص���Ӧ��̧��

	void getMap(CreateMap * map){ m_Map = map; };	//��ȡ��ͼָ��
	void setGear();	//��ʼ������


	Size visibleSize;
	Vec2 origin;
	Rect Gear_rec;	//���־���
	CreateMap * m_Map;	//��ͼָ��

	Sprite * Gear_spr;	//���־���

	int tc_x;	//���������
	int tc_y;
	int distance;	//��ͼ�ƶ�����
};

#endif