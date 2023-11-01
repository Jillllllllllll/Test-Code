# define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
#include <time.h>
#include <stdlib.h>
void game(char arr[LIN][VER])
{
	srand((unsigned int)time(NULL));
	Initialize(arr);
	Sleep(500);
	system("cls");
	cross(arr);
	while (1)
	{
		printf("请你输入坐标:>");
		PlayerInput(arr);
		if (IsWin(arr) == '#')
		{
			printf("电脑获胜,游戏结束\n");
			break;
		}
		if (IsWin(arr) == '*')
		{
			printf("你赢了!游戏结束\n");
			break;
		}
		if (IsWin(arr) == 'E')
		{
			printf("平局诶\n");
			break;
		}
	
		system("cls");
		ComputerInput(arr);
		if (IsWin(arr) == '#')
		{
			printf("电脑获胜,游戏结束\n");
			break;
		}
		if (IsWin(arr) == '*')
		{
			printf("你赢了!游戏结束\n");
			break;
		}
		if (IsWin(arr) == 'E')
		{
			printf("平局诶\n");
			break;
		}
	}
	if (IsWin(arr) != 'C')
	printf("游戏结束\n");

}
void menu()
{
	printf("****************************************\n");
	printf("*******    1:play       0:exit    ******\n");
	printf("****************************************\n");
}
void start()
{
	int input = 0;
	char arr[LIN][VER] = { 0 };
	do {
		menu();
		printf("请你输入:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			system("cls");
			printf("游戏开始\n");
			game(arr);
			break;
		}
		case 0:
			break;
		default:
		{
			printf("你输入的什么啊,重新输入\n");
			break;
		}
		}
	} while (input);
	printf("游戏退出\n");
}
int main()
{
	start();
	return 0;
}