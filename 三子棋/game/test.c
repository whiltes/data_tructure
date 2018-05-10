#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "game.h"

void meun()
{
	
	printf("**************************\n");
	printf("***  0.exit   1.play *****\n");
	printf("**************************\n");
}

void game(char board[ROW][COL])
{
	char ret = 0;
	InitBoard(board, ROW , COL);

	do
	{
		DisplayBoard(board, ROW , COL);
		printf("�����\n");
		PlayerMove(board, ROW , COL);
		DisplayBoard(board, ROW , COL);
		ret = CheckWin(board, ROW , COL);
		if(ret!=' ')
			break;
		printf("������\n");
		ComputerMove(board, ROW, COL);
		ret = CheckWin(board, ROW , COL);
		if(ret!=' ')
			break;
	}while(ret ==' ');
	if(ret == '0')
		DisplayBoard(board, ROW , COL);
	
	if(ret == 'Q')
	{
		printf("ƽ��\n");
	}
	if(ret == 'X')
	{
		printf("���Ӯ\n");
	}
	if(ret == '0')
	{
		printf("����Ӯ\n");
	}
}

int main()
{
	char arr[ROW][COL]= {0};
	int input = 0;

	srand( (unsigned)time( NULL ) );
	do
	{
		meun();
		printf("��ѡ��>: ");
		scanf("%d", &input);
		switch(input)
		{
		case 0:
			printf("�˳���Ϸ\n");
			break;
		case 1:
			game(arr);
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	}while(input!=0);

	return 0;
}


