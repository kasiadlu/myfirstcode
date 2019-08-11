#include <stdio.h>
#include "cs50.h"

#define Q_NUM 5

int main(void) {
	int tempNumber = 0;
	for (int i = 0; i < Q_NUM; i++) {
		printf("%d integer ", i + 1);
		int number = get_int("input: ");
		if (number % 2 != 0) {
			tempNumber = tempNumber + number;
		}
	}
	printf("Sum of all odd values: %d\n", tempNumber);
}
