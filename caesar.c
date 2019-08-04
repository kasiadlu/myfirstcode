#include <cs50.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int strLen(string s);
bool isInteger(string dupa);

int main(int argc, string argv[])
{
    
    if (argc == 2 && isInteger(argv[1])) {
        int k = atoi(argv[1]);
        printf("Success\n");
        printf("%i\n", k);
    } else {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

int strLen(string s) {
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        n++;
    }
    return n;
}

bool isInteger(string dupa) {
    int lentgh = strLen(dupa);
    for (int i = 0; i < lentgh; i++) {
        if (i == 0 && (int) dupa[0] == 48) {
            return false;
        }
        char a = dupa[i];
        if ((int) a < 48 || (int) a > 57) {
            return false;
        }
    }
    return true;
}
