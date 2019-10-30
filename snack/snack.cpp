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
//̰���߽ṹ��
typedef struct Snack
{    int size;
position pos[MAP_W*MAP_H];
}Snack;
          
Snack g_snack;

//ʳ��
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


//��Ϸ��ʼʱ̰���ߵĴ�С
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
//����̰����
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
	{//�����������

	//����Ƿ��а�������
		if(_kbhit())
		{
			key = _getch();
		}
		if(key == 'q' || key == 'q'){
			return;
		}
		//����ײǽ���¼�
		//���»���

       // UpdateScreen();

		Sleep(100);//��ʱ
	}
	
}
void Score()
{
	
	
}
int main(int argc, char* argv[])
{
    Init();//��ʼ��������ͼ
	GameLoop();//��ѭ��������������Ϸ����ˢ�£�����ײǽ���¼�
	Score();//��ӡ�÷�
	return 0;
}

