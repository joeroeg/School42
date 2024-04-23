#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

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

class ICharacter;

class AMateria {
protected:
std::string _type;

public:
    AMateria(); // default constructor
    AMateria(std::string const& type); // parameterized constructor
    virtual ~AMateria(); // destructor
    AMateria(AMateria const& src); // copy constructor
    AMateria & operator=(AMateria const & src); // assignment operator

    std::string const& getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
