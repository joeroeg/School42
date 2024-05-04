#include "Span.hpp"

Span::Span(void) : _maxSize(0) {}
Span::Span(size_t n) : _maxSize(n) {}
Span::Span(Span const& src) { *this = src; }
Span::~Span(void) {}
Span& Span::operator=(Span const& rhs) {
    if (this != &rhs) {
        _maxSize = rhs._maxSize;
        _vec = rhs._vec;
    }
    return *this;
}

void Span::addNumber(int n) {
    if (_vec.size() < _maxSize) {
        _vec.push_back(n);
    } else {
        throw std::runtime_error("Container is full");
    }
}

void Span::addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
    if (_vec.size() + std::distance(begin, end) <= _maxSize) {
        _vec.insert(_vec.end(), begin, end);
    } else {
        throw std::runtime_error("Container is full");
    }
}

size_t Span::shortestSpan(void) const {
    if (_vec.size() < 2)
        throw std::runtime_error("Not enough elements to calculate span");
    std::vector<int> sorted = _vec;
    std::sort(sorted.begin(), sorted.end());
    size_t minSpan = INT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i) {
        size_t span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

size_t Span::longestSpan(void) const {
    if (_vec.size() < 2)
        throw std::runtime_error("Not enough elements to calculate span");
    return *std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end());
}

void Span::addRange(int start, int end) {
    if (start > end)
        throw std::out_of_range("Invalid range");
    else if (_vec.size() + (end - start + 1) > _maxSize)
        throw std::out_of_range("Adding range exceeds maximum size of Span");
    srand(time(NULL));
    for (int i = start; i <= end; ++i) {
        int randomNumber = rand() % (end - start + 1) + start;
        _vec.push_back(randomNumber);
    }
}

void Span::printNumbers() const {
    std::cout << "Numbers in Span:" << std::endl;
    for (size_t i = 0; i < _vec.size(); ++i) {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;
}
