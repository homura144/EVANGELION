#pragma once
#include "SOFT_BARRIER.h"
class TRAP : public SOFT_BARRIER {
public:
	TRAP(int n);
	void die()const;
};