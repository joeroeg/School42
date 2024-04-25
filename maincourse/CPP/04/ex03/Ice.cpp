#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(std::string const & type) : AMateria(type) {
    std::cout << "Ice parameterized constructor called" << std::endl;
}

Ice::Ice(Ice const & src) {
    std::cout << "Ice copy constructor called" << std::endl;
    *this = src;
}

Ice::~Ice() {
    std::cout << "Ice destructor called" << std::endl;
}

Ice& Ice::operator=(Ice const & src) {
    std::cout << "Ice assignment operator called" << std::endl;
    if (this != &src) {
        this->_type = src._type;
    }
    return *this;
}

void Ice::use(ICharacter & target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const {
    std::cout << "Ice clone() method called" << std::endl;
    return new Ice(*this);
}
