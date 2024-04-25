#include "AMateria.hpp"

AMateria::AMateria() {
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {
    std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & src) : _type(src._type) {
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called" << std::endl;
}

AMateria & AMateria::operator=(AMateria const & src) {
    std::cout << "AMateria assignment operator called" << std::endl;
    if (this != &src) {
        this->_type = src._type;
    }
    return *this;
}

std::string const & AMateria::getType() const {
    std::cout << "AMateria getType() method called" << std::endl;
    return this->_type;
}

void AMateria::use(ICharacter & target) {
    std::cout << "* uses some materia on " << target.getName() << " *" << std::endl;
}

// AMateria* AMateria::clone() const {
//     // return new AMateria(*this); // this is wrong, because abstract class can't be instantiated. Only derived class can be instantiated.
//     return (AMateria*)(this);
// }

