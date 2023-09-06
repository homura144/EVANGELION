#pragma once
#include "BOSS.h"
class RAMIEL : public BOSS {
private:
	CANNON cannon;
	SHIELD shield;
	PROP* prop;//对当前道具的指针
public:
	RAMIEL();
	void skill();
	void draw()const;
	void reaction(int& h);
};