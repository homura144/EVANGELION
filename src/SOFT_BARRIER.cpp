#include"SOFT_BARRIER.h"
SOFT_BARRIER::SOFT_BARRIER(int length, int code, IMAGE* i, int h) :BARRIER(length, code, i), HP(h) {}
void SOFT_BARRIER::attacked(int h) {
	if (life) {
		HP -= h;
		if (HP <= 0) {//ËÀÍö
			life = 0;
			setmap(x, y, length, empty_s);
			die();
		}
	}
}