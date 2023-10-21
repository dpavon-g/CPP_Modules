#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
    std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type): WrongAnimal("WrongCat") {
    (void)type;
    std::cout << "Type(useless) WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy){
    std::cout << "Copy WrongCat constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const &copy){
    WrongAnimal::operator=(copy);
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Miau Miau!" << std::endl;
}
