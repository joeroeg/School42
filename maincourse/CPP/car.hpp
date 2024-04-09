#ifndef CAR_HPP
#define CAR_HPP
#include <string>

/**
 * @brief The Car class represents a vehicle with a make, model, and year.
 * The header file contains the class declaration
 * with the function prototypes and member variables.
 * The actual implementation of the class functions is in the source file.
 * The class definition is necessary to use the class in other parts of the program.
 * The #ifndef directive prevents multiple inclusions of the header file.
 *
*/

class Car {
private:
    std::string make;
    std::string model;
    int year;

public:
    Car(const std::string& make, const std::string& model, int year); // Constructor
    ~Car(); // Destructor
    Car(const Car& other); // Copy constructor
    Car& operator=(const Car& other); // Copy assignment operator

    void drive() const;
    void display() const;
};

#endif // CAR_HPP
