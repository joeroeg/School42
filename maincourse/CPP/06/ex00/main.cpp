#include <iostream>
#include <string>
#include "Convert.hpp"

int main(int argc, char** argv) {
    (void) argc;
    (void) argv;
    // if (argc != 2) {
    //     std::cerr << "Usage: ./convert <scalar-value-as-string>" << std::endl;
    //     return 1;
    // }


    // std::string input = argv[1];
    std::string input = "42";
    convertAndDisplay(input);
    return 0;
}
