#include <iostream>
#include <string>
#include <cctype>


/*
    std::string toUpperCase(const std::string &input)
    Mechanism: Pass by const reference.
    Implication: This is the most efficient method for this specific case because
    it avoids copying the input string (std::string) while also ensuring that
    the original string cannot be modified inside the function due to the const qualifier.
    It's ideal for read-only operations on large strings where performance and memory efficiency matter.
    No Copying: The function will access the variable directly, not a copy,
    which is efficient for large objects like strings or complex classes since it avoids the overhead of copying.
    Read-Only Access: The function promises not to modify the variable,
    as it is accessed through a const reference. The compiler enforces this, and attempting to modify the variable will result in a compilation error.
    You achieve efficiency by avoiding unnecessary copies of potentially large objects. You ensure safety by preventing modifications to the original data, making your code more predictable and easier to debug.

    std::string toUpperCase(const std::string input)
    Mechanism: Pass by value, but with a const qualifier on a value type. (it is an unusual case)
    Implication: This method makes a copy of the input string, which is less efficient due to the unnecessary copying.
    The const qualifier on the passed-by-value parameter doesn't serve a practical purpose for the caller,
    since any modification within the function would only affect the copy, not the original string.
    It's less efficient for large strings and the const on a copy doesn't add value.

    std::string toUpperCase(std::string &input)
    Mechanism: Pass by reference.
    Implication: This allows the function to avoid making a copy of the argument,
    which is more efficient than passing by value. However, because the reference is not const,
    it suggests that the function may modify the input string,
    which is not typically desirable for a function that converts a string to uppercase and returns a new string.
    It might lead to unintended side-effects if the original string is modified.

    std::string toUpperCase(std::string input)
    Mechanism: Pass by value.
    Implication: This method involves copying the input string, which incurs additional overhead, especially for large strings.
    It's a straightforward approach that prevents the original string from being altered,
    suitable for scenarios where the function may need to work with a local copy of the input.
    However, it's not the most efficient choice due to the copying involved.
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
