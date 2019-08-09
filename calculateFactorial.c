#include <stdio.h>
#include <cs50.h>

int getNaturalInt(string msg);
int calcFactorial(int naturalNumber);

int main(void)
{
    int naturalNumber = getNaturalInt("Enter a number: ");
    int resultOfFactorial = calcFactorial(naturalNumber);
    printf("Factorial is: %i\n", resultOfFactorial);
}

int getNaturalInt(string msg) {
    int naturalInt = 0;
    do {
        naturalInt = get_int("%s", msg);
    } while (naturalInt <= 0);
    return naturalInt; 
}

int calcFactorial(int naturalNumber) {
    int resultOfFactorial = 1;
    for (int i = 1; i <= naturalNumber; i++) {
        resultOfFactorial *= i;
        }
    return resultOfFactorial;
}


