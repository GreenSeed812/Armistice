#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	m_Map = CreateMap::create();
	m_Map->setMap(mapType1);
	this->addChild(m_Map);

	m_data = GameData::create();	//
	this->addChild(m_data);

	Ui = UI::create();	//初始化UI
	//Ui->setCameraMask((unsigned short)CameraFlag::USER1);
	//Ui->setGlobalZOrder(100);
	this->addChild(Ui);

	m_Pit = MapPit::create();
	m_Pit->getUi(Ui);
	m_Pit->getMap(m_Map);
	m_Map->addChild(m_Pit);

	m_OperationMap = OperationMap::create();	//初始化地图操作类
	m_OperationMap->getMap(m_Map);
	this->addChild(m_OperationMap);

	m_mainCamera = Camera::create();
	m_mainCamera->setCameraFlag(CameraFlag::USER1);
	m_mainCamera->setPosition(Ui->getPosition());
	this->addChild(m_mainCamera);

    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

	soldiers * m_soldiers1 = soldiers::create();
	m_soldiers1->setSoldiers(m_Map, m_data, CPU, Soldiers_infantry, 656, 80); //设置初始化主角的位置
	m_Map->addChild(m_soldiers1);
	soldiers * m_soldiers2 = soldiers::create();
	m_soldiers2->setSoldiers(m_Map, m_data, CPU, Soldiers_infantry, 700, 160); //设置初始化主角的位置
	m_Map->addChild(m_soldiers2);
	soldiers * m_soldiers3 = soldiers::create();
	m_soldiers3->setSoldiers(m_Map, m_data, CPU, Soldiers_infantry, 800, 240); //设置初始化主角的位置
	m_Map->addChild(m_soldiers3);
	soldiers * m_soldiers4 = soldiers::create();
	m_soldiers4->setSoldiers(m_Map, m_data, CPU, Soldiers_infantry, 500, 320); //设置初始化主角的位置

	soldiers * m_soldiers30 = soldiers::create();
	m_soldiers30->setSoldiers(m_Map, m_data, CPU, Soldiers_artillery, 500, 320); //设置初始化主角的位置
	m_Map->addChild(m_soldiers30);

	soldiers * m_soldiers5 = soldiers::create();
	m_soldiers5->setSoldiers(m_Map, m_data, CPU, Soldiers_infantry, 1000, 400); //设置初始化主角的位置
	m_Map->addChild(m_soldiers5);
	soldiers * m_soldiers6 = soldiers::create();
	m_soldiers6->setSoldiers(m_Map, m_data, CPU, Soldiers_infantry, 900, 480); //设置初始化主角的位置
	m_Map->addChild(m_soldiers6);
	/*
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    this->addChild(label, 1);
	*/
    return true;
}
bool HelloWorld::onTouchBegan(Touch * touch, Event * event)  //回调响应鼠按下
{
	if (Ui->Head != END) //检测是否点击到UI
	{
		return true;
	}
	return false;
}
void HelloWorld::onTouchMoved(Touch * touch, Event * event)  //鼠标移动
{
	

}
void HelloWorld::onTouchEnded(Touch * touch, Event * event)  //回调响应鼠标抬起
{
	setSoldiers(touch->getLocation().x, touch->getLocation().y);//创建敌人位置和种类
	
}
void  HelloWorld::setSoldiers(int x,int y)	//创建敌人位置和种类
{
	if (Ui->Head != END)
	{
		if (y < visibleSize.height / 8 + 40)
		{
			soldiers * m_soldiers = soldiers::create();
			m_soldiers->setSoldiers(m_Map, m_data, PLAYER, Ui->Head, 0, 80); //设置初始化主角的位置
			m_Map->addChild(m_soldiers);
		}
		else if (y < visibleSize.height / 8 * 2 + 40)
		{
			soldiers * m_soldiers = soldiers::create();
			m_soldiers->setSoldiers(m_Map, m_data, PLAYER, Ui->Head, 0, 160); //设置初始化主角的位置
			m_Map->addChild(m_soldiers);
		}
		else if (y < visibleSize.height / 8 * 3 + 40)
		{
			soldiers * m_soldiers = soldiers::create();
			m_soldiers->setSoldiers(m_Map, m_data, PLAYER, Ui->Head, 0, 240); //设置初始化主角的位置
			m_Map->addChild(m_soldiers);
		}
		else if (y < visibleSize.height / 8 * 4 + 40)
		{
			soldiers * m_soldiers = soldiers::create();
			m_soldiers->setSoldiers(m_Map, m_data, PLAYER, Ui->Head, 0, 320); //设置初始化主角的位置
			m_Map->addChild(m_soldiers);
		}
		else if (y < visibleSize.height / 8 * 5 + 40)
		{
			soldiers * m_soldiers = soldiers::create();
			m_soldiers->setSoldiers(m_Map, m_data, PLAYER, Ui->Head, 0, 400); //设置初始化主角的位置
			m_Map->addChild(m_soldiers);
		}
		else if (y < visibleSize.height / 8 * 6 + 40)
		{
			soldiers * m_soldiers = soldiers::create();
			m_soldiers->setSoldiers(m_Map, m_data, PLAYER, Ui->Head, 0, 480); //设置初始化主角的位置
			m_Map->addChild(m_soldiers);
		}
	}

}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
