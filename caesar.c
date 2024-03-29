#include <cs50.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int strLen(string s);
bool isInteger(string dupa);
string changeToCiphertext(string plaintext, int k);

int main(int argc, string argv[])
{
    
    if (argc == 2 && isInteger(argv[1])) {
        int k = atoi(argv[1]);
        string plaintext = get_string("plaintext: ");
        string ciphertext = changeToCiphertext(plaintext, k);
        printf("ciphertext: %s\n", ciphertext);
    } else {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

int strLen(string s) 
{
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        n++;
    }
    return n;
}

bool isInteger(string dupa) 
{
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

string changeToCiphertext(string plaintext, int k)
{
    int lentgh = strLen(plaintext);
    
    for (int i = 0; i < lentgh; i++) {
        int k26 = k % 26; // sprawdzenie czy kluczy szyfrujący nie przesunie się poza alfabet, który ma 26 liter
        int keyAdded = plaintext[i] + k26; // bazowy kod zaszyfrowanego znaku, który należy poniżej sprawdzić czy mieści się w alfabecie
        if (plaintext[i] >= 97 && plaintext[i] <= 122) { // jeżeli plaintext[i] mieści się w alfabecie małych liter
           if (keyAdded > 122) { // jeżeli keyadded wyskoczyło poza alfabet
            int leftReminder = 122 - plaintext[i]; // policz różnice między ostatnią literką alfabetu z lewej strony i naszym znakiem który chcemy zaszyfrować 
            int rightReminder = k26 - leftReminder - 1; // policz róznicę między ilością znaków o jaką musimy zaszyfrować plaintext[i] a ilością znaków z poprzedniej strony alfabetu pomniejszoną o 1
            plaintext[i] = 97 + rightReminder;
           } else { // gdy nie wyszliśmy poza alfabet
            plaintext[i] = keyAdded; 
           }
        } else if (plaintext[i] >= 65 && plaintext[i] <= 90){ // jeżeli plaintext[i] miesci się w alfabefie wielkich liter
            if (keyAdded > 90) {
            int leftReminder = 90 - plaintext[i];
            int rightReminder = k26 - leftReminder - 1;
            plaintext[i] = 65 + rightReminder;
            } else {
            plaintext[i] = keyAdded;
            }
        } else {
            plaintext[i] = plaintext[i];
        } 
    }
    return plaintext;          
}
