#include "iostream"
#include "string"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <cassert>

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

    delete newIce;
}

void subjectTestCase()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice"); // leak occur here
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

// void CreateMateriaLeak()
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     AMateria* tmp;
//     tmp = src->createMateria("ice"); // leak occur here

//     delete src;
// }

void CreateMateriaLeak()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    AMateria* tmp;
    tmp = src->createMateria("ice"); // tmp now points to a cloned Ice object
    tmp = src->createMateria("cure");

    delete tmp;  // Correctly delete the cloned Ice object
    delete src;  // Delete the source after its use
}


int main() {
    // testConstructorsAndOperators();
    // testClone();
    // testCharacterOperations();
    // testCharacterCopyAndAssignment();
    // testMateriaSource();
    subjectTestCase();
    // CreateMateriaLeak();


    return 0;
}

// int main()
// {
//     // parametrized constructor use example
//     AMateria original_materia("hello");
//     AMateria original_materia_2("world");
//     std::cout << original_materia.getType() << std::endl;

//     // copy constructor use example
//     AMateria copy_materia = original_materia;
//     std::cout << copy_materia.getType() << std::endl;

//     // assignment operator
//     copy_materia = original_materia_2;
//     std::cout << copy_materia.getType() << std::endl;

//     // clone example
//     AMateria* ice = new Ice("Ice");
//     AMateria* clone = ice->clone();
//     std::cout << "Original type: " << ice->getType() << std::endl;
//     std::cout << "Cloned type: " << clone->getType() << std::endl;
//     delete ice;
//     delete clone;

//     // character creation and inventory test
//     std::cout << "\ncharacter creation and inventory test(Character class)" << std::endl;
//     Character hero("Hero");
//     std::cout << hero.getName() << std::endl;
//     hero.printInventory(hero);

//     // use example
//     std::cout << "\ntest use (Ice class)" << std::endl;
//     AMateria* ice = new Ice("ice");
//     Ice iceMateria;
//     iceMateria.use(hero);

//     // // test equip (Icharacter class)
//     std::cout << "\ntest equip (Icharacter class)" << std::endl;
//     hero.equip(ice);
//     hero.equip(ice);
//     hero.equip(ice);
//     hero.equip(ice);
//     hero.printInventory(hero);

//     // // test use on target (Icharacter class)
//     std::cout << "\ntest use on target (Icharacter class)" << std::endl;
//     hero.use(0, hero);
//     hero.use(1, hero);
//     hero.use(2, hero);
//     hero.use(3, hero);

//     // // test unequip (Icharacter class)
//     std::cout << "\ntest unequip (Icharacter class)" << std::endl;
//     hero.unequip(0);
//     hero.unequip(1);
//     hero.unequip(2);
//     hero.unequip(3);
//     hero.printInventory(hero);

//     // test copy constructor of Character
//     std::cout << "\ntest copy constructor (Character class)" << std::endl;
//     std::cout << "hero" << std::endl;
//     hero.equip(ice);
//     hero.equip(ice);
//     hero.equip(ice);
//     hero.equip(ice);

//     Character hero_copy = hero;
//     std::cout << "\nhero inventory;" << std::endl;
//     hero.printInventory(hero);

//     std::cout << "\nhero_copy inventory;" << std::endl;
//     hero_copy.printInventory(hero_copy);

//     // test assignment operator of Character
//     std::cout << "\ntest assignment operator of Character (Character class)" << std::endl;
//     hero_copy = hero;
//     hero_copy.printInventory(hero_copy);

//     // test unequip
//     std::cout << "\ntest unequip (Character class)" << std::endl;
//     hero.printInventory(hero);
//     hero.unequip(0);
//     hero.unequip(1);
//     hero.unequip(2);
//     hero.unequip(3);
//     hero.unequip(0);
//     hero.unequip(1);
//     hero.unequip(2);
//     hero.unequip(3);
//     hero.printInventory(hero);
//     hero_copy.printInventory(hero_copy);


//     // test MateriaSource
//     std::cout << "Testing MateriaSource functionality...\n";
//     Character hero("Hero");
//     MateriaSource source;
//     hero.printInventory(hero);
//     AMateria* ice = new Ice();
//     source.learnMateria(ice);
//     AMateria* newIce = source.createMateria("ice");
//     hero.printInventory(hero);
//     hero.use(0, hero);

//     delete ice;
//     cleanupDroppedMateria();
//     std::cout << "\nDestructors" << std::endl;

//     return 0;
// }

// int main() {
//     MateriaSource source;
//     Ice* ice = new Ice();
//     // Cure* cure = new Cure();

//     // Test learnMateria
//     source.learnMateria(ice);
//     // source.learnMateria(cure);

//     // Test createMateria
//     AMateria* iceClone = source.createMateria("ice");
//     // AMateria* cureClone = source.createMateria("cure");
//     // AMateria* fireClone = source.createMateria("fire");

//     // Character interaction
//     Character hero("Hero");
//     hero.equip(iceClone);  // Equip cloned Ice
//     // hero.equip(cureClone); // Equip cloned Cure

//     std::cout << "Hero's Inventory after equipping Ice and Cure:" << std::endl;
//     hero.printInventory(hero);  // Should show Ice and Cure

//     // Testing use
//     hero.use(0, hero);  // Use Ice on self
//     // hero.use(1, hero);  // Use Cure on self

//     delete ice;
//     // delete cure;
//     // Assume proper deletion of clones in Character destructor

//     return 0;
// }

// int main() {
//     MateriaSource source;
//     source.learnMateria(new Ice());
//     source.learnMateria(new Cure());

//     AMateria* ice = source.createMateria("ice");
//     if (ice) {
//         std::cout << "Ice created successfully" << std::endl;
//     }

//     AMateria* cure = source.createMateria("cure");
//     if (cure) {
//         std::cout << "Cure created successfully" << std::endl;
//     }

//     AMateria* fire = source.createMateria("fire");
//     if (!fire) {
//         std::cout << "No fire materia available" << std::endl;
//     }

//     // Safely delete and handle pointers
//     delete ice;
//     delete cure;
//     // No need to delete fire as it's nullptr

//     return 0;
// }


// int main() {

//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     ICharacter* me = new Character("me");
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);
//     delete bob;
//     delete me;
//     delete src;
//     return 0;
// }
