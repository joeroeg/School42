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
    std::cout << "\ncharacter creation and inventory test(Character class)" << std::endl;
    Character hero("Hero");
    // std::cout << hero.getName() << std::endl;
    // hero.printInventory(hero);

    // use example
    std::cout << "\ntest use (Ice class)" << std::endl;
    AMateria* ice = new Ice("ice");
    // Ice iceMateria;
    // iceMateria.use(hero);

    // // test equip (Icharacter class)
    // std::cout << "\ntest equip (Icharacter class)" << std::endl;
    // hero.equip(ice);
    // hero.equip(ice);
    // hero.equip(ice);
    // hero.equip(ice);
    // hero.printInventory(hero);

    // // test use on target (Icharacter class)
    // std::cout << "\ntest use on target (Icharacter class)" << std::endl;
    // hero.use(0, hero);
    // hero.use(1, hero);
    // hero.use(2, hero);
    // hero.use(3, hero);

    // // test unequip (Icharacter class)
    // std::cout << "\ntest unequip (Icharacter class)" << std::endl;
    // hero.unequip(0);
    // hero.unequip(1);
    // hero.unequip(2);
    // hero.unequip(3);
    // hero.printInventory(hero);

    // test copy constructor of Character
    std::cout << "\ntest copy constructor (Character class)" << std::endl;
    std::cout << "hero" << std::endl;
    hero.equip(ice);
    hero.equip(ice);
    hero.equip(ice);
    hero.equip(ice);
    Character hero_copy = hero;
    // std::cout << "\nhero inventory;" << std::endl;
    // hero.printInventory(hero);

    // std::cout << "\nhero_copy inventory;" << std::endl;
    // hero_copy.printInventory(hero_copy);

    // // test assignment operator of Character
    // std::cout << "\ntest assignment operator of Character (Character class)" << std::endl;
    // hero_copy = hero;
    // hero_copy.printInventory(hero_copy);

    delete ice;
    std::cout << "\nDestructors" << std::endl;

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
