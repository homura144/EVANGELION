#pragma once
#include"PROP.h"
class GUN :public PROP {
public:
	GUN(int length, CAMP camp);
	void use(int x, int y, DIRECTION direction);
};