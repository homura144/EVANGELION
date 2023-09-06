#include"ATTACKS.h"
void ATTACKS::attack() {
	for (int i = 0; i < attack_n; i++) {
		bomb[i].attack();
		remain[i].attack();
		bullet[i].attack();
	}
}
void ATTACKS::draw()const {
	for (int i = 0; i < attack_n; i++) {
		bullet[i].draw();
		bomb[i].draw();
		remain[i].draw();
	}
}