#include "WrongDog.hpp"

WrongDog::WrongDog(): WrongAnimal("WrongDog") {
    std::cout << "Default WrongDog constructor called" << std::endl;
}

WrongDog::WrongDog(std::string type): WrongAnimal("WrongDog") {
    (void)type;
    std::cout << "Type(useless) WrongDog constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog &copy) : WrongAnimal(copy){
    std::cout << "Copy WrongDog constructor called" << std::endl;
}

WrongDog& WrongDog::operator=(WrongDog const &copy){
    WrongAnimal::operator=(copy);
    return *this;
}

WrongDog::~WrongDog() {
    std::cout << "WrongDog Destructor called" << std::endl;
}

void WrongDog::makeSound() const {
    std::cout << "Guau Guau!" << std::endl;
}