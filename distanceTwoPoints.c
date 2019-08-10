/*
 * main.c
 *
 *  Created on: 10 sie 2019
 *      Author: kbdlu
 */

#include <stdio.h>
#include "cs50.h"
#include <math.h>

double calcDistance(double x1, double x2, double y1, double y2);

int main(void) {
	double x1 = get_int("x1: ");
	double y1 = get_int("y1: ");
	double x2 = get_int("x2: ");
	double y2 = get_int("y2: ");
	printf("Point A is: (%lf,%lf)\n", x1, y1);
	printf("Point B is: (%lf,%lf)\n", x2, y2);

	double distance = calcDistance(x1, x2, y1, y2);
	printf("Distance |AB| is: %lf\n", distance);
}

double calcDistance(double x1, double x2, double y1, double y2) {
	double distance = sqrt((pow((x2 - x1), 2)) + (pow((y2 - y1), 2)));
	return distance;

}
