#pragma once
#include"ROLE.h"
extern int score;
class ENEMY :public ROLE {
public:
	ENEMY(int length, int HP_max, int speed, int firerate, IMAGE* i1, IMAGE* i2, IMAGE* i3, IMAGE* i4, int code);
	bool build(int _x, int _y, DIRECTION _direction);//创建一个敌人，_x，_y-初始坐标，_direction-初始方向，创建成功-1，失败-0
	void track();//追踪玩家,朝玩家方向前进
	void detect(int x1, int y1, int x2, int y2) const;//检测矩形区域内是否有特殊物体，并进行对应操作，x1,y1-矩形左上角坐标，x2,y2-矩形右下角坐标
	void attack();//自动攻击
	void attacked(int h);
	virtual void walk();//行走
	virtual void reaction(int& h);//受攻击时的反应，h-伤害
	virtual void attackway() = 0;//攻击方法
	virtual void die()const = 0;//死亡奖励
};