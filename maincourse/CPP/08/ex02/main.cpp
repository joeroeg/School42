#include "MutantStack.hpp"

void testIteration() {
    std::cout << "Iteration" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);

    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << std::endl;
}

void testIteratorComparison() {
    std::cout << "Iterator comparison" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator end = mstack.end();

    std::cout << "it == end: " << (it == end) << std::endl;
    std::cout << "it != end: " << (it != end) << std::endl;
    std::cout << "it < end: " << (it < end) << std::endl;
    std::cout << "it > end: " << (it > end) << std::endl;
    std::cout << "it <= end: " << (it <= end) << std::endl;

}

void testModifyWhileIterating() {
    std::cout << "Modifying while iterating" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        if (*it == 5)
            *it = 42;
    }

    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

void subjectTest() {
    std::cout << "Subject test" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

}

void listTest() {
    std::cout << "List test" << std::endl;
    std::list<int> lst;
    lst.push_back(8);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::list<int> s(lst);

}

int main() {
    testIteration();
    testIteratorComparison();
    testModifyWhileIterating();
    subjectTest();
    listTest();
    return 0;
}
