#include <stdio.h>


int rectangle_area(int lenght, int width)
{
    int l = lenght;
    int w = width;
    int area = l * w;
    return (area);

}



int main()
{
    printf("%d", rectangle_area(4, 2));
}