/*
Numbers ending with zeros are boring.
They might be fun in your world, but not here.
Get rid of them. Only the ending ones.

1450 -> 145
960000 -> 96
1050 -> 105
-1050 -> -105
Zero alone is fine, don't worry about it. Poor guy anyway
*/

#include <stdio.h>
#include <math.h>

int main() {
    int number = 123456789;
    int newNumber = 0;
    int digitPosition = 1;  // To keep track of the current digit position

    while (number > 0)
    {
        int digit = number % 10;
        
        
        if (digitPosition == 4)
        {
            digit = 0;  // Replace with the desired new value
        }
        else if (digitPosition == 7)
        {
            digit = 0;  // Replace with the desired new value
        }


        // newNumber = newNumber + digit * pow(10, digitPosition - 1);
        newNumber = newNumber * 10 + digit;
        number /= 10;
        digitPosition++;
    }

    //     // Reverse the newNumber
    // int reversedNumber = 0;
    // while (newNumber > 0) {
    //     int digit = newNumber % 10;
    //     reversedNumber = reversedNumber * 10 + digit;
    //     newNumber /= 10;
    // }

    printf("Modified number: %d\n", newNumber);
    return 0;
}
