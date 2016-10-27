#include"MapPit.h"

bool MapPit::init()
{
	if (!Node::init())
	{
		return false;
	}

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(MapPit::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(MapPit::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(MapPit::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	return true;
}

bool MapPit::onTouchBegan(Touch * touch, Event * event)  //�ص���Ӧ����
{
	//if (m_Ui)
	{
		return true;
	}

}
void MapPit::onTouchMoved(Touch * touch, Event * event)  //�ص���Ӧ���ƶ�
{


}
void MapPit::onTouchEnded(Touch * touch, Event * event)  //�ص���Ӧ��̧��
{
	int x = touch->getLocation().x / 80;
	int y = (touch->getLocation().y + 40) / 80;
	int m = m_Map->m_map[y][x];
	CCLOG("%d",m );
}