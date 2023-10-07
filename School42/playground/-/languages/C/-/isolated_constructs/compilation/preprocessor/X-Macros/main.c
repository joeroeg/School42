#include <stdio.h>
#include "countries.h"

typedef struct {
    const char *name;
    const char *code;
} Country;

Country countries[] = {
#define X(name, code) {name, code},
    COUNTRY_LIST
#undef X
};

int main() {
    for (int i = 0; i < sizeof(countries) / sizeof(Country); i++) {
        printf("%s (%s)\n", countries[i].name, countries[i].code);
    }
    return 0;
}
