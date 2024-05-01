#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {
public:
    virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate() {
    srand(static_cast<unsigned int>(time(NULL)));
    int r = rand() % 3;
    switch (r) {
        case 0: return (std::cout << "A\n", new A());
        case 1: return (std::cout << "B\n", new B());
        case 2: return (std::cout << "C\n", new C());
    }
    return NULL;
}

/**
 * @param dynamic_cast<new_type>(expression)
 * @param new_type: The target type to which the cast is attempted.
 * @param expression: The variable or expression being cast.
 * @note When used with pointers, dynamic_cast checks if the conversion can be made safely.
 * If the cast is successful, it returns a pointer of the new type pointing to the same object.
 * If the cast fails, it returns nullptr.
*/
void identify(Base* p) {
    if (dynamic_cast<A*>(p)) std::cout << "A\n";
    else if (dynamic_cast<B*>(p)) std::cout << "B\n";
    else if (dynamic_cast<C*>(p)) std::cout << "C\n";
    else std::cout << "Unknown type\n";
}

/**
 * @note When used with references, since references cannot be null, dynamic_cast throws an exception of type std::bad_cast if the cast fails:
 * If the cast is successful, it returns a reference to the new type.
 * If the cast fails, it throws a std::bad_cast exception.
*/
void identify(Base& p) {
    try {
        A& aRef = dynamic_cast<A&>(p);
        (void)aRef;
        std::cout << "A\n";
    } catch (const std::bad_cast&) {
        try {
            B& bRef = dynamic_cast<B&>(p);
            (void)bRef;
            std::cout << "B\n";
        } catch (const std::bad_cast&) {
            try {
                C& cRef = dynamic_cast<C&>(p);
                (void)cRef;
                std::cout << "C\n";
            } catch (const std::bad_cast&) {
                std::cout << "Unknown type\n";
            }
        }
    }
}

// This example will work but might throw an exception that is not handled properly.
// void identify(Base& p) {
//     if (dynamic_cast<A*>(&p)) std::cout << "A\n";
//     else if (dynamic_cast<B*>(&p)) std::cout << "B\n";
//     else if (dynamic_cast<C*>(&p)) std::cout << "C\n";
//     else std::cout << "Unknown type\n";
// }

int main() {
    Base* nullPtr = NULL;
    identify(nullPtr);
    for (int i = 0; i < 1; ++i) {
        Base* obj = generate();
        if (obj != NULL) {
            identify(obj);
            identify(*obj);
        }
        delete obj;
    }
    return 0;
}

