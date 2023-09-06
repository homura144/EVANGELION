#pragma once
#include"ENEMY.h"
#include"PROP.h"
class MOB :public ENEMY {
private:
	PROP* prop;
public:
	MOB(int firerate, IMAGE* i1, IMAGE* i2, IMAGE* i3, IMAGE* i4, int code, PROP* prop);
	void die() const;
	void attackway();
};