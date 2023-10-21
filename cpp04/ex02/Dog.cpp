#include "Dog.hpp"

Dog::Dog(): Animal("Dog"), brain(new Brain()) {
    std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(std::string type): Animal("Dog"), brain(new Brain()) {
    (void)type;
    std::cout << "Type(useless) Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy){
    std::cout << "Copy Dog constructor called" << std::endl;
}

Dog& Dog::operator=(Dog const &copy){
    Animal::operator=(copy);
    return *this;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Guau Guau!" << std::endl;
}
