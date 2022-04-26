#ifndef BOARD_H
#define BOARD_H

char player(int);
void draw_board(int *);
void insert(int *, int, int);
int sum_x(int *, int);
int sum_y(int *, int);
int sum_diagonal(int *, int);
int available_spaces(int *, int *, int *);

#endif
