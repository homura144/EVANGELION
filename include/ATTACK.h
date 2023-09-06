#pragma once
#include<graphics.h>
#include"CONST.h"
extern bool harm(int x, int y, int x1, int y1, CAMP camp, int ATK);
class ATTACK {
protected:
	int x, y;//位置坐标
	int length, height;//length-水平方向长度,height-垂直方向高度
	int ATK;//攻击力
	bool life;//是否已被创建
	CAMP camp;//阵营
	DWORD t;//记录创建/上次移动的时间
public:
	ATTACK();
	bool build(int _x, int _y, int _length, DIRECTION _direction, CAMP _camp, int vertical_length, int vertical_height, int _ATK);//创建攻击物，_x,_y-初始坐标，_direction-方向，_length-使用者的边长，_camp-使用者阵营， vertical_length ，vertival_width-该攻击物以垂直方向创建时的长度和高度，_ATK-攻击力，返回值：创建成功-1，失败-0
	virtual void attack() = 0;//进行攻击
	virtual void draw()const = 0;//绘制图像
};

