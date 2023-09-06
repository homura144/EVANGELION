#pragma once
#include"GLOBAL_FUNCTION.h"
#include"BARRIERS.h"
#include"IMAGES.h"
#include"GUN.h"
#include"KNIFE.h"
#include"MACHINEGUN.h"
#include"MINE.h"
#include"SPEAR.h"
#include"CANNON.h"
#include"SHIELD.h"
extern BARRIERS* barriers;
extern IMAGES* images;
class ROLE {
protected:
	int x, y;//位置，x-横坐标、y-纵坐标
	int HP_max;//生命值上限
	int HP;//生命值
	int speed, firerate;//行走速度,攻击速度，即每次行走（攻击）间隔多长时间
	DIRECTION direction;//方向
	int length;//边长
	IMAGE* image[4];//分别处于四个方向的角色图像
	int code;//代码
	DWORD t_walk, t_attack;//上一次行走的时间，上一次攻击的时间
public:
	ROLE(int length, int HP_max, int speed, int firerate, IMAGE* i1, IMAGE* i2, IMAGE* i3, IMAGE* i4, int code);
	void build(int _x, int _y, DIRECTION _direction);//创建角色，_x，_y-初始坐标_direction-初始方向
	bool attacktime();//是否可以攻击,1-可以，0-不可以
	bool walktime();//是否可以行走，1-可以，0-不可以
	bool move(DIRECTION direction);//按方向移动1像素,direction-方向，1-移动成功，2-移动失败
	void draw()const;//绘制角色
	virtual void attacked(int h) = 0;//受攻击，h-伤害
};