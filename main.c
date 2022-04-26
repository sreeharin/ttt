#include "board.h"
#include <stdio.h>
#include <stdlib.h>

int
main() 
{

	int *board = calloc(sizeof(int), 9);

  	draw_board(board);
	
  	free(board);
 	return 0;
}
