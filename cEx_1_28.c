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
	int number = 0;
	do {
		number = get_int("Enter a number between 1 - 500: ");
	} while (number <= 1 && number >= 500);

	int decimal1 = number % 10;
	printf("Dec1: %d\n", decimal1);
	int decimal2 = (number / 10) % 10;
	printf("Dec2: %d\n", decimal2);
	int decimal3 = (number / 100) % 10;
	printf("Dec3: %d\n", decimal3);

	int sumOfDigits = decimal1 + decimal2 + decimal3;
	printf("Sum of digits of %d is %d\n", number, sumOfDigits);
}
