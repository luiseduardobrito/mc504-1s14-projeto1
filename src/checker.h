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

void check_board(int puzzle[BSIZE][BSIZE]);

void check_lines(int puzzle[BSIZE][BSIZE]);

void check_columns(int puzzle[BSIZE][BSIZE]);

void check_blocks(int puzzle[BSIZE][BSIZE]);

void* check_line_thr(void* line[BSIZE]);

void* check_column_thr(int line[BSIZE]);

void* check_block_thr(int line[BSIZE]);

#endif /* CHECKER_H_ */
