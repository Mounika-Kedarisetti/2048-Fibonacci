#include<string.h>
#include<stdlib.h>
User *record;
void saveToFile(User *user)
{
	FILE *fptr;
	fptr = fopen("2048Fib.csv", "a+");
	char *str;
	if (user->board == 2)
		str ="2 * 2";
	else
		str = "4*4";
	fprintf(fptr, "%s,%s,%d,%s\n", user->date, user->name, user->movesCount, str);
	fclose(fptr);
}
void copy(struct User t1, struct User t2)
{
	strcpy(t1.date, t2.date);
	strcpy(t1.name, t2.name);
	t1.movesCount = t2.movesCount;
	t1.board = t2.board;
}
void swap(struct User u1, struct User u2)
{
	//struct User temp;
	char *name=(char *)malloc(sizeof(char) * 20);
	int movesCount=u1.movesCount;
	u1.movesCount = u2.movesCount;
	u2.movesCount = movesCount;
	int board=u1.board;
	u1.board = u2.board;
	u2.board = board;
	char *date=(char *)malloc(sizeof(char)*10);
	strcpy(name, u1.name);
	strcpy(u1.name, u2.name);
	strcpy(u2.name, name);
	strcpy(date, u1.date);
	strcpy(u1.date, u2.date);
	strcpy(u2.date, date);
}
void displayLeaderBoard()
{
	FILE *fptr;
	fptr = fopen("2048Fib.csv", "r");
	int i =0;
	char *str = (char *)malloc(sizeof(char) * 20);
	record = (struct  User*)malloc(sizeof(struct User) * 50);
	while (fscanf(fptr, "%[^,],%[^,],%d,%[^\n]\n,", record[i].date, record[i].name, &(record[i].movesCount), str) != EOF)
	{
		if (str[0] == '2')
			record[i].board = 2;
		else
			record[i].board = 4;
		i++;
	}
	fclose(fptr);
		int members = i,max_idx,j;
		for (i = 0; i < members;i++)
		{
			max_idx = i;
			for (j = i + 1; j < members; j++)
			{
				if (record[j].movesCount < record[max_idx].movesCount)
					max_idx = j;
			}
			swap(record[i],record[max_idx]);
			char *name = (char *)malloc(sizeof(char) * 20);
			int movesCount = record[i].movesCount;
			record[i].movesCount = record[max_idx].movesCount;
			record[max_idx].movesCount = movesCount;
			int board = record[i].board;
			record[i].board = record[max_idx].board;
			record[max_idx].board = board;
			char *date = (char *)malloc(sizeof(char) * 10);
			strcpy(name, record[i].name);
			strcpy(record[i].name, record[max_idx].name);
			strcpy(record[max_idx].name, name);
			strcpy(date, record[i].date);
			strcpy(record[i].date, record[max_idx].date);
			strcpy(record[max_idx].date, date);
		}
		printf("Sno     Name\t   Date\t   Board\tMoves\n");
		char board[4];
		for (i = 0; i < members; i++)
		{
			board[0] = record[i].board + '0';
			board[1] = '*';
			board[2] = record[i].board + '0';
			board[3] = '\0';
			
			printf("%d  %10s  %10s  %s   %d\n", i + 1, record[i].name, record[i].date, board, record[i].movesCount);
		}

}