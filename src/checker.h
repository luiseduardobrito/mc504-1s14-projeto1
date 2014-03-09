/*
 * checker.h
 *
 *  Created on: Mar 9, 2014
 *      Author: luiseduardobrito
 */

#include <pthread.h>

#include "const.h"

#ifndef CHECKER_H_
#define CHECKER_H_

int check(int board[BSIZE][BSIZE]);

int check_lines(int board[BSIZE][BSIZE]);

int check_columns(int board[BSIZE][BSIZE]);

int check_blocks(int board[BSIZE][BSIZE]);

void* check_line_thr(void* line[BSIZE]);

void* check_column_thr(int line[BSIZE]);

void* check_block_thr(int line[BSIZE]);

#endif /* CHECKER_H_ */
