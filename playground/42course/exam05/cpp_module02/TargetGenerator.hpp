#pragma once
#include <iostream>
#include <string>
#include <map>
#include "ATarget.hpp"

class ATarget;

class TargetGenerator {
private:
    TargetGenerator & operator=(TargetGenerator const & other);
    TargetGenerator(TargetGenerator const & other);
    std::map <std::string, ATarget * > _TargetGenerator;

public:
    TargetGenerator();
    ~TargetGenerator();

    void learnTargetType(ATarget * spell);
    void forgetTargetType(std::string const & spell);
    ATarget * createTarget(std::string const & spell);
};
