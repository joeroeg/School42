#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "The WrongCat constructor is called." << std::endl;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &copy)
{
    *this = copy;
    std::cout << "The WrongCat copy constructor is called." << std::endl;
}

// Assignation operator
WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    if (this != &copy)
        this->type = copy.type;
    std::cout << "The WrongCat assignation operator is called." << std::endl;
    return *this;
}

// Destructor
WrongCat::~WrongCat()
{
    std::cout << "The WrongCat destructor is called." << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow meow!" << std::endl;
}
