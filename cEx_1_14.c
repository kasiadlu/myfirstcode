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

	int startValue = -2147483647;
	int counter = 0;
	for (int i = 0; i < Q_NUM; i++) {
		int value = get_int("Enter a number: ");
		if(value > startValue) {
			startValue = value;
			counter = i + 1;
		}
	}
	printf("Highest value: %d\n", startValue);
	printf("Position: %d\n", counter);

}
