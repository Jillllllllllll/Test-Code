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
		printf("������������:>");
		PlayerInput(arr);
		if (IsWin(arr) == '#')
		{
			printf("���Ի�ʤ,��Ϸ����\n");
			break;
		}
		if (IsWin(arr) == '*')
		{
			printf("��Ӯ��!��Ϸ����\n");
			break;
		}
		if (IsWin(arr) == 'E')
		{
			printf("ƽ����\n");
			break;
		}
	
		system("cls");
		ComputerInput(arr);
		if (IsWin(arr) == '#')
		{
			printf("���Ի�ʤ,��Ϸ����\n");
			break;
		}
		if (IsWin(arr) == '*')
		{
			printf("��Ӯ��!��Ϸ����\n");
			break;
		}
		if (IsWin(arr) == 'E')
		{
			printf("ƽ����\n");
			break;
		}
	}
	if (IsWin(arr) != 'C')
	printf("��Ϸ����\n");

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
		printf("��������:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			system("cls");
			printf("��Ϸ��ʼ\n");
			game(arr);
			break;
		}
		case 0:
			break;
		default:
		{
			printf("�������ʲô��,��������\n");
			break;
		}
		}
	} while (input);
	printf("��Ϸ�˳�\n");
}
int main()
{
	start();
	return 0;
}