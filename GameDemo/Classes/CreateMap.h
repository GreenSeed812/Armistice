#ifndef _Create_MAP_
#define _Create_MAP_
#include"cocos2d.h"
using namespace cocos2d;

enum Map_type //ʿ������ö��
{
	mapType1, //�ؿ�����1
};
class CreateMap : public Node
{
public:

	virtual bool init();
	CREATE_FUNC(CreateMap);

	void setMap(Map_type type); //����һ���ؿ���ͼ
	void getMap();	//��ȡ��ͼ����ɵ�ͼ

	//int (*m_map)[6][30];	//��ͼ����
	int m_map[6][30];
	Vector<Sprite *> Map_spr1;	//
	Vector<Sprite *> Map_spr2;	//
	Vector<Sprite *> Map_spr3;	//
	Vector<Sprite *> Map_spr4;	//
	Vector<Sprite *> Map_spr5;	//
	Vector<Sprite *> Map_spr6;	//

};
#endif