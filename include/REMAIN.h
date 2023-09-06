#pragma once
#include"ATTACK.h"
class REMAIN :public ATTACK {
private:
	DIRECTION direction;//方向
	COLORREF color;//颜色
public:
	REMAIN();
	bool build(int x, int y, int length, DIRECTION direction, CAMP camp, int vertical_length, int vertical_height, int ATK, COLORREF color);//创建,_color-静止攻击物颜色， 其它同ATTACK::build()
	void attack();
	void draw()const;
};