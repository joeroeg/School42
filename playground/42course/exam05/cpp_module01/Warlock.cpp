#include "Warlock.hpp"

Warlock::Warlock() {};
Warlock & Warlock::operator=(Warlock const & other) { _name = other._name; _title = other._title; return *this; };
Warlock::Warlock(Warlock const & other) { *this = other; };
Warlock::Warlock(std::string const & name, std::string const & title) { _name = name; _title = title; std::cout << getName() << ": This looks like another boring day." << std::endl; };
Warlock::~Warlock() {
    std::cout << getName() << ": My job here is done!" << std::endl;
	for (std::map<std::string, ASpell*>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); ++it)
		delete it->second;
	_SpellBook.clear();
};
std::string const & Warlock::getName() const { return _name; };
std::string const & Warlock::getTitle() const { return _title; };
void Warlock::setTitle(std::string const & title) { _title = title; };
void Warlock::introduce() const { std::cout << getName() << ": I am " << getName() << ", " << getTitle() << "!" << std::endl; };

void Warlock::learnSpell(ASpell * spell) {
    if (_SpellBook.find(spell->getName()) == _SpellBook.end()) {
        _SpellBook[spell->getName()] = spell->clone();
    }
};

void Warlock::forgetSpell(std::string spell) {
    if (_SpellBook.find(spell) != _SpellBook.end()) {
        _SpellBook.erase(spell);
    }
};

void Warlock::launchSpell(std::string spell, ATarget const & target) {
    if (_SpellBook.find(spell) != _SpellBook.end()) {
        _SpellBook[spell]->launch(target);
    }
};
