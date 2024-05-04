#include "easyfind.hpp"

#define NUM 5 // Number to search for

int main() {
    // Test with vector (S)
    {
        int arr[] = {1, 2, 3, 4, 5};
        std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
        try {
            std::vector<int>::iterator it = easyfind(vec, NUM);
            std::cout << "Value found in vector at index: " << std::distance(vec.begin(), it) << std::endl;
        } catch (std::exception &e) {
            std::cout << "Exception for vector: " << e.what() << std::endl;
        }
    }

    // Test with list
    {
        int arr[] = {1, 2, 3, 4, 5};
        std::list<int> lst(arr, arr + sizeof(arr) / sizeof(arr[0]));
        try {
            std::list<int>::iterator it = easyfind(lst, NUM);
            std::cout << "Value found in list at index: " << std::distance(lst.begin(), it) << std::endl;
        } catch (std::exception &e) {
            std::cout << "Exception for list: " << e.what() << std::endl;
        }
    }

    // Test with deque
    {
        int arr[] = {1, 2, 3, 4, 5};
        std::deque<int> deq(arr, arr + sizeof(arr) / sizeof(arr[0]));
        try {
            std::deque<int>::iterator it = easyfind(deq, NUM);
            std::cout << "Value found in deque at index: " << std::distance(deq.begin(), it) << std::endl;
        } catch (std::exception &e) {
            std::cout << "Exception for deque: " << e.what() << std::endl;
        }
    }

    // Test with set
    {
        int arr[] = {1, 2, 3, 4, 5};
        std::set<int> s(arr, arr + sizeof(arr) / sizeof(arr[0]));
        try {
            std::set<int>::iterator it = easyfind(s, NUM);
            std::cout << "Value found in set: " << *it << std::endl;
        } catch (std::exception &e) {
            std::cout << "Exception for set: " << e.what() << std::endl;
        }
    }

    // Test with map
    {
        std::map<int, std::string> m;
        m[1] = "one";
        m[2] = "two";
        m[3] = "three";
        m[4] = "four";
        m[5] = "five";
        try {
            std::map<int, std::string>::iterator it = easyfindMap(m, 5);
            std::cout << "Value found in map: " << it->first << std::endl;
        } catch (std::exception &e) {
            std::cout << "Exception for map: " << e.what() << std::endl;
        }
    }
    return 0;
}
