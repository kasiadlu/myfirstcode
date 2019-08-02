#include <stdio.h>
#include <cs50.h>
#include <math.h>

//Linear:
void linear();
float calcZeroPointLinear(float parA, float parB);

//Quadratic:
void quadratic();
float calcDelta(float parA, float parB, float parC);
float calcZeroPoint1(float parA, float parB, float delta);
float calcZeroPoint2(float parA, float parB, float delta);

int main(void) {
    
    int number = 0;
    
    do {
        number = get_int("Enter 1 to calculate linear function or 2 to calculate quadratic function. Enter 0 to exit: ");
        if (number == 1) {
            linear();
        } else if (number == 2) {
            quadratic();
        }
    } while (number != 0);
        
}


void linear() {
     
    float parameterA = get_float("Parameter a is: ");
    float parameterB = get_float("Parameter b is: ");
    
    if (parameterA == 0 && parameterB != 0) {
        printf("This function has no zero\n");
    } else if (parameterA != 0) {
        float resultPointZero = calcZeroPointLinear(parameterA, parameterB);
        printf("Zero x = %f\n", resultPointZero);
    } else if (parameterA == 0 && parameterB == 0) {
        printf("This function has an infinite number of zeros\n");
    }
          
}

float calcZeroPointLinear(float parA, float parB) {
    float x = -(parB) / parA;
    return x;
}

// QUADRATIC 

void quadratic() {
     
    float parameterA = get_float("Parameter a is: ");
    float parameterB = get_float("Parameter b is: ");
    float parameterC = get_float("Parameter c is: ");
             
    float myDelta = calcDelta(parameterA, parameterB, parameterC);
    
    if (myDelta > 0) {
        float myZero1 = calcZeroPoint1(parameterA, parameterB, myDelta);
        float myZero2 = calcZeroPoint2(parameterA, parameterB, myDelta);
        printf("This function has two zeros: x1 = %f, x2 = %f\n", myZero1, myZero2);
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
