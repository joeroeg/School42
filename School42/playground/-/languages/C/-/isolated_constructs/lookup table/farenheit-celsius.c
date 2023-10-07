/*
we use a map (implemented as an array of strings) to store the conversion rates between Celsius and Fahrenheit temperatures.
We then look up the conversion rate for the given units in the map and use it to convert the input value.
If the conversion is found, we print out the result. Otherwise, we print an error message.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* conversion_map[] = {
        "Celsius", "Fahrenheit",
        "---------------------",
        "0", "32",
        "10", "50",
        "20", "68",
        "30", "86",
        "40", "104",
        "50", "122",
		NULL
    };

    char* from_unit = "Celsius";
    char* to_unit = "Fahrenheit";
    double value = 20.0;

    double result = 0.0;
    int found = 0;

    for (int i = 0; conversion_map[i] != NULL; i += 2) {
        if (strcmp(conversion_map[i], from_unit) == 0 && strcmp(conversion_map[i+1], to_unit) == 0) {
            result = atof(conversion_map[i+1]);
            found = 1;
            break;
        }
    }

    if (found) {
        result = (value * result) + atof(conversion_map[1]);
        printf("%.2f %s is %.2f %s\n", value, from_unit, result, to_unit);
    } else {
        printf("Conversion not found\n");
    }

    return 0;
}
