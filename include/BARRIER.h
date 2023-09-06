#pragma once
#include"GLOBAL_FUNCTION.h"
#include"IMAGES.h"
extern IMAGES*images;
class BARRIER {
protected:
	int x, y;//位置坐标
	int length;//边长
	IMAGE* image;//图像
	int code;//在地图上的代码
	bool life;//是否已被创建
public:
	BARRIER(int length, int code, IMAGE* image);
	void build(int x, int y);//创建障碍物，x，y-初始坐标
	void draw()const;//绘制
};