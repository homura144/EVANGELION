#include "GUN.h"
GUN::GUN(int length, CAMP camp) :PROP(length, camp, &images->gun) {}
void GUN::use(int x, int y, DIRECTION direction) {//生成一个子弹
	for (int i = 0; i < attack_n; i++) {
		if (attacks->bullet[i].build(x, y, length, direction, camp, 4, 4, 1, WHITE))
			break;
	}
}