#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <iomanip>
#include <string>

class Contact {
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    Contact();
    void setContact(const std::string& fName, const std::string& lName, const std::string& nick, const std::string& phone, const std::string& secret);
    void displayContactSummary(int index) const;
    void displayContactDetails() const;
};

#endif
