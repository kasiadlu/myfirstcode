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
	int number = get_int("Enter a number: ");
	int divisor = 1;
	for (int i = -2147483647; i <= number; i++) {
		if(number % divisor == 0) {
			printf("%d\n", divisor);
		}
		divisor++;
	}
}

