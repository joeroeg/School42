#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*
Order of construction:
For meta (Animal):
    The Animal constructor is called.
For j (Dog):
    The Animal constructor is called first (base class constructor).
    Then the Dog constructor is called.
For i (Cat):
    The Animal constructor is called first (base class constructor
    Then the Cat constructor is called.

Order of destruction:
For meta (Animal):
    The Animal destructor is called.
For j (Dog):
    Because the pointer type is Animal*, and the destructor in Animal is declared as virtual, the Dog destructor is called first (polymorphic behavior).
    Then the Animal destructor is called.
For i (Cat):
    Similarly, the Cat destructor is called first (due to the virtual destructor in Animal).
    Then the Animal destructor is called.
*/


/*
Importance of Virtual Destructor
The key to ensuring that the correct destructors are called for derived classes when using base class pointers is to declare the destructor in the base class (Animal in this case) as virtual.
This ensures that the destructor for the derived class (Dog or Cat) is invoked even when the object is deleted through a base class (Animal*) pointer.
This prevents resource leaks and ensures proper cleanup of derived class resources.
*/

int main() {
    // Scope for correct Animal types
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); // Will output the cat sound!
        j->makeSound(); // Will output the dog sound!
        meta->makeSound(); // Will output the Animal sound!

        delete meta;
        delete j;
        delete i;
    }

    std::cout << "-----------------" << std::endl;

    // Scope for wrong Animal types
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* j = new WrongCat();
        const WrongAnimal* i = new WrongCat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); // Will output the wrong animal sound!
        j->makeSound(); // Will output the wrong animal sound!
        meta->makeSound(); // Will output the wrong animal sound!

        delete meta;
        delete j;
        delete i;
    }

    return 0;
}
