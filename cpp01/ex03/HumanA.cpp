#include "HumanA.hpp"

void HumanA::setWeapon(Weapon &_human_weapon) {
	this->human_weapon = _human_weapon;
}

HumanA::HumanA(std::string _name, Weapon &_human_weapon):human_weapon(_human_weapon) {
	setName(_name);
	setWeapon(_human_weapon);
}

void HumanA::setName(std::string _name) {
    this->name = _name;
}

std::string &HumanA::getName() {
	return this->name;
}


Weapon& HumanA::getWeapon() {
	return this->human_weapon;
}


void HumanA::attack() {
    std::cout << getName() << " attacks with his " << getWeapon().getType() << std::endl;
}

