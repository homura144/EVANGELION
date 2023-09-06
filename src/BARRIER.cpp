#include "BARRIER.h"
BARRIER::BARRIER(int length, int code, IMAGE* image) :length(length), code(code), image(image), x(0), y(0), life(0) {}
void BARRIER::build(int _x, int _y) {//设定初始位置和方向
	x = _x;
	y = _y;
	life = 1;
	setmap(x, y, length, code);
}
void BARRIER::draw()const {
	if (life)putimage(x, y, image);//如果存在，在对应位置放置图片
}