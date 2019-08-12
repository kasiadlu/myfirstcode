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
	float counterPositive = 0;
	float summaryPositive = 0;
	for (int i = 0; i < Q_NUM; i++) {
		printf("%d integer ", i + 1);
		float number = get_float("input: ");
		if (number > 0) {
			counterPositive++;
			summaryPositive = summaryPositive + number;
		}
	}
	float averageOfPositive = summaryPositive / counterPositive;
	printf("Number of positive numbers: %.0f\n", counterPositive);
	printf("Average value of the positive numbers: %.2f\n", averageOfPositive);
}
