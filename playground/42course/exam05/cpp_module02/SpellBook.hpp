#pragma once
#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"

class ASpell;

class SpellBook {
private:
    SpellBook & operator=(SpellBook const & other);
    SpellBook(SpellBook const & other);
    std::map <std::string, ASpell * > _SpellBook;

public:
    SpellBook();
    ~SpellBook();

    void learnSpell(ASpell * spell);
    void forgetSpell(std::string const & spell);
    ASpell * createSpell(std::string const & spell);
};
