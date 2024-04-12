#include "Contact.hpp"

Contact::Contact() {}

void Contact::setContact(const std::string& firstName, const std::string& lastName, const std::string& nickName, const std::string& phoneNumber, const std::string& darkestSecret)
{
    _firstName = firstName;
    _lastName = lastName;
    _nickName = nickName;
    _phoneNumber = phoneNumber;
    _darkestSecret = darkestSecret;
}

