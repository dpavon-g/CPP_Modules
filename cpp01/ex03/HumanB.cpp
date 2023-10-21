#include "HumanB.hpp"

void HumanB::setWeapon(Weapon &_human_weapon) {
	this->human_weapon = &_human_weapon;
}

HumanB::HumanB(std::string _name){
	setName(_name);
	human_weapon = NULL;
}

void HumanB::setName(std::string _name) {
    this->name = _name;
}

std::string HumanB::getName() {
	return this->name;
}


Weapon *HumanB::getWeapon() {
	return this->human_weapon;
}


void HumanB::attack() {
    std::cout << getName() << " attacks with his " << getWeapon()->getType() << std::endl;
}

