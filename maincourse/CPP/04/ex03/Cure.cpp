#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(std::string const & type) : AMateria(type) {
    std::cout << "Cure parameterized constructor called" << std::endl;
}

Cure::Cure(Cure const & src) {
    std::cout << "Cure copy constructor called" << std::endl;
    *this = src;
}

Cure::~Cure() {
    std::cout << "Cure destructor called" << std::endl;
}

Cure & Cure::operator=(Cure const & src) {
    std::cout << "Cure assignment operator called" << std::endl;
    if (this != &src) {
        this->_type = src._type;
    }
    return *this;
}

void Cure::use(ICharacter & target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const {
    std::cout << "Cure clone() method called" << std::endl;
    return new Cure(*this);
}
