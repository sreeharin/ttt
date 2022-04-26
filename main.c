#include "board.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>

int
main() 
{

	int *board = calloc(sizeof(int), 9);

	insert(board, 0, 1);
	insert(board, 1, 1);
	/* insert(board, 2, 1); */

	insert(board, 3, -1);
	/* insert(board, 4, -1); */
	/* insert(board, 5, -1); */

  	draw_board(board);
	optimum_move(board);

  	free(board);
 	return 0;
}
