#include"KNIFE.h"
KNIFE::KNIFE(int ATK, int length, CAMP camp) :PROP(length, camp,&images->knife),ATK(ATK) {}
void KNIFE::use(int x, int y, DIRECTION direction){//生成1个静止伤害物
	for (int i = 0; i < attack_n; i++) {
		if (attacks->remain[i].build(x, y, length, direction,camp,length/2,length/4,ATK,MAGENTA))break;
	}
}
void KNIFE::changeatk(double n) {
	ATK*=n;
}