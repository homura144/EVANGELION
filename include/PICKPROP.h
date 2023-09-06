#pragma once
#include"PROP.h"
class PICKPROP :public PROP {
protected:
	int num;//数量
public:
	PICKPROP(int length, CAMP camp,IMAGE*image);
	void use(int x, int y, DIRECTION direction);
	void innum(int n);//数量增长n个
	void show() const;//展示图像和数量
	virtual void skill(int x, int y, DIRECTION direction)const=0;//每个可拾取道具的特殊能力，x,y-使用者坐标，direction-使用的方向
};