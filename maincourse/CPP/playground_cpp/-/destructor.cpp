#include <iostream>

class Base {
public:
    virtual ~Base() {
        std::cout << "Base destructor called" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived destructor called" << std::endl;
    }
};

class MoreDerived : public Derived {
public:
    ~MoreDerived() {
        std::cout << "MoreDerived destructor called" << std::endl;
    }
};

int main() {
    Base* b = new MoreDerived();
    delete b;  // Properly calls MoreDerived's destructor, then Derived's, then Base's destructor
    return 0;
}
