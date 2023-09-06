#include<fstream>
using namespace std;
#include<conio.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment (lib, "winmm.lib")
#include"EVA00.h"
#include"EVA01.h"
#include"EVA02.h"
#include"ENEMYS.h"
#include"BARRIERS.h"
#include"ATTACKS.h"
#include"IMAGES.h"
extern void shownum(int x, int y, int n);
//全局变量
HERO* hero;//玩家
ENEMYS* enemys;//敌人
BARRIERS* barriers;//障碍物
ATTACKS* attacks;//攻击
IMAGES* images = new IMAGES;//图像
int score = 0;//游戏分数
int map[HEIGHT][LENGTH] = { empty_s };//地图
void init();//初始化
void start();//开始界面
void set();//设置界面
void help();//帮助界面
void choose();//角色选择界面
bool play();//游戏界面，胜利-1，失败-0
bool round(int n);//游戏关卡，n-关卡数，返回值：胜利-1，失败-0
void init_map();//加载地图
void shop();//商店界面
void end(bool result);//结束界面，result-游戏结果
void start_draw();//绘制开始界面
void set_draw();//绘制设置界面
void choose_draw();//绘制角色选择界面
void round_draw(int n);//绘制游戏画面
void shop_draw();//绘制商店界面
void end_draw(int result);//绘制结束界面
void clear();//清除键盘输入缓冲区,防止错误的_getch()
int main() {
	init();
	while (1) {
		start();
		choose();
		end(play());
	}
}
void init() {
	srand(GetTickCount());//将时间作为随机数种子
	initgraph(LENGTH, HEIGHT);//创建画布
	images->load();//加载图像
}
void start() {
	clear();//清除之前的键盘输入
	start_draw();
	while (1) {
		switch (_getch()) {
		case 13:
			return;
		case 'i':
			set();
			start_draw();
			break;
		case 'o':
			help();
			start_draw();
			break;
		}
	}
}
void set() {
	clear();
	set_draw();
	FlushBatchDraw();//避免游戏内进入时，因为双缓冲制图而卡顿
	while (1) {
		switch (_getch()) {//获取键盘输入
		case '1':
            //打开音乐
			PlaySound(TEXT("../sounds/高桥洋子 - 残酷な天使のテーゼ.wav"), NULL, SND_ASYNC | SND_LOOP);
			break;
		case '2':
			PlaySound(TEXT("../sounds/高桥洋子 - Fly Me To The Moon.wav"), NULL, SND_ASYNC | SND_LOOP);
			break;
		case '3':
			PlaySound(TEXT("../sounds/高桥洋子 - 魂のルフラン.wav"), NULL, SND_ASYNC | SND_LOOP);
			break;
		case '4':
			PlaySound(TEXT("../sounds/ARIANNE - Komm, süsser Tod.wav"), NULL, SND_ASYNC | SND_LOOP);
			break;
		case '5':
			PlaySound(TEXT("../sounds/宇多田光 - Beautiful World.wav"), NULL, SND_ASYNC | SND_LOOP);
			break;
		case '6':
			PlaySound(TEXT("../sounds/宇多田光 - 桜流し.wav"), NULL, SND_ASYNC | SND_LOOP);
			break;
		case '7':
			PlaySound(TEXT("../sounds/宇多田光 - One Last Kiss.wav"), NULL, SND_ASYNC | SND_LOOP);
			break;
		case 27://按ESC返回开始界面
			clear();
			return;
		}
	}
}
void help() {
	cleardevice();
	putimage(0, 110, &images->help);
	setlinecolor(WHITE);
	settextstyle(25, 0, _T("宋体"));
	rectangle(200, 50, 450, 100);
	rectangle(200, 550, 450, 600);
	outtextxy(300, 60, _T("帮助"));
	outtextxy(260, 560, _T("ESC.返回菜单"));
	FlushBatchDraw();//避免游戏内进入时，因为双缓冲制图而卡顿
	while (1) {
		if (_getch() == 27) {//按ESC返回开始界面
			clear();
			return;
		}
	}
}
void choose() {
	clear();
	choose_draw();
	bool key = 0;//是否可以开始游戏
	while (1) {
		char c = _getch();//获取键盘输入
		if (c > '0' && c < '4') {
			if (key)delete hero;//如果玩家选择过角色，则删除角色
			key = 1;//如果输入1-3，则选择角色有效,可以开始游戏
			switch (c) {
			case '1':
				hero = new EVA00;
				break;
			case '2':
				hero = new EVA01;
				break;
			case '3':
				hero = new EVA02;
				break;
			}
		}
		else if (key && c == 13)break;//按回车开始游戏
	}
}
bool play() {
	score = 0;//每轮游戏开始时，分数重置为0
	for (int i = 0; i < 4; i++) {//循环4关
		bool r = round(i);//记录每关结果
		if (!r)return 0;
	}
	return 1;
}
bool round(int n) {
	clear();
	DWORD t = GetTickCount();//记录游戏进行的时间
	if (n > 0)shop();//如果不是第一关，则打开商店
	//创建新的对象
	enemys = new ENEMYS(n);
	barriers = new BARRIERS;
	attacks = new ATTACKS;
	init_map();//加载地图
	BeginBatchDraw();//开启双缓冲绘图
	while (1) {
		round_draw(n);//绘制游戏画面
		FlushBatchDraw();
		if (GetTickCount() - t > 1000) {//每过1s分数减1
			t = GetTickCount();
			score -= 1;
		}
		//玩家操作
		if (_kbhit()) {//检查是否有键盘输入，可以防止卡顿
			char c = _getch();
			if (c > '0' && c < '8')hero->selectPROP(int(c - 48)); //玩家选择道具
			else switch (c) {
			case 'q'://切换道具
				hero->switchPROP();
				break;
			case 'e'://切换道具
				hero->reswitchPROP();
				break;
			case 'i'://打开界面
				set();
				break;
			case 'o'://打开帮助界面
				help();
				break;
			case 'p'://按P暂停
				system("pause");
				break;
			}
		}
		//玩家移动
		if (GetAsyncKeyState(VK_UP)) hero->walk(UP);//GetAsyncKeyState响应更快，防止操作延时
		if (GetAsyncKeyState(VK_DOWN)) hero->walk(DOWN);
		if (GetAsyncKeyState(VK_LEFT))hero->walk(LEFT);
		if (GetAsyncKeyState(VK_RIGHT))hero->walk(RIGHT);
		//玩家攻击
		if (GetAsyncKeyState('W')) hero->attack(UP);
		if (GetAsyncKeyState('S')) hero->attack(DOWN);
		if (GetAsyncKeyState('A')) hero->attack(LEFT);
		if (GetAsyncKeyState('D')) hero->attack(RIGHT);
		hero->detectcrazy();//检测玩家的“暴走”
		enemys->walk();//敌人移动
		enemys->attack();//敌人攻击
		barriers->produce();//生成敌人
		attacks->attack();//攻击物发动攻击
		if (!hero->live() || barriers->bossdoor->entered()) {//本轮结束，删除本关对象
			delete enemys;
			delete barriers;
			delete attacks;
			if (!hero->live())return 0;//角色死亡，本关失败
			else return 1;//进入出口，本关胜利
		}
	}
}
void init_map() {
	for (int i = 0; i < LENGTH; i++)
		for (int j = 0; j < HEIGHT; j++) {//地图全部设置为空
			map[j][i] = 0;
		}
	//记录障碍物个数
	int n_stone = 0;
	int n_trap = 0;
	int n_iron = 0;
	int n_mobdoor = 0;
	int r = rand() % 3;//选择地图
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			switch (MAP[r][i][j]) {//创建障碍物
			case 1:
				barriers->stone[n_stone]->build(25 * j, 25 * i);
				n_stone++;
				break;
			case 2:
				barriers->iron[n_iron]->build(25 * j, 25 * i);
				n_iron++;
				break;
			case 3:
				barriers->trap[n_trap]->build(25 * j, 25 * i);
				n_trap++;
				break;
			case 4:
				barriers->mobdoor[n_mobdoor]->build(25 * j, 25 * i);
				n_mobdoor++;
				break;
			case 5:
				barriers->bossdoor->build(j * 25, i * 25);
				break;
			case 6:
				hero->build(j * 25, i * 25, UP);//创建玩家
				break;
			}
}
void shop() {
	clear();
	while (1) {
		shop_draw();
		FlushBatchDraw();
		switch (_getch()) {//根据键盘输入购买商品，查看道具
		case '1':
			hero->buyprop(hero_s);
			break;
		case '2':
			hero->buyprop(machinegun_s);
			break;
		case '3':
			hero->buyprop(mine_s);
			break;
		case '4':
			hero->buyprop(spear_s);
			break;
		case '5':
			hero->buyprop(cannon_s);
			break;
		case '6':
			hero->buyprop(shield_s);
			break;
		case 'q':
			hero->switchPROP();
			break;
		case 'e':
			hero->reswitchPROP();
			break;
		case 13:
			return;//按回车开始游戏
		}
	}
}
void end(bool result) {
	delete hero;//删除本轮玩家
	clear();
	EndBatchDraw();//结束双缓冲绘图
	end_draw(result);
	while (1) {
		switch (_getch()) {
		case 'r':
			return;//按R重新开始游戏
		case 27:
			exit(0);//按ESC结束游戏
			break;
		}
	}
}
void start_draw() {
	cleardevice();
	putimage(125, 50, &images->logo);
	setlinecolor(WHITE);
	settextstyle(25, 0, _T("宋体"));
	rectangle(200, 300, 450, 350);
	rectangle(200, 400, 450, 450);
	rectangle(200, 500, 450, 550);
	rectangle(200, 600, 450, 650);
	outtextxy(240, 310, _T("回车.开始游戏"));
	outtextxy(290, 410, _T("I.设置"));
	outtextxy(290, 510, _T("O.帮助"));
	outtextxy(210, 610, _T("历史最高分: "));
	//读取txt文件中的历史最高分，然后展示
	int max;
	ifstream input("score.txt");
	input >> max;
	shownum(350, 615, max);
	input.close();
}
void set_draw() {
	cleardevice();
	setlinecolor(WHITE);
	settextstyle(25, 0, _T("宋体"));
	rectangle(200, 50, 450, 100);
	rectangle(170, 150, 480, 200);
	rectangle(170, 250, 480, 300);
	rectangle(170, 350, 480, 400);
	rectangle(170, 450, 480, 500);
	rectangle(170, 550, 480, 600);
	outtextxy(275, 60, _T("设置音乐"));
	outtextxy(200, 160, _T("1. 残酷な天使のテーゼ"));
	outtextxy(200, 210, _T("2.Fly Me To The Moon"));
	outtextxy(200, 260, _T("3.魂のルフラン"));
	outtextxy(200, 310, _T("4.Komm, süsser Tod "));
	outtextxy(200, 360, _T("5.Beautiful World"));
	outtextxy(200, 410, _T("6.桜流し"));
	outtextxy(200, 460, _T("7.One Last Kiss"));
	outtextxy(280, 560, _T("ESC.返回"));
}
void choose_draw() {
	cleardevice();
	setlinecolor(WHITE);
	settextstyle(25, 0, _T("宋体"));
	rectangle(200, 50, 450, 100);
	rectangle(200, 150, 450, 200);
	rectangle(200, 250, 450, 300);
	rectangle(200, 350, 450, 400);
	rectangle(200, 550, 450, 600);
	outtextxy(275, 60, _T("选择角色"));
	outtextxy(270, 160, _T("1.EVA00"));
	outtextxy(270, 260, _T("2.EVA01"));
	outtextxy(270, 360, _T("3.EVA02"));
	outtextxy(260, 560, _T("回车.开始游戏"));
	settextstyle(20, 0, _T("宋体"));
	outtextxy(170, 210, _T("HP较高，速度较慢，拾取金币翻倍"));
	outtextxy(170, 310, _T("HP中等，速度中等，射速较快"));
	outtextxy(170, 410, _T("HP较低，速度较快，小刀伤害翻倍"));
}
void round_draw(int n) {
	cleardevice();
	barriers->draw();
	enemys->draw();
	hero->draw();
	hero->show();
	attacks->draw();
	settextstyle(15, 0, _T("宋体"));
	outtextxy(LENGTH / 2 - 50, 0, _T("ROUND:    / 4"));
	outtextxy(LENGTH / 2 - 50, HEIGHT - 20, _T("当前分数： "));
	shownum(LENGTH / 2 + 10, 0, n + 1);//显示关卡数
	shownum(LENGTH / 2 + 20, HEIGHT - 20, score);//显示分数
}
void shop_draw() {
	cleardevice();
	hero->show();
	setlinecolor(WHITE);
	settextstyle(25, 0, _T("宋体"));
	rectangle(200, 50, 450, 200);
	rectangle(100, 250, 300, 300);
	rectangle(350, 250, 550, 300);
	rectangle(100, 350, 300, 400);
	rectangle(350, 350, 550, 400);
	rectangle(100, 450, 300, 500);
	rectangle(350, 450, 550, 500);
	rectangle(200, 550, 450, 600);
	settextstyle(25, 0, _T("宋体"));
	outtextxy(300, 60, _T("商店"));
	outtextxy(240, 110, _T("每件商品金币×5"));
	outtextxy(240, 160, _T("可按Q/E查看道具"));
	outtextxy(110, 260, _T("1.回血×10"));
	outtextxy(360, 260, _T("2.机枪×50"));
	outtextxy(110, 360, _T("3.N2地雷×5"));
	outtextxy(360, 360, _T("4.朗基努斯×5"));
	outtextxy(110, 460, _T("5.阳电子炮×5"));
	outtextxy(360, 460, _T("6.盾牌×20"));
	outtextxy(260, 560, _T("回车.下一关"));
}
void end_draw(int result) {
	cleardevice();
	setlinecolor(WHITE);
	settextstyle(25, 0, _T("宋体"));
	rectangle(200, 50, 450, 100);
	rectangle(200, 150, 450, 200);
	rectangle(200, 250, 450, 300);
	rectangle(200, 350, 450, 400);
	rectangle(200, 450, 450, 500);
	rectangle(200, 550, 450, 600);
	outtextxy(275, 60, _T("本局结束"));
	outtextxy(210, 160, _T("本局分数："));
	outtextxy(210, 260, _T("历史最高分："));
	outtextxy(260, 460, _T("R.再玩一次"));
	outtextxy(250, 560, _T("ESC.结束游戏"));
	if (result)	outtextxy(300, 360, _T("胜利"));//展示游戏结果
	else outtextxy(300, 360, _T("失败"));
	shownum(350, 165, score);//展示本局游戏分数
	//读取txt文件中的历史最高分，然后展示
	int max;
	ifstream input("score.txt");
	input >> max;
	shownum(350, 265, max);//展示最高分
	input.close();
	if (score > max) {//如果本局分数为最高分,则储存本局分数到txt文件中
		ofstream output("score.txt");
		output << score << endl;
		output.close();
	}
}
void clear() {
	while (_kbhit()) {
		_getch();
	}
}