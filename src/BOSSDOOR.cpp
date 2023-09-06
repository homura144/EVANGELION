#include "BOSSDOOR.h"
BOSSDOOR::BOSSDOOR() :DOOR(large_length, bossdoor_s, &images->bossdoor), status(STATUS::produce) {}
void BOSSDOOR::produce() {
	if (status == STATUS::produce && GetTickCount() - t > 20000) {//如果为生产状态且已经被创建了20s，则生成一个BOSS
		if (create(boss_s))status = STATUS::shut;//成功生成BOSS，则进入关闭状态
	}
}
void BOSSDOOR::open() {//开启入口后调整为开启状态，并更改图像
	status = STATUS::open;
	image = &images->bossdoor_open;
}
void BOSSDOOR::enter() {//如果为开启状态，则调整为被进入状态
	if (status == STATUS::open)status = STATUS::entered;
}
bool BOSSDOOR::entered()const {
	if (status == STATUS::entered)return 1;
	else return 0;
}