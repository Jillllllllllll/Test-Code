#pragma once

#define LIN 3
#define VER 3
#include <stdio.h>
#include <windows.h>

void cross(char arr[LIN][VER]);
void Initialize(char arr[LIN][VER]);
void PlayerInput(char arr[LIN][VER]);
void ComputerInput(char arr[LIN][VER]);
char IsWin(char arr[LIN][VER]);