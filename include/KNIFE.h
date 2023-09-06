#pragma once
#include"PROP.h"
class KNIFE :public PROP {
private:
	int ATK;//攻击力
public:
	KNIFE(int ATK, int length, CAMP camp);
	void use(int x, int y, DIRECTION direction);
	void changeatk(double n);//修改小刀的ATK为原来的n倍
};