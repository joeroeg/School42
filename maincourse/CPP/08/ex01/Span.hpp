#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <cstdlib>

class Span {
private:
	size_t				_maxSize;
	std::vector<int>	_vec;

public:
    Span(void);
    Span(size_t n);
    Span(Span const& src);
    ~Span(void);
    Span& operator=(Span const& rhs);

    void	addNumber(int);
    void	addNumber(std::vector<int>::const_iterator, std::vector<int>::const_iterator);
    size_t	shortestSpan(void) const;
    size_t	longestSpan(void) const;
    void	addRange(int, int);
    void    printNumbers() const;

};

#endif
