#include "TargetGenerator.hpp"

TargetGenerator & TargetGenerator::operator=(TargetGenerator const & other) {
    _TargetGenerator = other._TargetGenerator;
    return *this;
};
TargetGenerator::TargetGenerator(TargetGenerator const & other) {
    *this = other;
};
TargetGenerator::TargetGenerator() {};
TargetGenerator::~TargetGenerator() {
    for (std::map<std::string, ATarget*>::iterator it = _TargetGenerator.begin(); it != _TargetGenerator.end(); ++it) {
		delete it->second;
	}
	_TargetGenerator.clear();
};

void TargetGenerator::learnTargetType(ATarget * target) {
    if (_TargetGenerator.find(target->getType()) == _TargetGenerator.end()) {
        _TargetGenerator[target->getType()] = target->clone();
    }
};

void TargetGenerator::forgetTargetType(std::string const & target) {
    if (_TargetGenerator.find(target) != _TargetGenerator.end()) {
        delete _TargetGenerator[target];
        _TargetGenerator.erase(target);
    }
};

ATarget * TargetGenerator::createTarget(std::string const & target) {
    ATarget * tmp = NULL;
    if (_TargetGenerator.find(target) != _TargetGenerator.end()) {
        tmp = _TargetGenerator[target];
    }
    return tmp;
};
