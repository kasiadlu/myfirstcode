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

#define SIZE 4

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
	float value = get_float("Enter a number: ");
	float maxValue = value;
	float minValue = value;
	for(int i = 0; i < SIZE - 1; i++) {
		float value = get_float("Enter a number: ");
		if(value < minValue) {
			minValue = value;
		} else if(value > maxValue) {
			maxValue = value;
		}
	}
	printf("Min. value: %.4f\n", minValue);
	printf("Max. value: %.4f\n", maxValue);

	float difference = maxValue - minValue;
	printf("Difference is: %.4f\n", difference);
}
