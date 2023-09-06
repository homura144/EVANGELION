#include "EVA02.h"
EVA02::EVA02() :HERO(75, 5, 250, &images->eva02[UP], &images->eva02[DOWN], &images->eva02[LEFT], &images->eva02[RIGHT]){
	knife.changeatk(2);
}