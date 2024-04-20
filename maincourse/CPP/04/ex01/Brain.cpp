#include "Brain.hpp"

// Default constructor
Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

// Copy constructor
// Brain::Brain(const Brain &copy) {
//     *this = copy;
//     std::cout << "Brain copy constructor called" << std::endl;
// }

Brain::Brain(const Brain &copy) {
    std::copy(copy.ideas, copy.ideas + 100, ideas);
}

// Assignation operator
Brain &Brain::operator=(const Brain &copy) {
    if (this != &copy) {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = copy.ideas[i];
        std::cout << "Brain assignation operator called" << std::endl;
    }
    return *this;
}

// Destructor
Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

// Getter for idea
std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return ideas[index];
    }
    return "";
}

// Setter for idea
void Brain::setIdea(int index, std::string idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
}

// Getter for address
std::string Brain::getAddress() const {
    return std::to_string(reinterpret_cast<std::uintptr_t>(this));
}

