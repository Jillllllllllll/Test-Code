# define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard (char arr[ROWS][COLS], int row, int col, char a)
{
	for (int i = 0; i <= ROWS; i++)
	{
		for (int j = 0; j <= COLS; j++)
		{
			arr[i][j] = a;
		}
	}
}


void PrintBoard(char arr[ROWS][COLS], int row, int col)
{
	for (int i = 0; i <= row; i++)
	{
		printf("%2d", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%2d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

void PutMine(char arr[ROWS][COLS], int row, int col)
{
	int sum = 0;
	while (1)
	{
		int x = (int)rand() % row + 1;
		int y = (int)rand() % col + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			sum++;
			if (sum == MINE)
				break;
		}
	}
}

int GetNum(char arr[ROWS][COLS], int x, int y)
{
	return (arr[x][y + 1] + arr[x + 1][y + 1] + arr[x + 1][y] + arr[x + 1][y - 1]
		+ arr[x][y - 1] + arr[x - 1][y + 1] + arr[x - 1][y] + arr[x - 1][y - 1]) - 8 * '0';
}

void FindMine(char arr[ROWS][COLS],char mine[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	char tmp;
	while (1)
	{
		printf("请你输入坐标:>");
		scanf("%d%d", &x, &y);
		system("cls");
		Open(mine, arr, x, y);
		PrintBoard(arr, ROW, COL);
		tmp = IsWin(arr);
		if (tmp == 'W')
		{
			printf("你赢了!\n");
			PrintBoard(mine, ROW, COL);
			break;
		}
		if(mine[x][y]== '1')
		{
			printf("对不起,你被炸死了\n");
			PrintBoard(mine, ROW, COL);
			break;
		}
		if ((x < 0 && x > ROW) && (y < 0 && y > COL))
		printf("坐标非法!\n");
	}
}
char IsWin(char arr[ROWS][COLS])
{
	int win = 0;
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++)
		{
			if (arr[i][j] == '*')
				win++;
		}
	}
	if (win == MINE)
	{
		return 'W';
	}
	else
	{
		return 'C';
	}
}
void Open(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	if ((x > 0 && x <= ROW) && (y > 0 && y <= COL))
	{
		int count = GetNum(mine, x, y);
		if (count != 0)
		{
			show[x][y] = count + '0';
		}
		else if (show[x][y] != ' ')
		{
			show[x][y] = ' ';
			int i = 0;
			int j = 0;
			for (i = x - 1; i <= x + 1; i++)
			{
				for (j = y - 1; j <= y + 1; j++)
				{
					Open(mine, show, i, j);
				}
			}
		}
		else
		{
			//show[x][y]=='0';递归停止；
			return;
		}

	}
}