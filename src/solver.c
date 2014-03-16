/*
 * solver.c
 *
 *  Created on: Mar 11, 2014
 *      Author: luiseduardobrito
 */

#include <math.h>
#include "solver.h"

int is_available(int puzzle[][BSIZE], int row, int col, int num) {
	int rowStart = (row / 3) * 3;
	int colStart = (col / 3) * 3;

	int i;

	for (i = 0; i < 9; ++i) {
		if (puzzle[row][i] == num)
			return 0;
		if (puzzle[i][col] == num)
			return 0;
		if (puzzle[rowStart + (i % 3)][colStart + (i / 3)] == num)
			return 0;
	}
	return 1;
}

int calculate_possibilities(int puzzle[][BSIZE], int row, int col) {
	int possible = 0;
	int count = 0;
	int i;

	for (i = 1; i < 10; i++) {
		if (is_available(puzzle, row, col, i)) {
			possible += i * pow(10, count);
			count++;
		}
	}

	return possible;
}

void hint_sudoku(int puzzle[][BSIZE]) {
	int i, j; //auxiliares
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (!puzzle[i][j]) {
				puzzle[i][j] = calculate_possibilities(puzzle, i, j);
			}
		}
	}
}

int solve_sudoku(int puzzle[][BSIZE], int row, int col) {
	int i;
	if (row < 9 && col < 9) {
		if (puzzle[row][col]) {
			if ((col + 1) < 9)
				return solve_sudoku(puzzle, row, col + 1);
			else if ((row + 1) < 9)
				return solve_sudoku(puzzle, row + 1, 0);
			else
				return 1;
		} else {
			for (i = 0; i < 9; ++i) {
				if (is_available(puzzle, row, col, i + 1)) {
					puzzle[row][col] = i + 1;
					if ((col + 1) < 9) {
						if (solve_sudoku(puzzle, row, col + 1))
							return 1;
						else
							puzzle[row][col] = 0;
					} else if ((row + 1) < 9) {
						if (solve_sudoku(puzzle, row + 1, 0))
							return 1;
						else
							puzzle[row][col] = 0;
					} else
						return 1;
				}
			}
		}
		return 0;
	} else
		return 1;
}
