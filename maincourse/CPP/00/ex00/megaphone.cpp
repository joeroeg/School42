#include <iostream>
#include <string>
#include <cctype>

std::string touppercase(const std::string &input) {
    std::string result;
    for (size_t i = 0; i < input.size(); ++i) {
        result += std::toupper(input[i]);
    }
    return result;
}

int main(int argc, char **argv) {
    std::string result = "";
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; ++i)
        result += argv[i];
    result = touppercase(result);
    std::cout << result << std::endl;
    return 0;
}
