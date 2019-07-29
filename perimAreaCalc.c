#include <stdio.h>
#include <cs50.h>
#include <string.h>

float getPositiveFloat(string msg);
float calcSquareArea(float squareSideLength);
float calcSquarePerimeter (float squareSideLength);
float calcRectangleArea(float rectangleSideA, float rectangleSideB);
float calcTriangleArea (float baseTriangle, float heightTriangle);

int main(void) {
    
    // Ask for lentgh of stuff
    
    float squareSideLength = getPositiveFloat("What's the length of a square?: ");
    float rectangleSideA = getPositiveFloat("What's the lentgh of rectangle side A?: ");
    float rectangleSideB = getPositiveFloat("What's the lentgh of rectangle side B?: ");
    float baseOfTriangle = getPositiveFloat("What's the lentgh of a base of a triangle?: ");
    float heightOfTriangle = getPositiveFloat("What's the lentgh of a height of a triangle?: ");
   
    // Make some strange calculations
    
    float resultSquareArea = calcSquareArea(squareSideLength);
    float resultSquarePerimeter = calcSquarePerimeter(squareSideLength);
    
    float resultRectangleArea = calcRectangleArea(rectangleSideA, rectangleSideB);
    float resultRectanglePerimeter = calcRectangleArea(rectangleSideA, rectangleSideB);
    
    float resultTriangleArea = calcTriangleArea(baseOfTriangle, heightOfTriangle);
            
    // Print results
    
    printf("Square area is: %f\n", resultSquareArea); 
    printf("Square perimeter is: %f\n", resultSquarePerimeter);
    
    printf("Rectangle area is: %f\n", resultRectangleArea); 
    printf("Rectangle perimeter is: %f\n", resultRectanglePerimeter);
    
    printf("Triangle area is: %f\n", resultTriangleArea);
}

float getPositiveFloat(string msg) {
    float positiveFloat = 0;
    do {
        positiveFloat = get_float("%s", msg);
    } while (positiveFloat <= 0);
    return positiveFloat; 
}

float calcSquareArea(float squareSideLength) {
    return squareSideLength * squareSideLength; 
}

float calcSquarePerimeter (float squareSideLength) {
    float result = 4 * squareSideLength;
    return result;
}

float calcRectangleArea(float rectangleSideA, float rectangleSideB) {
    return rectangleSideA * rectangleSideB;
}

float calcRectanglePerimeter (float rectangleSideA, float rectangleSideB) {
    float result = 2 * rectangleSideA + 2 * rectangleSideB;
    return result;
}

float calcTriangleArea (float baseTriangle, float heightTriangle) {
    float result = 0.5 * baseTriangle * heightTriangle;
    return result;
}
