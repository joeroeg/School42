#include <iostream>
#include <cassert>

#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void testConstructorsAndOperators() {
    Ice original_ice;
    Ice original_ice_2;
    std::cout << original_ice.getType() << std::endl;

    Ice copy_ice = original_ice;
    std::cout << copy_ice.getType() << std::endl;

    copy_ice = original_ice_2;
    std::cout << copy_ice.getType() << std::endl;
}

void testClone() {
    Ice* ice = new Ice();
    AMateria* clone = ice->clone();
    std::cout << "Original type: " << ice->getType() << std::endl;
    std::cout << "Cloned type: " << clone->getType() << std::endl;
    delete ice;
    delete clone;
}

void testCharacterOperations() {
    Character hero("Hero");
    std::cout << hero.getName() << std::endl;
    hero.printInventory(hero);

    AMateria* ice = new Ice("ice");
    hero.equip(ice);
    hero.equip(ice);
    hero.equip(ice);
    hero.equip(ice);
    hero.printInventory(hero);

    hero.use(0, hero);
    hero.use(1, hero);
    hero.use(2, hero);
    hero.use(3, hero);

    hero.unequip(0);
    hero.unequip(1);
    hero.unequip(2);
    hero.unequip(3);
    hero.printInventory(hero);

    cleanupDroppedMateria();
    delete ice;
}

void testCharacterCopyAndAssignment() {
    Character hero("Hero");
    Ice* ice = new Ice();

    hero.equip(ice);
    hero.equip(ice);
    hero.equip(ice);
    hero.equip(ice);

    Character hero_copy = hero;
    hero_copy.printInventory(hero_copy);
    hero_copy = hero;
    hero_copy.printInventory(hero_copy);

    delete ice;
}

void testMateriaSource() {
    Character hero("Hero");
    MateriaSource source;
    source.learnMateria(new Ice());
    AMateria* newIce = source.createMateria("ice");
    hero.equip(newIce);
    hero.printInventory(hero);
    hero.use(0, hero);
}

void subjectTestCase()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete me;
    delete bob;
    delete src;
}

int main() {
    // testConstructorsAndOperators();
    // testClone();
    // testCharacterOperations();
    // testCharacterCopyAndAssignment();
    // testMateriaSource();
    subjectTestCase();


    return 0;
}

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

// int main()
// {
//     // Create a character
//     ICharacter *me = new Character("me");
//     Character *bob = new Character("bob");

//     // Create a materia source
//     IMateriaSource *src = new MateriaSource();
//     MateriaSource *src2 = new MateriaSource();

//     // Learn some materia
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     // Create a materia
//     AMateria *ice = src->createMateria("ice");
//     AMateria *cure = src->createMateria("cure");

//     // Equip some materia
//     me->equip(ice);
//     me->equip(cure);

//     // Use the materia
//     me->use(0, *bob);
//     me->use(1, *bob);

//     // // Unequip the materia
//     me->unequip(0);
//     me->unequip(1);

//     // Use the materia after unequipping
//     me->use(0, *bob);
//     me->use(1, *bob);

//     // Delete the character
//     delete me;
//     delete bob;
//     delete src;
//     delete src2;
//     delete ice;
//     delete cure;

//     return 0;
// }
