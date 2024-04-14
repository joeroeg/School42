#include "PhoneBook.hpp"

// Constructor to initialize the contact count.
PhoneBook::PhoneBook() : _contactCount(0) {}

void PhoneBook::addContact(const Contact& contact) {
    static int index = _contactCount % 8;
    _contacts[index % 8] = contact;
    if (_contactCount < 8) _contactCount++;
    index++;
}

void PhoneBook::displayContacts() const {
    for (int i = 0; i < _contactCount; i++) {
        _contacts[i].displayContactSummary(i);
    }
}

bool isValidInteger(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

/**
 * @see https://en.cppreference.com/w/cpp/string/byte/isdigit
 * @see https://en.cppreference.com/w/cpp/string/basic_string/stol
*/
void PhoneBook::searchContact() const {
    std::cout << "Enter the index of the contact: ";
    std::string input;
    std::getline(std::cin, input);
	if (!isValidInteger(input)) {
		std::cout << "Invalid input. Please try again." << std::endl;
		return;
	}
    int index = std::stoi(input);
    if (index < 0 || index >= _contactCount) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    _contacts[index].displayContactDetails();
}
