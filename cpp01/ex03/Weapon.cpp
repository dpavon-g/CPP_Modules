#include "Weapon.hpp"

std::string &Weapon::getType() {
    return (this->type);
}

Weapon::Weapon() {
    this->type = "default weapon";
}

Weapon::Weapon(std::string _name) {
	setType(_name);
}

void Weapon::setType(std::string _type) {
    this->type = _type;
}

Weapon::~Weapon() {
    std::cout << "Throw weapon" << std::endl;
}
