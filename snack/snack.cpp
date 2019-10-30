// snack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#define MAP_W 60 
#define MAP_H 20 
typedef struct postion
{
	int x;
	int y;
	
}position;
//贪吃蛇结构体
typedef struct Snack
{    int size;
position pos[MAP_W*MAP_H];
}Snack;
          
Snack g_snack;

//食物
position g_food;


void DrawChar(int x,int y,char ch)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	
	putchar(ch);
}

void InitFood()
{
	srand( (unsigned)time( NULL) );
	g_food.x =rand() %MAP_W;
    g_food.y =rand() %MAP_H;

	DrawChar(g_food.x,g_food.y, '.');
}


//游戏开始时贪吃蛇的大小
void InitSnack()
{
	g_snack.size =3;
	g_snack.pos [0].x =MAP_W/2;
	g_snack.pos [0].y =MAP_H/2;
 	
	g_snack.pos [1].x =MAP_W/2-1;
	g_snack.pos [1].y =MAP_H/2;
	
	g_snack.pos [2].x =MAP_W/2-2;
	g_snack.pos [2].y =MAP_H/2;
	
}
//绘制贪吃蛇
void DrawSnack()
{
	for(int i =0;i<g_snack.size;i++)
	{
		if(i==0)
		{
			DrawChar(g_snack.pos[i].x, g_snack.pos[i].y,'*');
		}
		else
		{
			DrawChar(g_snack.pos[i].x, g_snack.pos[i].y,'#');
		}
	}
}

void InitMAP()
{
	for(int i=0;i<=MAP_H;i++)
	{
		for(int f=0;f<=MAP_W;f++)
		{
			if(f==MAP_W)
			{
				printf("|\n");
			}
			else if(i==MAP_H)
			{
				printf("-");
			}
			else
			{
				printf(" ");
			}
		}
	}
}
void Init(){
	InitMAP();
	InitSnack();
	DrawSnack();
	InitFood();
}
void GameLoop(){
	int key =0;
while(1)
	{//处理键盘输入

	//检测是否有按键输入
		if(_kbhit())
		{
			key = _getch();
		}
		if(key == 'q' || key == 'q'){
			return;
		}
		//处理撞墙等事件
		//更新画面

       // UpdateScreen();

		Sleep(100);//延时
	}
	
}
void Score()
{
	
	
}
int main(int argc, char* argv[])
{
    Init();//初始化，画地图
	GameLoop();//主循环，按键处理，游戏界面刷新，处理撞墙等事件
	Score();//打印得分
	return 0;
}

