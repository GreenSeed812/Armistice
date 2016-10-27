#include"bullet.h"

bool bullet::init()
{
	if (!Node::init())
	{
		return false;
	}



	return true;
}
void bullet::getBullet(Soldiers_operation  m_operation, Soldiers_enum m_Soldiers,int x,int y,int enemyX)	//创建子弹
{
	if (m_operation == PLAYER)	//玩家
	{
		if (m_Soldiers == Soldiers_infantry)	//步兵	   //不同士兵设置不同子弹
		{
			damage = 10;	//设置攻击力
			spr_bullets = Sprite::create("bullet.png");
			spr_bullets->setPosition(x, y);
			auto Mt = MoveTo::create(5.0f, Vec2(x + 3000, y));
			auto callBack = CallFunc::create([this]()->void{

				//spr_bullets->removeFromParent();
			});

			spr_bullets->runAction(Sequence::create(Mt, callBack, nullptr));  //绘制精灵动作

			this->addChild(spr_bullets);
		}
		if (m_Soldiers == Soldiers_artillery)	//炮兵
		{
			damage = 30;	//设置攻击力
			spr_bullets = Sprite::create("shells.png");
			spr_bullets->setPosition(x, y);
			auto Mt = JumpTo::create(1.7f, Vec2(enemyX * 40, y), 150, 1);
			auto callBack = CallFunc::create([this]()->void{

				//spr_bullets->removeFromParent();
			});

			spr_bullets->runAction(Sequence::create(Mt, callBack, nullptr));  //绘制精灵动作

			this->addChild(spr_bullets);

		}
	}
	if (m_operation == CPU)	//电脑
	{
		if (m_Soldiers == Soldiers_infantry)	//不同士兵设置不同子弹
		{
			damage = 20;	//设置攻击力
			spr_bullets = Sprite::create("bullet2.png");
			spr_bullets->setPosition(x, y);
			auto Mt = MoveTo::create(5.0f, Vec2(x - 3000, y));
			auto callBack = CallFunc::create([this]()->void{

				//spr_bullets->removeFromParent();
			});

			spr_bullets->runAction(Sequence::create(Mt, callBack, nullptr));  //绘制精灵动作

			this->addChild(spr_bullets);
		}
		if (m_Soldiers == Soldiers_artillery)	//炮兵
		{
			damage = 30;	//设置攻击力
			spr_bullets = Sprite::create("shells.png");
			spr_bullets->setPosition(x, y);
			auto Mt = JumpTo::create(1.7f, Vec2(enemyX * 40, y), 150, 1);
			auto callBack = CallFunc::create([this]()->void{

				//spr_bullets->removeFromParent();
			});

			spr_bullets->runAction(Sequence::create(Mt, callBack, nullptr));  //绘制精灵动作

			this->addChild(spr_bullets);

		}

	}
}