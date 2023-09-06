#include "PROP.h"
PROP::PROP(int length, CAMP camp,IMAGE*image) :length(length), camp(camp),image(image) {}
void PROP::show()const {
	putimage(LENGTH - small_length,HEIGHT-small_length,image);//在右下角展示道具图像
}