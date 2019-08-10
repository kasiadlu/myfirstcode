/*
 * main.c
 *
 *  Created on: 10 sie 2019
 *      Author: kbdlu
 */

#include <stdio.h>
#include "cs50.h"
#include <math.h>

int getPositiveInt(string msg);
int howManyBanknote100(int money);
int howManyBanknote50(int money);
int howManyBanknote20(int money);
int howManyBanknote10(int money);
int howManyBanknote5(int money);
int howManyBanknote2(int money);
int howManyBanknote1(int money);

int main(void) {

	// Enter amount of money //

	int money = getPositiveInt("Amount of money: ");

	// Do calculations //

	int banknote100 = howManyBanknote100(money);
	int banknote50 = howManyBanknote50(money);
	int banknote20 = howManyBanknote20(money);
	int banknote10 = howManyBanknote10(money);
	int banknote5 = howManyBanknote5(money);
	int banknote2 = howManyBanknote2(money);
	int banknote1 = howManyBanknote1(money);

	// Print how many banknotes of every type do we need//

	printf("%d banknote(s) of 100\n", banknote100);
	printf("%d banknote(s) of 50\n", banknote50);
	printf("%d banknote(s) of 20\n", banknote20);
	printf("%d banknote(s) of 10\n", banknote10);
	printf("%d banknote(s) of 5\n", banknote5);
	printf("%d banknote(s) of 2\n", banknote2);
	printf("%d banknote(s) of 1\n", banknote1);

}

	int getPositiveInt(string msg) {
	    int positiveInt = 0;
	    do {
	        positiveInt = get_int("%s", msg);
	    } while (positiveInt <= 0);
	    return positiveInt;
	}

	int howManyBanknote100(int money) {
		int banknote100 = money / 100;
		return banknote100;
	}

	int howManyBanknote50(int money) {
		int banknote50 = (money % 100) / 50;
		return banknote50;
	}

	int howManyBanknote20(int money) {
		int banknote20 = ((money % 100) % 50) / 20;
		return banknote20;
	}

	int howManyBanknote10(int money) {
		int banknote10 = (((money % 100) % 50) % 20) / 10;
		return banknote10;
	}

	int howManyBanknote5(int money) {
		int banknote5 = ((((money % 100) % 50) % 20) % 10) / 5;
		return banknote5;
	}

	int howManyBanknote2(int money) {
		int banknote2 = (((((money % 100) % 50) % 20) % 10) % 5) / 2;
		return banknote2;
	}

	int howManyBanknote1(int money) {
		int banknote1 = (((((money % 100) % 50) % 20) % 10) % 5) % 2;
		return banknote1;
	}
