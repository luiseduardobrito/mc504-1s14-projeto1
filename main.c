#include <stdio.h>
#include <stdlib.h>

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

	int puzzle[BSIZE][BSIZE], i, j;

	for(i = 0; i < BSIZE; i++)
		for(j = 0; j < BSIZE; j++)
			scanf("%d", &puzzle[i][j]);

	if(!solve_sudoku(puzzle, 0 , 0)) {
		printf("\n\n fudeu");
	}

	else {
		printBoard(puzzle);
	}

	return 0;
}

