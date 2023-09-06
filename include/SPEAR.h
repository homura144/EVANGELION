#pragma once
#include "PICKPROP.h"
class SPEAR : public PICKPROP {
public:
	SPEAR(int length, CAMP camp);
	void skill(int x, int y, DIRECTION direction) const;
};