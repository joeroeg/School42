#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void testDeepCopy()
{
    Dog dog1;
    Dog dog2 = dog1;  // Using copy constructor
    Dog dog3;
    dog3 = dog1;      // Using copy assignment operator

    std::cout << "Dog1 brain address: " << dog1.getBrainAddress() << std::endl;
    std::cout << "Dog2 brain address: " << dog2.getBrainAddress() << std::endl;
    std::cout << "Dog3 brain address: " << dog3.getBrainAddress() << std::endl;

    dog1.modifyBrainIdea(0, "Idea 1");
    dog2.modifyBrainIdea(1, "Idea 2");
    dog3.modifyBrainIdea(2, "Idea 3");

    std::cout << "Dog1 brain idea 0: " << dog1.getBrainIdea(0) << std::endl;
    std::cout << "Dog2 brain idea 1: " << dog2.getBrainIdea(1) << std::endl;
    std::cout << "Dog3 brain idea 2: " << dog3.getBrainIdea(2) << std::endl;
}


int main() {

    Animal* animals[10];

    for (int i = 0; i < 5; ++i) {
        animals[i] = new Dog();
        animals[i + 5] = new Cat();
    }

    std::cout << "-------------------" << std::endl;

    // Example of polymorphism and checking for proper sounds and types
    for (int i = 0; i < 10; ++i) {
        animals[i]->makeSound();
    }

    std::cout << "-------------------" << std::endl;

    // Cleaning up
    for (int i = 0; i < 10; ++i) {
        delete animals[i];
    }

    std::cout << "-------------------" << std::endl;

    testDeepCopy();
    return 0;
}

