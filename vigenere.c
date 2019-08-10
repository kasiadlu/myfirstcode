/*
 * main.c
 *
 *  Created on: 10 sie 2019
 *      Author: kbdlu
 */

#include <stdio.h>
#include "cs50.h"
#include <math.h>
#include <string.h>
#include <ctype.h>

int strLen(string s);
int getCipherNumberOfChar(char c);
char changeToCiphertext(char letter, int k);

int main(void) {

	string plaintext = get_string("Plaintext: ");
	int plaintextLength = strLen(plaintext);
	string key = get_string("Type key: ");
	int keyLentgh = strLen(key);

	int j = -1;
	for(int i = 0; i < plaintextLength; i++) {
		if(isupper(plaintext[i]) || islower(plaintext[i])) {
			j++;
		} // to wpisujemy po to zeby szyfrowanie zatrzymywalo sie na spacjach i znakach specjalnych oraz cyferkach i wszystkim co nie jest literka
		char cipherLetter = key[j % keyLentgh];
		int cipherNumber = getCipherNumberOfChar(cipherLetter);
		printf("plaintext[i]: %c, cipherLetter: %c, cipherNumber: %d", plaintext[i], cipherLetter, cipherNumber);
		plaintext[i] = changeToCiphertext(plaintext[i], cipherNumber);
		printf("plaintext[i] after ciphering: %c\n", plaintext[i]);
	}
	printf("%s", plaintext);
}

int strLen(string s) {
	int n = 0;
	for (int i = 0; s[i] != 0; i++) {
		n++;
	}
	return n;
}

int getCipherNumberOfChar(char c) {
	if (islower((int) c)) {
		return c - 97;
	} else if (isupper((int) c)) {
		return c - 65;
	} else {
		return 0;
	}
}

char changeToCiphertext(char letter, int k) {
	int k26 = k % 26; // sprawdzenie czy kluczy szyfrujący nie przesunie się poza alfabet, który ma 26 liter
	int keyAdded = letter + k26; // bazowy kod zaszyfrowanego znaku, który należy poniżej sprawdzić czy mieści się w alfabecie
	if (islower((int) letter)) { // jeżeli letter[i] mieści się w alfabecie małych liter
		if (keyAdded > 122) { // jeżeli keyadded wyskoczyło poza alfabet
			int leftReminder = 122 - letter; // policz różnice między ostatnią literką alfabetu z lewej strony i naszym znakiem który chcemy zaszyfrować
			int rightReminder = k26 - leftReminder - 1; // policz róznicę między ilością znaków o jaką musimy zaszyfrować letter[i] a ilością znaków z poprzedniej strony alfabetu pomniejszoną o 1
			letter = 97 + rightReminder;
		} else { // gdy nie wyszliśmy poza alfabet
			letter = keyAdded;
		}
	} else if (isupper((int) letter)){ // jeżeli letter[i] miesci się w alfabefie wielkich liter
		if (keyAdded > 90) {
			int leftReminder = 90 - letter;
			int rightReminder = k26 - leftReminder - 1;
			letter = 65 + rightReminder;
		} else {
			letter = keyAdded;
		}
	}
	return letter;
}
