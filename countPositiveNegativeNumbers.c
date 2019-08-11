/*
 * main.c
 *
 *  Created on: 10 sie 2019
 *      Author: kbdlu
 */

#include <stdio.h>
#include "cs50.h"
#include <string.h>

void program();

#define Q_NUM 5

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
	int counterPositive = 0;
	int counterNegative = 0;
	int counterZeros = 0;
	for (int i = 0; i < Q_NUM; i++) {
		printf("%d integer ", i + 1);
		int number = get_int("input: ");
		if (number > 0) {
			counterPositive++;
		} else if (number < 0) {
			counterNegative++;
		} else {
			counterZeros++;
		}
	}
	printf("Number of positive numbers: %d\n", counterPositive);
	printf("Number of negative numbers: %d\n", counterNegative);
	printf("Number of zeros: %d\n", counterZeros);
}

