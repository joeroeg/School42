#include "Ice.hpp"

Ice::Ice() {
    std::cout << "Default constructor" << std::endl;
}

Ice::~Ice() {
    std::cout << "Default destructor" << std::endl;
}

Ice::Ice(std::string type) : AMateria(type) {
    std::cout << "Parametrized constructor" << std::endl;
}

Ice::Ice(Ice const& other) : AMateria(other._type) {
    std::cout << "Copy constructor" << std::endl;
}

Ice& Ice::operator=(Ice const & src) {
    std::cout << "Ice assignment operator called" << std::endl;
    if (this != &src) {
        this->_type = src._type;
    }
    return *this;
}

/**
 * @param this refers to the object on which clone() is called.
 * @return AMateria* - return a base pointer for a polymorphic behavior
 * @param Ice(*this) - must be dereferenced to invoke Ice copy constructor.
*/
AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
