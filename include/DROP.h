#pragma once
#include"BARRIER.h"
class DROP:public BARRIER{
public:
	DROP(IMAGE* image, int code);
	bool build(int x, int y);////创建一个掉落物，x,y-初始坐标，返回值：创建成功-1,失败-0
	void picked();//被拾取
};