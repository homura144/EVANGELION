#pragma once
#include"CONST.h"
extern void setmap(int x, int y, int length, int code);//设置正方形区域的代码，x,y-正方形左上角坐标，length-正方形边长,code-代码
extern bool empty(int x1, int y1, int x2, int y2);//检测矩形区域是否为空，x1,y1-矩形左上角坐标，x2,y2-矩形右下角坐标，返回值：有物体-0，区域为空-1
extern bool empty(int x, int y, int length);//检测正方形区域是否为空，x,y-正方形左上角坐标，length-正方形边长，返回值：有物体-0，区域为空-1
extern bool harm(int x1, int y1, int x2, int y2, CAMP camp, int ATK);// 检测矩形区域内能受伤的物体, 并造成伤害，x1, y1 - 矩形左上角坐标，x2, y2 - 矩形右下角坐标，camp - 伤害来源所属阵营，ATK - 攻击力，返回值：1 - 造成了伤害，0 - 没造成伤害
extern void harmnear(int x, int y, int length, int range, CAMP camp, int ATK);//分别对四个方向以length为长，range为宽的矩形区域造成伤害，x,y-伤害来源坐标，length-伤害来源边长，range-伤害范围，camp-伤害来源所属阵营，ATK-攻击力
extern void shownum(int x, int y, int n);//在指定位置显示整数变量，x,y-整数左上角坐标，n-整数数值