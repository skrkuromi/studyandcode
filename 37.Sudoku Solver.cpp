#include<stdio.h>
char index[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int flag = 1;
int isright(char board[][9], int x, int y, char ch);
void solveSudoku(char board[][9], int boardRowSize, int boardColSize) {
	int x = boardRowSize-1, y = boardColSize-1;
	if(x != -1)
	{
		if(board[x][y] == '.')
		{
			for(int i = 0;i < 9;i++)
			{
				if(isright(board, x, y, index[i]))
				{
					board[x][y] = index[i];
					if(y)
					solveSudoku(board, x+1, y);
					else solveSudoku(board, x, 9);
					if(flag)
					board[x][y] = '.';
				}
			}
		}
		else if(y)
		solveSudoku(board, x+1, y);
		else solveSudoku(board, x, 9);
	}
	else flag = 0;
}
int isright(char board[][9], int x, int y, char ch)
{
	for(int i = 0;i < 9;i++)
	{
		if(board[x][i] == ch && i != y)
		return 0;
	}
	for(int i = 0;i < 9;i++)
	{
		if(board[i][y] == ch && i != x)
		return 0;
	}
	int x1 = x/3*3;
	int y1 = y/3*3;
	for(int i = 0;i < 3;i++)
		for(int j = 0;j < 3;j++)
		if(board[x1+i][y1+j] == ch && !(x1+i == x && y1+j == y))
			return 0;
	return 1;
}
int main ()
{
	char nums[9][9] = {{'.','.','9','7','4','8','.','.','.'},
						{'7','.','.','.','.','.','.','.','.'},
						{'.','2','.','1','.','9','.','.','.'},
						{'.','.','7','.','.','.','2','4','.'},
						{'.','6','4','.','1','.','5','9','.'},
						{'.','9','8','.','.','.','3','.','.'},
						{'.','.','.','8','.','3','.','2','.'},
						{'.','.','.','.','.','.','.','.','6'},
						{'.','.','.','2','7','5','9','.','.'}};
//	char nums[9][9] = { {'5','3','.','.','7','.','.','.','.'},
//						{'6','.','.','1','9','5','.','.','.'},
//						{'.','9','8','.','.','.','.','6','.'},
//						{'8','.','.','.','6','.','.','.','3'},
//						{'4','.','.','8','.','3','.','.','1'},
//						{'7','.','.','.','2','.','.','.','6'},
//						{'.','6','.','.','.','.','2','8','.'},
//						{'.','.','.','4','1','9','.','.','5'},
//						{'.','.','.','.','8','.','.','7','9'}};
						
	solveSudoku(nums, 9, 9);
	for(int i = 0;i < 9;i++)
	{
		for(int j = 0;j < 9;j++)
		printf("%c", nums[i][j]);
		printf("\n");
	}
	return 0;
 } 
