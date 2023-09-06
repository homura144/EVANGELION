#pragma once
#include"ENEMY.h"
class BOSS :public ENEMY {
public:
	BOSS(int HP, int speed, int firerate, IMAGE* i1, IMAGE* i2, IMAGE* i3, IMAGE* i4);
	void attackway();
	void die() const;
	virtual void draw()const;
	virtual void skill()=0;//×¨Êô¼¼ÄÜ
};