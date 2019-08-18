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
	float x = 0;
	do {
		x = get_float("Enter a number: ");
	} while (x == 0);

	float result = sin(1 / x);
	printf("Value of sin(1/%f) is %.4f\n", x, result);

}
