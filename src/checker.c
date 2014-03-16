/*
 * checker.c
 *
 *  Created on: Mar BSIZE, 2014
 *      Author: luiseduardobrito
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "const.h"
#include "checker.h"

#define NUM_THREADS	3

char *messages[NUM_THREADS];

int PUZZLE[BSIZE][BSIZE];

int foundError = 0;

struct thread_data {
	int thread_id;
	int type;
};

struct thread_data thread_data_array[NUM_THREADS];

void *check_board_thr(void *thread_args) {

	struct thread_data *my_data = (struct thread_data *) thread_args;
	int type = my_data->type;

	switch (type) {

	case 0:
		check_lines(PUZZLE);
		break;
	case 1:
		check_columns(PUZZLE);
		break;
	case 2:
		check_blocks(PUZZLE);
		break;
	}

	pthread_exit(NULL);
}

void check_board(int puzzle[][BSIZE]) {

	int i, j, rc;

	for (i = 0; i < BSIZE; i++)
		for (j = 0; j < BSIZE; j++)
			PUZZLE[i][j] = puzzle[i][j];

	pthread_t threads[NUM_THREADS];

	for (i = 0; i < NUM_THREADS; i++) {

		thread_data_array[i].thread_id = i;
		thread_data_array[i].type = i;

		printf("Criando thread %d...\n", i + 1);

		rc = pthread_create(&threads[i], NULL, check_board_thr,
				(void *) &thread_data_array[i]);
		if (rc) {
			printf("ERRO: erro de retorno foi %d\n", rc);
			exit(-1);
		}
	}

	for (i = 0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}

	printf("\n\nChecagem completa. ");
	if (!foundError) {
		printf("Nenhum erro encontrado.");
	}
	printf("\n\n");
}

int cmpfunc(const void * a, const void * b) {
	return (*(int*) a - *(int*) b);
}
void quickSort(int a[], int l, int r) {
	qsort(a, BSIZE, sizeof(int), cmpfunc);
}

void findError(int aux[9], int type, int pos) {

	char str[20];

	switch (type) {
		case 1:
			strcpy(str, "na linha");
			break;
		case 2:
			strcpy(str, "na coluna");
			break;

		case 3:
			strcpy(str, "no bloco");
			break;
	}

	int i;

	//ordena o vetor
	quickSort(aux, 0, 8);

	//acha numeros repetidos e fora do intervalo
	for (i = 0; i < 9; i++) {
		if (aux[i] > 9 || aux[i] < 1) {

			printf("Número %d fora do intervalo definido %s de numero %d\n", aux[i],
					str, pos);
			foundError = 1;
		}

		if (i < 8 && aux[i] == aux[i + 1]) {
			printf("Número %d repetido %s de numero %d\n", aux[i], str, pos);
			foundError = 1;
		}
	}
}

void check_lines(int puzzle[][BSIZE]) {

	int row, col;
	int aux[BSIZE];

	for (row = 0; row < BSIZE; row++) {

		// Procura erro na linha atual
		for (col = 0; col < BSIZE; col++) {
			aux[col] = puzzle[row][col];
		}

		// Procura erro na linha atual
		findError(aux, 1, row + 1);
	}
}

void check_columns(int puzzle[][BSIZE]) {
	int row, col;
	int aux[BSIZE];

	for (col = 0; col < BSIZE; col++) {

		// Procura erro na linha atual
		for (row = 0; row < BSIZE; row++) {
			aux[row] = puzzle[row][col];
		}

		// Procura erro na coluna atual
		findError(aux, 2, col + 1);
	}
}

void check_blocks(int puzzle[][BSIZE]) {

	int i;

	int rowStart = 0, colStart = 0, blockNum;
	int aux[BSIZE];

	for (rowStart = 0; rowStart < 7; rowStart += 3) {

		for (colStart = 0; colStart < 7; colStart += 3) {

			for (i = 0; i < BSIZE; i++) {
				aux[i] = puzzle[rowStart + (i % 3)][colStart + (i / 3)];
			}

			blockNum++;

			findError(aux, 3, blockNum);
		}
	}
}
