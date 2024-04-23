#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *_source[4];

public:
    MateriaSource(); // default constructor
    MateriaSource(MateriaSource const &src); // copy constructor
    MateriaSource &operator=(MateriaSource const &src); // assignment operator
    virtual ~MateriaSource(); // destructor

    AMateria *getMateria(int idx) const;
    virtual void learnMateria(AMateria *m);
    virtual AMateria *createMateria(std::string const &type);
};

#endif
