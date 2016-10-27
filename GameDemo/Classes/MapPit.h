#ifndef _MapPit_
#define _MapPit_
#include"cocos2d.h"
#include"CreateMap.h"
#include"UI.h"
using namespace cocos2d;

class MapPit :public Node	//ս������
{
public:
	virtual bool init();
	CREATE_FUNC(MapPit);
	bool  onTouchBegan(Touch * touch, Event * event);  //�ص���Ӧ����
	void  onTouchMoved(Touch * touch, Event * event);  //����ƶ�
	void  onTouchEnded(Touch * touch, Event * event);  //�ص���Ӧ��̧��

	void getMap(CreateMap * Map){ m_Map = Map; };	//��ȡ��ͼָ��
	void getUi(UI * Ui){ m_Ui = Ui; };	//��ȡUI

	UI * m_Ui;	//UIָ��
	CreateMap * m_Map;	//��ͼָ��

};

#endif
