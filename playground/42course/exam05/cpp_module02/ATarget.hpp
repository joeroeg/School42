#pragma once
#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget {
protected:
    std::string _type;

public:
    ATarget();
    ATarget & operator=(ATarget const & other);
    ATarget(ATarget const & other);
    ATarget(std::string const & type); // not clear if it's reference or string
    virtual ~ATarget();
    std::string const & getType() const;
    void getHitBySpell(ASpell const & spell) const;

    virtual ATarget * clone() const = 0;
};
