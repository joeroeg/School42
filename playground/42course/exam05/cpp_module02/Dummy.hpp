#pragma once
#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class Dummy : public ATarget {
public:
    Dummy();
    virtual ~Dummy();
    ATarget * clone() const;
};
