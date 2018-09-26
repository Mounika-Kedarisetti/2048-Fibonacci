#include<stdlib.h>
#include<string.h>
typedef struct User{
	char name[20];
	int movesCount;
	int board;
	char date[20];
	
};
User * createUser(char *name,int board_size){
	User *user = (User*)malloc(sizeof(User));
	strcpy(user->name,name);
	user->movesCount = 0;
	user->board = board_size;
	return user;
}
char *createMonthArr(int mon)
{
	switch (mon) {
	case 0: return "JAN";
	case 1:return "FEB";
	case 2:return "MAR";
	case 3:return "APR";
	case 4:return "MAY";
	case 5:return "JUN";
	case 6:return "JUL";
	case 7:return "AUG";
	case 8:return "SEP";
	case 9:return "OCT";
	case 10:return "NOV";
	case 11:return "DEC";
	}
}
void setDate(User *user, struct tm tm)
{
	char *date = (char*)malloc(sizeof(char) * 20);
	date[1] = tm.tm_mday % 10 + '0';
	date[0] = tm.tm_mday / 10 + '0';
	int	i = 2;
	date[i] = '-';
	i++;

	char *mon_str = createMonthArr(tm.tm_mon);
	for (int j = 0; j < 3; j++)
	{
		//i++;
		date[i] = mon_str[j];
		i++;
	}
	date[i] = '-';
	i++;
	int year = 1900 + tm.tm_year;
	int k = 4, n = 10000, m = 1000;
	while (n != 1)
	{
		date[i] = ((year%n) / m) + '0';
		n = n / 10;
		m = m / 10;
		i++;
	}
	date[i] = '\0';
	strcpy(user->date, date);
}
