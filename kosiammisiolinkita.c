#include <stdio.h>
#include <cs50.h>

int main(void) {
    
    int number = 0;
    
    do {
        number = get_int("Enter a number between 0 and 2: ");
        if (number == 1) {
            printf("Wesołych Świąt!\n");
        } else if (number == 2) {
            printf("Kosiam Misiolinka!\n");
        }
    } while (number != 0);
        
}
