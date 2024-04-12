#include <iostream>
#include "Contact.hpp"

int main()
{
    std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
    Contact newContact;

    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);

    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickName);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);

    std::cout << "Enter Dark Secret: ";
    std::getline(std::cin, darkestSecret);

    newContact.setContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
}
