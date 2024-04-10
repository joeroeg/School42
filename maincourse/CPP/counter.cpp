#include <iostream>

class Counter {
public:
    static int count; // Declaration of a static member variable

    // Constructor
    Counter() {
        // Increment the count for each object created
        count++;
    }
};

// Definition and initialization of the static member variable
int Counter::count = 0;

int main() {
    Counter obj1; // First object, count is now 1
    Counter obj2; // Second object, count is now 2

    // Even though we access count through different objects,
    // the value of count is shared among all instances.
    std::cout << "Count from obj1: " << obj1.count << std::endl;
    std::cout << "Count from obj2: " << obj2.count << std::endl;

    // It's more common and appropriate to access static members through the class name
    std::cout << "Count from class: " << Counter::count << std::endl;

    return 0;
}
