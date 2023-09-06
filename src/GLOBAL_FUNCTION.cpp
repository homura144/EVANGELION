#include"GLOBAL_FUNCTION.h"
#include"HERO.h"
#include"ENEMYS.h"
extern HERO* hero;
extern ENEMYS*enemys;
extern int map[LENGTH][HEIGHT];
void setmap(int x, int y, int length, int code) {
	for (int i = x; i < x + length; i++)
		for (int j = y; j < y + length; j++) {
			map[j][i] = code;
		}
}
bool empty(int x1, int y1, int x2, int y2) {
	if (x1 < 0 || y1 < 0 || x2 >= LENGTH || y2 >= HEIGHT)return 0;//出界，不为空
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++) {
			if (map[j][i] != empty_s) return 0;//只要有物体，就不为空
		}
	return 1;
}
bool empty(int x, int y, int length) {
	return empty(x, y, x + length - 1, y + length - 1);
}
bool harm(int x1, int y1, int x2, int y2, CAMP camp, int ATK) {
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++) {//检测区域内的地图代码，根据代码反推该区域的物体
			if (i >= 0 && i < LENGTH && j >= 0 && j < HEIGHT && map[j][i] != empty_s) {
				if (map[j][i] >= stone_s && map[j][i] < stone_s + barrier_n) {//如果地图代码在stone_s到stone_s+barrier_n范围内，说明该区域是一个STONE类对象
					barriers->stone[map[j][i] - stone_s]->attacked(ATK);//用地图代码减去STONE类的起始代码得到这个STONE对象的数组下标，然后对它造成伤害
					return 1;
				}
				else if (map[j][i] >= iron_s && map[j][i] < iron_s + barrier_n) {
					barriers->iron[map[j][i] - iron_s]->attacked(ATK);
					return 1;
				}
				else if (map[j][i] >= trap_s && map[j][i] < trap_s + barrier_n) {
					barriers->trap[map[j][i] - trap_s]->attacked(ATK);
					return 1;
				}
				else switch (camp) {
				case CAMP::hero://只能被玩家伤害
					if (map[j][i] >= average1_s && map[j][i] < average1_s + mob_n) {
						enemys->average1[map[j][i] - average1_s]->attacked(ATK);
						return 1;
					}
					else if (map[j][i] >= average2_s && map[j][i] < average2_s + mob_n) {
						enemys->average2[map[j][i] - average2_s]->attacked(ATK);
						return 1;
					}
					else if (map[j][i] == boss_s) {
						enemys->boss->attacked(ATK);
						return 1;
					}
					break;
				case CAMP::enemy://只能被敌人伤害
					if (map[j][i] == hero_s) {
						hero->attacked(ATK);
						return 1;
					}
					break;
				}
			}
		}
	return 0;
}
void harmnear(int x, int y, int length, int range, CAMP camp, int ATK) {
	harm(x, y - range, x + length - 1, y - 1, camp, ATK);
	harm(x, y + length, x + length - 1, y + length + range - 1, camp, ATK);
	harm(x - range, y, x - 1, y + length - 1, camp, ATK);
	harm(x + length, y, x + length + range - 1, y + length - 1, camp, ATK);
}
void shownum(int x,int y,int n) {
	settextstyle(15, 0, _T("宋体"));
	setbkmode(TRANSPARENT);//字体背景透明
	//把int型变量转化成TCHAR型输出
	TCHAR s[10];
    wsprintf(s,TEXT("%i"),n);
	outtextxy(x, y,s);
}