#pragma once
#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell {
protected:
    std::string _name;
    std::string _effects;

public:
    ASpell();
    ASpell & operator=(ASpell const & other);
    ASpell(ASpell const & other);
    ASpell(std::string const & name, std::string const & effects); // not clear if it's reference or string
    virtual ~ASpell();
    std::string getName() const;
    std::string getEffects() const;
    void launch(ATarget const & target) const;

    virtual ASpell * clone() const = 0;
};
