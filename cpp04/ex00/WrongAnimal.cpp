#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("WrongAnimal"){
    std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type) {
    std::cout << "Type WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
    std::cout << "Copy WrongAnimal constructor called" << std::endl;
    *this = copy;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &copy) {
    this->_type = copy._type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "The Wronganimal has made a strange sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->_type;
}
