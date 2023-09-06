#include"PICKPROP.h"
extern void shownum(int x, int y, int n);
PICKPROP::PICKPROP(int length, CAMP camp, IMAGE* image) :PROP(length, camp, image), num(0) {}
void PICKPROP::innum(int n) {
	num += n;
}
void PICKPROP::show()const {
	PROP::show();
	shownum(LENGTH - small_length - 25, HEIGHT - 15, num);
}
void PICKPROP::use(int x, int y, DIRECTION direction) {
	if (camp == CAMP::enemy) {//如果使用者是敌人，则可以使用道具
		skill(x, y, direction);
	}
	else if (num > 0) {//如果是玩家且数量足够
		num--;//数量减少
		skill(x, y, direction);
	}
}