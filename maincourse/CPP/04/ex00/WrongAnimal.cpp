#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Animal")
{
    std::cout << "The WrongAnimal constructor is called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
    std::cout << "The WrongAnimal parameter constructor is called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    *this = copy;
    std::cout << "The WrongAnimal copy constructor is called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    if (this != &copy)
        this->type = copy.type;
    std::cout << "The WrongAnimal assignation operator is called." << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "The WrongAnimal destructor is called." << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}
