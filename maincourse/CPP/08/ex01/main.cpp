#include "Span.hpp"

void subjectTest(void) {
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void addRangeTest(void) {
    try {
        Span sp1 = Span(10);
        sp1.addRange(1, 10);
        sp1.printNumbers();
        std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void outOfRangeTest(void) {
    try {
        Span sp3 = Span(3);
        for (int i = 0; i < 4; ++i)
            sp3.addNumber(i);
        sp3.addRange(5, 1);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void notEnoughElementsTest(void) {
    try {
        Span sp4 = Span(3);
        sp4.shortestSpan();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

int main(void) {
    notEnoughElementsTest();
    outOfRangeTest();
    subjectTest();
    addRangeTest();
    return 0;
}
