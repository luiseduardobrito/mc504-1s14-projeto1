/*
 * checker.c
 *
 *  Created on: Mar 9, 2014
 *      Author: luiseduardobrito
 */

#include <stdio.h>
#include <stdlib.h>

#include "const.h"
#include "checker.h"

int check(board[BSIZE][BSIZE]) {

	if(!check_lines(board))
		return 0;

	if(!check_columns(board))
		return 0;

	if(!check_blocks(board))
		return 0;

	return 1;
}

int check_lines(board[BSIZE][BSIZE]) {
	return 0;
}

int check_columns(board[BSIZE][BSIZE]){
	return 0;
}

int check_blocks(board[BSIZE][BSIZE]){
	return 0;
}

int check_line_thr(line[BSIZE]){
	return 0;
}

int check_column_thr(line[BSIZE]){
	return 0;
}

int check_block_thr(line[BSIZE]){
	return 0;
}
