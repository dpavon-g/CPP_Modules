#include "Brain.hpp"

Brain::Brain() {
    int i = 0;
    while (i < 100) {
        this->ideas[i] = "Thinks"; 
        i++;
    }
    std::cout << "Default brain constructor called" << std::endl;
}

Brain::Brain(const Brain &copy) {
    *this = copy;
    std::cout << "Copy brain constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &toCopy) {
    if (this != &toCopy) {
        int i = 0;
        while (i < 100) {
            this->ideas[i] = toCopy.ideas[i];
            i++;
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain Destructor called" << std::endl;
}

