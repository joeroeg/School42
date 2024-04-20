#include <iostream>

class GameCharacter {
public:
    virtual GameCharacter* clone() const = 0;
    virtual void interact() const = 0;
    virtual ~GameCharacter() {
        std::cout << "Destroying " << typeid(*this).name() << " at " << this << std::endl;
    }

    // Example attributes
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

int main() {
    std::cout << "Creating prototypes:" << std::endl;
    GameCharacter* orcPrototype = new Orc();
    GameCharacter* elfPrototype = new Elf();

    std::cout << "\nCloning prototypes:" << std::endl;
    GameCharacter* orcClone = orcPrototype->clone();
    GameCharacter* elfClone = elfPrototype->clone();

    orcClone->interact();
    elfClone->interact();

    delete orcPrototype;
    delete elfPrototype;
    delete orcClone;
    delete elfClone;

    return 0;
}
