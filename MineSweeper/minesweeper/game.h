#pragma once
# define ROW 16
# define COL 16
# define ROWS ROW+2
# define COLS COL+2
# define MINE 2


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
void InitBoard(char arr[ROWS][COLS], int row, int col, char a);
void PrintBoard(char arr[ROWS][COLS], int row, int col);
void PutMine(char arr[ROWS][COLS], int row, int col);
void FindMine(char arr[ROWS][COLS], char mine[ROWS][COLS], int row, int col);
char IsWin(char arr[ROWS][COLS]);
void Open(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);