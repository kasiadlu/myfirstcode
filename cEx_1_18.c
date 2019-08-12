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
	int lines = get_int("Number of lines: ");
	int characters = get_int("Number of characters: ");

	int tempNumberOfCharacters = 0;
	for(int i = 0; i < lines; i++) {
		for(int j = 0; j < characters; j++) {
			tempNumberOfCharacters = tempNumberOfCharacters + 1;
			printf("%d ", tempNumberOfCharacters);
		}
	printf("\n");
	}
}

