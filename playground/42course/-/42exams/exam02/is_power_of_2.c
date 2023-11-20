int is_power_of_2(unsigned int n) {
    // A number that is a power of 2 will have only one bit set in its binary representation.
    // So, if n is a power of 2, n & (n-1) will be 0.

    if (n == 0)
        return 0;

    return (n & (n - 1)) == 0;
}
