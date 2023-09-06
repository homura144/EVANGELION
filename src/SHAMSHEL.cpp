#include "SHAMSHEL.h"
SHAMSHEL::SHAMSHEL() :BOSS(100, 15, 2000, &images->shamshel[UP], &images->shamshel[DOWN], &images->shamshel[LEFT], &images->shamshel[RIGHT]) {}
void SHAMSHEL::skill() {
	DIRECTION d[2] = { UP,DOWN };
	if (rand() % 2) {//随机向左右或者上下攻击
		d[0] = LEFT;
		d[1] = RIGHT;
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < attack_n; j++) {
			if (attacks->remain[j].build(x, y, length, d[i], CAMP::enemy, 8, 75, 5, RED))break;//两个方向各生成一个静止伤害物
		}
}
