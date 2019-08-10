/*
 * main.c
 *
 *  Created on: 10 sie 2019
 *      Author: kbdlu
 */

#include <stdio.h>
#include "cs50.h"
#include <string.h>

#define Q_NUM 7

int main(void) {
	int tempMax = -2147483647; // wprowadź zmienną tempMax o wartości najmniejszego możliwego inta
	for (int i = 0; i < Q_NUM; i++) { // wykonaj fora tyle razy ile zmiennych chcesz sprawdzic
		printf("Input integer %d:", i + 1); // podaj wartośc zmiennej
		int a = get_int(" "); // przypisz wartosc do zmiennej a
		if(a > tempMax) { // porownaj wartosc z tempMax
			tempMax = a; // jesli a wieksze niz tempMax przypisz aktualna wartosc a do tempMax
		}
	}
	printf("Maximum value is: %d", tempMax);
}
