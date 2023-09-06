#include"BULLET.h"
BULLET::BULLET() :direction(UP), color(WHITE) {}
bool BULLET::build(int _x, int _y, int _length, DIRECTION _direction, CAMP _camp, int vertical_length, int vertical_height, int _ATK, COLORREF _color) {
	if (ATTACK::build(_x, _y, _length, _direction, _camp, vertical_length, vertical_height, _ATK)) {
		direction = _direction;
		color = _color;
		return 1;
	}
	else return 0;
}
void BULLET::attack() {
	if (life && GetTickCount() - t > 10) {//每过10ms移动一次
		t = GetTickCount();
		switch (direction) {//按方向移动
		case UP:
			y -= 1;
			break;
		case DOWN:
			y += 1;
			break;
		case LEFT:
			x -= 1;
			break;
		case RIGHT:
			x += 1;
			break;
		}
		if (x <0 || x>LENGTH || y <0 || y>HEIGHT) {//超出画布,直接消失
			life = 0;
		}
		else {//检测是否造成了伤害，是则消失
			if (harm(x, y, x + length - 1, y + height - 1, camp, ATK)) {
				life = 0;
			}
		}
	}
}
void BULLET::draw() const {
	if (life) {
		setfillcolor(color);
		solidrectangle(x, y, x + length - 1, y + height - 1);
	}
}