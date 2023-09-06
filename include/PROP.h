#pragma once
#include"IMAGES.h"
#include"ATTACKS.h"
extern IMAGES* images;
extern ATTACKS* attacks;
class PROP {
protected:
	CAMP camp;//道具使用者所属阵营
	int length;//边长
	IMAGE* image;//图像
public:
	PROP(int lentgh, CAMP camp, IMAGE* image);
	virtual void show() const;//展示道具信息
	virtual void use(int x, int y, DIRECTION direction) = 0;//使用道具，x,y-使用的位置，direction-使用的方向
};