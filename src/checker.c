/*
 * checker.c
 *
 *  Created on: Mar 9, 2014
 *      Author: luiseduardobrito
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "const.h"
#include "checker.h"

pthread_t thr_lines[BSIZE];

int check(int board[BSIZE][BSIZE]) {

	if(!check_lines(board))
		return FALSE;

//	if(!check_columns(board))
//		return FALSE;
//
//	if(!check_blocks(board))
//		return FALSE;

	return TRUE;
}

int check_lines(int board[BSIZE][BSIZE]) {

	int i;

	for(i = 0; i < BSIZE; i++)
		pthread_create(&(thr_lines[i]), NULL, &check_line_thr, board[i]);

	for(i = 0; i < BSIZE; i++) {

		int pthread_result;
		pthread_join(thr_lines[i], &pthread_result);

		if(!pthread_result) {
			printf("lines_false ");
			return FALSE;
		}
	}

	return TRUE;
}

int check_columns(int board[BSIZE][BSIZE]){
	return 0;
}

int check_blocks(int board[BSIZE][BSIZE]){
	return 0;
}

void* check_line_thr(void* line[BSIZE]){

	int i, mask[BSIZE];

	for(i = 0; i < BSIZE; i++)
		mask[i] = FALSE;

	for(i = 0; i < BSIZE; i++) {

		int val = (int) line[i];

		if(mask[val - 1]) {
			printf("thr_false ");
			pthread_exit(FALSE);
		}
	}

	pthread_exit(TRUE);
}

void* check_column_thr(int line[BSIZE]){
	return 0;
}

void* check_block_thr(int line[BSIZE]){
	return 0;
}
