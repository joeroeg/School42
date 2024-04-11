#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {}

void Contact::setContact(const std::string& fName, const std::string& lName, const std::string& nick, const std::string& phone, const std::string& secret) {
    firstName = fName;
    lastName = lName;
    nickname = nick;
    phoneNumber = phone;
    darkestSecret = secret;
}

void Contact::displayContactSummary(int index) const {
    std::cout << std::setw(10) << index << "|";
    if (firstName.length() > 10) {
        std::cout << std::setw(10) << firstName.substr(0,9) + "." << "|";
    } else {
        std::cout << std::setw(10) << firstName << "|";
    }
    if (lastName.length() > 10) {
        std::cout << std::setw(10) << lastName.substr(0,9) + "." << "|";
    } else {
        std::cout << std::setw(10) << lastName << "|";
    }
    if (nickname.length() > 10) {
        std::cout << std::setw(10) << nickname.substr(0,9) + "." << std::endl;
    } else {
        std::cout << std::setw(10) << nickname << std::endl;
    }
}

void Contact::displayContactDetails() const {
    std::cout << "First Name: " << firstName << std::endl
              << "Last Name: " << lastName << std::endl
              << "Nickname: " << nickname << std::endl
              << "Phone Number: " << phoneNumber << std::endl
              << "Darkest Secret: " << darkestSecret << std::endl;
}
