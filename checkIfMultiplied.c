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
bool checkIfMultiplied(int a, int b);

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
	int firstNumber = get_int("Input the first number: ");
	int secondNumber = get_int("Input the second number: ");

	if (checkIfMultiplied(firstNumber, secondNumber)) {
		printf("Multiplied!\n");
	}
}


bool checkIfMultiplied(int a, int b) {
	if (b % a == 0 || a % b == 0) {
		return true;
	} else {
		printf("Not multipliedl\n");
		return false;
	}
}
