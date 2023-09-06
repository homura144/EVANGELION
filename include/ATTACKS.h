#pragma once
#include"BOMB.h"
#include"BULLET.h"
#include"REMAIN.h"
struct ATTACKS {
	BOMB bomb[attack_n];
	BULLET bullet[attack_n];
	REMAIN remain[attack_n];
	void attack();//¹¥»÷
	void draw()const;//»æÖÆ
};