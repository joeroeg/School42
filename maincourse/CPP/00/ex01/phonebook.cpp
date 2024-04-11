#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : contactCount(0) {}

void PhoneBook::addContact(const Contact& contact) {
    int index = contactCount % 8;
    contacts[index] = contact;
    if (contactCount < 8) contactCount++;
}

void PhoneBook::displayContacts() const {
    for (int i = 0; i < contactCount; i++) {
        contacts[i].displayContactSummary(i);
    }
}

void PhoneBook::searchContact() const {
    int index;
    std::cout << "Enter the index of the contact: ";
    std::cin >> index;
    if (index < 0 || index >= contactCount) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    contacts[index].displayContactDetails();
}
