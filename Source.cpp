#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include "BoardUtilsFib.h"
#include "FibMoves.h"
#include "userUtils.h"
#include "leaderBoard.h"
void saveGame(Board *fibTable, User *user)
{

	//user->
	FILE *fp = fopen("savedgame.csv", "w");
	fprintf(fp, "%s,%d,%d,%s", user->name, user->movesCount, user->board, user->date);
	int i, j;
	for (i = 0; i < fibTable->size; i++)
	{
		for (j = 0; j < fibTable->size; j++)
			fprintf(fp, ",%d", fibTable->table[i][j]);
	}
	fclose(fp);
}
void makeMove(Board *fibBoard, User *user)
{
	int flag = 0;
	clearAndRedrawScreen(fibBoard);
	while (1)
	{
		char ch;
		printf("\nenter a direction:\n");
		printf("W:up\ts:down\n");
		printf("A:left\td:right\n");
		printf("Z: save and quit\n");
		fflush(stdin);
		scanf("%c", &ch);
		fflush(stdin);
		if (ch == 'z'||ch=='Z')
		{
			saveGame(fibBoard, user);
			return ;
		}
		else
		{
			char k = takeAndCheckInputFib(ch);
			if (k == '0')
			{
				printf("please give a valid direction");
				continue;
			}
			else
			{
				flag = 0;
				processInput(fibBoard, ch,&flag);
				clearAndRedrawScreen(fibBoard);
				if (flag == 1)
				{
					user->movesCount = user->movesCount + 1;
					clearAndRedrawScreen(fibBoard);
				}
				if (checkIfWon(fibBoard) == 1)
				{
					clearAndRedrawScreen(fibBoard);
					printf("%s,you've won in %d moves!", user->name, user->movesCount);
					saveToFile(user);
					break;
				}
				if (flag != 0)
				{
					fillATile(fibBoard);
					clearAndRedrawScreen(fibBoard);
					if (checkIfLost(fibBoard) == 1)
					{
						printf("%s,you've lost in %d moves!", user->name, user->movesCount);
						//	saveToFile(user);
						break;
					}
				}
			}
		}
	}
}
	Board *resumeSavedGame(User *user)
	{
		FILE *fp = fopen("savedgame.csv", "r");
		fscanf(fp, "%[^,],%d,%d,%[^,]", user->name, &(user->movesCount), &(user->board), user->date);
		int i, j;
		Board *fibTable = (Board*)malloc(sizeof(Board));
		fibTable->size = user->board;
		int **table = (int **)malloc(sizeof(int*)*fibTable->size);
		for (i = 0; i < fibTable->size; i++)
		{
			table[i] = (int *)malloc(sizeof(int)*fibTable->size);
			for (j = 0; j < fibTable->size; j++)
			{
				fscanf(fp, ",%d", &(table[i][j]));
			}
		}
		fibTable->table = table;
		fclose(fp);
		return fibTable;
	}
	int main()
	{
		srand(time(NULL));
		printf(".....WELCOME TO THE GAME.....\n");
		printf("1:play game\n");
		printf("2:replay last saved game\n");
		printf("3:display leaderboard\n");
		printf("enter your choice\n");
		int disp;
		scanf("%d", &disp);
		if (disp == 1)
		{
			printf("enter your name");
			char *name = (char *)malloc(sizeof(char) * 30);
			scanf("%s", name);
			printf("select one of the following board sizes:\n1:2x2      2:4x4\n");
			int choice;
			scanf("%d", &choice);
			fflush(stdin);
			User *user = createUser(name, choice * 2);
			time_t t = time(NULL);
			struct tm tm = *localtime(&t);
			setDate(user, tm);
			puts(user->date);
			Board *fibBoard = createBoardFib((choice * 2));
			initialize(fibBoard);
			clearAndRedrawScreen(fibBoard);
			makeMove(fibBoard, user);
		}
		if (disp == 3)
		{
			displayLeaderBoard();
		}
		if (disp == 2)
		{
			User*user = (User*)malloc(sizeof(User));
			Board *fibBoard = resumeSavedGame(user);
			makeMove(fibBoard, user);
		}
		getchar();
		getchar();
		return 0;
	}