#include"bullet.h"

bool bullet::init()
{
	if (!Node::init())
	{
		return false;
	}



	return true;
}
void bullet::getBullet(Soldiers_operation  m_operation, Soldiers_enum m_Soldiers,int x,int y,int enemyX)	//�����ӵ�
{
	if (m_operation == PLAYER)	//���
	{
		if (m_Soldiers == Soldiers_infantry)	//����	   //��ͬʿ�����ò�ͬ�ӵ�
		{
			damage = 10;	//���ù�����
			spr_bullets = Sprite::create("bullet.png");
			spr_bullets->setPosition(x, y);
			auto Mt = MoveTo::create(5.0f, Vec2(x + 3000, y));
			auto callBack = CallFunc::create([this]()->void{

				//spr_bullets->removeFromParent();
			});

			spr_bullets->runAction(Sequence::create(Mt, callBack, nullptr));  //���ƾ��鶯��

			this->addChild(spr_bullets);
		}
		if (m_Soldiers == Soldiers_artillery)	//�ڱ�
		{
			damage = 30;	//���ù�����
			spr_bullets = Sprite::create("shells.png");
			spr_bullets->setPosition(x, y);
			auto Mt = JumpTo::create(1.7f, Vec2(enemyX * 40, y), 150, 1);
			auto callBack = CallFunc::create([this]()->void{

				//spr_bullets->removeFromParent();
			});

			spr_bullets->runAction(Sequence::create(Mt, callBack, nullptr));  //���ƾ��鶯��

			this->addChild(spr_bullets);

		}
	}
	if (m_operation == CPU)	//����
	{
		if (m_Soldiers == Soldiers_infantry)	//��ͬʿ�����ò�ͬ�ӵ�
		{
			damage = 20;	//���ù�����
			spr_bullets = Sprite::create("bullet2.png");
			spr_bullets->setPosition(x, y);
			auto Mt = MoveTo::create(5.0f, Vec2(x - 3000, y));
			auto callBack = CallFunc::create([this]()->void{

				//spr_bullets->removeFromParent();
			});

			spr_bullets->runAction(Sequence::create(Mt, callBack, nullptr));  //���ƾ��鶯��

			this->addChild(spr_bullets);
		}
		if (m_Soldiers == Soldiers_artillery)	//�ڱ�
		{
			damage = 30;	//���ù�����
			spr_bullets = Sprite::create("shells.png");
			spr_bullets->setPosition(x, y);
			auto Mt = JumpTo::create(1.7f, Vec2(enemyX * 40, y), 150, 1);
			auto callBack = CallFunc::create([this]()->void{

				//spr_bullets->removeFromParent();
			});

			spr_bullets->runAction(Sequence::create(Mt, callBack, nullptr));  //���ƾ��鶯��

			this->addChild(spr_bullets);

		}

	}
}