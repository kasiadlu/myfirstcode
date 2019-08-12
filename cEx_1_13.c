/*
 * main.c
 *
 *  Created on: 10 sie 2019
 *      Author: kbdlu
 */

#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <math.h>

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
	int startValue = 0;
	int value = get_int("Enter a value: ");
	for (int i = 0; i < 100; i++) {
		startValue++;
		if (startValue % value == 3) {
			printf("%d\n", startValue);
		}
	}



}
