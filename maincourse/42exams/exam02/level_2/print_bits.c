#include <unistd.h>
#include <stdio.h>

// void print_bits(unsigned char octet) {
//     int i;
//     for (i = 7; i >= 0; i--) {
//         char bit = (octet & (1 << i)) ? '1' : '0';
//         write(1, &bit, 1);
//     }
// }

// void print_bits(unsigned char octet)
// {
//     int i = 8;
//     while (i--)
//     {
//         if (octet & (1 << i))
//             write(1, "1", 1);
//         else
//             write(1, "0", 1);
//     }
// }

void print_bits(unsigned char octet)
{

}

void test_print_bits()
{
    unsigned char test_cases[] = {0, 1, 2, 127, 128, 255};
    const char* expected_output[] = {"00000000", "00000001", "00000010", "01111111", "10000000", "11111111"};

    printf("Test No.\tInput\tExpected\tGot\n");
    printf("------------------------------------------------\n");

    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
    {
        printf("%d\t\t%u\t%s\t\t", i + 1, test_cases[i], expected_output[i]);
        print_bits(test_cases[i]);
        printf("\n");
    }
}

int main()
{
    test_print_bits();
    return 0;
}
