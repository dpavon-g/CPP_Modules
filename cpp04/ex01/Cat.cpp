#include "Cat.hpp"

Cat::Cat(): Animal("Cat"), brain(new Brain()) {
    std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(std::string type): Animal("Cat"), brain(new Brain()) {
    (void)type;
    std::cout << "Type(useless) Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy){
    std::cout << "Copy Cat constructor called" << std::endl;
}

Cat& Cat::operator=(Cat const &copy){
    Animal::operator=(copy);
    return *this;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Miau Miau!" << std::endl;
}
