#pragma once
#include"SAKIEL.h"
#include"SHAMSHEL.h"
#include"RAMIEL.h"
#include"GAGHIEL.h"
#include"AVERAGE1.h"
#include"AVERAGE2.h"
struct ENEMYS{
	BOSS* boss;
	MOB* average1[mob_n];
	MOB* average2[mob_n];
	MOB** mob[2] = { average1,average2 };
	ENEMYS(int n);
	~ENEMYS();
	void walk();//ÐÐ×ß
	void attack();//¹¥»÷
	void draw()const;//»æÖÆ
};