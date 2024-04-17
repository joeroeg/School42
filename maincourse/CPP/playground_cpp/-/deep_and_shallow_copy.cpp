#include <iostream>

/*
Shallow vs. Deep Copy:

Shallow Copy: The default behavior of a compiler-generated copy constructor,
which simply copies values of each field from one object to another.
If the field is a pointer, the pointer's address is copied but not the data it points to.

Deep Copy: Involves copying the actual data pointed to by the pointers,
not just the address, so that each object has its own copy of the data.
This is necessary when the class manages dynamic memory or other resources that should not be shared between instances.

Need for Deep Copy Logic:
When your class holds resources like dynamically allocated memory, file handles, network connections, etc.,
a shallow copy could lead to issues such as double-free errors or resource leaks when one object is deleted or goes out of scope.
Implementing deep copy logic in the copy constructor ensures each object instance maintains its own separate copy of resources, thereby preventing such issues.
*/

/**
 * Shallow Copy Example:
 * In this example, the Shallow class performs a shallow copy of the data pointer.
 * Because `data` is a pointer, using data(source.data) means both the original object and the new object will point to the same memory location.
 * They are both referencing the same dynamically allocated integer.
*/
class Shallow {
private:
    int* data;  // Pointer to an int
public:
    // Constructor that allocates memory for an int and initializes it
    Shallow(int d) {
        data = new int(d);  // Allocate memory for an int and store the address in data
    }

    // Shallow Copy Constructor
    Shallow(const Shallow &source) : data(source.data) { // Copying the pointer, not the data pointed to by the pointer
        std::cout << "Shallow copy performed." << std::endl;
        // Syntax data(source.data):
        // source is the object being copied.
        // source.data accesses the data member of source, which is a pointer to an int.
        // data(source.data) initializes the data pointer of the new object with the same memory address as the data pointer of the source object.
        // Consequence of data(source.data)
        // Both the original and the new Shallow objects now have their data members pointing to the same int in memory.
        // There is no new memory allocation; the address is merely copied.
        // When one of these objects is destroyed, it will delete the memory pointed to by data.
        // Since both objects point to the same memory, the second object to be destroyed will attempt to delete memory that has already been freed, leading to undefined behavior like crashes or data corruption.
    }
    ~Shallow() {
        delete data;  // Free the memory allocated for data
    }
    int getData() {
        return *data;
    }
};


class Deep {
private:
    int* data;
public:
    Deep(int d) {
        data = new int(d);
    }
    // Deep Copy Constructor
    Deep(const Deep &source) {
        data = new int(*source.data); // Copying the data pointed to, not the pointer
        std::cout << "Deep copy performed." << std::endl;
    }
    ~Deep() {
        delete data;
    }
    int getData() {
        return *data;
    }
};

int main() {

    // In this deep copy example, obj1 and obj2 each manage their own copy of data.
    // Modifications or destruction of one object's data will not affect the other.
    Deep obj1(200);
    Deep obj2 = obj1;  // Deep copy

    std::cout << "Data of obj1: " << obj1.getData() << std::endl;
    std::cout << "Data of obj2: " << obj2.getData() << std::endl;


    // In this example, obj3 and obj4 both point to the same data.
    // If one of them modifies the data or one object is deleted (leading to the destruction of data),
    // it can lead to undefined behavior for the other object.
    Shallow obj3(200);
    Shallow obj4 = obj3;  // Shallow copy

    std::cout << "Data of obj1: " << obj3.getData() << std::endl;
    std::cout << "Data of obj2: " << obj4.getData() << std::endl;

    return 0;
}
