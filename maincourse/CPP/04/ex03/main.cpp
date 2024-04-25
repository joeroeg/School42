#include <iostream>
#include <cassert>

#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

// int main()
// {
// 	std::cout << "---Creating a new MateriaSource---" << std::endl;
// 	IMateriaSource* src = new MateriaSource();

// 	std::cout << "---Learning Ice and Cure---" << std::endl;
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	std::cout << "---Creating a new Character---" << std::endl;
// 	ICharacter* me = new Character("me");

// 	std::cout << "---Equipping Ice and Cure---" << std::endl;
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	std::cout << "---Creating a new Character bob---" << std::endl;
// 	ICharacter* bob = new Character("bob");

// 	std::cout << "---Using Ice and Cure on bob---" << std::endl;
// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	std::cout << "---Unequipping Ice and Cure---" << std::endl;
// 	delete bob;
// 	delete me;
// 	delete src;

// 	return 0;
// }

int main()
{
    // Create a character
    ICharacter *me = new Character("me");
    Character *bob = new Character("bob");

    // Create a materia source
    IMateriaSource *src = new MateriaSource();
    MateriaSource *src2 = new MateriaSource();

    // Learn some materia
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // Create a materia
    AMateria *ice = src->createMateria("ice");
    AMateria *cure = src->createMateria("cure");

    // Equip some materia
    me->equip(ice);
    me->equip(cure);

    // Use the materia
    me->use(0, *bob);
    me->use(1, *bob);

    // // Unequip the materia
    me->unequip(0);
    me->unequip(1);

    // Use the materia after unequipping
    me->use(0, *bob);
    me->use(1, *bob);

    // Delete the character
    delete me;
    delete bob;
    delete src;
    delete src2;
    delete ice;
    delete cure;

    return 0;
}

// int main()
// {
//     Character *me = new Character("me");
//     MateriaSource *src = new MateriaSource();
//     src->learnMateria(new Ice());
//     AMateria *ice = src->createMateria("ice");
//     me->equip(ice);
//     me->use(0, *me);
//     delete me;
//     delete src;
//     return 0;
// }
