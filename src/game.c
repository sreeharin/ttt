#include "game.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>

static inline int
diff(int score, int player)
{
	/*
	 * P_MAX -> 3
	 * C_MAX -> -3
	 * */
	return (player == 1) ? P_MAX - score : C_MAX - score;
}

struct scores *
calculate_scores(int *board)
{
	struct scores *tmp_scores = malloc(sizeof(struct scores *));
	tmp_scores->row[0] = sum_x(board, 0);
	tmp_scores->row[1] = sum_x(board, 1);
	tmp_scores->row[2] = sum_x(board, 2);

	tmp_scores->col[0] = sum_y(board, 0);
	tmp_scores->col[1] = sum_y(board, 1);
	tmp_scores->col[2] = sum_y(board, 2);

	tmp_scores->diagonal[0] = sum_diagonal(board, -1);
	tmp_scores->diagonal[1] = sum_diagonal(board, 1);

	return tmp_scores;
}

void
optimum_move(int *board)
{
	struct scores *_scores = calculate_scores(board);
	printf("row 0 => %d\n", _scores->row[0]);
	printf("row 1 => %d\n", _scores->row[1]);
	printf("row 2 => %d\n", _scores->row[2]);
	
	printf("col 0 => %d\n", _scores->col[0]);
	printf("col 1 => %d\n", _scores->col[1]);
	printf("col 2 => %d\n", _scores->col[2]);
	
	printf("diagonal 0 => %d\n", _scores->diagonal[0]);
	printf("diagonal 1 => %d\n", _scores->diagonal[1]);

}

void
counter_move(void)
{
	printf("Counter\n");
}
