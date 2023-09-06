#include "EVA00.h"
EVA00::EVA00() :HERO(125, 15, 250, &images->eva00[UP], &images->eva00[DOWN], &images->eva00[LEFT], &images->eva00[RIGHT]) {}
void EVA00::getgold(int n) {
	gold+=2;
}