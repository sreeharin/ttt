#ifndef GAME_H
#define GAME_H

#define C_MAX -3
#define P_MAX 3

struct scores
{
	int row[3];
	int col[3];
	int diagonal[2];
};

static inline int diff(int, int);
struct scores *calculate_scores(int *);
void optimum_move(int *);
void counter_move(void);

#endif
