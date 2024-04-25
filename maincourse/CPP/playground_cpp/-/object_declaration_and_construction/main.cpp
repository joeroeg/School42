
#include <iostream>
#include "Rectangle_simple.hpp"
#include "Rectangle.hpp"

/*
In C++, object declaration and construction are foundational aspects of working with classes.
They involve specifying a class type for creating an object and managing how the object's memory is allocated and initialized.


## Object Declaration and Construction

1. Object Declaration
    Purpose: To define a variable of a class type, which refers to an instance of that class.
    Syntax: ClassName objectName;
    Behavior: When you declare an object, C++ allocates memory for that object based on the class's definition. However, without explicit initialization (like using a constructor), primitive data types within the object may have indeterminate values.

2. Object Construction
Purpose: To initialize the object's data members when it is created.
Mechanisms:
    Default Constructor: Automatically called if no arguments are provided. Initializes an object's data members with default values.
    Parameterized Constructor: Takes one or more arguments and initializes the object's data members using those arguments.
    Copy Constructor: Initializes a new object as a copy of an existing object.
    List Initialization (C++11 and later): Uses curly braces {} to initialize data members.

## Best Practices for Object Declaration and Construction
- Proper Initialization: Always use constructors to ensure that all object members are properly initialized when the object is created. This prevents issues with uninitialized data that can lead to unpredictable behavior.
- Explicit Constructors: Declare single-argument constructors as explicit to prevent them from being used for implicit type conversions, which can lead to unexpected results.
- Resource Safety: For classes that manage resources (like dynamic memory), ensure the proper implementation of the Rule of Three/Five, which includes constructors, a destructor, and copy/move assignment operators to manage resource copying and cleanup correctly.
- Prefer Initialization Over Assignment: Use member initializer lists in constructors to initialize members rather than assigning them values in the constructor body. This is more efficient as it avoids initializing twice.
- Uniform Initialization: Use brace initialization (introduced in C++11) to prevent narrowing conversions and to provide a consistent syntax for initialization that works with most types.

*/

int main() {

	Rectangle_simple rect1;
    Rectangle_simple rect2(10, 10);

	// Using the Default Constructor
    Rectangle rect3;

    // Using the Parameterized Constructor
    Rectangle rect4(20, 20);

    // Using the Copy Constructor
    Rectangle rect5 = rect4;

    // List Initialization (C++11) g++ -std=c++11
    // Rectangle rect6 {5, 15};

    // Print areas
    std::cout << "Area of rect1: " << rect1.area() << std::endl;
    std::cout << "Area of rect2: " << rect2.area() << std::endl;
    std::cout << "Area of rect3: " << rect3.area() << std::endl;
    std::cout << "Area of rect4: " << rect4.area() << std::endl;
	std::cout << "Area of rect5: " << rect5.area() << std::endl;
	// std::cout << "Area of rect6: " << rect6.area() << std::endl;

    return 0;
}
