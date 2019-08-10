/*
 * main.c
 *
 *  Created on: 10 sie 2019
 *      Author: kbdlu
 */

#include <stdio.h>
#include "cs50.h"
#include <string.h>

int getPositiveInt(string msg);
int howManyYears(int number);
int howManyWeeks(int number);
int howManyDaysLeft(int number);

int main(void) {
	int numberOfDays = getPositiveInt("Number of days: ");
	int numberOfYears = howManyYears(numberOfDays);
	printf("Years: %d\n", numberOfYears);
	int numberOfWeeks = howManyWeeks(numberOfDays);
	printf("Weeks: %d\n", numberOfWeeks);
	int numberOfDaysLeft = howManyDaysLeft(numberOfDays);
	printf("Days: %d\n", numberOfDaysLeft);
}

int getPositiveInt(string msg) {
    int positiveInt = 0;
    do {
        positiveInt = get_int("%s", msg);
    } while (positiveInt <= 0);
    return positiveInt;
}

int howManyYears(int number) {
	int numberOfYears = number / 365;
	return numberOfYears;
}

int howManyWeeks(int number) {
	int numberOfWeeks = (number % 365) / 7;
	return numberOfWeeks;
}

int howManyDaysLeft(int number) {
	int numberOfDaysLeft = (number % 365) % 7;
	return numberOfDaysLeft;
}
