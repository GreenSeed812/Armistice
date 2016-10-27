#include"CreateMap.h"

bool CreateMap::init()
{
	if (!Node::init())
	{
		return false;
	}


	return true;
}
void CreateMap::setMap(Map_type  type) //创建一个关卡地图
{
	if (type == mapType1)
	{
		int map[6][30] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };

		for (size_t i = 0; i < 6; i++)
		{
			for (size_t j = 0; j < 30; j++)
			{
				m_map[i][j] = map[i][j];
			}
		}
	}
	
	getMap(); //获取地图块组成地图
	 new int[6][30];
}
void CreateMap::getMap()  //获取地图块组成地图
{
	int x = 0;
	int y = 480;
	for (size_t i = 0; i < 6; i++)
	{
		for (size_t j = 0; j < 30; j++)
		{
			if (m_map[i][j] == 1)
			{
				
				Sprite * Map_green = Sprite::create("grass.png");
				Map_green->setPosition(x,y);
				this->addChild(Map_green);

				if (i == 5)
				{
					Map_spr1.pushBack(Map_green);
				}
				if (i == 4)
				{
					Map_spr2.pushBack(Map_green);
				}
				if (i == 3)
				{
					Map_spr3.pushBack(Map_green);
				}
				if (i == 2)
				{
					Map_spr4.pushBack(Map_green);
				}
				if (i == 1)
				{
					Map_spr5.pushBack(Map_green);
				}
				if (i == 0)
				{
					Map_spr6.pushBack(Map_green);
				}
			}

			x+=80;
		}
		y -= 80;
		x = 0;
	}
	
}