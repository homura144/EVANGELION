#pragma once
#include"SOFT_BARRIER.h"
class STONE :public SOFT_BARRIER {
public:
	STONE(int n);
	void die()const;
};