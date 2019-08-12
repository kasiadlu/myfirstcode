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


bool strCompare(string corPass, string pass);
int strLen(string word);

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

	string correctPassword = "kupka";
	string password = get_string("Enter a password: ");
	if(strCompare(correctPassword, password)) {
		printf("Correct password. You're welcome\n");
	} else {
		printf("Incorrect password\n");
	}
}

bool strCompare(string corPass, string pass) {
	int passLentgh = strLen(pass);
	int corPassLentgh = strLen(corPass);
	if(passLentgh == corPassLentgh) {
		for(int i = 0; corPass[i] != 0; i++) {
			if(corPass[i] != pass[i]) {
				return false;
			}
		}
		return true;
	} else {
		return false;
	}

}

int strLen(string word) {
	int counter = 0;
	for(int i = 0; word[i] != 0; i++) {
		counter++;
	}
	return counter;
}
