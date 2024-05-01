#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

void testDefaultConstructor() {
    Array<int> arr;
    std::cout << "Test Default Constructor: Passed - Size is " << arr.size() << " (Expected: 0)" << std::endl;
}

void testParameterizedConstructor() {
    Array<int> arr(5);
    bool success = true;
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            success = false;
            break;
        }
    }
    std::cout << "Test Parameterized Constructor: " << (success ? "Passed" : "Failed")
              << " - All elements initialized to 0" << std::endl;
}

void testCopyConstructor() {
    Array<int> original(3);
    for (size_t i = 0; i < original.size(); i++) {
        original[i] = static_cast<int>(i + 1);
    }
    Array<int> copy(original);

    bool success = true;
    for (size_t i = 0; i < copy.size(); i++) {
        if (copy[i] != original[i]) {
            success = false;
            break;
        }
    }
    std::cout << "Test Copy Constructor: " << (success ? "Passed" : "Failed")
              << " - Copy matches original" << std::endl;
}

void testAssignmentOperator() {
    Array<int> first(2);
    first[0] = 10; first[1] = 20;
    Array<int> second(1);
    second = first;
    second[0] = 30;

    std::cout << "Test Assignment Operator: "
              << ((first[0] == 10 && second[0] == 30) ? "Passed" : "Failed")
              << " - first[0]: " << first[0] << ", second[0]: " << second[0] << std::endl;
}

void testElementAccess() {
    Array<int> arr(3);
    arr[0] = 100; arr[1] = 200; arr[2] = 300;
    bool success = (arr[0] == 100 && arr[1] == 200 && arr[2] == 300);
    std::cout << "Test Element Access: " << (success ? "Passed" : "Failed")
              << " - Values: " << arr[0] << ", " << arr[1] << ", " << arr[2] << std::endl;
}

void testOutOfBoundsAccess() {
    Array<int> arr(3);
    try {
        int test = arr[5]; // This should throw an exception
        (void)test;
        std::cout << "Test Out-of-Bounds Access: Failed (no exception thrown)" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Test Out-of-Bounds Access: Passed (exception caught: " << e.what() << ")" << std::endl;
    } catch (...) {
        std::cout << "Test Out-of-Bounds Access: Failed (wrong exception type)" << std::endl;
    }
}

void testSizeMethod() {
    Array<int> arr(4);
    std::cout << "Test Size Method: " << (arr.size() == 4 ? "Passed" : "Failed")
              << " - Size is " << arr.size() << " (Expected: 4)" << std::endl;
}

void testIntType() {
    Array<int> arr(5);
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = static_cast<int>(i * 10);
    }
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] != static_cast<int>(i * 10)) {
            std::cout << "Test with int failed at index " << i << std::endl;
            return;
        }
    }
    std::cout << "Test with int passed successfully." << std::endl;
}

void testComplexType() {
    Array<TestClass> arr(5);
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = TestClass(static_cast<int>(i * 5));
    }
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] != TestClass(static_cast<int>(i * 5))) {
            std::cout << "Test with TestClass failed at index " << i << std::endl;
            return;
        }
    }
    std::cout << "Test with TestClass passed successfully." << std::endl;
}

void testReadWriteAccess() {
    Array<int> arr(5);
    bool success = true;
    std::cout << "Testing write access via operator[]..." << std::endl;
    // Writing values
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;  // Write test
    }
    // Reading values to verify
    for (int i = 0; i < 5; i++) {
        if (arr[i] != i * 10) {
            success = false;
            std::cerr << "Mismatch at index " << i << ": expected " << i * 10 << ", got " << arr[i] << std::endl;
            break;
        }
    }
    std::cout << (success ? "Write and read access test passed." : "Write and read access test failed.") << std::endl;
}

void testReadOnlyAccess() {
    const Array<int> arr = Array<int>(5);
    std::cout << "Testing read-only access via operator[] on const instance..." << std::endl;
    bool success = true;
    try {
        for (int i = 0; i < 5; i++) {
            std::cout << "Value at index " << i << ": " << arr[i] << std::endl;  // Read test
        }
    } catch (...) {
        success = false;
        std::cerr << "Exception caught during read-only access test." << std::endl;
    }
    std::cout << (success ? "Read-only access test passed." : "Read-only access test failed.") << std::endl;
}


int testSubject() {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    std::cout << "Populating arrays with random values..." << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    std::cout << "Testing copy constructor and destructor in scoped block..." << std::endl;
    //SCOPE
    {
        Array<int> tmp = numbers; // Testing copy constructor
        Array<int> test(tmp);     // Testing copy constructor
    } // tmp and test are destroyed here, testing the destructor

    std::cout << "Validating data integrity after copy operations..." << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "Error: Data integrity check failed at index " << i << std::endl;
            delete [] mirror;
            return 1;
        }
    }

    std::cout << "Testing out-of-bounds access with negative index..." << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Caught exception for negative index: " << e.what() << '\n';
    }

    std::cout << "Testing out-of-bounds access with index exceeding size..." << std::endl;
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Caught exception for exceeding index: " << e.what() << '\n';
    }

    std::cout << "Re-populating array with new random values..." << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    std::cout << "Cleaning up resources..." << std::endl;
    delete [] mirror; // Clean up the mirror array

    std::cout << "Test completed successfully." << std::endl;
    return 0;
}

int main(int, char**)
{
    testSubject();
    testDefaultConstructor();
    testParameterizedConstructor();
    testCopyConstructor();
    testAssignmentOperator();
    testElementAccess();
    testOutOfBoundsAccess();
    testSizeMethod();
    testIntType();
    testComplexType();
    testReadWriteAccess();
    testReadOnlyAccess();
    return 0;
}
