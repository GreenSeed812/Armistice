#include"UI.h"

bool UI::init()
{
	if (!Node::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();


	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(UI::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(UI::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(UI::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	Map_green = Sprite::create("green.png");
	Map_green->setPosition(visibleSize.width / 2, 1000);
	this->addChild(Map_green);

	Head_spr1 = Sprite::create("soldiers.png");  //初始化UI图片
	Head_spr1->setPosition(100, 300);
	Head_spr1->setScale(1.2);
	this->addChild(Head_spr1);

	Head_spr2 = Sprite::create("artillery.png");  //初始化UI图片
	Head_spr2->setPosition(100, 350);
	Head_spr2->setScale(1.2);
	this->addChild(Head_spr2);

	return true;
}

bool UI::onTouchBegan(Touch * touch, Event * event)  //回调响应鼠按下
{
	Rect BOX_rect;

	BOX_rect = Head_spr1->getBoundingBox();
	if (BOX_rect.containsPoint(Vec2(touch->getLocation().x, touch->getLocation().y)))  //点击头像时生成的人物图片
	{
		Soldiers_spr1 = Sprite::create("soldiers.png");
		Soldiers_spr1->setPosition(visibleSize.width / 2, 1000);
		Soldiers_spr1->setScale(2);	//生成图片放大

		Head_spr1->setScale(2);	//ui图片放大
		this->addChild(Soldiers_spr1);
		Head = Soldiers_infantry;	//步兵
		return true;
	}

	BOX_rect = Head_spr2->getBoundingBox();
	if (BOX_rect.containsPoint(Vec2(touch->getLocation().x, touch->getLocation().y)))  //点击头像时生成的人物图片
	{
		Soldiers_spr1 = Sprite::create("artillery.png");
		Soldiers_spr1->setPosition(visibleSize.width / 2, 1000);
		Soldiers_spr1->setScale(2);	//

		Head_spr2->setScale(2);	//
		this->addChild(Soldiers_spr1);
		Head = Soldiers_artillery;	//步兵
		return true;
	}

	Head = END; //没有点击到UI时
	return false;
}
void UI::onTouchMoved(Touch * touch, Event * event)  //鼠标移动
{

	if (touch->getLocation().x > 150)
	{

		Soldiers_spr1->setPosition(touch->getLocation().x, touch->getLocation().y);

		if (touch->getLocation().y < visibleSize.height / 8 + 40)	//设置绿色选框的位置
		{
			Map_green->setPosition(visibleSize.width / 2, 80);
		}
		else if (touch->getLocation().y < visibleSize.height / 8 * 2 + 40)
		{
			Map_green->setPosition(visibleSize.width / 2, 160);
		}
		else if (touch->getLocation().y < visibleSize.height / 8 * 3 + 40)
		{
			Map_green->setPosition(visibleSize.width / 2, 240);
		}
		else if (touch->getLocation().y < visibleSize.height / 8 * 4 + 40)
		{
			Map_green->setPosition(visibleSize.width / 2, 320);
		}
		else if (touch->getLocation().y < visibleSize.height / 8 * 5 + 40)
		{
			Map_green->setPosition(visibleSize.width / 2, 400);
		}
		else if (touch->getLocation().y < visibleSize.height / 8 * 6 + 40)
		{
			Map_green->setPosition(visibleSize.width / 2, 480);
		}
	}
	else
	{
		Head_spr1->setPosition(100,Head_spr1->getPosition().y);

		Map_green->setPosition(visibleSize.width / 2, 1000);
		Soldiers_spr1->setPosition(visibleSize.width / 2, 1000);
	}

}
void UI::onTouchEnded(Touch * touch, Event * event)  //回调响应鼠抬起
{
	if (touch->getLocation().x < 150)
	{
		Head = END; //没有点击到UI时
	}
	Soldiers_spr1->removeFromParent();
	Map_green->setPosition(visibleSize.width / 2, 1000);
	Head_spr1->setScale(1.2);
	Head_spr2->setScale(1.2);
}
