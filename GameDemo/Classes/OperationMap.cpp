#include"OperationMap.h"

bool OperationMap::init()
{
	if (!Node::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	auto listener = EventListenerTouchAllAtOnce::create();	//��㴥���ص�
	listener->onTouchesBegan = CC_CALLBACK_2(OperationMap::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(OperationMap::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(OperationMap::onTouchesEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	setGear();	//��ʼ������
	return true;
}
void OperationMap::setGear()	//��ʼ������
{
	Gear_spr = Sprite::create("gear.png");
	Gear_spr->setPosition(visibleSize.width,0);
	this->addChild(Gear_spr);

	Rect rec = { visibleSize.width / 9 , visibleSize.height / 9 , 900,480 }; //����һ���������ڵ�ͼ�ƶ�

	Gear_rec = rec; //m_Map->getBoundingBox();	//��ȡ���־���

}
void OperationMap::onTouchesBegan(const std::vector<Touch*> touches, Event * event)  //�ص���Ӧ����
{
	int i = 0;
	for (auto item : touches)       //���������еĸ�����Ա
	{
		auto touch = item;

		if (Gear_rec.containsPoint(Vec2(touch->getLocation().x, touch->getLocation().y))) //����Ƿ���������
		{
			i++;
			tc_x = touch->getLocation().x;	//����ǰ��������¼
			tc_y = touch->getLocation().y;
			if (i == 2)
			{
				//return true;
			}
			
		}
	}
	//return false;
}
void OperationMap::onTouchesMoved(const std::vector<Touch*> touches, Event * event)  //����ƶ�
{
	int i = 0;
	for (auto item : touches)       //���������еĸ�����Ա
	{
		auto touch = item;
		if (Gear_rec.containsPoint(Vec2(touch->getLocation().x, touch->getLocation().y))) //����Ƿ���������
		{
			i++;
		if (i == 2)	//���������Ϊ2���
			{
				if (m_Map->getPosition().x > -80 && touch->getLocation().x > tc_x)
					{
						distance = touch->getLocation().x - tc_x;	//����������ƶ�����
						m_Map->setPosition(m_Map->getPosition().x + 0.2, 0);	//���õ�ͼ��ǰ�ƶ�����
						tc_x = touch->getLocation().x;	//����ǰ��������¼
						tc_y = touch->getLocation().y;
						Gear_spr->setRotation(touch->getLocation().x);	//���ó�����ת�Ƕ�
					}
				else if (m_Map->getPosition().x + 2320 < visibleSize.width && touch->getLocation().x < tc_x)
					{
						distance = touch->getLocation().x - tc_x;	//����������ƶ�����
						m_Map->setPosition(m_Map->getPosition().x - 0.2, 0);	//���õ�ͼ��ǰ�ƶ�����
						tc_x = touch->getLocation().x;	//����ǰ��������¼
						tc_y = touch->getLocation().y;
						Gear_spr->setRotation(touch->getLocation().x);	//���ó�����ת�Ƕ�
					}
				else
					{
						distance = touch->getLocation().x - tc_x;	//����������ƶ�����
						m_Map->setPosition(m_Map->getPosition().x + distance, 0);	//���õ�ͼ��ǰ�ƶ�����
						tc_x = touch->getLocation().x;	//����ǰ��������¼
						tc_y = touch->getLocation().y;
						Gear_spr->setRotation(touch->getLocation().x);	//���ó�����ת�Ƕ�
					}
			}
		}
	}
}
void OperationMap::onTouchesEnded(const std::vector<Touch*> touches, Event * event)  //�ص���Ӧ���̧��
{
	if (m_Map->getPosition().x > -80)
	{
		//m_Map->setPosition(-80, 0);	//���õ�ͼ��ǰ�ƶ�����
	}
	else if (m_Map->getPosition().x + 2320 < visibleSize.width)
	{
		m_Map->setPosition(-2320 + visibleSize.width, 0);	//���õ�ͼ��ǰ�ƶ�����
	}
}