#include "iostream"
#include "string"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

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
    hero.printInventory(hero);
    AMateria* ice = new Ice();

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
    hero.printInventory(hero);
    AMateria* ice = new Ice();

    hero.equip(ice);
    hero.equip(ice);
    hero.equip(ice);
    hero.equip(ice);

    Character hero_copy = hero;
    hero_copy.printInventory(hero_copy);
    hero_copy = hero;

    hero_copy.use(0, hero);
    hero_copy.use(1, hero);
    hero_copy.use(2, hero);
    hero_copy.use(3, hero);

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

    delete bob;
    delete me;
    delete src;
}

void multipleEquipTest() {
    Character hero("Hero");
    Character villain("Villain");
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    hero.equip(ice);
    hero.equip(cure);
    hero.equip(ice);
    hero.equip(cure);
    hero.equip(ice);
    hero.equip(cure);
    hero.equip(ice);
    hero.printInventory(hero);

    hero.use(0, villain);
    hero.use(1, villain);
    hero.use(2, villain);
    hero.use(3, villain);

    hero.unequip(0);
    hero.unequip(1);
    hero.unequip(2);
    hero.unequip(3);
    hero.unequip(4);
    hero.unequip(5);
    hero.printInventory(hero);

    cleanupDroppedMateria();
    delete ice;
    delete cure;
}

void materiaFactoryTest() {
    Character hero("Hero");
    ICharacter* villain = new Character("Villain");
    IMateriaSource* factory = new MateriaSource();
    AMateria* ice = new Ice();
    factory->learnMateria(ice);
    factory->learnMateria(new Cure());
    AMateria* tmp_storage;
    factory->createMateria("ice");
    tmp_storage = factory->createMateria("cure");

    hero.equip(ice);
    hero.equip(tmp_storage);
    hero.use(0, *villain);
    hero.use(1, hero);

    delete villain;
    delete factory;
}

int main() {
    testConstructorsAndOperators();
    testClone();
    testCharacterOperations();
    testCharacterCopyAndAssignment();
    testMateriaSource();
    multipleEquipTest();
    materiaFactoryTest();
    subjectTestCase();

    return 0;
}
