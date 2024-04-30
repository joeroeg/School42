#include "Convert.hpp"
#include <iostream>
#include <sstream>

void convertAndDisplay(const std::string& input) {
    try {
        int value = std::stoi(input);
        std::cout << "char: " << static_cast<char>(value) << std::endl;
    } catch (...) {
        std::cout << "Conversion failed for type int." << std::endl;
    }
    try {
        int value = std::stoi(input);
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    } catch (...) {
        std::cout << "Conversion failed for type int." << std::endl;
    }
    try {
        float value = std::stof(input);
        std::cout << "float: " << static_cast<float>(value) << std::endl;
    } catch (...) {
        std::cout << "Conversion failed for type float." << std::endl;
    }
    try {
        double value = std::stoi(input);
        std::cout << "double: " << static_cast<double>(value) << std::endl;
    } catch (...) {
        std::cout << "Conversion failed for type double." << std::endl;
    }
}
