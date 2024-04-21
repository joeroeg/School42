#include <iostream>
#include <unordered_map>
/*

The prototype pattern is a creational design pattern in software development. It is used when the type of objects to create is determined by a prototypical instance, which is cloned to produce new objects. This pattern is used to:
- Avoid subclasses of an object creator in the client application, like the factory method pattern does.
- Avoid the inherent cost of creating a new object in the standard way (e.g., using the 'new' keyword) when it is prohibitively expensive for a given application.
https://en.wikipedia.org/wiki/Prototype_pattern
https://youtu.be/tv-_1er1mWI?si=wJn9JIrkR8Nsfnhe&t=144


Explanation:
Prototype Pattern: GraphicTool uses a prototype Graphic to create new objects. The clone() method is used for this purpose.
Simulating Dynamic Loading: We simulate dynamic class instantiation with the createGraphicByName function, which acts like a simple factory based on input from the user.
Run-time Flexibility: Users specify what type of graphic object they want at runtime, and the appropriate class is instantiated.


Let's consider a practical scenario adding a new type of game character, let's say a "Goblin,".
This example will clearly demonstrate what changes need to be made when introducing new functionality.


*/

class GameCharacter {
public:
    virtual GameCharacter* clone() const = 0;
    virtual void interact() const = 0;
    virtual ~GameCharacter() {
        std::cout << "Destroying " << typeid(*this).name() << " at " << this << std::endl;
    }

protected:
    int health;
    int speed;
};

class Orc : public GameCharacter {
public:
    Orc() {
        health = 100;
        speed = 50;
        std::cout << "Creating Orc at " << this << std::endl;
    }
    Orc(const Orc& other) {
        health = other.health;
        speed = other.speed;
        std::cout << "Cloning Orc. Original at " << &other << ", Clone at " << this << std::endl;
    }
    GameCharacter* clone() const  {
        return new Orc(*this);
    }
    void interact() const  {
        std::cout << "Orc interacts at " << this << " with Health: " << health << std::endl;
    }
};

class Elf : public GameCharacter {
public:
    Elf() {
        health = 80;
        speed = 100;
        std::cout << "Creating Elf at " << this << std::endl;
    }
    Elf(const Elf& other) {
        health = other.health;
        speed = other.speed;
        std::cout << "Cloning Elf. Original at " << &other << ", Clone at " << this << std::endl;
    }
    GameCharacter* clone() const  {
        return new Elf(*this);
    }
    void interact() const  {
        std::cout << "Elf interacts at " << this << " with Speed: " << speed << std::endl;
    }
};

class Goblin : public GameCharacter {
public:
    Goblin() {
        health = 60;
        speed = 70;
        std::cout << "Creating Goblin at " << this << std::endl;
    }
    Goblin(const Goblin& other) {
        health = other.health;
        speed = other.speed;
        std::cout << "Cloning Goblin. Original at " << &other << ", Clone at " << this << std::endl;
    }
    GameCharacter* clone() const override {
        return new Goblin(*this);
    }
    void interact() const override {
        std::cout << "Goblin interacts at " << this << " with Speed: " << speed << std::endl;
    }
};


// int main() {
//     std::cout << "Creating prototypes:" << std::endl;
//     GameCharacter* orcPrototype = new Orc();
//     GameCharacter* elfPrototype = new Elf();
//     GameCharacter* goblinPrototype = new Goblin();

//     // Store prototypes in a map
//     std::unordered_map<std::string, GameCharacter*> prototypes;
//     prototypes["Orc"] = orcPrototype;
//     prototypes["Elf"] = elfPrototype;
//     prototypes["Goblin"] = goblinPrototype;

//     std::cout << "\nCloning prototypes:" << std::endl;
//     GameCharacter* orcClone = orcPrototype->clone();
//     GameCharacter* elfClone = elfPrototype->clone();
//     GameCharacter* goblinClone = goblinPrototype->clone();

//     orcClone->interact();
//     elfClone->interact();
//     goblinClone->interact();

//     delete orcPrototype;
//     delete elfPrototype;
//     delete goblinPrototype;
//     delete orcClone;
//     delete elfClone;
//     delete goblinClone;

//     return 0;
// }


/*
Using an unordered_map to Manage Prototypes
To enhance the flexibility and manageability of your prototypes, you can integrate an unordered_map.
This would allow you to store and retrieve prototypes using a string identifier, making it easier to add new types or manage existing ones without altering the main flow of your program.
This approach also simplifies the process of cloning specific types based on runtime decisions or configuration settings.
*/

int main() {
    std::unordered_map<std::string, GameCharacter*> prototypes;
    prototypes["Orc"] = new Orc();
    prototypes["Elf"] = new Elf();
    prototypes["Goblin"] = new Goblin();

    std::cout << "\nCloning prototypes:" << std::endl;
    GameCharacter* orcClone = prototypes["Orc"]->clone();
    GameCharacter* elfClone = prototypes["Elf"]->clone();
    GameCharacter* goblinClone = prototypes["Goblin"]->clone();

    orcClone->interact();
    elfClone->interact();
    goblinClone->interact();

    // Clean up
    for (auto& pair : prototypes) {
        delete pair.second;
    }
    delete orcClone;
    delete elfClone;
    delete goblinClone;

    return 0;
}
