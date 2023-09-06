#pragma once
#include"ATTACK.h"
class BOMB :public ATTACK {
private:
	IMAGE* image;//Í¼Ïñ
public:
	BOMB();
	bool build(int _x, int _y, int _length, DIRECTION _direction, CAMP _camp, int _ATK);//´´½¨,Í¬ATTACK::build()
	void attack();
	void draw() const;
};