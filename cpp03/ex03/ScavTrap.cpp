#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
    std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
    std::cout << "Name ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &Copy) : ClapTrap(Copy) {
    std::cout << "Copy ScavTrap constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &Copy) {
    ClapTrap::operator=(Copy);
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(std::string const &target) {
	if (this->getHitPoints() > 0) {
		if (this->getEnergyPoints() == 0)
			std::cout << "ScavTrap " << this->getName() << " dont have enough energypoints!" << std::endl;
		else {
			this->setEnergyPoints(this->getEnergyPoints() - 1);
			std::cout << "ScavTrap " << this->getName() << " attack " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		}
	}
	else
		std::cout << "ScavTrap " << this->getName() << " is dead!!" << std::endl;
}