/*
va_list is used in C and C++ programming languages to handle a variable number of arguments in a function.
It provides a way to access the arguments passed to a function when the number of arguments is not known at compile time.

Here are some examples of where va_list is commonly used:
1. The printf function in C uses va_list to handle a variable number of arguments. The format string specifies the types and positions of the arguments, but the number of arguments is not known until runtime.
2. The scanf function in C uses va_list in a similar way to printf, to handle a variable number of arguments based on the format string.
3. The vprintf and vscanf functions in C provide a way to pass a va_list directly to the function, instead of using the format string. This can be useful when you want to build a formatted string or parse a string using a dynamic format.
4. Many other functions in C and C++ use va_list to handle a variable number of arguments, such as vfprintf, vsprintf, vsnprintf, vsscanf, execl, execv, execvp, and many more.
5. va_list can also be used to write your own functions that take a variable number of arguments, as I showed in my previous example.

Variadic functions are functions that can accept a variable number of arguments.
In C, variadic functions are declared using the ellipsis (...) notation in the function declaration.

va_start: Initializes the va_list object that will hold the variable number of arguments.
va_arg: Accesses the next argument of the given type in the va_list.
va_end: Cleans up the va_list object after all arguments have been accessed.

In this example main function, we call the sum function with different numbers of arguments and print the result using printf.
The first call to sum passes three arguments, and the function correctly calculates their sum and prints 6.
The second call to sum passes five arguments, and the function again correctly calculates their sum and prints 15.
Finally, the third call to sum passes zero arguments, and the function correctly returns 0.

va_list
void va_start(va_list ap, parmN);           // initializes the va_list ap to point to the first argument after the named parameter parmN. parmN is the last named parameter in the function's parameter list.
type va_arg(va_list ap, type);              // retrieves the next argument from the va_list and converts it to the specified type. The ap argument is the va_list to retrieve the argument from, and type is the type of the argument.
void va_copy(va_list dest, va_list src);    // creates a copy of the va_list src in dest. This can be useful if you need to iterate over the arguments multiple times.
void va_end(va_list ap);                    // cleans up the va_list and should be called after you're done accessing the arguments.

*/

#include <stdio.h>
#include <stdarg.h>

void print_ints(int count, ...)
{
    va_list ap;
    va_start(ap, count);
    printf("print_ints: ");
    for (int i = 0; i < count; i++)
    {
        int val = va_arg(ap, int);
        printf("%d ", val);
    }

    va_end(ap);
}

int sum(int count, ...) {
    int total = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        total += va_arg(args, int);
    }
    va_end(args);
    return total;
}

int main() {
    print_ints(3, 1, 2, 3);
    printf("\nsum: %d\n", sum(3, 1, 2, 3)); // prints "6"
    printf("sum: %d\n", sum(5, 1, 2, 3, 4, 5)); // prints "15"
    printf("sum: %d\n", sum(0)); // prints "0"
    return 0;
}


