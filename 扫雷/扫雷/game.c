#define _CRT_SECURE_NO_WARNINGS 1 
#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void PrintBoard(char board[ROWS][COLS],int row,int col)
{
	int i = 0;
	int j = 0;
	printf("----------扫雷---------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= ROW; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= COL; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----------扫雷---------\n");
}
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = boom;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
int get_mine_boom(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +
		   mine[x][y - 1] + mine[x][y + 1] +
		   mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] -
		   8 * '0';
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) 
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col-boom)
	{
		printf("请输入坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("游戏结束\n");
				PrintBoard(mine, row, col);
				break;
			}
			else
			{
				int count = get_mine_boom(mine, x, y);
				show[x][y] = count + '0';
				PrintBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("输入坐标越界，请重新输入：\n");
		}
	}
	if (win == row * col - boom)
	{
		printf("恭喜您，挑战成功\n");
		PrintBoard(mine, row, col);
	}
}