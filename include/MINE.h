#pragma once
#include "PICKPROP.h"
class MINE :public PICKPROP {
public:
	MINE(int length, CAMP camp);
	void skill(int x, int y, DIRECTION direction) const;
};