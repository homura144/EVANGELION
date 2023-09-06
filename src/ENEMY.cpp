#include"ENEMY.h"
#include"HERO.h"
extern HERO* hero;
extern int map[LENGTH][HEIGHT];
ENEMY::ENEMY(int length, int HP_max, int speed, int firerate, IMAGE* i1, IMAGE* i2, IMAGE* i3, IMAGE* i4, int code) :ROLE(length, HP_max, speed, firerate, i1, i2, i3, i4, code) {}
void ENEMY::track() {
	DIRECTION d1, d2, tempd;//d1为敌人行走的垂直方向，d2为敌人行走的水平方向，tempd来暂存备选方向
	//获取玩家左上角和敌人的水平（垂直）对称轴的水平（垂直）距离
	int tempx = x+length/2 - hero->getx();
	int tempy = y+length/2- hero->gety();
	if (tempx > 0 && tempx < hero->getlength()) {//如果敌人垂直的对称轴与玩家相交，则敌人向上(下)发动攻击能击中玩家，说明玩家进入敌人的垂直攻击范围
		direction = tempy > 0 ? UP : DOWN;//如果玩家纵坐标小于敌人的对称轴（在敌人的上方），则敌人方向调整为向上，否则向下
		move(direction);
	}
	else if (tempy >0&& tempy < hero->getlength()) {//玩家进入敌人的水平攻击范围
		direction = tempx > 0 ? LEFT : RIGHT;//如果玩家横坐标小于敌人的对称轴（在敌人的左方），则敌人方向调整为向左，否则向右
		move(direction);
	}
	else {//如果玩家没有进入敌人攻击范围，则确定玩家在敌人的哪个方向，然后敌人沿折线前进
		if (tempy > 0)d1 = UP;//玩家在上方
		else {//玩家在下方
			d1 = DOWN;
			tempy = -tempy;//保证距离为正数
		}
		if (tempx > 0)d2 = LEFT;//玩家在左方
		else {//玩家在右方
			d2 = RIGHT;
			tempx = -tempx;
		}
		if (tempy > tempx) {//垂直距离更大，则垂直方向为首选方向，水平方向为备选方向
			direction = d1;
			tempd = d2;
		}
		else {//水平距离更大，则水平方向为首选方向，垂直方向为备选方向
			direction = d2;
			tempd = d1;
		}
		if (!move(direction)) {//如果朝首选方向移动失败，则朝备选方向移动
			direction = tempd;
			move(direction);
		}
	}
	//移动后,检测角色四周是否有特殊物品
	detect(x, y - 1, x + length - 1, y - 1);
	detect(x, y + length, x + length - 1, y + length);
	detect(x - 1, y, x - 1, y + length - 1);
	detect(x + length, y, x + length, y + length - 1);
}
void ENEMY::walk() {
	if (walktime()) track();
}
bool ENEMY::build(int _x, int _y, DIRECTION _direction) {
	if (HP <= 0) {
		ROLE::build(_x, _y, _direction);
		HP = HP_max;
		return 1;
	}
	else return 0;
}
void ENEMY::attack() {
	if (attacktime())attackway();
}
void ENEMY::attacked(int h) {
	if (HP > 0) {
		reaction(h);//先对攻击做出相应反应
		HP -= h;
		if (HP <= 0) {//血量<0,死亡
			clearrectangle(x - 1, y - 1, x + length, y + length);//清除图像
			setmap(x, y, length, empty_s);//设置所在位置为空
			die();//提供死亡奖励
		}
	}
}
void ENEMY::reaction(int& h){}
void ENEMY::detect(int x1, int y1, int x2, int y2)const {
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++) {//检测到未拾取道具，则道具被拾取
			if (i >= 0 && i < LENGTH && j >= 0 && j < HEIGHT && map[j][i] != empty_s) {
				if (map[j][i] >= machinegun_s && map[j][i] < machinegun_s + barrier_n) {
					barriers->machinegun[map[j][i] - machinegun_s]->picked();
				}
				else if (map[j][i] >= mine_s && map[j][i] < mine_s + barrier_n) {
					barriers->mine[map[j][i] - mine_s]->picked();
				}
				else if (map[j][i] >= spear_s && map[j][i] < spear_s + barrier_n) {
					barriers->spear[map[j][i] - spear_s]->picked();
				}
				else if (map[j][i] >= cannon_s && map[j][i] < cannon_s + barrier_n) {
					barriers->cannon[map[j][i] - cannon_s]->picked();
				}
				else if (map[j][i] >= shield_s && map[j][i] < shield_s + barrier_n) {
					barriers->shield[map[j][i] - shield_s]->picked();
				}
				else if (map[j][i] >= gold_s && map[j][i] < gold_s + barrier_n) {
					barriers->gold[map[j][i] - gold_s]->picked();
				}
			}
		}
}