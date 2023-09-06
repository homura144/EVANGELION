#include "TRAP.h"
#include"BARRIERS.h"
extern BARRIERS* barriers;
TRAP::TRAP(int n) :SOFT_BARRIER(small_length, trap_s + n, &images->trap, 5) {}
void TRAP::die()const {//生成金币作为奖励
	barriers->buildaward(x, y, 2, 1, 0);//生成奖励
}