/*
 * solver.h
 *
 *  Created on: Mar 11, 2014
 *      Author: luiseduardobrito
 */

#ifndef SOLVER_H_
#define SOLVER_H_

#include "const.h"

#include <stdio.h>
#include <math.h>

int is_available(int puzzle[][BSIZE], int row, int col, int num);
int calculate_possibilities(int puzzle[][BSIZE], int row, int col);
void hint_sudoku(int puzzle[][BSIZE]);
int solve_sudoku(int puzzle[][BSIZE], int row, int col);

#endif /* SOLVER_H_ */
