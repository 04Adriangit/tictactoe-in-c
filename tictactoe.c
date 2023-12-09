/*
 * tictactoe.c
 *
 *  Created on: 06.12.2023
 *      Author: swt
 */

#include <stdio.h>

//contants
#define WIDTH 3
#define LENGTH 3
//functions
void drawboard(char board[WIDTH][LENGTH]);
void fillboard(char board[WIDTH][LENGTH], int c, int r, char symbol);
int checkfortaken(char board[WIDTH][LENGTH], int c, int r);
int checkforwinner(char board[WIDTH][LENGTH]);

int main()
{
	char board[WIDTH][LENGTH];
	int row, column;
	int gamestatus = 1;
	printf("Welcome to Tic-Tac-Toe!\n");
	printf("Player 1 is X, player 2 is O\n");
	printf("Player 1 starts.\n");
	drawboard(board);
	//game loop
	while(gamestatus)
	{

		printf("Where do you want to put X?\n");
		printf("Row: ");
		scanf("%d", &row);
		if(row < 1 || row > 3)
		{
			while(row < 1 || row > 3)
			{
				printf("Game is 3x3.\n");
				scanf("%d", &row);
			}
		}
		printf("Column:");
		scanf("%d", &column);
		if(column < 1 || column > 3)
		{
			while(column < 1 || column > 3)
			{
				printf("Game is 3x3.\n");
				scanf("%d", &column);
			}
		}
		if(checkfortaken(board, row, column) == 1)
		{
			while(checkfortaken(board, row, column) == 1)
			{
				printf("Spot taken. Try another one!\n");
				printf("Row: ");
				scanf("%d", &row);
				if(row < 1 || row > 3)
				{
					while(row < 1 || row > 3)
					{
						printf("Game is 3x3.\n");
						scanf("%d", &row);
					}
				}
				printf("Column:");
				scanf("%d", &column);
				if(column < 1 || column > 3)
				{
					while(column < 1 || column > 3)
					{
						printf("Game is 3x3.\n");
						scanf("%d", &column);
					}
				}
			}
			checkfortaken(board, row, column);
			fillboard(board, row, column, 'X');
		}
		else
		{
			fillboard(board, row, column, 'X');
		}
		drawboard(board);
		if(checkforwinner(board) == 1)
		{
			printf("Player 1 won. Congratulations! :D");
			gamestatus = 0;
			break;
		}
		else if(checkforwinner(board) == 9)
		{
			printf("It's a draw!");
			gamestatus = 0;
			break;
		}
		printf("Player 2's turn.\n");
		printf("Where do you want to put O?\n");
		printf("Row: ");
		scanf("%d", &row);
		if(row < 1 || row > 3)
		{
			while(row < 1 || row > 3)
			{
				printf("Game is 3x3.\n");
				scanf("%d", &row);
			}
		}
		printf("Column:");
		scanf("%d", &column);
		if(column < 1 || column > 3)
		{
			while(column < 1 || column > 3)
			{
				printf("Game is 3x3.\n");
				scanf("%d", &column);
			}
		}
		if(checkfortaken(board, row, column) == 1)
		{
			while(checkfortaken(board, row, column) == 1)
			{
				printf("Spot taken. Try another one!\n");
				printf("Row: ");
				scanf("%d", &row);
				if(row < 1 || row > 3)
				{
					while(row < 1 || row > 3)
					{
						printf("Game is 3x3.\n");
						scanf("%d", &row);
					}
				}
				printf("Column:");
				scanf("%d", &column);
				if(column < 1 || column > 3)
				{
					while(column < 1 || column > 3)
					{
						printf("Game is 3x3.\n");
						scanf("%d", &column);
					}
				}
			}
			checkfortaken(board, row, column);
			fillboard(board, row, column, 'O');
		}
		else
		{
			fillboard(board, row, column, 'O');
		}
		drawboard(board);
		if(checkforwinner(board) == 1)
		{
			printf("Player 2 won. Congratulations! :D");
			gamestatus = 0;
			break;
		}
		else if(checkforwinner(board) == 9)
		{
			printf("It's a draw!");
			gamestatus = 0;
			break;
		}
		printf("Player 1's turn.\n");
	}

}

void drawboard(char board[WIDTH][LENGTH])
{
	for(int i = 0; i < WIDTH; i++)
	{
		for(int j = 0; j < LENGTH; j++)
		{
			if(board[i][j] == '\0')
			{
				board[i][j] = '-';
			}
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}
void fillboard(char board[WIDTH][LENGTH], int c, int r, char symbol)
{
	board[c-1][r-1] = symbol;

}

int checkfortaken(char board[WIDTH][LENGTH], int c, int r)
{
	int taken = 0;
	if(board[c-1][r-1] == 'X' || board[c-1][r-1] == 'O')
	{
		taken = 1;
	}
	else
	{
		return taken;
	}
	return taken;
}

int checkforwinner(char board[WIDTH][LENGTH])
{
	int winner = 0;
	int draw_count = 0;
	// if there is a winner
	for(int i = 0; i < 3; i++)
	{
		if((board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') || (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O'))
		{
			winner = 1;  // set winner 1 if row is x or o
		}
	}

	for(int j = 0; j < 3; j++)
	{
		if((board[0][j] == 'X' && board[1][j] == 'X' && board[2][j] == 'X') || (board[0][j] == 'O' && board[1][j] == 'O' && board[2][j] == 'O'))
		{
			winner = 1; // set winner 1 if column is x or o
		}
	}

		if((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'))
		{
			winner = 1; // set winner 1 if diagonal left to right is x or o
		}
		else if((board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
		{
			winner = 1; // set winner 1 if diagonal right to left is x or o
		}
	// it it's a draw
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if(board[i][j] == 'X' || board[i][j] == 'O')
				{
					draw_count++;
					if(draw_count == 9)
					{
						return draw_count;
					}
				}
			}
		}


	return winner;
}



