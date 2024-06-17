#include "SpellBook.hpp"

SpellBook & SpellBook::operator=(SpellBook const & other) {
    _SpellBook = other._SpellBook;
    return *this;
};
SpellBook::SpellBook(SpellBook const & other) {
    *this = other;
};
SpellBook::SpellBook() {};
SpellBook::~SpellBook() {
    for (std::map<std::string, ASpell*>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); ++it) {
		delete it->second;
	}
	_SpellBook.clear();
};

void SpellBook::learnSpell(ASpell * spell) {
    if (_SpellBook.find(spell->getName()) == _SpellBook.end()) {
        _SpellBook[spell->getName()] = spell->clone();
    }
};

void SpellBook::forgetSpell(std::string const & spell) {
    if (_SpellBook.find(spell) != _SpellBook.end()) {
        delete _SpellBook[spell];
        _SpellBook.erase(spell);
    }
};

ASpell * SpellBook::createSpell(std::string const & spell) {
    ASpell * tmp = NULL;
    if (_SpellBook.find(spell) != _SpellBook.end()) {
        tmp = _SpellBook[spell];
    }
    return tmp;
};
