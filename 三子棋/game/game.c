#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for(i=0; i<row; i++)
	{
		int j = 0;
		for(j=0; j<col;j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;

	for(i=0; i<row; i++)
	{
		int j = 0;
		for(j=0; j<col; j++)
		{
			printf(" %c ",board[i][j]);
			printf("|");
		}
		printf("\n");
		if(i!=row-1)
		printf("---|---|---|\n");
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while(1)
	{
		printf("请输入坐标—>:");
		scanf("%d%d", &x, &y);
		if(board[x-1][y-1] == ' ')
		{
			board[x-1][y-1] = 'X';
			break;
		}
		else 
		{
			printf("坐标非法，请重新输入\n");
		}	
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while(1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if(board[x][y] == ' ')
		{
			board[x][y] = '0';
			break;
		}
	}
}

int IsFull(char board[ROW][COL])
{
	int i = 0;
	int j = 0;

	for(i=0; i<ROW; i++)
	{
		for(j=0; j<COL; j++)
		{
			if(board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char CheckWin(char board[ROW][COL], int row, int col)
{
	int i = 0;

	for(i=0; i<row; i++)
	{
		if(board[i][0]==board[i][1] && board[i][1]==board[i][2] &&board[i][2]!=' ')   //行
		{
			return board[i][0];
		}
		if(board[0][i]==board[1][i] && board[1][i]==board[2][i] &&board[2][i]!=' ')   //列
		{
			return board[2][i];
		}
		if(board[0][0]==board[1][1] && board[1][1]==board[2][1] &&board[1][2]!=' ')
		{
			return board[2][2];
		}
		if(board[0][2]==board[1][1] && board[1][1]==board[2][0] &&board[2][0]!=' ')
		{
			return board[2][0];
		}
	}

	if(IsFull(board)== 1)
	{
		return 'Q';
	}

	return ' ';
}

