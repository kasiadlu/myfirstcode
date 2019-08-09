#include <stdio.h>
#include <cs50.h>
#include <string.h>

int strLen(string s);
string doBackwardString(string word);

int main(void){
    string word = get_string("Enter a word: ");
    printf("%s", doBackwardString(word));
    printf("\n");
}

int strLen(string s) {
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        n++;
    }
    return n;
}

string doBackwardString(string word) {
    int size = strLen(word);
    for (int i = 0; i < (size / 2); i++) { // size / 2 - ponieważ dochodzimy tylko do połowy wyrazu, druga połowa się samoistnie podmienia 
        char temp = word[i]; // tworzymy zmienną temp, która przechowuje wartość, która zaraz zostanie nadpisana
        word[i] = word[size - i - 1]; // nadpisujemy word[i] wartością z przeciwnej strony
        word[size - i - 1] = temp; // ponieważ pod word[i] nie ma poprzedniego znaku, przypisujemy wartość temp, ponieważ on ją posiada
    }
    return word;
}
