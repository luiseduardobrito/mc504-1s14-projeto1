#include <stdio.h>
#include <stdlib.h>

#include "src/const.h"

void print_board(int board[BSIZE][BSIZE]) {

	int i, j;

	for (i = 0; i < BSIZE; i++) {

		printf("\n");

		for (j = 0; j < BSIZE; j++)
			printf("%d ", board[i][j]);
	}
}

int main() {

	int i, j;

	int board[BSIZE][BSIZE];

	// Inicializa quadro com zeros
	for (i = 0; i < BSIZE; i++)
		for (j = 0; j < BSIZE; j++)
			scanf("%d ", &board[i][j]);

	print_board(board);

	if(check(board))
		printf("\n\n valido");
	else
		printf("\n\n invalido");

	return 0;
}
