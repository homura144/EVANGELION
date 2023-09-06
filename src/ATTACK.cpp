#include "ATTACK.h"
ATTACK::ATTACK():x(0), y(0), length(0), height(0), ATK(0),life(0), camp(CAMP::hero), t(0) {}
bool ATTACK::build(int _x, int _y, int _length, DIRECTION direction, CAMP _camp, int vertical_length, int vertical_height, int _ATK) {
	if (!life) {//如果不存在，则可以创建
		t = GetTickCount();//重置时间
		life = 1;
		camp = _camp;
		ATK = _ATK;
		if (direction == UP || direction == DOWN) {//如果是垂直方向，则长度和高度就是垂直时的，具体位置要根据创建者的边长调整
			length = vertical_length;
			height = vertical_height;	
			x = _x + _length / 2 - length / 2;
			if (direction == UP) y = _y - height - 1;
			else y = _y + _length;
		}
		else {//如果是水平方向，则长度和高度与垂直时相反
			length = vertical_height;
			height = vertical_length;	
			y = _y + _length / 2 - height / 2;
			if (direction == LEFT) x = _x - length - 1;
			else x = _x + _length;
		}
		return 1;
	}
	else return 0;
}
