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
	char show[ROWS][COLS] = { 0 };//����ɨ�ײ��ִ�С
	char mine[ROWS][COLS] = { 0 };

	do
	{
		srand((unsigned int)time(NULL));
		InitBoard(show, ROWS, COLS, '*');//��ʼ��
		InitBoard(mine, ROWS, COLS, '0');
		PutMine(mine, ROW, COL);//������
		menu();//��ʾ�˵�
		printf("��ѡ��:>");
		scanf("%d", &input);
		system("cls");
		switch(input)
		{
		case 1:
		{			
			printf("��Ϸ��ʼ!\n");
			printf("���̴�С:%d*%d\n", ROW, COL);
			printf("��������:%d\n",MINE);
			Sleep(1000);
			system("cls");
			int x = 0;
			int y = 0;
			PrintBoard(show, ROW, COL);//��ʾ�û�������ɨ�׽���
			FindMine(show,mine, ROW, COL);
			IsWin(mine, ROW, COL);
			break;
		}

		case 2:
			printf("�˳���Ϸ\n");//ֱ���˳�
			break;
		default:
			printf("���������ʲô��?\n");
		}
	} while (input);
}



int main()
{
	game();//��Ϸ����
	return 0;
}