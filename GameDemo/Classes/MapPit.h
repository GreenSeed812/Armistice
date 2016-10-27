#ifndef _MapPit_
#define _MapPit_
#include"cocos2d.h"
#include"CreateMap.h"
#include"UI.h"
using namespace cocos2d;

class MapPit :public Node	//战壕开启
{
public:
	virtual bool init();
	CREATE_FUNC(MapPit);
	bool  onTouchBegan(Touch * touch, Event * event);  //回调响应鼠按下
	void  onTouchMoved(Touch * touch, Event * event);  //鼠标移动
	void  onTouchEnded(Touch * touch, Event * event);  //回调响应鼠抬起

	void getMap(CreateMap * Map){ m_Map = Map; };	//获取地图指针
	void getUi(UI * Ui){ m_Ui = Ui; };	//获取UI

	UI * m_Ui;	//UI指针
	CreateMap * m_Map;	//地图指针

};

#endif
