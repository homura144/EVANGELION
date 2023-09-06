#include"MOB.h"
MOB::MOB(int firerate, IMAGE* i1, IMAGE* i2, IMAGE* i3, IMAGE* i4, int code,PROP*prop):ENEMY(midium_length, 10, 15, firerate, i1, i2, i3, i4, code),prop(prop) {}
void MOB::die() const{
	barriers->buildaward(x, y, 10, 5, 1);//生成奖励
	score += 50;//分数增加
}
void MOB::attackway(){//小怪的攻击方法是使用道具
	prop->use(x,y,direction);
}