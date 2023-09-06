#pragma once
#include"ATTACK.h"
class BULLET:public ATTACK {
private:
	DIRECTION direction;//方向
	COLORREF color;//颜色
public:
	BULLET();
	bool build(int _x, int _y, int _length, DIRECTION _direction, CAMP _camp, int vertical_length, int vertical_height, int _ATK, COLORREF _color);//创建，_color-子弹颜色，其它同ATTACK::build()
	void attack();
	void draw() const;
};