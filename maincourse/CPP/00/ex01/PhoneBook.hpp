#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <locale>

class PhoneBook {
private:
    Contact _contacts[8];
    int _contactCount;

public:
    PhoneBook();
    void addContact(const Contact& contact);
    void displayContacts() const;
    void searchContact() const;
    bool isFull() const { return _contactCount >= 8; }
};

#endif
