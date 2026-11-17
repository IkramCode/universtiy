#include <stdio.h>

int main (){
    float pi = 3.14;
    float radius;
    printf("Enter the radius of the circle: ");
    scanf("%f",&radius);

    float area = pi * radius * radius;
    float circumference = 2 * pi * radius;

    printf("Area: %f, Cicuumference: %f", area , circumference);
}
