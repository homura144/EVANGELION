#pragma once
#include "BOSS.h"
class GAGHIEL : public BOSS {
private:
	KNIFE knife;
public:
	GAGHIEL();
	void skill();
	void walk();
};