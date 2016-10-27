#include"soldiersAI.h"

bool soldiersAI::init()
{
	if (!Node::init())
	{
		return false;
	}
	stateX = 0;
	stateY = 0;

	return true;
}
void soldiersAI::update(float time)
{
	setMAP_state();

}
void soldiersAI::get_Soldiers(Soldiers_operation  soldiers_operation, Soldiers_enum  soldiers)
{
	m_soldiers_operation = soldiers_operation;
	m_soldiers = soldiers;
	this->scheduleUpdate(); //重写update
}
void soldiersAI::setMAP_state()  //设置士兵是否踩到某个图块
{
	int map_tag = SoldiersX / 40;

	if (m_soldiers_operation == PLAYER)	//玩家
	{
		
		if (SoldiersY <= 80)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr1)
			{
				if (state == Right)
				{
					if (i == map_tag - 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(1);
						break;
					}
				}
				if (state == Left)
				{
					if (i == map_tag + 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(1);
						break;
					}
				}
				if (state == End)
				{
					if (i == map_tag)
					{
						spr->setTag(0);
					}
				}

				i++;
			}
		}
		else if (SoldiersY <= 160)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr2)
			{
				if (state == Right)
				{
					if (i == map_tag - 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(1);
						break;
					}
				}
				if (state == Left)
				{
					if (i == map_tag + 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(1);
						break;
					}
				}
				if (state == End)
				{
					if (i == map_tag)
					{
						spr->setTag(0);
					}
				}
				i++;
			}
		}
		else if (SoldiersY <= 240)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr3)
			{
				if (state == Right)
				{
					if (i == map_tag - 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(1);
						break;
					}
				}
				if (state == Left)
				{
					if (i == map_tag + 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(1);
						break;
					}
				}
				if (state == End)
				{
					if (i == map_tag)
					{
						spr->setTag(0);
					}
				}

				i++;
			}
		}
		else if (SoldiersY <= 320)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr4)
			{
				if (state == Right)
				{
					if (i == map_tag - 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(1);
						break;
					}
				}
				if (state == Left)
				{
					if (i == map_tag + 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(1);
						break;
					}
				}
				if (state == End)
				{
					if (i == map_tag)
					{
						spr->setTag(0);
					}
				}

				i++;
			}
		}
		else if (SoldiersY <= 400)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr5)
			{
				if (state == Right)
				{
					if (i == map_tag - 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(1);
						break;
					}
				}
				if (state == Left)
				{
					if (i == map_tag + 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(1);
						break;
					}
				}
				if (state == End)
				{
					if (i == map_tag)
					{
						spr->setTag(0);
					}
				}

				i++;
			}
		}
		else if (SoldiersY <= 480)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr6)
			{
				if (state == Right)
				{
					if (i == map_tag - 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(1);
						break;
					}
				}
				if (state == Left)
				{
					if (i == map_tag + 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(1);
						break;
					}
				}
				if (state == End)
				{
					if (i == map_tag)
					{
						spr->setTag(0);
					}
				}

				i++;
			}
		}

	}

	//////////////////////////////////////////////////////

	if (m_soldiers_operation == CPU)
	{
		
		if (SoldiersY <= 80)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr1)
			{
				if (state == Right)
				{
					if (i == map_tag - 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(2);
						break;
					}
				}
				if (state == Left)
				{
					if (i == map_tag + 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(2);
						break;
					}
				}
				if (state == End)
				{
					if (i == map_tag)
					{
						spr->setTag(0);
					}
				}


				i++;
			}
		}
		else if (SoldiersY <= 160)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr2)
			{
				if (state == Right)
				{
					if (i == map_tag - 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(2);
						break;
					}
				}
				if (state == Left)
				{
					if (i == map_tag + 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(2);
						break;
					}
				}
				if (state == End)
				{
					if (i == map_tag)
					{
						spr->setTag(0);
					}
				}


				i++;
			}
		}
		else if (SoldiersY <= 240)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr3)
			{
				if (state == Right)
				{
					if (i == map_tag - 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(2);
						break;
					}
				}
				if (state == Left)
				{
					if (i == map_tag + 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(2);
						break;
					}
				}
				if (state == End)
				{
					if (i == map_tag)
					{
						spr->setTag(0);
					}
				}

				i++;
			}
		}
		else if (SoldiersY <= 320)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr4)
			{
				if (state == Right)
				{
					if (i == map_tag - 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(2);
						break;
					}
				}
				if (state == Left)
				{
					if (i == map_tag + 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(2);
						break;
					}
				}
				if (state == End)
				{
					if (i == map_tag)
					{
						spr->setTag(0);
					}
				}

				i++;
			}
		}
		else if (SoldiersY <= 400)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr5)
			{
				if (state == Right)
				{
					if (i == map_tag - 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(2);
						break;
					}
				}
				if (state == Left)
				{
					if (i == map_tag + 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(2);
						break;
					}
				}
				if (state == End)
				{
					if (i == map_tag)
					{
						spr->setTag(0);
					}
				}

				i++;
			}
		}
		else if (SoldiersY <= 480)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr6)
			{
				if (state == Right)
				{
					if (i == map_tag - 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(2);
						break;
					}
				}
				if (state == Left)
				{
					if (i == map_tag + 1)
					{
						spr->setTag(0);
					}
					if (i == map_tag)
					{
						spr->setTag(2);
						break;
					}
				}
				if (state == End)
				{
					if (i == map_tag)
					{
						spr->setTag(0);
					}
				}

				i++;
			}
		}

	}


}

