#ifndef _Game_enum_
#define _Game_enum_
#include"cocos2d.h"
using namespace cocos2d;					//����ö��
enum Soldiers_operation  //�жϲ�������
{
	CPU,
	PLAYER,

};
enum Soldiers_enum //ʿ������ö��
{
	Soldiers_infantry, //����
	Soldiers_artillery,//�ڱ�
	END,
};
enum Soldiers_state //ʿ����ǰ״̬
{
	Right,	//����
	Left,	//����
	Standing,	//վ��
	Bullet,	//���
	End,	//����

};

#endif