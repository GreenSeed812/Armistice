#include"soldiers.h"

bool soldiers::init()
{
	if (!Node::init())
	{
		return false;
	}
	soldiers_Spr = nullptr;
	HP = 100;	//初始化血量
	Bullet = false;
	
	AI = soldiersAI::create();
	this->addChild(AI);

	
	this->scheduleUpdate(); //重写update
	return true;
}
void soldiers::update(float time)
{
	

	if (soldiers_Spr && AI->state != End)
	{
		sprX = soldiers_Spr->getPosition().x;
		sprY = soldiers_Spr->getPosition().y;
		attack();	//判断是否攻击
		death();	//判断死亡
	}
	else if (AI->state == End)
	{
		this->unscheduleAllSelectors();	//停止所有调度器
		soldiers_Spr->removeFromParent();
	}

}
void soldiers::attack()	//攻击判断
{
	if (m_operation == PLAYER)
	{

		if (AI->state == Right && AI->getMAP_state(sprX + 400, sprY, sprX, sprY) == 2)  //返回当前坐标地图块状态
		{
			Bullet = true;
		}
		else 
		{
			Bullet = false;
			soldiers_walking();	//行走逻辑
		}

	}

	if (m_operation == CPU)
	{

		if (AI->state == Left && AI->getMAP_state(sprX - 400, sprY, sprX, sprY) == 1)  //返回当前坐标地图块状态
		{
			Bullet = true;
		}
		else
		{
			Bullet = false;
			soldiers_walking();	//行走逻辑
		}

	}
}
void soldiers::bullets(float time)	//发射子弹
{
	if (Bullet)
	{
		bullet * m_bullet = bullet::create();
		m_bullet->getBullet(m_operation, m_Soldiers, sprX, sprY,AI->enemy_X);
		this->addChild(m_bullet);

		if (m_operation == PLAYER)
		{
			if (sprY <= 80)
			{
				m_data->Cpu_bullet1.pushBack(m_bullet);
			}
			else if (sprY <= 160)
			{
				m_data->Cpu_bullet2.pushBack(m_bullet);
			}
			else if (sprY <= 240)
			{
				m_data->Cpu_bullet3.pushBack(m_bullet);
			}
			else if (sprY <= 320)
			{
				m_data->Cpu_bullet4.pushBack(m_bullet);
			}
			else if (sprY <= 400)
			{
				m_data->Cpu_bullet5.pushBack(m_bullet);
			}
			else if (sprY <= 480)
			{
				m_data->Cpu_bullet6.pushBack(m_bullet);
			}
		}

		if (m_operation == CPU)
		{
			if (sprY <= 80)
			{
				m_data->Player_bullet1.pushBack(m_bullet);
			}
			else if (sprY <= 160)
			{
				m_data->Player_bullet2.pushBack(m_bullet);
			}
			else if (sprY <= 240)
			{
				m_data->Player_bullet3.pushBack(m_bullet);
			}
			else if (sprY <= 320)
			{
				m_data->Player_bullet4.pushBack(m_bullet);
			}
			else if (sprY <= 400)
			{
				m_data->Player_bullet5.pushBack(m_bullet);
			}
			else if (sprY <= 480)
			{
				m_data->Player_bullet6.pushBack(m_bullet);
			}
		}
	}
}
void soldiers::death()	//死亡逻辑
{
	/////////////////////////

	if (m_operation == PLAYER)	//玩家死亡判断
	{
		if (sprY <= 80)
		{
			int i = 0;
			for (auto data : m_data->Player_bullet1)
			{
				auto Pin = data->spr_bullets->getPosition();
				auto Rect = soldiers_Spr->getBoundingBox();

				if (Rect.containsPoint(Pin))
				{
					HP -= data->damage; //士兵血量减去子弹攻击力

					m_data->Player_bullet1.erase(i);
					data-> removeFromParent();
					
					break;
				}
				i++;
			}
		}
		else if (sprY <= 160)
		{
			int i = 0;
			for (auto data : m_data->Player_bullet2)
			{
				auto Pin = data->spr_bullets->getPosition();
				auto Rect = soldiers_Spr->getBoundingBox();
				if (Rect.containsPoint(Pin))
				{
					HP -= data->damage; //士兵血量减去子弹攻击力

					m_data->Player_bullet2.erase(i);
					data->removeFromParent();
			
					break;
				}
				i++;
			}
		}
		else if (sprY <= 240)
		{
			int i = 0;
			for (auto data : m_data->Player_bullet3)
			{
				auto Pin = data->spr_bullets->getPosition();
				auto Rect = soldiers_Spr->getBoundingBox();
				if (Rect.containsPoint(Pin))
				{
					HP -= data->damage; //士兵血量减去子弹攻击力

					m_data->Player_bullet3.erase(i);
					data->removeFromParent();
		
					break;
				}
				i++;
			}
		}
		else if (sprY <= 320)
		{
			int i = 0;
			for (auto data : m_data->Player_bullet4)
			{
				auto Pin = data->spr_bullets->getPosition();
				auto Rect = soldiers_Spr->getBoundingBox();
				if (Rect.containsPoint(Pin))
				{
					HP -= data->damage; //士兵血量减去子弹攻击力

					m_data->Player_bullet4.erase(i);
					data->removeFromParent();
			
					break;
				}
				i++;
			}
		}
		else if (sprY <= 400)
		{
			int i = 0;
			for (auto data : m_data->Player_bullet5)
			{
				auto Pin = data->spr_bullets->getPosition();
				auto Rect = soldiers_Spr->getBoundingBox();
				if (Rect.containsPoint(Pin))
				{
					HP -= data->damage; //士兵血量减去子弹攻击力

					m_data->Player_bullet5.erase(i);
					data->removeFromParent();
			
					break;
				}
				i++;
			}
		}
		else if (sprY <= 480)
		{
			int i = 0;
			for (auto data : m_data->Player_bullet6)
			{
				auto Pin = data->spr_bullets->getPosition();
				auto Rect = soldiers_Spr->getBoundingBox();
				if (Rect.containsPoint(Pin))
				{
					HP -= data->damage; //士兵血量减去子弹攻击力

					m_data->Player_bullet6.erase(i);
					data->removeFromParent();
				
					break;
				}
				i++;
			}
		}
		
	}

	/////////////////////////////////////////////////////////

	if (m_operation == CPU)	//电脑死亡判断
	{
		if (sprY <= 80)
		{
			int i = 0;
			for (auto data : m_data->Cpu_bullet1)
			{
				auto Pin = data->spr_bullets->getPosition();
				auto Rect = soldiers_Spr->getBoundingBox();

				/*if (Pin.x <= 1000)
				{
					m_data->Cpu_bullet1.erase(i);
					data->removeFromParent();
					break;
				}*/
				if (Rect.containsPoint(Pin))
				{
					HP -= data->damage; //士兵血量减去子弹攻击力
					
					m_data->Cpu_bullet1.erase(i);
					data->removeFromParent();
			
					break;
					
				}
				i++;
			}
		}
		else if (sprY <= 160)
		{
			int i = 0;
			for (auto data : m_data->Cpu_bullet2)
			{
				auto Pin = data->spr_bullets->getPosition();
				auto Rect = soldiers_Spr->getBoundingBox();
				if (Rect.containsPoint(Pin))
				{
					HP -= data->damage; //士兵血量减去子弹攻击力

					m_data->Cpu_bullet2.erase(i);
					data->removeFromParent();
			
					break;

				}
				i++;
			}
		}
		else if (sprY <= 240)
		{
			int i = 0;
			for (auto data : m_data->Cpu_bullet3)
			{
				auto Pin = data->spr_bullets->getPosition();
				auto Rect = soldiers_Spr->getBoundingBox();
				if (Rect.containsPoint(Pin))
				{
					HP -= data->damage; //士兵血量减去子弹攻击力

					m_data->Cpu_bullet3.erase(i);
					data->removeFromParent();
				
					break;

				}
				i++;
			}
		}
		else if (sprY <= 320)
		{
			int i = 0;
			for (auto data : m_data->Cpu_bullet4)
			{
				auto Pin = data->spr_bullets->getPosition();
				auto Rect = soldiers_Spr->getBoundingBox();
				if (Rect.containsPoint(Pin))
				{
					HP -= data->damage; //士兵血量减去子弹攻击力

					m_data->Cpu_bullet4.erase(i);
					data->removeFromParent();
			
					break;

				}
				i++;
			}
		}
		else if (sprY <= 400)
		{
			int i = 0;
			for (auto data : m_data->Cpu_bullet5)
			{
				auto Pin = data->spr_bullets->getPosition();
				auto Rect = soldiers_Spr->getBoundingBox();
				if (Rect.containsPoint(Pin))
				{
					HP -= data->damage; //士兵血量减去子弹攻击力

					m_data->Cpu_bullet5.erase(i);
					data->removeFromParent();
				
					break;

				}
				i++;
			}
		}
		else if (sprY <= 480)
		{
			int i = 0;
			for (auto data : m_data->Cpu_bullet6)
			{
				auto Pin = data->spr_bullets->getPosition();
				auto Rect = soldiers_Spr->getBoundingBox();
				if (Rect.containsPoint(Pin))
				{
					HP -= data->damage; //士兵血量减去子弹攻击力

					m_data->Cpu_bullet6.erase(i);
					data->removeFromParent();
				
					break;

				}
				i++;
			}
		}

	}


	if (HP <= 0)	//血量小于0角色死亡
	{
		soldiers_Spr->setColor(ccc3(255, 0, 0)); //设置敌人颜色为红色
		//soldiers_Spr = nullptr;
		AI->state = End;
	}
}
void soldiers::soldiers_walking()
{
	if (m_operation == PLAYER && !Bullet)
	{
		if (m_Soldiers == Soldiers_infantry)	//步兵
		{
			if (AI->state == Right)
			{
				soldiers_Spr->setPosition(sprX += 1, sprY);
			}
			else
			{
				soldiers_Spr->setPosition(sprX -= 1, sprY);
			}
		}
		if (m_Soldiers == Soldiers_artillery)	//炮兵
		{
			if (AI->state == Right)
			{
				soldiers_Spr->setPosition(sprX += 1, sprY);
			}
			else
			{
				soldiers_Spr->setPosition(sprX -= 1, sprY);
			}
		}
	}
	if (m_operation == CPU && !Bullet)
	{
		if (m_Soldiers == Soldiers_infantry)	//步兵
		{
			if (AI->state == Left)
			{
				soldiers_Spr->setPosition(sprX, sprY);
			}
			else
			{
				soldiers_Spr->setPosition(sprX += 1, sprY);
			}
		}
		if (m_Soldiers == Soldiers_artillery)	//炮兵
		{
			if (AI->state == Left)
			{
				soldiers_Spr->setPosition(sprX, sprY);
			}
			else
			{
				soldiers_Spr->setPosition(sprX -= 1, sprY);
			}
		}
	}

}
void soldiers::setSoldiers(CreateMap * Map,GameData * data, Soldiers_operation operation, Soldiers_enum  Soldiers, float x, float y) //设置初始化主角的位置
{
	m_operation = operation;	//操作类型
	m_Soldiers = Soldiers;	//士兵种类
	if (m_operation == PLAYER)
	{
		AI->state = Right;
		if (Soldiers == Soldiers_infantry)	//不同敌人类型设置敌人和子弹调度器
		{
			soldiers_Spr = Sprite::create("soldiers.png");
			soldiers_Spr->setPosition(x, y);
			this->addChild(soldiers_Spr); //绘制精灵

			schedule(CC_SCHEDULE_SELECTOR(soldiers::bullets), 1);	//调度器发射子弹

		}
		if (Soldiers == Soldiers_artillery)
		{
			soldiers_Spr = Sprite::create("artillery.png");
			soldiers_Spr->setPosition(x, y);
			this->addChild(soldiers_Spr); //绘制精灵

			schedule(CC_SCHEDULE_SELECTOR(soldiers::bullets), 1);	//调度器发射子弹

		}
	}
	if (m_operation == CPU)
	{
		AI->state = Left;
		if (Soldiers == Soldiers_infantry)	//不同敌人类型设置敌人和子弹调度器
		{
			soldiers_Spr = Sprite::create("soldiers.png");
			soldiers_Spr->setFlipX(true);
			soldiers_Spr->setPosition(x, y);
			this->addChild(soldiers_Spr); //绘制精灵

			schedule(CC_SCHEDULE_SELECTOR(soldiers::bullets), 1);	//调度器发射子弹

		}
		if (Soldiers == Soldiers_artillery)
		{
			soldiers_Spr = Sprite::create("artillery.png");
			soldiers_Spr->setFlipX(true);
			soldiers_Spr->setPosition(x, y);
			this->addChild(soldiers_Spr); //绘制精灵

			schedule(CC_SCHEDULE_SELECTOR(soldiers::bullets), 1);	//调度器发射子弹

		}
	}

	m_data = data;	//获取数据指针
	m_Map = Map;	//获取地图指针
	AI->get_Map(Map);	//AI获取地图指针

	AI->get_Soldiers(operation, Soldiers);
}