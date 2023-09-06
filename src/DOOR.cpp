#include "DOOR.h"
#include"ENEMYS.h"
extern ENEMYS* enemys;
DOOR::DOOR(int length, int code, IMAGE* image) :BARRIER(length, code, image), t(0) {}
void DOOR::build(int _x, int _y) {
	BARRIER::build(_x, _y);
	t = GetTickCount();
}
bool DOOR::create(int n) {
	//数组下标表示四个方向，每一组相同下标的tempx,tempy为传送门在这个方向生成的敌人的坐标
	int tempx[4] = { x,x,x - length,x + length };
	int tempy[4] = { y - length,y + length,y,y };
	for (int i = 0; i < 4; i++) {
		if (empty(tempx[i], tempy[i], length)) {//如果四个方向中有空区域,则生成一个敌人
			if (n == boss_s)enemys->boss->build(tempx[i], tempy[i], DIRECTION(i));//代码为boss
			else {//代码为mob，选择指针
				MOB** mob;
				switch (n) {
				case average1_s:
					mob = enemys->average1;
					break;
				case average2_s:
					mob = enemys->average2;
					break;
				default:
					return 0;
				}
				for (int j = 0; j < mob_n; j++) {
					if (mob[j]->build(tempx[i], tempy[i], DIRECTION(i)))return 1;//成功生成一个小怪时结束循环
				}
				return 1;
			}
		}
		}
	return 0;//没有空区域，返回0
}
