#include"STONE.h"
#include"BARRIERS.h"
extern BARRIERS* barriers;
STONE::STONE(int n) :SOFT_BARRIER(small_length, stone_s + n, &images->stone, 5) {}
void STONE::die()const {//生成金币作为奖励
	barriers->buildaward(x, y, 5, 1, 0);//生成奖励
}