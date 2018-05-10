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
		printf("玩家走\n");
		PlayerMove(board, ROW , COL);
		DisplayBoard(board, ROW , COL);
		ret = CheckWin(board, ROW , COL);
		if(ret!=' ')
			break;
		printf("电脑走\n");
		ComputerMove(board, ROW, COL);
		ret = CheckWin(board, ROW , COL);
		if(ret!=' ')
			break;
	}while(ret ==' ');
	if(ret == '0')
		DisplayBoard(board, ROW , COL);
	
	if(ret == 'Q')
	{
		printf("平局\n");
	}
	if(ret == 'X')
	{
		printf("玩家赢\n");
	}
	if(ret == '0')
	{
		printf("电脑赢\n");
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
		printf("请选择—>: ");
		scanf("%d", &input);
		switch(input)
		{
		case 0:
			printf("退出游戏\n");
			break;
		case 1:
			game(arr);
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	}while(input!=0);

	return 0;
}


