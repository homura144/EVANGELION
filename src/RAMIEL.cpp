#include "RAMIEL.h"
RAMIEL::RAMIEL() :BOSS(100, 20, 2000, &images->ramiel[UP], &images->ramiel[DOWN], &images->ramiel[LEFT], &images->ramiel[RIGHT]), cannon(length,CAMP::enemy,8), shield(length, CAMP::enemy),prop(&cannon) {
}
void RAMIEL::skill(){
	if (rand() % 10 == 0) {//随机切换道具
		if (prop == &cannon) {
			prop = &shield;
			shield.innum(50);//增加盾牌数量用于防御
		}
		else prop = &cannon;
	}
	for (DIRECTION d = UP; d <= RIGHT; d = (DIRECTION)(d + 1))prop->use(x, y, d);//向四个方向使用道具
}
void RAMIEL::draw()const{
	if (prop == &shield)shield.show(x, y);//如果当前道具是盾牌，展示盾牌
	BOSS::draw();
}
void RAMIEL::reaction(int& h){
	if (prop== &shield)shield.defend(h);//受伤时，如果当前道具是盾牌，触发盾牌防御
}