#include <iostream>
#include <string>
#include "Convert.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./a.out <scalar-value-as-string>" << std::endl;
        return 1;
    }
    Converter	converter(argv[1]);
    cout << converter;
    return 0;
}
