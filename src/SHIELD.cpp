#include "SHIELD.h"
SHIELD::SHIELD(int length, CAMP camp) :PICKPROP(length, camp, &images->shield) {}
void SHIELD::skill(int x, int y, DIRECTION direction)const {//生成1个静止伤害物
	for (int i = 0; i < attack_n; i++) {
		if (attacks->remain[i].build(x, y, length, direction, camp, length / 2, length / 4, 5, BLUE))break;
	}
}
void SHIELD::defend(int& h) {
	if (num > 0) {
		if (num >= h) {//盾牌数量充足，吸收全部伤害
			num -= h;
			h = 0;
		}
		else
		{//盾牌数量不足，只吸收部分伤害
			num = 0;
			h -= num;
		}
	}
}
void SHIELD::show(int x, int y)const {//若盾牌数量大于0，则画一个圈，表示可以继续吸收伤害
	if (num > 0) {
		setlinecolor(WHITE);
		circle(x + length / 2, y + length / 2, 0.7 * length);
	}
}