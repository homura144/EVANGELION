#include"ROLE.h"
extern bool empty(int x, int y, int x1, int y1);
ROLE::ROLE(int length, int HP_max, int speed, int firerate, IMAGE* i1, IMAGE* i2, IMAGE* i3, IMAGE* i4, int code) :length(length), HP_max(HP_max), speed(speed), firerate(firerate), code(code), direction(UP), x(0), y(0), HP(0), t_walk(0), t_attack(0), image{i1,i2,i3,i4}{}
void ROLE::build(int _x, int _y, DIRECTION _direction) {//设定初始位置和方向
	x = _x;
	y = _y;
	direction = _direction;
	setmap(x, y, length, code);
}
void ROLE::draw()const{
	if (HP > 0) {
		setlinecolor(RED);
		rectangle(x - 1, y - 1, x + length, y + length);//绘制AT力场
		putimage(x, y, image[direction], SRCPAINT);//绘制角色图像
	}
}
bool ROLE::attacktime(){
	if (HP > 0 && GetTickCount() - t_attack >firerate) {//如果相比上一次攻击过了相应时间，则可以攻击
		t_attack = GetTickCount();//重置时间
		return 1;
	}
	else return 0;
}
bool ROLE::walktime(){
	if (HP > 0 && GetTickCount() - t_walk >speed) {//如果相比上一次行走过了相应时间，则可以行走
		t_walk = GetTickCount();//重置
		return 1;
	}
	else return 0;
}
bool ROLE::move(DIRECTION direction) {
	int old_x = x, old_y = y;//记录移动前的位置
	setmap(x, y, length, empty_s);//设置移动前所在的位置为空
	switch (direction) {//检测前方（按移动方向）的区域是否为空，为空则移动角色位置
	case UP:
		if (empty(x, y - 1, x + length - 1, y - 1)) y -= 1;
		break;
	case DOWN:
		if (empty(x, y + length, x + length - 1, y + length)) y += 1;
		break;
	case LEFT:
		if (empty(x - 1, y, x - 1, y + length - 1)) x -= 1;
		break;
	case RIGHT:
		if (empty(x + length, y, x + length, y + length - 1)) 	x += 1;
		break;
	}
	setmap(x, y, length, code);//设置移动后所在位置的代码
	if (old_x == x && old_y == y)return 0;//如果移动前后的位置相同，则移动失败，否则成功
	else return 1;
}