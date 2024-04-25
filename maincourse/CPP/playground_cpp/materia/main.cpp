#include "iostream"
#include "string"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Character.hpp"

int main()
{
    // parametrized constructor use example
    // AMateria original_materia("hello");
    // AMateria original_materia_2("world");
    // std::cout << original_materia.getType() << std::endl;

    // copy constructor use example
    // AMateria copy_materia = original_materia;
    // std::cout << copy_materia.getType() << std::endl;

    // assignment operator
    // copy_materia = original_materia_2;
    // std::cout << copy_materia.getType() << std::endl;

    // clone example
    // AMateria* ice = new Ice("Ice");
    // AMateria* clone = ice->clone();
    // std::cout << "Original type: " << ice->getType() << std::endl;
    // std::cout << "Cloned type: " << clone->getType() << std::endl;
    // delete ice;
    // delete clone;

    // character creation and inventory test
    Character hero("Hero");
    std::cout << hero.getName() << std::endl;
    hero.printInventory(hero);

    // use example
    AMateria* ice = new Ice("ice");
    Ice iceMateria;
    iceMateria.use(hero);

    // test equip
    hero.equip(ice);
    hero.equip(ice);
    hero.equip(ice);
    hero.equip(ice);
    hero.printInventory(hero);

    // test use target
    hero.use(0, hero);
    hero.use(1, hero);
    hero.use(2, hero);
    hero.use(3, hero);

    // test unequip
    hero.unequip(0);
    hero.unequip(1);
    hero.unequip(2);
    hero.unequip(3);
    hero.printInventory(hero);



    return 0;
}

/*
    // IMateriaSource* src = new MateriaSource();
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());
    // ICharacter* me = new Character("me");
    // AMateria* tmp;
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    // ICharacter* bob = new Character("bob");
    // me->use(0, *bob);
    // me->use(1, *bob);
    // delete bob;
    // delete me;
    // delete src;
*/
