#include "Contact.hpp"


Contact::Contact() {}

void Contact::setContact(const std::string& fName, const std::string& lName, const std::string& nick, const std::string& phone, const std::string& secret) {
    _firstName = fName;
    _lastName = lName;
    _nickname = nick;
    _phoneNumber = phone;
    _darkestSecret = secret;
}

/**
 * @see https://en.cppreference.com/w/cpp/io/manip/setw
 * @see https://en.cppreference.com/w/cpp/string/basic_string/substr
*/
void Contact::displayContactSummary(int index) const {
    if (index == 0) {
        std::cout << std::setw(10) << "Index" << "|"
                  << std::setw(10) << "First Name" << "|"
                  << std::setw(10) << "Last Name" << "|"
                  << std::setw(10) << "Nickname" << std::endl;
    }
    std::cout << std::setw(10) << index << "|";
    if (_firstName.length() > 10) {
        std::cout << std::setw(10) << _firstName.substr(0,9) + "." << "|";
    } else {
        std::cout << std::setw(10) << _firstName << "|";
    }
    if (_lastName.length() > 10) {
        std::cout << std::setw(10) << _lastName.substr(0,9) + "." << "|";
    } else {
        std::cout << std::setw(10) << _lastName << "|";
    }
    if (_nickname.length() > 10) {
        std::cout << std::setw(10) << _nickname.substr(0,9) + "." << std::endl;
    } else {
        std::cout << std::setw(10) << _nickname << std::endl;
    }
}

void Contact::displayContactDetails() const {
    std::cout << "First Name: " << _firstName << std::endl
              << "Last Name: " << _lastName << std::endl
              << "Nickname: " << _nickname << std::endl
              << "Phone Number: " << _phoneNumber << std::endl
              << "Darkest Secret: " << _darkestSecret << std::endl;
}
