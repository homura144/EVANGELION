#include "CANNON.h"
CANNON::CANNON(int length, CAMP camp,int ray_length):PICKPROP(length, camp, &images->cannon),ray_length(ray_length) {}
void CANNON::skill(int x, int y, DIRECTION direction)const{
	for (int i = 0; i < attack_n; i++) {//生成1个静止伤害物
		if (attacks->remain[i].build(x, y, length, direction, camp, ray_length, LENGTH, 2, WHITE))break;
	}
}