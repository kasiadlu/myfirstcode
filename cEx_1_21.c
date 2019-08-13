/*
 * main.c
 *
 *  Created on: 10 sie 2019
 *      Author: kbdlu
 */

#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include "math.h"

void program();

#define SIZE 5

int main(void) {
	do {
		string command = get_string("Input \'y\' to open a program, anything other for exit: ");
		if (command[0] == 'y') {
			program();
		} else {
			return 0;
		}
	} while (true);
}

void program() {
	int array[SIZE] = {};
	array[0] = get_int("Enter a number: ");
	printf("Array values are:\n");
	printf("n[0] = %d\n", array[0]);
	for(int i = 1; i < SIZE; i++) {
		array[i] = array[i - 1] * 3;
		printf("n[%d] = %d\n", i, array[i]);
	}
}
