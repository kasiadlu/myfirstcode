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
	for(int i = 0; i < SIZE; i++) {
		array[i] = get_int("Enter a value: ");
	}
	int smallestElement = array[0];
	int position = 0;
	for(int i = 0; i < SIZE; i++) {
		if(array[i] < smallestElement) {
			smallestElement = array[i];
			position = i;
		}
	}
	printf("Smallest element: %i\n", smallestElement);
	printf("Position of the element: %i\n", position);
}
