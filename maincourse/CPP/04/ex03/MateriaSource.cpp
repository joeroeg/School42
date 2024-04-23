#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor" << std::endl;
    for (int i = 0; i < 4; i++)
        _source[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
    std::cout << "MateriaSource copy constructor" << std::endl;
    *this = src;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &src)
{
    std::cout << "MateriaSource assignment operator" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_source[i])
            delete _source[i];
        _source[i] = src._source[i]->clone();
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_source[i])
            delete _source[i];
    }
}

AMateria *MateriaSource::getMateria(int idx) const
{
    if (idx < 0 || idx >= 4)
        return NULL;
    std::cout << "MateriaSource getMateria" << std::endl;
    return _source[idx];
}

void MateriaSource::learnMateria(AMateria *m)
{
    std::cout << "MateriaSource learnMateria" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (!_source[i])
        {
            // printf("---Learning %s\n", m->getType().c_str());
            _source[i] = m;
            return;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    std::cout << "MateriaSource createMateria" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_source[i] && _source[i]->getType() == type)
            return _source[i]->clone();
    }
    return NULL;
}

