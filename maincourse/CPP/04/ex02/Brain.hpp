#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
private:
    std::string ideas[100];

public:
    Brain(); // Default constructor
    Brain(const Brain &copy); // Copy constructor
    Brain &operator=(const Brain &copy); // Assignation operator
    ~Brain(); // Destructor

    std::string getIdea(int index) const; // Getter for idea
    void setIdea(int index, std::string idea); // Setter for idea
    std::string getAddress() const;
};

#endif
