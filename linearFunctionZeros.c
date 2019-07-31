#include <stdio.h>
#include <cs50.h>
#include <string.h>

float calcZeroPoint(float parA, float parB);

int main(void) {
     
    float parameterA = get_float("Parameter a is: ");
    float parameterB = get_float("Parameter b is: ");
    
    if (parameterA == 0 && parameterB != 0) {
        printf("This function has no zero\n");
    } else if (parameterA != 0) {
        float resultPointZero = calcZeroPoint(parameterA, parameterB);
        printf("Zero x = %f\n", resultPointZero);
    } else if (parameterA == 0 && parameterB == 0) {
        printf("This function has an infinite number of zeros\n");
    }
          
}

float calcZeroPoint(float parA, float parB) {
    float x = -(parB) / parA;
    return x;
}
