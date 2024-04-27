#include "MateriaSource.hpp"
#include <cstdio>

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource default constructor" << std::endl;
    for (int i = 0; i < 4; i++)
        _slot[i] = NULL;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource default destructor" << std::endl;
    for (int i = 0; i < 4; i++)
        if (_slot[i])
        {
            delete _slot[i];
            _slot[i] = NULL;
        }
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
    std::cout << "MateriaSource copy constructor" << std::endl;
    *this = src;
}

MateriaSource& MateriaSource::operator=(MateriaSource const& other) {
    std::cout << "MateriaSource assignment operator" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (_slot[i]) {
                delete _slot[i];
                _slot[i] = NULL;
            }
            if (other._slot[i])
                _slot[i] = other._slot[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    std::cout << "MateriaSource learnMateria" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (!_slot[i])
        {
            _slot[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
    for (int i = 0; i < 4; ++i) {
        if (_slot[i] && _slot[i]->getType() == type) {
            std::cout << "Creating a new materia of type: " << type << std::endl;
            return _slot[i];
        }
    }
    std::cout << "Failed to create materia: No materia of type " << type << " learned" << std::endl;
    return NULL;
}

