#include <iostream>
#include <string>

/*
The class definition is a crucial aspect of object-oriented programming in C++,
where you outline the structure and behaviors that objects of the class should exhibit.
A well-defined class serves as a blueprint for objects, encapsulating data and functions together,
which makes the program more modular, maintainable, and reusable.

## Class Definition Components
    Data Members: Variables used to store the state of an object.
    Member Functions: Functions that define the behaviors of an object.
    Access Specifiers: Keywords that set the accessibility of the class members.
        Public: Members are accessible from anywhere where the object is visible.
        Private: Members are only accessible within other members of the same class or by friends.
        Protected: Members are accessible within the class and by derived classes.

## Best Practices for Class Definitions
- Encapsulation: Keep data members private as much as possible. This protects the object's integrity by preventing external code from changing its internal state directly.
- Interface and Implementation Separation: Provide a clean interface for usage by other code, hiding the implementation details.
- Use Constructors for Initialization: Always ensure that objects start in a valid state by initializing all members via constructors.
- Explicit Constructors: Mark single-argument constructors as explicit to prevent unexpected type conversions.
- Consistent Accessor/Mutator Functions: Provide functions for accessing and modifying the data members if they are private.
- Resource Management: Follow the Rule of Three (or Five in C++11 and later) if your class manages resources like dynamic memory or file handles:
    Destructor: Cleans up resources.
    Copy Constructor: Ensures deep copy if needed.
    Copy Assignment Operator: Provides copying functionality.
    Move Constructor and Move Assignment Operator (C++11): Provides efficient transfer of resources from temporary objects.
- Avoid Excessive Use of Friend Classes and Functions: They can break encapsulation.
- Inheritance Design: Use virtual functions for methods expected to be overridden in derived classes. Prefer composition over inheritance where appropriate.

## Explanation of the Example

Encapsulation: model, year, and fuelAmount are private, ensuring they can't be modified directly from outside the class.
Initialization: The constructor initializes all members to ensure the Car object starts in a consistent state.
Access and Modification: Public methods provide controlled access to the object's properties and allow for specific behaviors like driving and refueling.
Resource Management: Although this simple example doesn't manage resources that require deep copying or moving, proper destructors are still defined for good practice.
*/

class Car {
private:
    std::string model;
    int year;
    double fuelAmount;

    void checkFuel() const {
        if (fuelAmount <= 0) {
            std::cout << "Fuel tank is empty." << std::endl;
        }
    }

public:
    // Constructor
    explicit Car(std::string m, int y) : model(std::move(m)), year(y), fuelAmount(50.0) {}

    // Destructor
    ~Car() {
        std::cout << "Destroying " << model << ", " << year << std::endl;
    }

    // Accessors
    std::string getModel() const { return model; }
    int getYear() const { return year; }
    double getFuelAmount() const { return fuelAmount; }

    // Behavior method
    void drive(double miles) {
        double fuelNeeded = miles / 25.0; // Assuming 25 miles per gallon
        if (fuelNeeded > fuelAmount) {
            std::cout << "Not enough fuel to drive." << std::endl;
            checkFuel();
        } else {
            fuelAmount -= fuelNeeded;
            std::cout << "Driving " << miles << " miles. Remaining fuel: " << fuelAmount << " gallons." << std::endl;
        }
    }

    // Mutator
    void refuel(double gallons) {
        fuelAmount += gallons;
        std::cout << "Refueled " << gallons << " gallons. Total fuel: " << fuelAmount << " gallons." << std::endl;
    }
};

int main() {
    Car myCar("Toyota Camry", 2020);
    myCar.drive(100);
    myCar.refuel(20);
    return 0;
}
