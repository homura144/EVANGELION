#pragma once
#include"ROLE.h"
class HERO :public ROLE {
protected:
	//玩家的道具
	GUN gun;
	KNIFE knife;
	MACHINEGUN machinegun;
	MINE mine;
	SPEAR spear;
	CANNON cannon;
	SHIELD shield;
	PROP* prop[7];//道具的指针的数组
	int prop_i;//prop[7]的下标，表示当前道具在数组第几个
	int gold;//金币数量
	bool crazy;//是否处于“暴走”
	DWORD t_crazy;//进入“暴走”的时间
public:
	HERO(int HP, int speed, int firerate, IMAGE* i1, IMAGE* i2, IMAGE* i3, IMAGE* i4);
	int getx()const;//返回x
	int gety()const;//返回y
	int getlength() const;//返回length
	bool live()const;//返回是否活着，1-活着，0-已死亡
	void build(int _x, int _y, DIRECTION _direction);
	void walk(DIRECTION _direction);//按方向行走, _direction-方向
	void attack(DIRECTION _direction);//按方向攻击, _direction-方向
	void selectPROP(int x);//选择第x个道具
	void switchPROP();//按顺序切换道具
	void reswitchPROP();//按反顺序切换道具
	void buyprop(int n);//购买道具，n-道具的prop_s代码
	void attacked(int h);
	void detect(int x1, int y1, int x2, int y2, bool move);//检测矩形区域内是否有特殊物体，并进行对应操作，x1,y1-矩形左上角坐标，x2,y2-矩形右下角坐标，move-检测前的移动是否成功
	virtual void getgold(int n);//获得金币,n-金币数
	void becrazy();//进入"暴走"
	void detectcrazy();//检测是否关闭"暴走"
	void instrumentality();//使用"补完"
	void draw()const;
	void show() const;//展示信息
};