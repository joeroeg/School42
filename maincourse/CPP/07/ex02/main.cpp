#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

void testDefaultConstructor() {
    Array<int> arr;
    std::cout << "Testing Default Constructor:" << std::endl;
    if (arr.size() == 0) {
        std::cout << "PASS: Size is correctly set to 0." << std::endl;
    } else {
        std::cout << "FAIL: Size is not 0." << std::endl;
    }

    // out_of_range exception test
    try {
        int test = arr[0];  // This should throw an exception
        (void)test;
        std::cout << "FAIL: Accessing element did not throw an exception." << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "PASS: Triggered exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "FAIL: Threw an unexpected exception type: " << e.what() << std::endl;
    }
}

void testParameterizedConstructor() {
    const size_t n = 10;
    Array<int> arr(n);
    std::cout << "\nTesting Parameterized Constructor:" << std::endl;
    // Size test
    if (arr.size() == n) {
        std::cout << "PASS: Size is correctly set to " << n << "." << std::endl;
    } else {
        std::cout << "FAIL: Size is not correctly set. Expected " << n << ", got " << arr.size() << "." << std::endl;
    }

    // Initialized to zero test
    bool allInitializedCorrectly = true;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] != 0) {
            allInitializedCorrectly = false;
            std::cout << "FAIL: Element at index " << i << " is not initialized to 0, value is " << arr[i] << "." << std::endl;
            break;
        }
    }
    if (allInitializedCorrectly) {
        std::cout << "PASS: All elements initialized to 0." << std::endl;
    }
}

void testCopyConstructor() {
    std::cout << "\nTesting Copy Constructor:" << std::endl;
    Array<int> original(1);
    original[0] = 42;

    Array<int> copy = original;

    // Check copied content
    if (copy[0] == original[0]) {
        std::cout << "PASS: Copied correctly." << std::endl;
    } else {
        std::cout << "FAIL: Did not copy content correctly." << std::endl;
    }

    // Check if the copy remains unchanged
    original[0] = 100;
    if (copy[0] != 100) {
        std::cout << "PASS: Copy remains unchanged" << std::endl;
    } else {
        std::cout << "FAIL: Copy does not remain unchanged" << std::endl;
    }
}

void testAssignmentOperator() {
    std::cout << "\nTesting Assignment operator:" << std::endl;
    Array<int> source(1);
    source[0] = 42;

    Array<int> assigned;
    assigned = source;

    if (assigned[0] == source[0]) {
        std::cout << "PASS: Assignment is done" << std::endl;
    } else {
        std::cout << "Test FAIL" << std::endl;
    }
}

void testElementAccess() {
    std::cout << "\nTesting Element Access:" << std::endl;
    Array<int> arr(1);
    arr[0] = 42;
    bool success = arr[0] == 42;

    if (success) {
        std::cout << "PASS: Element Access successful: " << arr[0] << std::endl;
    } else {
        std::cout << "FAIL: Element Access failed" << std::endl;
    }
}

void testOutOfBoundsAccess() {
    std::cout << "\nTesting Out of bounds:" << std::endl;
    Array<int> arr(3);
    try {
        int test = arr[5];
        (void)test;
        std::cout << "FAIL: Accessing element out of bounds did not throw an exception." << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "PASS: Triggered exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "FAIL: Threw an unexpected exception type: " << e.what() << std::endl;
    } catch (...) {
    }
}

void testSizeMethod() {
    std::cout << "\nTesting size method..." << std::endl;
    Array<int> arr(5);
    if (arr.size() == 5) {
        std::cout << "PASS: Size method returned correct size." << std::endl;
    } else {
        std::cout << "FAIL: Size method returned incorrect size." << std::endl;
    }
}

void testIntType() {
    std::cout << "\nTesting with int type..." << std::endl;
    Array<int> arr(5);
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = static_cast<int>(i * 5);
    }
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] != static_cast<int>(i * 5)) {
            std::cout << "FAIL: Test failed at index" << i << std::endl;
            return;
        }
    }
    std::cout << "PASS: Test passed successfully." << std::endl;
}

void testComplexType() {
    std::cout << "\nTesting with complex type..." << std::endl;
    Array < Array<int> > matrix(2);

    Array<int> row1(2);
    row1[0] = 1;
    row1[1] = 2;
    Array<int> row2(2);
    row2[0] = 3;
    row2[1] = 4;

    matrix[0] = row1;
    matrix[1] = row2;

    // Validate the matrix. This is done by
    bool success = (matrix[0][0] == 1 && matrix[0][1] == 2 &&
                    matrix[1][0] == 3 && matrix[1][1] == 4);

    std::cout << (success ? "PASS" : "FAIl")
              << " - Matrix: " << std::endl <<
              "[" << matrix[0][0] << "]" << "[" << matrix[0][1] << "]" << std::endl <<
              "[" << matrix[1][0] << "]" << "[" << matrix[1][1] << "]" << std::endl;
}

void testFundamentalVsClass() {
    std::cout << "\nTesting fundamental vs class type initialization..." << std::endl;
    Array<int> intArray(3);  // Should call default constructor for int (value-initialization)
    std::cout << "Testing with fundamental type:" << std::endl;
    for (size_t i = 0; i < intArray.size(); ++i) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;  // Expect 0 (value-initialized)
    }

    // Testing with a class type
    Array<std::string> stringArray(3);  // Should call std::string's default constructor
    std::cout << "\nTesting with class type:" << std::endl;
    for (size_t i = 0; i < stringArray.size(); ++i) {
        std::cout << "stringArray[" << i << "] = '" << stringArray[i] << "'" << std::endl;  // Expect empty strings
    }
}

void testReadWriteAccess() {
    std::cout << "\nTesting read-write access" << std::endl;
    Array<int> intArray(3); // read-write version of the array
    for (size_t i = 0; i < intArray.size(); ++i) {
        intArray[i] = i * 10;
        std::cout << "Before intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    for (size_t i = 0; i < intArray.size(); ++i) {
        intArray[i] += 5;  // Modify the values
        std::cout << " After intArray[" << i << "] = " << intArray[i] << std::endl;
    }
}

void testReadOnlyAccess() {
    std::cout << "\nTesting read-only access" << std::endl;
    Array<int> intArray(3);
    for (size_t i = 0; i < intArray.size(); ++i) {
        intArray[i] = i * 10;  // Initialize the array with some values
    }

    const Array<int> readOnlyArray = intArray;  // Create a read-only version of the array

    std::cout << "Testing read-only access:" << std::endl;
    for (size_t i = 0; i < readOnlyArray.size(); ++i) {
        std::cout << "readOnlyArray[" << i << "] = " << readOnlyArray[i] << std::endl;
        // Attempting to modify readOnlyArray[i] here would be a compile-time error
    }
    // Uncommenting the following line will result compile-time error
    // readOnlyArray[0] = 42;  // This should not compile
}


int testSubject() {
    std::cout << "\nTesting subject's test case" << std::endl;
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
            std::cerr << "Error: Data integrity check failed at index ❌" << i << std::endl;
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
    testDefaultConstructor();
    testParameterizedConstructor();
    testCopyConstructor();
    testAssignmentOperator();
    testElementAccess();
    testOutOfBoundsAccess();
    testSizeMethod();
    testIntType();
    testComplexType();
    testFundamentalVsClass();
    testReadWriteAccess();
    testReadOnlyAccess();
    testSubject();
    return 0;
}
