#ifndef _Game_UI_
#define _Game_UI_
#include"cocos2d.h"
#include"game_enum.h"
using namespace cocos2d;

class UI : public Node
{
public:

	virtual bool init();
	CREATE_FUNC(UI);

	bool  onTouchBegan(Touch * touch, Event * event);  //�ص���Ӧ����
	void  onTouchMoved(Touch * touch, Event * event);  //����ƶ�
	void  onTouchEnded(Touch * touch, Event * event);  //�ص���Ӧ��̧��


	Sprite * Head_spr1;	//����UIͷ��
	Sprite * Head_spr2;
	Sprite * Head_spr3;
	Sprite * Head_spr4;

	Sprite * Map_green; //��ͼ��ɫѡ��

	Sprite * Soldiers_spr1;	//��ɫ�϶�ʱ�ľ���
	Soldiers_enum  Head;	//ͷ��ö��
	Size visibleSize;
	Vec2 origin;

};
#endif