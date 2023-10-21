#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
    std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
    std::cout << "Name FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &Copy) : ClapTrap(Copy) {
    std::cout << "Copy FragTrap constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &Copy) {
    ClapTrap::operator=(Copy);
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFiveGuys(){
    std::cout << "FragTrap " << this->getName() << " has requested to high five!" << std::endl;
}

void FragTrap::attack(std::string const &target) {
	if (this->getHitPoints() > 0) {
		if (this->getEnergyPoints() == 0)
			std::cout << "FragTrap " << this->getName() << " dont have enough energypoints!" << std::endl;
		else {
			this->setEnergyPoints(this->getEnergyPoints() - 1);
			std::cout << "FragTrap " << this->getName() << " attack " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		}
	}
	else
		std::cout << "FragTrap " << this->getName() << " is dead!!" << std::endl;
}