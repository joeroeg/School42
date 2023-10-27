#include <stdio.h>

typedef int (*MathFunc)(float, int);

int do_math(float arg1, int arg2) {
    return arg2;
}

int call_a_func(MathFunc call_this) {
    int output = call_this(5.5, 7);
    return output;
}

// Define another function with the same signature
int another_math_func(float arg1, int arg2) {
    return (int)arg1 + arg2;
}

int main() {
    int final_result;

    // Test with the do_math function
    final_result = call_a_func(&do_math);
    printf("Result with do_math: %d\n", final_result);

    // Test with the another_math_func function
    final_result = call_a_func(&another_math_func);
    printf("Result with another_math_func: %d\n", final_result);

    return 0;
}
