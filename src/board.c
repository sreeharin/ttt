#include "board.h"
#include <stdio.h>
#include <assert.h>

/*
 * board
 * ------
 *
 * | 0 | 1 | 2 |
 * | 3 | 4 | 5 |
 * | 6 | 7 | 8 |
 *
 * players
 * -------
 *
 *  X : human
 *	O : computer
 * 
 * */

char
player(int no)
{
	char player = (no == -1) ? 'O' : (no == 1) ? 'X' : '0';
	return player;
}

void 
draw_board(int *board)
{
	for (int i = 0; i < 9; i++) 
		{
    		((i + 1) % 3 == 0) ?
				printf("| %c |\n", player(*(board + i))) :
				printf("| %c ", player(*(board + i)));
  		}
}

void 
insert(int *board, int index, int player) 
{
	assert(index >= 0 && index <= 8);
	board[index] = player; 
}

int 
sum_x(int *board, int row) 
{
  	/*
   	* 0 -> 0, 1, 2
   	* 1 -> 3, 4, 5
   	* 2 -> 6, 7, 8
   	* */

	assert(row >= 0 && row <= 2);

  	int sum = 0;

  	if (row == 0) 
	{
    	sum = board[0] + board[1] + board[2];
  	} else if (row == 1) 
	{
    	sum = board[3] + board[4] + board[5];
  	} else if (row == 2) 
	{
    	sum = board[6] + board[7] + board[8];
  	}

  	return sum;
}

int 
sum_y(int *board, int column) 
{
  	/*
   	* 0 -> 0, 3, 6
   	* 1 -> 1, 4, 7
   	* 2 -> 2, 5, 8
   	* */
	
	assert(column >= 0 && column <= 2);

  	int sum = 0;
  	if (column == 0) 
	{
    	sum = board[0] + board[3] + board[6];
  	} else if (column == 1) 
	{
    	sum = board[1] + board[4] + board[7];
  	} else if (column == 2) 
	{
    	sum = board[2] + board[5] + board[8];
  	}

 	 return sum;
}

int
sum_diagonal(int *board, int diagonal)
{
	/*
	 *
	 * Diagonals
	 * ---------
	 *  -1 : Left to Right
	 *  0, 4, 8
	 *
	 *  1 : Right to Left
	 *	2, 4, 6
	 *
	 * */
	
	assert(diagonal == -1 || diagonal == 1);

	int sum = 0;
	if(diagonal == -1)
	{
		sum = board[0] + board[4] + board[8]; 
	}else if(diagonal == 1)
	{
		sum = board[2] + board[4] + board[6];
	}

	return sum;
}

int 
available_spaces(int *board, int *tmp_array, int *size)
{
	int count = 0;
	for(int i = 0; i < 9; i++)
	{
		if(*(board+i) == 0)
		{
			*(tmp_array + count++) = i;
		}
	}
	*size = count;
}

