#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) {
            std::cout << "EOF received, exiting program." << std::endl;
            break;
        }

        if (command == "EXIT") break;
        else if (command == "ADD") {
            if (phoneBook.isFull()) {
            std::cout << "PhoneBook is full. The oldest contact will be replaced." << std::endl;
        }

        std::string firstName, lastName, nickname, phoneNumber, darkSecret;

        std::cout << "Enter first name: ";
        std::getline(std::cin, firstName);

        std::cout << "Enter last name: ";
        std::getline(std::cin, lastName);

        std::cout << "Enter nickname: ";
        std::getline(std::cin, nickname);

        std::cout << "Enter phone number: ";
        std::getline(std::cin, phoneNumber);

        std::cout << "Enter Dark Secret: ";
        std::getline(std::cin, darkSecret);

        Contact newContact;
        newContact.setContact(firstName, lastName, nickname, phoneNumber, darkSecret);

        phoneBook.addContact(newContact);
        std::cout << "Contact added successfully." << std::endl;
        }
        else if (command == "SEARCH") {
            phoneBook.displayContacts();
            phoneBook.searchContact();
        }
    }

    return 0;
}
