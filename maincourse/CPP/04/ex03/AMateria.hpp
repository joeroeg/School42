#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

/**
 * @brief The AMateria class is an abstract class that represents a materia.
 * @param clone() method is a typical implementation of the Prototype design pattern.
 * This pattern is used when the type of objects to create is determined by a prototypical instance, which is cloned to produce new objects.
 * This is particularly useful in systems where the object's class does not need to be known at compile time.
 *
 * Functionality:
 * 1. clone() allows creating a new AMateria object that is an exact copy of the object it is called on.
 * This is crucial because it allows you to duplicate AMateria instances without knowing their specific derived types.
 * 2. This method is declared as pure virtual in the AMateria class, making AMateria abstract and ensuring that all derived classes must provide their own implementation of clone().
 * This is important because each type of AMateria (like Ice or Cure) may have its own specific data that needs to be copied accurately.
 *
 * Example Use Case: magine you have a Character that can equip AMateria objects.
 * If the Character needs to duplicate its materias, perhaps to assign them to another Character,
 * it can use the clone() method on each AMateria it possesses to create new instances without any knowledge of their concrete classes.
 *
 * @param use() method is used to define what happens when an AMateria is used by a character, allowing for different behaviors depending on the type of materia.
 * Functionality: Unlike clone(), use() is not pure virtual and may have a default implementation in the AMateria base class.
 * However, it can (and usually should) be overridden in derived classes to provide specific effects appropriate for each type of materia.
 * This method takes an ICharacter reference as an argument, enabling interaction between the materia and the character.
 * It allows the materia to affect the character based on its unique properties (like dealing damage, healing, etc.).
 *
 * Example Use Case: In a game, when a Character uses an Ice materia, the use() method of the Ice class might reduce the temperature of the environment or deal frost damage to an enemy.
 * This method would be defined specifically within the Ice class to perform this action.
*/

/*
The clone() method is particularly associated with the Prototype design pattern, which is part of the Gang of Four (GoF) design patterns.
The Gang of Four refers to four authors—Erich Gamma, Richard Helm, Ralph Johnson, and John Vlissides—who collectively wrote the seminal book "Design Patterns: Elements of Reusable Object-Oriented Software" in 1994. This book is a foundational resource in object-oriented software engineering and describes various software design patterns, including the Prototype pattern.
*/

/*
Impact on Behavior
Flexibility: The use of clone() and use() allows for a flexible design where materias can be managed and utilized polymorphically.
Characters can interact with arrays of materias without knowing their specific types, allowing for easy expansion or modification of the types of materias available in the system.
Maintainability: With each materia type encapsulating its cloning and usage behavior, the system is easier to maintain and extend.
If new types of materias need to be added, they can be implemented without altering existing code—just by adding new classes that implement clone() and use().

clone() and use() are critical for allowing polymorphic behavior and dynamic instance management in your materia system,
facilitating complex interactions within your game-like simulation while maintaining the system's flexibility and maintainability.
*/

class AMateria {
protected:

public:
    AMateria(std::string const & type);
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
