#include <iostream>
#include <string>
#include <cctype>


/*
    std::string toUpperCase(const std::string &input)
    Mechanism: Pass by const reference.
    Passing a string by const reference to the toUpperCase function avoids unnecessary copies,
    ensuring efficiency with large strings while also protecting the original string from modifications.
    This method combines performance benefits with data integrity, making it ideal for read-only operations.

    std::string toUpperCase(const std::string input)
    Mechanism: Pass by value, but with a const qualifier on a value type. (unusual case)
    Passing a string by value with a const qualifier in the `toUpperCase` function results in an inefficient copy of the input string,
    where the const qualifier offers no benefit since modifications only affect the local copy, not the original.
    This approach is less suitable for large strings due to the performance cost of copying.

    std::string toUpperCase(std::string &input)
    Mechanism: Pass by reference.
    Passing a string by non-const reference to the `toUpperCase` function avoids copying,
    enhancing efficiency, but risks modifying the original string, potentially leading to unintended consequences if the function changes the input string.
    This approach suggests the function could alter the original string, which may not be the desired behavior in all cases.

    std::string toUpperCase(std::string input)
    Mechanism: Pass by value.
    Passing a string by value to the `toUpperCase` function ensures the original string remains unmodified by working on a local copy,
    making it a safe but less efficient choice due to the overhead of copying, especially with large strings.
    This method is straightforward but can be costly in terms of performance.
*/

/**
 * @brief It takes a constant reference to a std::string as its parameter,
 * which ensures that the original string passed to the function is not modified.
 * It returns a std::string.
 * @param std::string: A class that represents a sequence of characters.
 * @param std::toupper: A function that converts a character to uppercase.
 * @param input.size(): The number of characters in the input string.
*/
std::string toUpperCase(const std::string &input) {
    std::string result;
    for (size_t i = 0; i < input.size(); ++i) {
        result += std::toupper(input[i]);
    }
    return result;
}

/**
 * @param std::string: A class that represents a sequence of characters.
 * @param std::cout The standard output stream used to print text to the console. std is the namespace where cout is defined.
 * @param <<: The insertion operator, used with std::cout to send data to the output stream.
 * It can be chained to output multiple items consecutively.
 * @param argv[i]: a pointer to a C-string (null-terminated array of characters)
 * @param std::ends: Manipulator that inserts a null character into the output stream.
 * @param std::endl: Manipulator that inserts a newline character into the output stream.
*/
int main(int argc, char *argv[]) {
    std::string result = "";
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; ++i)
        result += argv[i];
    result = toUpperCase(result);
    std::cout << result << std::endl;
    return 0;
}
