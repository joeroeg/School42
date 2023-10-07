#include <stdio.h>
#include <line
#include "shapes.h"


int main() {
    int width, height, radius;
    printf("Enter the width and height of a rectangle: ");
    scanf("%d %d", &width, &height);
    printf("The area of the rectangle is %d\n", rectangle_area(width, height));

    printf("Enter the radius of a circle: ");
    scanf("%d", &radius);
    printf("The area of the circle is %d\n", circle_area(radius));

    return 0;
}
