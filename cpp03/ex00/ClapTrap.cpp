#include "ClapTrap.hpp"

//Canonical class functions

ClapTrap::ClapTrap(): _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &copy) {
	this->_attackDamage = copy.getAttackDamage();
	this->_name = copy.getName();
	this->_hitPoints = copy.getHitPoints();
	this->_energyPoints = copy.getEnergyPoints();
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

// Getters and setters

std::string ClapTrap::getName(void) const {
	return this->_name;
}

int ClapTrap::getHitPoints(void) const {
	return this->_hitPoints;
}

int ClapTrap::getEnergyPoints(void) const {
	return this->_energyPoints;
}

int ClapTrap::getAttackDamage(void) const {
	return this->_attackDamage;
}

void ClapTrap::setAttackDamage(unsigned int amount) {
	this->_attackDamage = amount;
}

void ClapTrap::setEnergyPoints(unsigned int amount) {
	this->_energyPoints = amount;
}

void ClapTrap::setHitPoints(unsigned int amount) {
	this->_hitPoints = amount;
}

// Expected funtions

void ClapTrap::attack(std::string const &target) {
	if (this->getHitPoints() > 0) {
		if (this->getEnergyPoints() == 0)
			std::cout << "ClapTrap " << this->getName() << " dont have enough energypoints!" << std::endl;
		else {
			this->setEnergyPoints(this->getEnergyPoints() - 1);
			std::cout << "ClapTrap " << this->getName() << " attack " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		}
	}
	else
		std::cout << "ClapTrap " << this->getName() << " is dead!!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->getHitPoints() > 0) {
		if (this->getEnergyPoints() == 0)
			std::cout << "ClapTrap " << this->getName() << " dont have enough energypoints!" << std::endl;
		else {
			if (amount <= 0)
				std::cout << "Invalid repair amount" << std::endl;
			else {
				int hitpoints = this->getHitPoints();
				this->setHitPoints(hitpoints += amount);
				this->setEnergyPoints(this->getEnergyPoints() - 1);
				std::cout << "ClapTrap " << this->getName() << " has repaired " << amount << " hitPoints!" << std::endl;
			}
		}
	}
	else
		std::cout << "ClapTrap " << this->getName() << " is dead!!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->getHitPoints() > 0) {
		if (this->getEnergyPoints() > 0) {
			if (amount > 0) {
				if (amount > 10) {
					std::cout << "Attack Damage need to be less than 10" << std::endl;
					amount = 10;
				}
				std::cout << "ClapTrap " << this->getName() << " take " << amount << " attackdamage!" << std::endl;
				this->setAttackDamage(this->getAttackDamage() + amount);
				this->setEnergyPoints(this->getEnergyPoints() - 1);
			}
			else
				std::cout << "Invalid amount" << std::endl;
		}
		else
			std::cout << "ClapTrap " << this->getName() << " dont have enough energypoints!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->getName() << " is dead!!" << std::endl;

}