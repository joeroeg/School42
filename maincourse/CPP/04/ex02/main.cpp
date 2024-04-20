#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/**
 * @brief because the Animal class is abstract, we can't create an instance of it
*/
int main() {

    // Scope for correct Animal types
    {
        // const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); // Will output the cat sound!
        j->makeSound(); // Will output the dog sound!
        // meta->makeSound(); // Will output the Animal sound!

        // delete meta;
        delete j;
        delete i;
    }

    return 0;
}

