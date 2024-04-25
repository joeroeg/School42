#include "AMateria.hpp"

AMateria::AMateria() {
    std::cout << "Default constructor" << std::endl;
}

AMateria::~AMateria() {
    std::cout << "Default destructor" << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type)
{
    std::cout << "Parameterized constructor" << std::endl;
}

AMateria::AMateria(AMateria const& other) : _type(other._type) {
    std::cout << "Copy constructor" << std::endl;
}

AMateria& AMateria::operator=(AMateria const & src) {
    if (this != &src)
    {
        this->_type = src._type;
    }
    return *this;
}

std::string const& AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "Default use" << std::endl;
}
