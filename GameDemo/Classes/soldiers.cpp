#include"soldiers.h"

bool soldiers::init()
{
	if (!Node::init())
	{
		return false;
	}
	soldiers_Spr = nullptr;
	HP = 100;	//��ʼ��Ѫ��
	Bullet = false;
	
	AI = soldiersAI::create();
	this->addChild(AI);

	
	this->scheduleUpdate(); //��дupdate
	return true;
}
void soldiers::update(float time)
{
	

	if (soldiers_Spr && AI->state != End)
	{
		sprX = soldiers_Spr->getPosition().x;
		sprY = soldiers_Spr->getPosition().y;
		attack();	//�ж��Ƿ񹥻�
		death();	//�ж�����
	}
	else if (AI->state == End)
	{
		this->unscheduleAllSelectors();	//ֹͣ���е�����
		soldiers_Spr->removeFromParent();
	}

}
void soldiers::attack()	//�����ж�
{
	if (m_operation == PLAYER)
	{

		if (AI->state == Right && AI->getMAP_state(sprX + 400, sprY, sprX, sprY) == 2)  //���ص�ǰ�����ͼ��״̬
		{
			Bullet = true;
		}
		else 
		{
			Bullet = false;
			soldiers_walking();	//�����߼�
		}

	}

	if (m_operation == CPU)
	{

		if (AI->state == Left && AI->getMAP_state(sprX - 400, sprY, sprX, sprY) == 1)  //���ص�ǰ�����ͼ��״̬
		{
			Bullet = true;
		}
		else
		{
			Bullet = false;
			soldiers_walking();	//�����߼�
		}

	}
}
void soldiers::bullets(float time)	//�����ӵ�
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
void soldiers::death()	//�����߼�
{
	/////////////////////////

	if (m_operation == PLAYER)	//��������ж�
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
					HP -= data->damage; //ʿ��Ѫ����ȥ�ӵ�������

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
					HP -= data->damage; //ʿ��Ѫ����ȥ�ӵ�������

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
					HP -= data->damage; //ʿ��Ѫ����ȥ�ӵ�������

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
					HP -= data->damage; //ʿ��Ѫ����ȥ�ӵ�������

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
					HP -= data->damage; //ʿ��Ѫ����ȥ�ӵ�������

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
					HP -= data->damage; //ʿ��Ѫ����ȥ�ӵ�������

					m_data->Player_bullet6.erase(i);
					data->removeFromParent();
				
					break;
				}
				i++;
			}
		}
		
	}

	/////////////////////////////////////////////////////////

	if (m_operation == CPU)	//���������ж�
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
					HP -= data->damage; //ʿ��Ѫ����ȥ�ӵ�������
					
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
					HP -= data->damage; //ʿ��Ѫ����ȥ�ӵ�������

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
					HP -= data->damage; //ʿ��Ѫ����ȥ�ӵ�������

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
					HP -= data->damage; //ʿ��Ѫ����ȥ�ӵ�������

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
					HP -= data->damage; //ʿ��Ѫ����ȥ�ӵ�������

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
					HP -= data->damage; //ʿ��Ѫ����ȥ�ӵ�������

					m_data->Cpu_bullet6.erase(i);
					data->removeFromParent();
				
					break;

				}
				i++;
			}
		}

	}


	if (HP <= 0)	//Ѫ��С��0��ɫ����
	{
		soldiers_Spr->setColor(ccc3(255, 0, 0)); //���õ�����ɫΪ��ɫ
		//soldiers_Spr = nullptr;
		AI->state = End;
	}
}
void soldiers::soldiers_walking()
{
	if (m_operation == PLAYER && !Bullet)
	{
		if (m_Soldiers == Soldiers_infantry)	//����
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
		if (m_Soldiers == Soldiers_artillery)	//�ڱ�
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
		if (m_Soldiers == Soldiers_infantry)	//����
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
		if (m_Soldiers == Soldiers_artillery)	//�ڱ�
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
void soldiers::setSoldiers(CreateMap * Map,GameData * data, Soldiers_operation operation, Soldiers_enum  Soldiers, float x, float y) //���ó�ʼ�����ǵ�λ��
{
	m_operation = operation;	//��������
	m_Soldiers = Soldiers;	//ʿ������
	if (m_operation == PLAYER)
	{
		AI->state = Right;
		if (Soldiers == Soldiers_infantry)	//��ͬ�����������õ��˺��ӵ�������
		{
			soldiers_Spr = Sprite::create("soldiers.png");
			soldiers_Spr->setPosition(x, y);
			this->addChild(soldiers_Spr); //���ƾ���

			schedule(CC_SCHEDULE_SELECTOR(soldiers::bullets), 1);	//�����������ӵ�

		}
		if (Soldiers == Soldiers_artillery)
		{
			soldiers_Spr = Sprite::create("artillery.png");
			soldiers_Spr->setPosition(x, y);
			this->addChild(soldiers_Spr); //���ƾ���

			schedule(CC_SCHEDULE_SELECTOR(soldiers::bullets), 1);	//�����������ӵ�

		}
	}
	if (m_operation == CPU)
	{
		AI->state = Left;
		if (Soldiers == Soldiers_infantry)	//��ͬ�����������õ��˺��ӵ�������
		{
			soldiers_Spr = Sprite::create("soldiers.png");
			soldiers_Spr->setFlipX(true);
			soldiers_Spr->setPosition(x, y);
			this->addChild(soldiers_Spr); //���ƾ���

			schedule(CC_SCHEDULE_SELECTOR(soldiers::bullets), 1);	//�����������ӵ�

		}
		if (Soldiers == Soldiers_artillery)
		{
			soldiers_Spr = Sprite::create("artillery.png");
			soldiers_Spr->setFlipX(true);
			soldiers_Spr->setPosition(x, y);
			this->addChild(soldiers_Spr); //���ƾ���

			schedule(CC_SCHEDULE_SELECTOR(soldiers::bullets), 1);	//�����������ӵ�

		}
	}

	m_data = data;	//��ȡ����ָ��
	m_Map = Map;	//��ȡ��ͼָ��
	AI->get_Map(Map);	//AI��ȡ��ͼָ��

	AI->get_Soldiers(operation, Soldiers);
}