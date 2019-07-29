#include <stdio.h>

int power(int base, int exponent);

int main(void) {
    int a = 10;
    int b = 0;
    int c = power(a, b);
    printf("Result: %i\n", c);
 
}

int power(int base, int exponent) {
    int result = 1;
    for(int i = 0; i < exponent; i++) {
        result = result * base; 
    }
    return result;
}
    

