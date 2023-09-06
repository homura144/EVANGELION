#pragma once
#include"PICKPROP.h"
class MACHINEGUN :public PICKPROP {
public:
	MACHINEGUN(int length, CAMP camp);
	void skill(int x, int y, DIRECTION direction) const;
};