int isValidInput(char letter){
	if (letter == 'w' || letter == 'a' || letter == 's' || letter == 'd' || letter == 'W' || letter == 'A' || letter == 'S' || letter == 'D'||letter=='z'||letter=='Z')
		return 1;
	return 0;
}
char takeAndCheckInputFib(char ch)
{
	if (isValidInput(ch) != 1)
		return '0';
	return ch;
}
int getIndex(int num)
{
	if (num == 1)
		return 1;
	int a = 1, b = 1, c = 1, index = 1;
	int res = 1;
	while (c < num)
	{
		c = a + b;
		index = index + 1;
		a = b;
		b = c;
	}
	return index;

}
int fibNumber(int index)
{
	if (index < 0)
		return -1;
	if (index == 1 || index==0)
		return 1;
	return fibNumber(index - 1) + fibNumber(index -2);
}
void goUp(Board *fibGame,int *flag)
{
	for (int j = 0; j < fibGame->size; j++)
	{
		int i = 0;
		while (i < fibGame->size)
		{
			if (fibGame->table[i][j] == 0)
			{
				i=i+1;
				continue;
			}
			if (fibGame->table[i][j] != 0)
			{
				int index = getIndex(fibGame->table[i][j]);
				int q = i + 1;
				while (q < fibGame->size&&fibGame->table[q][j] == 0)
					q = q + 1;
				if (q >= fibGame->size)
				{
					int t = i;
					while (t - 1 >= 0)
					{
						if (fibGame->table[t-1][j] != 0)
							break;
						t = t - 1;
					}
					if (t != i)
					{
						fibGame->table[t][j] = fibGame->table[i][j];
						fibGame->table[i][j] = 0;
						*flag = 1;
					}
					break;
				}
				int k = getIndex(fibGame->table[i][j]);
				int z = getIndex(fibGame->table[q][j]);
				int a = fibNumber(index + 1);
				int b = fibNumber(index - 1);
				if ((fibGame->table[q][j] ==1&& fibGame->table[i][j] == 1) || fibNumber(index + 1) == fibGame->table[q][j] || fibNumber(index - 1) == fibGame->table[q][j])
				{
					*flag = 1;
					int t = i;
					while (t - 1 >= 0)
					{
						if (fibGame->table[t-1][j] == 0)
							t = t - 1;
						else
							break;
					}
					fibGame->table[t][j] = fibGame->table[i][j] + fibGame->table[q][j];
					fibGame->table[q][j] = 0;
					int p = q;
					t = t + 1;
					while (p < fibGame->size)
					{
						while (p < fibGame->size&&fibGame->table[p][j] == 0 )
							p = p + 1;
						if (p < fibGame->size)
						{
							fibGame->table[t][j] = fibGame->table[p][j];
							t = t + 1;
							p = p + 1;
						}
						else
							break;
					}
					while (t < fibGame->size)
					{
						fibGame->table[t][j] = 0;
						t = t + 1;
					}

				}
				i = i + 1;
			}
		}
	}
}
void goDown(Board *fibGame,int *flag)
{
	for (int j = 0; j < fibGame->size; j++)
	{
		int i = fibGame->size - 1;
		while (i >= 0)
		{
			if (fibGame->table[i][j] == 0)
			{
				i = i - 1;
				continue;
			}
			if (fibGame->table[i][j] != 0)
			{
				int index = getIndex(fibGame->table[i][j]);
				int q = i - 1;
				while (q >= 0 && fibGame->table[q][j] == 0)
					q = q - 1;
				if (q < 0)
				{
					int t = i;
					while (t + 1 < fibGame->size)
					{
						if (fibGame->table[t + 1][j] != 0)
							break;
						t = t + 1;
					}
					if (t != i)
					{
						fibGame->table[t][j] = fibGame->table[i][j];
						fibGame->table[i][j] = 0;
						*flag = 1;
					}
					break;
				}
				if ((fibGame->table[q][j] == 1 && fibGame->table[i][j] == 1) || fibNumber(index + 1) == fibGame->table[q][j] || fibNumber(index - 1) == fibGame->table[q][j])
				{
					*flag = 1;
					int t = i;
					while (t + 1 < fibGame->size)
					{
						if (fibGame->table[t + 1][j] == 0)
							t = t + 1;
						else
							break;
					}
					fibGame->table[t][j] = fibGame->table[i][j] + fibGame->table[q][j];
					fibGame->table[q][j] = 0;
					int p = q;
					t = t - 1;
					while (p >= 0)
					{
						while (p >= 0&&fibGame->table[p][j] == 0)
							p = p - 1;
						if (p >= 0)
						{
							fibGame->table[t][j] = fibGame->table[p][j];
							t = t - 1;
							p = p - 1;
						}
						else
							break;
					}
					while (t >= 0)
					{
						fibGame->table[t][j] = 0;
						t = t - 1;
					}
				}
				i = i - 1;
			}
		}
	}
}
void goRight(Board *fibGame, int *flag)
{
	for (int i = 0; i < fibGame->size; i++)
	{
		int j = fibGame->size - 1;
		while (j >= 0)
		{
			if (fibGame->table[i][j] == 0)
			{
				j = j - 1;
				continue;
			}
			if (fibGame->table[i][j] != 0)
			{
				int index = getIndex(fibGame->table[i][j]);
				int q = j - 1;
				while (q>=0&&fibGame->table[i][q] == 0)
					q = q - 1;
				if (q < 0)
				{
					int t = j;
					while (t + 1 <fibGame->size)
					{
						if (fibGame->table[i][t + 1] != 0)
							break;
						t = t +1;
					}
					if (t != j)
					{
						fibGame->table[i][t] = fibGame->table[i][j];
						fibGame->table[i][j] = 0;
						*flag = 1;
					}
					break;
				}
				if ((fibGame->table[i][q] == 1 && fibGame->table[i][j] == 1) || fibNumber(index + 1) == fibGame->table[i][q] || fibNumber(index - 1) == fibGame->table[i][q])
				{
					*flag = 1;
					int t = j;
					while (t + 1 <fibGame->size)
					{
						if (fibGame->table[i][t + 1] == 0)
							t = t + 1;
						else
							break;
					}
					fibGame->table[i][t] = fibGame->table[i][j] + fibGame->table[i][q];
					fibGame->table[i][q] = 0;
					int p = q;
					t = t - 1;
					while (p >=0)
					{
						while (p >= 0&&fibGame->table[i][p] == 0)
							p = p - 1;
						if (p >=0)
						{
							fibGame->table[i][t] = fibGame->table[i][p];
							t = t - 1;
							p = p - 1;
						}
						else
							break;
					}
					while (t >=0)
					{
						fibGame->table[i][t] = 0;
						t = t - 1;
					}
				}
				j = j - 1;
			}

		}
	}
}
void goLeft(Board * fibGame,int *flag)
{
	for (int i = 0; i < fibGame->size; i++)
	{
		int j = 0;
		while (j < fibGame->size)
		{
			if (fibGame->table[i][j] == 0)
			{
				j = j + 1;
				continue;
			}
			if (fibGame->table[i][j] != 0)
			{
				int index = getIndex(fibGame->table[i][j]);
				int q = j + 1;
				while (q < fibGame->size&&fibGame->table[i][q] == 0)
					q = q + 1;
				if (q >= fibGame->size)
				{
					int t = j;
					while (t - 1 >= 0)
					{
						if (fibGame->table[i][t - 1] != 0)
							break;
						t = t - 1;
					}
					if (t != j)
					{
						fibGame->table[i][t] = fibGame->table[i][j];
						fibGame->table[i][j] = 0;
						*flag = 1;
					}
					break;
				}
				if ((fibGame->table[i][1] == 1 && fibGame->table[i][j] == 1) || fibNumber(index + 1) == fibGame->table[i][q] || fibNumber(index - 1) == fibGame->table[i][q])
				{
					*flag = 1;
					int t = j;
					while (t - 1 >= 0)
					{
						if (fibGame->table[i][t - 1] == 0)
							t = t - 1;
						else
							break;
					}
					fibGame->table[i][t] = fibGame->table[i][j] + fibGame->table[i][q];
					fibGame->table[i][q] = 0;
					int p = q;
					t = t + 1;
					while (p < fibGame->size)
					{
						while (p < fibGame->size&&fibGame->table[i][p] == 0)
							p = p + 1;
						if (p < fibGame->size)
						{
							fibGame->table[i][t] = fibGame->table[i][p];
							t = t + 1;
							p = p + 1;
						}
						else
							break;
					}
					while (t < fibGame->size )
					{
						fibGame->table[i][t] = 0;
						t = t + 1;
					}

				}
				j = j + 1;
			}

		}
	}
}
void processInput(Board *board, char inputChar,int *flag)
{

	if (inputChar == 'A' || inputChar == 'a')
	{
		goLeft(board,flag);
	}
	if (inputChar == 'D' || inputChar == 'd')
	{
	goRight(board,flag);
	}
	if (inputChar == 'W' || inputChar == 'w')
	{
	goUp(board,flag);

	}
	if (inputChar == 'S' || inputChar == 's')
	{
	goDown(board,flag);
	}
}
int hasFibAdjacent(int **table, int row, int col, int size)
{
	int i = row - 1;
	int j = col;
	int index = getIndex(table[row][col]);
	while (i >= 0)
	{
		if (table[i][j] == 0)
		{
			i--;
			continue;
		}
		if (fibNumber(index - 1) == table[i][j] || fibNumber(index + 1) == table[i][j])
			return 1;
		break;
	}
	i = row + 1;
	while (i < size)
	{
		if (table[i][j] == 0)
		{
			i++;
			continue;
		}
		if (fibNumber(index - 1) == table[i][j] || fibNumber(index + 1) == table[i][j])
			return 1;
		break;
	}
	j = col - 1;
	i = row;
	while (j >= 0)
	{
		if (table[i][j] == 0)
		{
			j--;
			continue;
		}
		if (fibNumber(index - 1) == table[i][j] || fibNumber(index + 1) == table[i][j])
			return 1;
		break;
	}
	j = col + 1;
	while (j < size)
	{
		if (table[i][j] == 0)
		{
			j++;
			continue;
		}
		if (fibNumber(index - 1) == table[i][j] || fibNumber(index + 1) == table[i][j])
			return 1;
		break;
	}
	return 0;

}
int checkIfLost(Board *fibTable)
{
	int size = fibTable->size;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (fibTable->table[i][j] == 0)
				return 0;
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (hasFibAdjacent(fibTable->table, i, j, fibTable->size) == 1)
				return 0;
		}
	}
	return 1;
}
int checkIfWon(Board *fibTable)
{
	int size = fibTable->size;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			//int k = fibNumber(2 * size*size);
			if (fibTable->table[i][j] == fibNumber((2 * size*size)-1))
				return 1;
		}
	}
	return 0;
}
