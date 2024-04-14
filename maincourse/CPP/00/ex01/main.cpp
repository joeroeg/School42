#include "PhoneBook.hpp"

/**
 * Trims the input string by removing leading and trailing whitespaces.
 * @param str The input string to be trimmed.
 * @param start The iterator pointing to the first non-whitespace character.
 * @param end The iterator pointing to the last non-whitespace character.
 * @return The trimmed string.
 * @see https://en.cppreference.com/w/cpp/string/byte/isspace
 * @see https://en.cppreference.com/w/cpp/algorithm/find_if_not
 * @see https://en.cppreference.com/w/cpp/algorithm/find
*/
std::string trim(const std::string& str) {
    std::string::const_iterator start = std::find_if_not(str.begin(), str.end(), ::isspace);
    std::string::const_iterator end = std::find_if_not(str.rbegin(), str.rend(), ::isspace).base();
    return std::string(start, end);
}

/**
 * Checks if the input string is not empty.
 * @param input The input string to be checked.
 * @return True if the input string is not empty, false otherwise.
 * @see https://en.cppreference.com/w/cpp/string/basic_string/empty
*/
bool isNotEmpty(const std::string& input) {
    return !input.empty();
}

/**
 * Validates the phone number input.
 * @param input The phone number input to be validated.
 * @return True if the input is a valid phone number, false otherwise.
 * @see https://en.cppreference.com/w/cpp/string/basic_string/find_first_not_of
*/
bool isValidPhoneNumber(const std::string& input) {
    return (input.length() >= 1 && input.length() <= 18) && input.find_first_not_of("0123456789") == std::string::npos;
}

/**
 * Prompts the user for input and validates it using the provided validator function.
 * @param prompt The prompt message to display to the user.
 * @param validator The function to validate the input.
 * @return The validated input.
 * @see https://en.cppreference.com/w/cpp/utility/functional/function
 * @see https://en.cppreference.com/w/cpp/string/basic_string/getline
*/
std::string getValidatedInput(const std::string& prompt, std::function<bool(const std::string&)> validator) {
    std::string input;
    do {
        if (std::cin.eof()) {
            std::cout << "EOF received, exiting program." << std::endl;
            exit(0);
        }
        std::cout << prompt;
        std::getline(std::cin, input);
        input = trim(input);
        if (!validator(input)) {
            if (prompt == "Enter phone number: ")
                std::cout << "Invalid phone number. Phone number length around the world ranges from 1 digits to only 18. Please try again." << std::endl;
            else
                std::cout << "Invalid input. Please try again." << std::endl;
        }
    } while (!validator(input));
    return input;
}

void handleAdd(PhoneBook& phoneBook) {
    if (phoneBook.isFull())
        std::cout << "PhoneBook is full. The oldest contact will be replaced." << std::endl;

    std::string first_name = getValidatedInput("Enter first name: ", isNotEmpty);
    std::string last_name = getValidatedInput("Enter last name: ", isNotEmpty);
    std::string nick_name = getValidatedInput("Enter nickname: ", isNotEmpty);
    std::string phone_number = getValidatedInput("Enter phone number: ", isValidPhoneNumber);
    std::string dark_secret = getValidatedInput("Enter Dark Secret: ", isNotEmpty);

    Contact newContact;
    newContact.setContact(first_name, last_name, nick_name, phone_number, dark_secret);
    phoneBook.addContact(newContact);
    std::cout << "Contact added successfully." << std::endl;
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Welcome to the PhoneBook!" << std::endl;
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) {
            std::cout << "EOF received, exiting program." << std::endl;
            break;
        }
        if (command == "EXIT") break;
        else if (command == "ADD") handleAdd(phoneBook);
        else if (command == "SEARCH") {
            phoneBook.displayContacts();
            phoneBook.searchContact();
        }
        else
            std::cout << "Error: Invalid command" << std::endl;
    }
    return 0;
}
