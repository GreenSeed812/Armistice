#include"OperationMap.h"

bool OperationMap::init()
{
	if (!Node::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	auto listener = EventListenerTouchAllAtOnce::create();	//多点触摸回调
	listener->onTouchesBegan = CC_CALLBACK_2(OperationMap::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(OperationMap::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(OperationMap::onTouchesEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	setGear();	//初始化齿轮
	return true;
}
void OperationMap::setGear()	//初始化齿轮
{
	Gear_spr = Sprite::create("gear.png");
	Gear_spr->setPosition(visibleSize.width,0);
	this->addChild(Gear_spr);

	Rect rec = { visibleSize.width / 9 , visibleSize.height / 9 , 900,480 }; //创建一个矩形用于地图移动

	Gear_rec = rec; //m_Map->getBoundingBox();	//获取齿轮矩形

}
void OperationMap::onTouchesBegan(const std::vector<Touch*> touches, Event * event)  //回调响应鼠按下
{
	int i = 0;
	for (auto item : touches)       //遍历容器中的各个成员
	{
		auto touch = item;

		if (Gear_rec.containsPoint(Vec2(touch->getLocation().x, touch->getLocation().y))) //检测是否点击到齿轮
		{
			i++;
			tc_x = touch->getLocation().x;	//将当前点击坐标记录
			tc_y = touch->getLocation().y;
			if (i == 2)
			{
				//return true;
			}
			
		}
	}
	//return false;
}
void OperationMap::onTouchesMoved(const std::vector<Touch*> touches, Event * event)  //鼠标移动
{
	int i = 0;
	for (auto item : touches)       //遍历容器中的各个成员
	{
		auto touch = item;
		if (Gear_rec.containsPoint(Vec2(touch->getLocation().x, touch->getLocation().y))) //检测是否点击到齿轮
		{
			i++;
		if (i == 2)	//如果触摸点为2你好
			{
				if (m_Map->getPosition().x > -80 && touch->getLocation().x > tc_x)
					{
						distance = touch->getLocation().x - tc_x;	//计算出坐标移动距离
						m_Map->setPosition(m_Map->getPosition().x + 0.2, 0);	//设置地图当前移动坐标
						tc_x = touch->getLocation().x;	//将当前鼠标坐标记录
						tc_y = touch->getLocation().y;
						Gear_spr->setRotation(touch->getLocation().x);	//设置齿轮旋转角度
					}
				else if (m_Map->getPosition().x + 2320 < visibleSize.width && touch->getLocation().x < tc_x)
					{
						distance = touch->getLocation().x - tc_x;	//计算出坐标移动距离
						m_Map->setPosition(m_Map->getPosition().x - 0.2, 0);	//设置地图当前移动坐标
						tc_x = touch->getLocation().x;	//将当前鼠标坐标记录
						tc_y = touch->getLocation().y;
						Gear_spr->setRotation(touch->getLocation().x);	//设置齿轮旋转角度
					}
				else
					{
						distance = touch->getLocation().x - tc_x;	//计算出坐标移动距离
						m_Map->setPosition(m_Map->getPosition().x + distance, 0);	//设置地图当前移动坐标
						tc_x = touch->getLocation().x;	//将当前鼠标坐标记录
						tc_y = touch->getLocation().y;
						Gear_spr->setRotation(touch->getLocation().x);	//设置齿轮旋转角度
					}
			}
		}
	}
}
void OperationMap::onTouchesEnded(const std::vector<Touch*> touches, Event * event)  //回调响应鼠标抬起
{
	if (m_Map->getPosition().x > -80)
	{
		//m_Map->setPosition(-80, 0);	//设置地图当前移动坐标
	}
	else if (m_Map->getPosition().x + 2320 < visibleSize.width)
	{
		m_Map->setPosition(-2320 + visibleSize.width, 0);	//设置地图当前移动坐标
	}
}