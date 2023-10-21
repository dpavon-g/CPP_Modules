#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"), ScavTrap(), FragTrap() {
	this->_name = "";
	this->setHitPoints(this->FragTrap::_base_hitPoints);
	this->setEnergyPoints(this->ScavTrap::_base_energyPoints);
	this->setAttackDamage(this->FragTrap::_base_attackDamage);
    std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap() {
	this->_name = name;
	this->setHitPoints(this->FragTrap::_base_hitPoints);
	this->setEnergyPoints(this->ScavTrap::_base_energyPoints);
	this->setAttackDamage(this->FragTrap::_base_attackDamage);
    std::cout << "Name DiamondTrap constructor called" << std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap &Copy) : ClapTrap(Copy), ScavTrap(), FragTrap(), _name(Copy._name) {
	std::cout << "Copy DiamondTrap constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const &Copy) {
	this->_name = Copy._name;
    this->_hitPoints = Copy._hitPoints;
	this->_energyPoints = Copy._energyPoints;
	this->_attackDamage = Copy._attackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::whoAmI() {
	std::cout << "ClapTrap name: " << this->ClapTrap::getName() << std::endl;
	std::cout << "DiamondTrap name: " << this->getName() << std::endl;
}

std::string DiamondTrap::getName() {
	return this->_name;
}