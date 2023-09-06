#include "GAGHIEL.h"
#include"HERO.h"
extern HERO* hero;
GAGHIEL::GAGHIEL() :BOSS(100, 10, 1000, &images->gaghiel[UP], &images->gaghiel[DOWN], &images->gaghiel[LEFT], &images->gaghiel[RIGHT]), knife(5, length, CAMP::enemy) {}
void GAGHIEL::skill() {
	for (DIRECTION d = UP; d <= RIGHT; d = DIRECTION(d + 1))knife.use(x, y, d);//向四个方向使用knife
}
void GAGHIEL::walk() {
	if (walktime()) {
		if (rand() % 50 == 0) {//有1/50几率移动到玩家旁边，并且使敌人和玩家的对称轴重合
	//数组下标表示四个方向，每一组相同下标的tempx,tempy为BOSS在玩家的这个方向出现的坐标
			int tempx[4] = { hero->getx() + hero->getlength() / 2 - length / 2,hero->getx() + hero->getlength() / 2 - length / 2,hero->getx() - length,hero->getx() + hero->getlength() };
			int tempy[4] = { hero->gety() - length,hero->gety() + hero->getlength(),hero->gety() + hero->getlength() / 2 - length / 2,hero->gety() + hero->getlength() / 2 - length / 2 };
			for (int i = 0; i < 4; i++) {
				if (empty(tempx[i], tempy[i], length)) {//如果四个方向中有空区域，则将坐标改到空区域
					setmap(x, y, length, empty_s);//将原来位置设置为空
					x = tempx[i];
					y = tempy[i];
					setmap(x, y, length, code);
					break;
				}
			}
		}
		else track();
	}
}
