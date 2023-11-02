# define _CRT_SECURE_NO_WARNINGS 1


#include "game.h"

void cross(char arr[LIN][VER])
{
	int i = 0;
	for (i = 0;i < LIN; i++)
	{
		printf(" %c | %c | %c \n",arr[i][0],arr[i][1],arr[i][2]);
		if (i< LIN -1)
		printf("---|---|---\n");
	}
}
void Initialize(char arr[LIN][VER])
{
	
	for (int i = 0; i < LIN; i++)
	{
		for (int k = 0; k < VER; k++)
		{
			arr[i][k] = ' ';
		}
	}
}

void PlayerInput(char arr[LIN][VER])
{
	
	int a = 0, b = 0;
	Back:scanf("%d%d", &a, &b);
	system("cls");
	if (a <= 3 && b <= 3 && b > 0 && a > 0)
	{
		if (arr[a - 1][b - 1] == ' ')
		{
			arr[a - 1][b - 1] = '*';
			cross(arr);
		}
		else
		{
			cross(arr);
			printf("这已经有棋子了\n");
			goto Back;
		}
	}
	else
	{
		cross(arr);
		printf("棋盘上好像没有这个点....\n");
		goto Back;
		
	}

}
void ComputerInput(char arr[LIN][VER])
{
	int a=0, b=0;
	while (1)
	{
		a = rand() % 3;
		b = rand() % 3;
		if (arr[a][b] == ' ')
		{
			Sleep(200);
			arr[a][b] = '#';
			break;
		}

	}
	cross(arr);
	}

char IsWin(char arr[LIN][VER])
{
	int num = 0;
	for (int i = 0; i < LIN; i++)
	{
		for (int k = 0; k < VER; k++)
		{
			if (arr[i][k] == ' ')
				break;
			else
				num++;
		}
	}
	if (num == 9)
	{
		return 'E';
	}

	if (arr[1][1] == arr[0][0] && arr[2][2] == arr[1][1] && arr[1][1] != ' ')
	{
		return arr[1][1];
	}
	if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] && arr[1][1] != ' ')
	{
		return arr[1][1];
	}
	for (int i = 0; i <= 2; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != ' ')
		{
			return arr[i][1];
		}
	}

	for (int i = 0; i <= 2; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[i][1] != ' ')
		{
			return arr[0][i];
		}
	}
	return 'C';
 }

