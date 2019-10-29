// snack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<windows.h>
void Init(){

}
void GameLoop(){

}
void Score(){
	while(1){
		Sleep(100);//延时
	}

}
int main(int argc, char* argv[])
{
    Init();//初始化，画地图
	GameLoop();//主循环，按键处理，游戏界面刷新，处理撞墙等事件
	Score();//打印得分
	return 0;
}

