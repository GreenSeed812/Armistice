#ifndef _Game_enum_
#define _Game_enum_
#include"cocos2d.h"
using namespace cocos2d;					//公用枚举
enum Soldiers_operation  //判断操作类型
{
	CPU,
	PLAYER,

};
enum Soldiers_enum //士兵类型枚举
{
	Soldiers_infantry, //步兵
	Soldiers_artillery,//炮兵
	END,
};
enum Soldiers_state //士兵当前状态
{
	Right,	//向右
	Left,	//想左
	Standing,	//站立
	Bullet,	//射击
	End,	//死亡

};

#endif