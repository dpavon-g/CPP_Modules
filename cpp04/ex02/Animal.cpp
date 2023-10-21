#include "Animal.hpp"

Animal::Animal(): _type("Animal"){
    std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(std::string type): _type(type) {
    std::cout << "Type Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) {
    std::cout << "Copy Animal constructor called" << std::endl;
    *this = copy;
}

Animal& Animal::operator=(Animal const &copy) {
    this->_type = copy._type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "The animal has made a strange sound" << std::endl;
}

std::string Animal::getType() const {
    return this->_type;
}
