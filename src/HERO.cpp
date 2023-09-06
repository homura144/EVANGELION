#include"HERO.h"
#include"ENEMYS.h"
extern ENEMYS* enemys;
extern int map[LENGTH][HEIGHT];
HERO::HERO(int HP, int speed, int firerate, IMAGE* i1, IMAGE* i2, IMAGE* i3, IMAGE* i4) :ROLE(midium_length, HP, speed, firerate, i1, i2, i3, i4, hero_s), gun(length, CAMP::hero), knife(2, length, CAMP::hero), machinegun(length, CAMP::hero), mine(length, CAMP::hero), spear(length, CAMP::hero), cannon(length, CAMP::hero, 4), shield(length, CAMP::hero), prop{ &gun,&knife,&machinegun,&mine,&spear,&cannon,&shield }, gold(0), prop_i(0), crazy(0), t_crazy(0) {}
int HERO::getx()const {
	return x;
}
int HERO::gety()const {
	return y;
}
int HERO::getlength()const {
	return length;
}
bool HERO::live()const {
	if (HP > 0)  return 1;
	else return 0;
}
void HERO::build(int _x, int _y, DIRECTION _direction) {
	ROLE::build(_x, _y, _direction);
	if (HP <= 0)HP = HP_max;//如果血量为0（即本局游戏第一次创建玩家），则血量回满，否则不回血
}
void HERO::walk(DIRECTION _direction) {
	if (walktime()) {//如果可以移动,则按方向移动1像素
		bool m = move(_direction);
		//移动后,检测角色四周是否有特殊物品
		detect(x, y - 1, x + length - 1, y - 1, m);
		detect(x, y + length, x + length - 1, y + length, m);
		detect(x - 1, y, x - 1, y + length - 1, m);
		detect(x + length, y, x + length, y + length - 1, m);
	}
}
void HERO::attack(DIRECTION _direction) {
	if (attacktime()) {//如果可以攻击，则改变玩家方向，并使用当前道具
		direction = _direction;
		prop[prop_i]->use(x, y, direction);
	}
}
void  HERO::selectPROP(int x) {
	if (!crazy)prop_i = x - 1;//如果不处于“暴走”，换成上一个道具
}
void HERO::switchPROP() {
	if (!crazy) {//如果不处于“暴走”，换成下一个道具
		if (prop_i == 6)prop_i = 0;//如果已是最后的道具，切换到第一个
		else prop_i++;
	}
}
void HERO::reswitchPROP() {
	if (!crazy) {//如果不处于“暴走”，换成上一个道具
		if (prop_i == 0)prop_i = 6;//如果已是第一个道具，切换到最后一个
		else prop_i--;
	}
}
void HERO::buyprop(int n) {
	if (gold >= 5) {//如果金币足够，则可以购买，最后减少道具
		switch (n) {
		case hero_s:
			if (HP + 10 <= HP_max)HP += 10;//如果血量+10后未满，则可以回血10
			else if (HP < HP_max)HP = HP_max;//如果血量未满，则可以回到血量上限
			else return;//如果血量已满，则不减少金币
			break;
		case machinegun_s:
			machinegun.innum(50);
			break;
		case mine_s:
			mine.innum(4);
			break;
		case spear_s:
			spear.innum(4);
			break;
		case cannon_s:
			cannon.innum(4);
			break;
		case shield_s:
			shield.innum(20);
			break;
		}
		gold -= 5;
	}
}
void HERO::attacked(int h) {
	if (crazy)h /= 2;//如果处于“暴走”，则伤害减少
	if (prop[prop_i] == &shield)shield.defend(h);//如果当前道具是盾牌，则触发盾牌防御
	HP -= h;
	//受伤后达到对应血量，则触发“暴走”或“补完”
	if (HP <= HP_max / 2 && HP + h > HP_max / 2)becrazy();
	if (HP <= HP_max / 4 && HP + h > HP_max / 4)becrazy();
	if (HP <= HP_max / 8 && HP + h > HP_max / 8)instrumentality();
}
void HERO::detect(int x1, int y1, int x2, int y2, bool move) {
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++) {
			if (i >= 0 && i < LENGTH && j >= 0 && j < HEIGHT && map[j][i] != empty_s) {
				if (move && map[j][i] >= trap_s && map[j][i] < trap_s + barrier_n) {//检测到陷阱，角色掉血
					attacked(1);
					return;//停止检测，避免重复掉血
				}
				//检测到未拾取道具，道具被拾取，角色道具数量增加
				else if (map[j][i] >= machinegun_s && map[j][i] < machinegun_s + barrier_n) {
					barriers->machinegun[map[j][i] - machinegun_s]->picked();
					machinegun.innum(50);
				}
				else if (map[j][i] >= mine_s && map[j][i] < mine_s + barrier_n) {
					barriers->mine[map[j][i] - mine_s]->picked();
					mine.innum(5);
				}
				else if (map[j][i] >= spear_s && map[j][i] < spear_s + barrier_n) {
					barriers->spear[map[j][i] - spear_s]->picked();
					spear.innum(5);
				}
				else if (map[j][i] >= cannon_s && map[j][i] < cannon_s + barrier_n) {
					barriers->cannon[map[j][i] - cannon_s]->picked();
					cannon.innum(5);
				}
				else if (map[j][i] >= shield_s && map[j][i] < shield_s + barrier_n) {
					barriers->shield[map[j][i] - shield_s]->picked();
					shield.innum(20);
				}
				else if (map[j][i] >= gold_s && map[j][i] < gold_s + barrier_n) {
					barriers->gold[map[j][i] - gold_s]->picked();
					getgold(1);
				}
				else if (map[j][i] == bossdoor_s) {//进入出口
					barriers->bossdoor->enter();
				}
			}
		}
}
void HERO::getgold(int n) {
	gold += n;
}
void HERO::becrazy() {
	if (!crazy) {//如果不处于“暴走”，则进入“暴走”
		t_crazy = GetTickCount();
		crazy = 1;
		speed /= 2;
		prop_i = 1;
		knife.changeatk(2);
	}
	else if (crazy)t_crazy += 10000;//如果处于“暴走”，则增加“暴走”的时间
}
void HERO::detectcrazy() {
	if (crazy && GetTickCount() - t_crazy > 10000) {//到时间则关闭“暴走”，属性恢复
		crazy = 0;
		speed *= 2;
		knife.changeatk(0.5);
	}
}void HERO::instrumentality() {//攻击所有敌人和障碍物
	enemys->boss->attacked(20);
	for (int i = 0; i < mob_n; i++) {
		enemys->average1[i]->attacked(10);
		enemys->average2[i]->attacked(10);
	}
	for (int i = 0; i < barrier_n; i++) {
		barriers->stone[i]->attacked(10);
		barriers->iron[i]->attacked(10);
		barriers->trap[i]->attacked(10);
	}
}
void HERO::draw()const {
	if (crazy) {//如果处于“暴走”,角色图像变红
		setfillcolor(LIGHTRED);
		solidrectangle(x - 1, y - 1, x + length, y + length);
	}
	if (prop[prop_i] == &shield) shield.show(x, y);//如果当前道具是盾牌，显示盾牌
	ROLE::draw();
}
void HERO::show()const {
	setlinecolor(WHITE);
	setfillcolor(RED);
	//绘制血条，显示血量
	if (HP > 0)solidrectangle(0, 0, HP, 15);
	rectangle(0, 0, HP_max, 15);
	//展示当前道具信息
	shownum(HP_max + 1, 0, HP);
	prop[prop_i]->show();
	//展示金币数量
	putimage(0, HEIGHT - small_length, &images->gold);
	shownum(small_length, HEIGHT - 15, gold);
}