#include "IRON.h"
#include"BARRIERS.h"
extern BARRIERS* barriers;
IRON::IRON(int n) :SOFT_BARRIER(small_length, iron_s + n, &images->iron, 20) {}
void IRON::die()const {
	barriers->buildaward(x, y, 5, 0, 1);//Éú³É½±Àø
}