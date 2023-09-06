#pragma once
#include"DOOR.h"
class BOSSDOOR :public DOOR {
private:
	enum class STATUS { produce, shut, open, entered }status;//状态,分为生产状态，关闭状态，开启状态，已进入状态
public:
	BOSSDOOR();
	void produce();//生成BOSS
	void open();//打开出口
	void enter();//进入出口
	bool entered()const;//返回是否进入了出口，是-1，否-0
};