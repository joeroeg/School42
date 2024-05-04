#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack(void) {};
    ~MutantStack(void) {};
    MutantStack(MutantStack const &src) { *this = src; }
    MutantStack &operator=(MutantStack const &src) { (void)src; return *this; }

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};

#endif
