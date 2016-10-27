#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include"soldiers.h"
#include"UI.h"
#include"CreateMap.h"
#include"GameData.h"
#include"OperationMap.h"
#include"MapPit.h"
#include "cocos2d.h"
using namespace cocos2d;

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	bool  onTouchBegan(Touch * touch, Event * event);  //�ص���Ӧ����
	void  onTouchMoved(Touch * touch, Event * event);  //����ƶ�
	void  onTouchEnded(Touch * touch, Event * event);  //�ص���Ӧ��̧��

	void  setSoldiers(int x,int y);	//��������λ�ú�����

	Size visibleSize;
	Vec2 origin;

	GameData * m_data;
	CreateMap * m_Map;
	OperationMap * m_OperationMap;
	UI * Ui;
	MapPit * m_Pit;
	Camera * m_mainCamera;			// ϵͳĬ�����

};

#endif // __HELLOWORLD_SCENE_H__
