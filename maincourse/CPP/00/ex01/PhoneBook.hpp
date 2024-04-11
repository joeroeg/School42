#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int contactCount;

public:
    PhoneBook();
    void addContact(const Contact& contact);
    void displayContacts() const;
    void searchContact() const;
    bool isFull() const { return contactCount >= 8; }
};

#endif
