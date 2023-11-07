# define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("***************************\n");
	printf("*******   1. play   *******\n");
	printf("*******   0. exit   *******\n");
	printf("***************************\n");
}


void game()
{
	int input = 0;
	char show[ROWS][COLS] = { 0 };//设置扫雷部分大小
	char mine[ROWS][COLS] = { 0 };

	do
	{
		srand((unsigned int)time(NULL));
		InitBoard(show, ROWS, COLS, '*');//初始化
		InitBoard(mine, ROWS, COLS, '0');
		PutMine(mine, ROW, COL);//布置雷
		menu();//显示菜单
		printf("请选择:>");
		scanf("%d", &input);
		system("cls");
		switch(input)
		{
		case 1:
		{			
			printf("游戏开始!\n");
			printf("棋盘大小:%d*%d\n", ROW, COL);
			printf("地雷数量:%d\n",MINE);
			Sleep(1000);
			system("cls");
			int x = 0;
			int y = 0;
			PrintBoard(show, ROW, COL);//显示用户看到的扫雷界面
			FindMine(show,mine, ROW, COL);
			IsWin(mine, ROW, COL);
			break;
		}

		case 2:
			printf("退出游戏\n");//直接退出
			break;
		default:
			printf("你输入的是什么啊?\n");
		}
	} while (input);
}



int main()
{
	game();//游戏主体
	return 0;
}