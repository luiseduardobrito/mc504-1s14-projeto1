/*
 * checker.h
 *
 *  Created on: Mar 9, 2014
 *      Author: luiseduardobrito
 */

#include "const.h"

#ifndef CHECKER_H_
#define CHECKER_H_

int check(board[BSIZE][BSIZE]);

int check_lines(board[BSIZE][BSIZE]);

int check_columns(board[BSIZE][BSIZE]);

int check_blocks(board[BSIZE][BSIZE]);

int check_line_thr(line[BSIZE]);

int check_column_thr(line[BSIZE]);

int check_block_thr(line[BSIZE]);

#endif /* CHECKER_H_ */
