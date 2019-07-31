#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

float calcDelta(float parA, float parB, float parC);
float calcZeroPoint1(float parA, float parB, float delta);
float calcZeroPoint2(float parA, float parB, float delta);

int main(void) {
     
    float parameterA = get_float("Parameter a is: ");
    float parameterB = get_float("Parameter b is: ");
    float parameterC = get_float("Parameter c is: ");
             
    float myDelta = calcDelta(parameterA, parameterB, parameterC);
    
    if (myDelta > 0) {
        float myZero1 = calcZeroPoint1(parameterA, parameterB, myDelta);
        float myZero2 = calcZeroPoint2(parameterA, parameterB, myDelta);
        printf("This function has two zeros: x1 = %f, x2 = %f", myZero1, myZero2);
    } else if (myDelta == 0) {
        float myZero1 = calcZeroPoint1(parameterA, parameterB, myDelta);
        printf("This function has one zero: x = %f\n", myZero1);
    } else {
        printf("This function has no zero\n");
    }
          
}

float calcDelta(float parA, float parB, float parC) {
    float delta = (parB*parB) - 4 * parA * parC;
    return delta;
}

float calcZeroPoint1(float parA, float parB, float delta) {
    
    float zero1 = (-parB - (sqrt(delta))) / 2 * parA;
    return zero1;  
}

float calcZeroPoint2(float parA, float parB, float delta) {
    
    float zero2 = (-parB + (sqrt(delta))) / 2 * parA;
    return zero2;
}
