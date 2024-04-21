#include <iostream>
#include <string>


/*
Direct Instantiation Approach
In this version, we'll use a simple function or method that constructs game characters based on a specified type. This approach removes the cloning mechanism and instead relies on directly creating new instances based on the type argument.

Key Differences from Prototype Pattern Implementation:
- No Cloning: There's no clone() method or any mechanism related to copying existing objects. Each character is instantiated fresh from the class constructor based on the type string provided.
- Type-Based Creation: A factory function (createCharacter) checks the type string and instantiates the appropriate subclass of GameCharacter. This requires modification of the factory function whenever new character types are added, which can increase maintenance complexity.
- Memory Management: Similar to the Prototype version, each character's creation and destruction are logged to track memory allocation and deallocation.

Comparison and Insights:
- Flexibility and Extensibility: The direct instantiation method is less flexible compared to the Prototype pattern. Adding a new character type requires changes to the factory function, whereas in the Prototype pattern, adding a new type only involves creating another prototype instance without changing existing code.
- Coupling: The factory function is more tightly coupled to the specific classes (Orc, Elf), which isn't ideal for scaling up with many different character types.
- Complexity: Direct instantiation is straightforward but can become cumbersome and error-prone as more types are added, especially in comparison to the Prototype pattern that abstracts the creation process into a cloning operation, simplifying the management of diverse object types.

Let's consider a practical scenario adding a new type of game character, let's say a "Goblin,".
This example will clearly demonstrate what changes need to be made when introducing new functionality.





*/
class GameCharacter {
public:
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
    void interact() const override {
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
    void interact() const override {
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
    void interact() const override {
        std::cout << "Goblin interacts at " << this << " with Speed: " << speed << std::endl;
    }
};

// Factory for creating GameCharacters by type name
GameCharacter* createCharacter(const std::string& type) {
    if (type == "Orc") {
        return new Orc();
    } else if (type == "Elf") {
        return new Elf();
    }
    else if (type == "Goblin") {
        return new Goblin();  // Newly added code
    }
    return nullptr;
}


int main() {
    GameCharacter* orc = createCharacter("Orc");
    GameCharacter* elf = createCharacter("Elf");
    GameCharacter* goblin = createCharacter("Goblin");


    orc->interact();
    elf->interact();
    goblin->interact();

    delete orc;
    delete elf;
    delete goblin;

    return 0;
}
