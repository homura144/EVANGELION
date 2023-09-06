#include"REMAIN.h"
REMAIN::REMAIN() :direction(UP), color(WHITE) {}
bool REMAIN::build(int _x, int _y, int _length, DIRECTION _direction, CAMP _camp, int vertical_length, int vertical_height, int _ATK, COLORREF _color) {
	if (ATTACK::build(_x, _y, _length, _direction, _camp, vertical_length, vertical_height, _ATK)) {
		direction = _direction;
		color = _color;
		return 1;
	}
	else return 0;
}
void REMAIN::attack() {
	if(life&&GetTickCount()- t>200) { //创建了200ms后造成伤害
	life = 0;
	switch (direction) {//每隔25个像素对区域造成一次伤害，攻击物方向是伤害区域的移动方向，根据方向确定伤害区域的起点
	case UP://移动方向为垂直向上
		for (int tempy1 = y + height - 24, tempy2 = y + height;; tempy1 -= 25, tempy2 -= 25)//tempy1,tempy2为伤害区域两端的纵坐标，每伤害一次，两个坐标向上移动25个像素
		{
			if (tempy1 < y) {//如果伤害区域超出了攻击物的范围，则将伤害区域限制在攻击物的范围内，之后停止伤害
				harm(x, y, x + length, tempy2, camp, ATK);
				break;
			}
			harm(x, tempy1, x + length, tempy2, camp, ATK);
		}
		break;
	case DOWN:
		for (int tempy1 = y, tempy2 = y + 24;; tempy1 += 25, tempy2 += 25)
		{
			if (tempy2 > y + height - 1) {
				harm(x, tempy1, x + length, y + height - 1, camp, ATK);
				break;
			}
			harm(x, tempy1, x + length, tempy2, camp, ATK);
		}
		break;
	case LEFT:
		for (int tempx1 = x + length - 24, tempx2 = x + length;; tempx1 -= 25, tempx2 -= 25)
		{
			if (tempx1 < x) {
				harm(x, y, tempx2, y + height, camp, ATK);
				break;
			}
			harm(tempx1, y, tempx2, y + height, camp, ATK);
		}
		break;
	case RIGHT:
		for (int tempx1 = x, tempx2 = x + 24;; tempx1 += 25, tempx2 += 25)
		{
			if (tempx2 > x + length - 1) {
				harm(tempx1, y, x + length - 1, y + height, camp, ATK);
				break;
			}
			harm(tempx1, y, tempx2, y + height, camp, ATK);
		}
		break;
	}
}
}
void REMAIN::draw()const {
	if (life) {
		setfillcolor(color);
		solidrectangle(x, y, x + length - 1, y + height - 1);
	}
}