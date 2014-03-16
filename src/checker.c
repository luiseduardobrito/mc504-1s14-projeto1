/*
 * checker.c
 *
 *  Created on: Mar BSIZE, 2014
 *      Author: luiseduardobrito
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "const.h"
#include "checker.h"

pthread_t thr_lines[BSIZE];

void check_board(int puzzle[BSIZE][BSIZE]) {
	check_lines(puzzle);
	check_columns(puzzle);
	check_blocks(puzzle);
}

int partition(int a[], int l, int r) {
	int pivot, i, j, t;
	pivot = a[l];
	i = l;
	j = r + 1;

	while (1) {
		do
			++i;
		while (a[i] <= pivot && i <= r);
		do
			--j;
		while (a[j] > pivot);
		if (i >= j)
			break;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	t = a[l];
	a[l] = a[j];
	a[j] = t;
	return j;
}

void quickSort(int a[], int l, int r) {
	int j;

	if (l < r) {
		// divide and conquer
		j = partition(a, l, r);
		quickSort(a, l, j - 1);
		quickSort(a, j + 1, r);
	}
}

void findError(int aux[9]) {

	int i;

	//ordena o vetor
	quickSort(aux, 0, 8);

	//acha numeros repetidos e fora do intervalo
	for (i = 0; i < 9; i++) {
		if (aux[i] > 9 || aux[i] < 1) {
			printf("Número %d fora do intervalo definido", aux[i]);
		}

		if (aux[i] == aux[i + 1]) {
			printf("Número %d repetido", aux[i]);
		}
	}

}

void check_lines(int puzzle[BSIZE][BSIZE]) {
	int row, col;
	int aux[BSIZE];

	for (row = 0; row < BSIZE; row++) {
		for (col = 0; col < BSIZE; col++) {
			aux[col] = puzzle[row][col];
		}
		findError(aux);
	}
}

void check_columns(int puzzle[BSIZE][BSIZE]) {
	int row, col;
	int aux[BSIZE];

	for (col = 0; col < BSIZE; col++) {
		for (row = 0; row < BSIZE; row++) {
			aux[row] = puzzle[row][col];
		}
		findError(aux);
	}
}

void check_blocks(int puzzle[BSIZE][BSIZE]) {

	int i;

	int rowStart = 0, colStart = 0;
	int aux[BSIZE];

	for (rowStart = 0; rowStart < 7; rowStart += 3) {
		for (colStart = 0; colStart < 7; colStart += 3) {
			for (i = 0; i < BSIZE; i++) {
				aux[i] = puzzle[rowStart + (i % 3)][colStart + (i / 3)];
			}
			findError(aux);
		}
	}
}
