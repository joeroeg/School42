#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <map>

class Harl {
private:
    void debug();
    void info();
    void warning();
    void error();

    typedef void (Harl::*array_func)();

public:
    Harl();
    void complain(std::string level);
};

#endif
