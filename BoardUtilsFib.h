#include<stdlib.h>
#include<stdio.h>
typedef struct Board {
	int **table;
	int size;
};

Board *createBoardFib(int fsize)
{
	Board *fibTable = (Board*)malloc(sizeof(Board));
	fibTable->size = fsize;
	int **table = (int **)malloc(sizeof(int*)*fsize);
	for (int i = 0; i < fsize; i++)
	{
		table[i] = (int *)malloc(sizeof(int)*fsize);
		for (int j = 0; j < fsize; j++)
			table[i][j] = 0;
	}

	fibTable->table = table;
	return fibTable;

}
int getEmptyTiles(Board *fibTable, int **zeros)
{
	int i, j, c = 0;
	for (i = 0; i < fibTable->size; i++)
	{
		for (j = 0; j < fibTable->size; j++)
		{
			if (fibTable->table[i][j] == 0)
			{
				zeros[c][0] = i;
				zeros[c][1] = j;
				c++;
			}
		}
	}
	return c;
}
void fillEmptyTile(Board *fibTable, int **zeros, int size){
	int k = rand() % size;
	int i = zeros[k][0];
	int j = zeros[k][1];
	fibTable->table[i][j] = 1;
}
void clearScreen(){
	system("cls");
}
void drawBoardOnScreen(Board *fibGame)
{
	int i, j;
	for (i = 0; i < fibGame->size; i++)
	{
		for (j = 0; j < fibGame->size; j++)
		{
			printf("%d  ", fibGame->table[i][j]);
		}
		printf("\n");
	}
}
void initialize(Board * fibTable)
{
	int **zeros = (int**)malloc(sizeof(int*)*(fibTable->size*fibTable->size));
	for (int i = 0; i < fibTable->size*fibTable->size; i++)
	{
		zeros[i] = (int*)malloc(sizeof(int)* 2);
	}
	int c=getEmptyTiles(fibTable, zeros);
	fillEmptyTile(fibTable, zeros,c);
	c = getEmptyTiles(fibTable, zeros);
	fillEmptyTile(fibTable, zeros, c);
}
void clearAndRedrawScreen(Board *fibGame)
{
	clearScreen();
	drawBoardOnScreen(fibGame);
}

void fillATile(Board *fibTable)
{
	int **zeros = (int**)malloc(sizeof(int*)*(fibTable->size*fibTable->size));
	for (int i = 0; i < fibTable->size*fibTable->size; i++)
	{
		zeros[i] = (int*)malloc(sizeof(int)* 2);
	}
	int c = getEmptyTiles(fibTable, zeros);
	if (c == 0)
		return;
	fillEmptyTile(fibTable, zeros, c);
}
