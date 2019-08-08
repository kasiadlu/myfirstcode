#include <stdio.h>
#include <cs50.h>
#include <string.h>

int getNumberOfDigits(long cardNum);
void checkValidity(long cardNum);
bool isVisa (long cardNum);
bool isVisaValid (long cardNum, int numberOfDigits);
bool isAmex (long cardNum);
bool isAmexValid (long cardNum);
bool isMasterCard (long cardNum);
bool isMasterCardValid (long cardNum);
int shittyBackwardsEvenSum(int digits[], int size);
int multiplyBy2AndIfBiggerThan10ReturnDigitsSum(int digit);
int normalBackwardsOddNumberSum(int digits[], int size);


int main(void)
{
    long cardNumber = get_long("Card number: ");
    checkValidity(cardNumber);
    return 0;
}


int getNumberOfDigits(long cardNum) {
    int count = 0;
    while(cardNum != 0)
    {
        cardNum = cardNum / 10;
        count++;
    }
    return count;
}

void checkValidity(long cardNum)
{
    string result = "INVALID";
    if (isAmex(cardNum)) {
        if(isAmexValid(cardNum)) {
            result = "AMEX";
        }
    } else if (isVisa(cardNum)) {
        if(isVisaValid(cardNum, getNumberOfDigits(cardNum))) {
            result = "VISA";
        }
    } else if (isMasterCard(cardNum)) {
        if(isMasterCardValid(cardNum)) {
            result = "MASTERCARD";
        }
    }
    printf("%s\n", result);
}

bool isVisa (long cardNum)
{
    int numberOfDigits = getNumberOfDigits(cardNum);
    int previousValue = cardNum;
    while(cardNum > 0)
    {
        previousValue = cardNum;
        cardNum = cardNum / 10;
    }
    return (previousValue == 4) && (numberOfDigits == 13 || numberOfDigits == 16);
}   

bool isVisaValid (long cardNum, int numberOfDigits) {
    const int VISA_MIN_SIZE = 13;
    const int VISA_MAX_SIZE = 16;
    int visaDigits[16] = {};
    int totalSum = -1;
    if (numberOfDigits == VISA_MIN_SIZE) {
        for (int i = VISA_MIN_SIZE - 1; i >= 0; i--) {
            visaDigits[i] = cardNum % 10;
            cardNum /= 10;
        }
        totalSum = shittyBackwardsEvenSum(visaDigits, VISA_MIN_SIZE) + normalBackwardsOddNumberSum(visaDigits, VISA_MIN_SIZE);
    } else if (numberOfDigits == VISA_MAX_SIZE) {
        for (int i = VISA_MAX_SIZE - 1; i >= 0; i--) {
            visaDigits[i] = cardNum % 10;
            cardNum /= 10;
        }
        totalSum = shittyBackwardsEvenSum(visaDigits, VISA_MAX_SIZE) + normalBackwardsOddNumberSum(visaDigits, VISA_MAX_SIZE);
    }
    
    return totalSum % 10 == 0;
}

bool isAmex (long cardNum)
{
    int numberOfDigits = getNumberOfDigits(cardNum);
    int previousValue = cardNum;
    while(cardNum > 10)
    {
        previousValue = cardNum;
        cardNum = cardNum / 10;
    }
    return (previousValue == 34 || previousValue == 37) && (numberOfDigits == 15);
}   

bool isAmexValid (long cardNum) {
    const int AMEX_SIZE = 15;
    int amexDigits[15] = {};
    for (int i = AMEX_SIZE - 1; i >= 0; i--) {
        amexDigits[i] = cardNum % 10;
        cardNum /= 10;
    }
    int totalSum = shittyBackwardsEvenSum(amexDigits, AMEX_SIZE) + normalBackwardsOddNumberSum(amexDigits, AMEX_SIZE);
    return totalSum % 10 == 0;
}

bool isMasterCard (long cardNum)
{
    int numberOfDigits = getNumberOfDigits(cardNum);
    int previousValue = cardNum;
    while(cardNum > 10)
    {
        previousValue = cardNum;
        cardNum = cardNum / 10;
    }
    return (previousValue >= 51 && previousValue <= 55) && (numberOfDigits == 16);
}  

bool isMasterCardValid (long cardNum) {
    const int MC_SIZE = 16;
    int mcDigits[16] = {};
    for (int i = MC_SIZE - 1; i >= 0; i--) {
        mcDigits[i] = cardNum % 10;
        cardNum /= 10;
    }
    int totalSum = shittyBackwardsEvenSum(mcDigits, MC_SIZE) + normalBackwardsOddNumberSum(mcDigits, MC_SIZE);
    return totalSum % 10 == 0;
}

int shittyBackwardsEvenSum(int digits[], int size) {
    int sum = 0;
    for (int i = size - 2; i >= 0; i -= 2) {
        sum += multiplyBy2AndIfBiggerThan10ReturnDigitsSum(digits[i]);
    }
    return sum;
}

int normalBackwardsOddNumberSum(int digits[], int size) {
    int sum = 0;
    for (int i = size - 1; i >= 0; i -= 2) {
        sum += digits[i];
    }
    return sum;
}

int multiplyBy2AndIfBiggerThan10ReturnDigitsSum(int digit) {
    int multipliedDigit = digit * 2;
    if (multipliedDigit >= 10) {
        return 1 + (multipliedDigit % 10);
    } else {
        return multipliedDigit;
    }
} 
