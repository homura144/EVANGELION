#include"MACHINEGUN.h"
MACHINEGUN::MACHINEGUN(int length, CAMP camp) :PICKPROP(length, camp, &images->machinegun) {}
void MACHINEGUN::skill(int x, int y, DIRECTION direction)const {//生成3个子弹
	int tempx[3] = { x,x,x };//每个子弹的横坐标
	int tempy[3] = { y,y,y };//每个子弹的纵坐标
	if (direction == UP || direction == DOWN) {//发射方向为上（下），则生成子弹的水平坐标不同
		tempx[1] -= 8;
		tempx[2] += 8;
	}
	else {//发射方向为左（右），则生成子弹的水平坐标不同
		tempy[1] -= 8;
		tempy[2] += 8;
	}
	for (int j = 0; j < 3; j++) {//循环生成3个子弹
		for (int i = 0; i < attack_n; i++) {
			if (attacks->bullet[i].build(tempx[j], tempy[j], length, direction, camp, 4, 4, 1, WHITE))break;
		}
	}
}