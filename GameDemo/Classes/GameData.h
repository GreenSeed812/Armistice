#ifndef _Game_Data_
#define _Game_Data_
#include"cocos2d.h"
#include"bullet.h"
using namespace cocos2d;

class GameData : public Node
{
public:

	virtual bool init();
	CREATE_FUNC(GameData);

	Vector<bullet *> Player_bullet1;	//´æ´¢Íæ¼Ò×Óµ¯
	Vector<bullet *> Player_bullet2;	//´æ´¢Íæ¼Ò×Óµ¯
	Vector<bullet *> Player_bullet3;	//´æ´¢Íæ¼Ò×Óµ¯
	Vector<bullet *> Player_bullet4;	//´æ´¢Íæ¼Ò×Óµ¯
	Vector<bullet *> Player_bullet5;	//´æ´¢Íæ¼Ò×Óµ¯
	Vector<bullet *> Player_bullet6;	//´æ´¢Íæ¼Ò×Óµ¯



	Vector<bullet *> Cpu_bullet1;	//´æ´¢µÐÈË×Óµ¯
	Vector<bullet *> Cpu_bullet2;	//´æ´¢µÐÈË×Óµ¯
	Vector<bullet *> Cpu_bullet3;	//´æ´¢µÐÈË×Óµ¯
	Vector<bullet *> Cpu_bullet4;	//´æ´¢µÐÈË×Óµ¯
	Vector<bullet *> Cpu_bullet5;	//´æ´¢µÐÈË×Óµ¯
	Vector<bullet *> Cpu_bullet6;	//´æ´¢µÐÈË×Óµ¯

};
#endif