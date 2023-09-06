#include"ENEMYS.h"
ENEMYS::ENEMYS(int n) { 
	for (int i = 0; i < mob_n; i++) {
		average1[i] = new AVERAGE1(i);
		average2[i] = new AVERAGE2(i);
	}
	switch (n) {//根据关卡数选择BOSS
	case 0:
		boss = new SAKIEL;
		break;
	case 1:
		boss = new SHAMSHEL;
		break;
	case 2:
		boss = new RAMIEL;
		break;
	case 3:
		boss = new GAGHIEL;
		break;
	}
}
ENEMYS::~ENEMYS() {
	for (int i = 0; i < mob_n; i++) {
		for (int j = 0; j < 2; j++)delete mob[j][i];
	}
	delete boss;
}
void ENEMYS::walk() {
	for (int i = 0; i < mob_n; i++) {
		for (int j = 0; j < 2; j++)mob[j][i]->walk();
	}
	boss->walk();
}
void ENEMYS::attack() {
	for (int i = 0; i < mob_n; i++) {
		for (int j = 0; j < 2; j++)mob[j][i]->attack();
	}
	boss->attack();
}
void ENEMYS::draw()const {
	for (int i = 0; i < mob_n; i++) {
		for (int j = 0; j < 2; j++)mob[j][i]->draw();
	}
	boss->draw();
}