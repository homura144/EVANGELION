#pragma once
#include "PICKPROP.h"
class CANNON : public PICKPROP {
private:
	int ray_length;//¼¤¹âµÄ¿í¶È
public:
	CANNON(int length, CAMP camp, int ray_length);
	void skill(int x, int y, DIRECTION direction) const;
};