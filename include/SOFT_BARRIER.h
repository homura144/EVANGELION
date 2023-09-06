#pragma once
#include"BARRIER.h"
class SOFT_BARRIER :public BARRIER {
protected:
	int HP;//ÉúÃüÖµ
public:
	SOFT_BARRIER(int length, int code, IMAGE* i, int h);
	void attacked(int h);//ÊÜ¹¥»÷£¬h-ÉËº¦
	virtual void die()const = 0;//ËÀÍö½±Àø
};