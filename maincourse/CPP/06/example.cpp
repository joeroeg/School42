#include <iostream>

// Base class
class Base {
public:
    virtual void virtualFunc() { std::cout << "Base virtualFunc" << std::endl; }
    virtual void pureVirtualFunc() = 0;
};

// Derived class
class Derived : public Base {
public:
    void virtualFunc() { std::cout << "Derived virtualFunc" << std::endl; }
    void pureVirtualFunc() { std::cout << "Derived pureVirtualFunc" << std::endl; }
};

int main() {
    Derived d;
    Base* b = &d;
    b->virtualFunc();
    b->pureVirtualFunc();
    return 0;
}
