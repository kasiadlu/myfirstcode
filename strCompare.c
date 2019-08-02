#include <stdio.h>
#include <cs50.h>
#include <string.h>

int strLen(string s);
bool isEqual(string s1, string s2);

int main(void) {
    
    string str1 = get_string("Type something: \n");
    string str2 = get_string("Type something again: \n");
    
        
    if(isEqual(str1, str2)) {
        printf("It's the same!\n");
    } else {
        printf("It's not the same!\n");        
    }
}

int strLen(string s) {
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        n++;
    }
    return n;
}

bool isEqual(string s1, string s2) {
    int n1 = strLen(s1);
    int n2 = strLen(s2);
    if (n1 == n2) {
        for (int i = 0; i < n1; i++) {
            if (s1[i] != s2[i]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}




