#pragma once
#include "BARRIER.h"
class DOOR :public BARRIER {
protected:
	DWORD t;//被创建的时间
public:
	DOOR(int length, int code, IMAGE* image);
	void build(int _x, int _y);
	bool create(int n);//生成敌人，n-敌人的代码，返回值：成功生成-1，失败-0
	virtual void produce() = 0;//创建敌人
};

