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

int getPositiveInt(string msg);
int howManyHours(int secondsGiven);
int countWhatLeftOfHours(int secondsGiven);
int howManyMinutes(int whatLeftOfHours);
int howManySeconds (int whatLeftOfHours);

int main(void) {
	int secondsGiven = getPositiveInt("Enter a number of seconds: ");
	int hours = howManyHours(secondsGiven);
	int whatLeftOfHours = countWhatLeftOfHours(secondsGiven);
	int minutes = howManyMinutes(whatLeftOfHours);
	int seconds = howManySeconds(whatLeftOfHours);
	printf("H: %d M: %d S: %d", hours, minutes, seconds);
}

int getPositiveInt(string msg) {
	    int positiveInt = 0;
	    do {
	        positiveInt = get_int("%s", msg);
	    } while (positiveInt <= 0);
	    return positiveInt;
	}

int howManyHours(int secondsGiven) {
		int hours = secondsGiven / 3600;
		return hours;
}

int countWhatLeftOfHours(int secondsGiven) {
		int whatLeftOfHours = secondsGiven % 3600;
		return whatLeftOfHours;
}

int howManyMinutes(int whatLeftOfHours) {
		int minutes = whatLeftOfHours / 60;
		return minutes;
}

int howManySeconds (int whatLeftOfHours) {
		int seconds = whatLeftOfHours % 60;
		return seconds;
}
