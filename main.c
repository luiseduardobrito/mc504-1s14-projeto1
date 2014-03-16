#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "src/checker.h"
#include "src/solver.h"

int puzzle[BSIZE][BSIZE];

void printBoard(int board[9][9]) {
	int row, col;
	for (row = 1; row < 10; ++row) {
		for (col = 1; col < 10; ++col) {
			if (board[row - 1][col - 1] < 10) {
				printf("%d ", board[row - 1][col - 1]);
			} else {
				printf("(%d) ", board[row - 1][col - 1]);
			}
		}
		printf("\n");
	}

}

int main() {

	printf("SUDOKU MULTIHTREAD\n\nComandos disponíveis:\n");
	printf("1 )  Checar diagrama\n");
	printf("2 )  Resolver diagrama\n");
	printf("3 )  Modo dica\n\n\nEscolha um comando... ");

	int cmd;
	scanf("%d", &cmd);

	int puzzle[BSIZE][BSIZE], i, j;

	for (i = 0; i < BSIZE; i++)
		for (j = 0; j < BSIZE; j++)
			scanf("%d", &puzzle[i][j]);

	switch(cmd) {
		case 1:
			check_board(puzzle);
			break;
		case 2:

			solve_sudoku(puzzle, 0, 0);
			printf("\n\n\nDiagrama resolvido:\n\n");
			printBoard(puzzle);
			break;

		case 3:
			hint_sudoku(puzzle);

			printf("\n\n\nDiagrama preenchido com dicas:");
			printBoard(puzzle);
			break;
	}

	return 0;
}
