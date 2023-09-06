#include "BOMB.h"
#include"IMAGES.h"
extern IMAGES* images;
extern void harmnear(int x, int y, int length, int range, CAMP camp, int ATK);
BOMB::BOMB():image(&images->bomb){}
bool BOMB::build(int _x, int _y, int _length, DIRECTION direction, CAMP _camp,int _ATK) {
	return ATTACK::build(_x, _y, _length,direction,_camp, midium_length, midium_length, _ATK);
}
void BOMB::attack() {
	if (life && GetTickCount() - t > 2000) {//创建了2s后，炸弹爆炸，对内部和附近区域造成伤害
		harm(x,y,x+length-1,y+length-1, camp,ATK);
		harmnear(x, y,length,small_length,camp,ATK);
		life = 0;
	}
}
void BOMB::draw()const {
	if (life)putimage(x, y, image);
}