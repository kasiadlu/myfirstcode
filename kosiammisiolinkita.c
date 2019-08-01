#include <stdio.h>
#include <cs50.h>

int main(void) {
    
    int number = get_int("Enter a number between 0 and 2: ");
    
    if (number == 1) {
        printf("Wesołych Świąt!\n");
    } else if (number == 2) {
        printf("Kosiam Misiolinka!\n");
    } else if (number == 0) {
        exit(0);
    } else {
        main();
    }
}
