#include"BOSS.h"
BOSS::BOSS(int HP_max, int speed, int firerate, IMAGE* i1, IMAGE* i2, IMAGE* i3, IMAGE* i4) :ENEMY(large_length, HP_max, speed, firerate, i1, i2, i3, i4, boss_s) {}
void BOSS::attackway(){//攻击方法是伤害附近的玩家/障碍物，并放技能
	harmnear(x, y, length, 1,CAMP::enemy,4);
	skill();
}
void BOSS::die()const{
	barriers->bossdoor->open();//开启出口
	barriers->buildaward(x,y,5,0,1);//生成奖励
	score += 1000;//分数增加
}
void BOSS::draw()const {
	ROLE::draw();
	setlinecolor(WHITE);
	setfillcolor(RED);
	//绘制血条，显示血量
	rectangle(LENGTH - HP_max, 0, LENGTH - 1, 15);
	if (HP > 0) {
		solidrectangle(LENGTH - HP_max, 0, LENGTH - 1 - HP_max + HP, 15);
		shownum(LENGTH - HP_max - 25, 0, HP);
	}
}