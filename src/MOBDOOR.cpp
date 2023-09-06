#include "MOBDOOR.h"
MOBDOOR::MOBDOOR(int n) :DOOR(midium_length, mobdoor_s + n, &images->mobdoor) {}
void MOBDOOR::produce() {
	if (life && GetTickCount() - t > 5000) {//每隔5s可以生成小怪
		t = GetTickCount();//重置时间
		switch (rand() % 5) {//根据随机结果生成小怪
		case 0:
			create(average1_s);
			break;
		case 1:
			create(average2_s);
			break;
		default:
			return;
		}
	}
}