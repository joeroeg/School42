// Contact.hpp
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    void setContact(const std::string& fName, const std::string& lName, const std::string& nick, const std::string& phone, const std::string& secret);
    void displayContactSummary(int index) const;
    void displayContactDetails() const;
};

#endif
