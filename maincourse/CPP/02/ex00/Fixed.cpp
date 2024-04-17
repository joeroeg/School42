#include "Fixed.hpp"

/**
 * A default constructor is a constructor that is called when an object is instantiated without any arguments.
 * It is used to initialize the object's state to default values or perform any other setup operations.
 * If a class does not provide any constructors, the compiler generates a default constructor implicitly.
 * However, if a user-defined constructor is provided, the compiler does not generate a default constructor.
 * In such cases, if an object is instantiated without arguments and no default constructor is defined,
 * the compiler will raise an error. Therefore, it is good practice to define a default constructor explicitly.
 *
 * This default constructor initializes the 'fixed_point_value' member variable to 0.
 * It also prints a message to the console to indicate that the default constructor has been called.
 * This message can be useful for debugging and understanding the sequence of constructor calls.
*/
Fixed::Fixed() : _fixed_point_value(0) {
    std::cout << "Default constructor called" << std::endl;
}

/**
 * A copy constructor initializes a new instance of a class by copying an existing instance of the same class.
 * It is implicitly invoked in the following scenarios:
 * 1. When initializing a new object as a copy of an existing object.
 * 2. When an object is passed by value to a function.
 * 3. When an object is returned by value from a function.
 *
 * If a user-defined copy constructor is not provided:
 * - The compiler generates a default copy constructor, which performs a shallow copy. This default behavior applies unless:
 *   a) A user-defined destructor or assignment operator is provided,
 *      in which case the compiler's default behavior may not suffice for proper duplication of resources.
 *
 * Specific calls to the copy constructor include:
 * 1. Passing an object by value as a function argument.
 * 2. Returning an object by value from a function.
 * 3. Directly initializing one object from another (e.g., Fixed b = a;).
 *
 * Important: If a class manages resources that require deep copies (like dynamic memory),
 * a user-defined copy constructor is necessary to ensure each instance manages its own resources.
 *
 * Can we make a copy constructor private?
 * Yes, making the copy constructor private prevents the creation of new instances by copying an existing object.
 * This can be useful in scenarios where copying is not allowed or desired, such as singleton classes.
 * However, it may also lead to compilation errors in cases where the copy constructor is implicitly invoked.
 * To prevent such errors, the copy constructor can be declared private without providing an implementation.
 * This way, the class itself can still use the copy constructor, but other code cannot.
 *
 * this* - is a pointer to the object that is being created.
 * other - is a reference to the object that is being copied.s
 */
Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

/**
 * The copy assignment operator is used to assign the state of one instance of a class to another existing instance.
 * It is typically invoked in the following scenarios:
 * 1. When an object is assigned to another using the assignment operator (e.g., a = b;).
 *
 * This implementation of the copy assignment operator includes:
 * - A check for self-assignment: If the source and the destination objects are the same (checked using their addresses),
 *   the function returns immediately to prevent unnecessary operations and potential errors.
 * - Direct field-wise copying: Each field of the source object is copied to the destination object. Here, only
 *   'fixed_point_value' is copied, assuming no resource management beyond simple data fields is required.
 *
 * Best Practices:
 * - The operator returns a reference to the current instance (*this) to allow chaining of assignment operations
 *   (e.g., a = b = c;).
 * - Implementing the operator with a self-assignment check is crucial for safety in cases where the class manages
 *   dynamic memory or other resources that could lead to issues like resource leaks or double frees.
 *
 * Can we make a copy assignment operator private?
 * Yes, making the copy assignment operator private prevents the assignment of one object to another.
 * This can be useful in scenarios where assignment is not allowed or desired, such as singleton classes.
 * However, it may also lead to compilation errors in cases where the assignment operator is implicitly invoked.
 * To prevent such errors, the assignment operator can be declared private without providing an implementation.
 * This way, the class itself can still use the assignment operator, but other code cannot.
 */
Fixed &Fixed::operator=(const Fixed &other) {
    // The function's name operator= tells the compiler that this function is going to define the behavior of the = operator for the Fixed class.
    // const Fixed &other - The parameter is a reference to a const Fixed object. Using a reference avoids copying the object during the call. The const keyword indicates that the function will not modify the object other.
    // Fixed & - The return type. This function returns a reference to the instance (*this) that it just assigned to. Returning a reference allows for chain assignments like a = b = c.
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixed_point_value = other._fixed_point_value;
    }
    return *this;
}

/**
 * A destructor is a special member function that is called when an object goes out of scope or is explicitly deleted.
 * It is used to release resources acquired by the object during its lifetime, such as dynamic memory allocations.
 * The destructor is called automatically by the compiler when the object is destroyed.
 * If a class does not provide a destructor, the compiler generates a default destructor implicitly.
 * However, if a user-defined destructor is provided, the compiler does not generate a default destructor.
 * In such cases, if an object is destroyed and no destructor is defined, the compiler will raise an error.
 * Therefore, it is good practice to define a destructor explicitly.
*/
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fixed_point_value;
}

void Fixed::setRawBits(int const raw) {
    _fixed_point_value = raw;
}
