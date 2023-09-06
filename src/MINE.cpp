#include "MINE.h"
MINE::MINE(int length, CAMP camp) :PICKPROP(length, camp, &images->mine) {}
void MINE::skill(int x, int y, DIRECTION direction)const {//Éú³É1¸öÕ¨µ¯
	for (int i = 0; i < attack_n; i++) {
		if (attacks->bomb[i].build(x, y, length, direction, camp,5))break;
	}
}