int soldiersAI::getMAP_state(int x, int y,int sprX,int sprY) //返回坐标地图块状态
{
	SoldiersX = sprX;	//士兵坐标
	SoldiersY = sprY;

	int mapX = x / 40;	//查找坐标

	if (m_soldiers_operation == PLAYER)
	{

		if (SoldiersY <= 80)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr1)
			{
				
				if (spr->getTag() == 2)	//1为玩家士兵踩的地图块 2为电脑
				{
					enemy_X = i;	//将当前有敌人的方块记录
					return spr->getTag();
				}

				if (i == mapX)
				{
					break;
				}
				i++;
			}
		}
		else if (SoldiersY <= 160)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr2)
			{

				if (spr->getTag() == 2)	//1为玩家士兵踩的地图块 2为电脑
				{
					enemy_X = i;	//将当前有敌人的方块记录
					return spr->getTag();
				}

				if (i == mapX)
				{
					break;
				}
				i++;
			}
		}
		else if (SoldiersY <= 240)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr3)
			{
				
				if (spr->getTag() == 2)	//1为玩家士兵踩的地图块 2为电脑
				{
					enemy_X = i;	//将当前有敌人的方块记录
					return spr->getTag();
				}

				if (i == mapX)
				{
					break;
				}
				i++;
			}
		}
		else if (SoldiersY <= 320)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr4)
			{
				if (spr->getTag() == 2)	//1为玩家士兵踩的地图块 2为电脑
				{
					enemy_X = i;	//将当前有敌人的方块记录
					return spr->getTag();
				}

				if (i == mapX)
				{
					break;
				}
				i++;
			}
		}
		else if (SoldiersY <= 400)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr5)
			{
				if (spr->getTag() == 2)	//1为玩家士兵踩的地图块 2为电脑
				{
					enemy_X = i;	//将当前有敌人的方块记录
					return spr->getTag();
				}

				if (i == mapX)
				{
					break;
				}
				i++;
			}
		}
		else if (SoldiersY <= 480)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr6)
			{
				if (spr->getTag() == 2)	//1为玩家士兵踩的地图块 2为电脑
				{
					enemy_X = i;	//将当前有敌人的方块记录
					return spr->getTag();
				}

				if (i == mapX)
				{
					break;
				}
				i++;
			}
		}
	}
	

	/////////////////////////////////

	if (m_soldiers_operation == CPU)
	{
		if (SoldiersY <= 80)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr1)
			{
				if (i == mapX)
				{
					if (spr->getTag() == 1)	//1为玩家士兵踩的地图块 2为电脑
					{
						enemy_X = i;	//将当前有敌人的方块记录
						return spr->getTag();
					}

				}
				i++;
			}
		}
		else if (SoldiersY <= 160)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr2)
			{
				if (i == mapX)
				{
					if (spr->getTag() == 1)	//1为玩家士兵踩的地图块 2为电脑
					{
						enemy_X = i;	//将当前有敌人的方块记录
						return spr->getTag();
					}

				}
				i++;
			}
		}
		else if (SoldiersY <= 240)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr3)
			{
				if (i == mapX)
				{
					if (spr->getTag() == 1)	//1为玩家士兵踩的地图块 2为电脑
					{
						enemy_X = i;	//将当前有敌人的方块记录
						return spr->getTag();
					}

				}
				i++;
			}
		}
		else if (SoldiersY <= 320)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr4)
			{
				if (i == mapX)
				{
					if (spr->getTag() == 1)	//1为玩家士兵踩的地图块 2为电脑
					{
						enemy_X = i;	//将当前有敌人的方块记录
						return spr->getTag();
					}

				}
				i++;
			}
		}
		else if (SoldiersY <= 400)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr5)
			{
				if (i == mapX)
				{
					if (spr->getTag() == 1)	//1为玩家士兵踩的地图块 2为电脑
					{
						enemy_X = i;	//将当前有敌人的方块记录
						return spr->getTag();
					}

				}
				i++;
			}
		}
		else if (SoldiersY <= 480)
		{
			int i = 0;
			for (auto spr : m_Map->Map_spr6)
			{
				if (i == mapX)
				{
					if (spr->getTag() == 1)	//1为玩家士兵踩的地图块 2为电脑
					{
						enemy_X = i;	//将当前有敌人的方块记录
						return spr->getTag();
					}

				}
				i++;
			}
		}
	}

	//return 0;
}