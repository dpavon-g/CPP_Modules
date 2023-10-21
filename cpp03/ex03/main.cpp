#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	DiamondTrap joselito("Joselito");

	// joselito.attack("Juan antonio");
	// joselito.ClapTrap::attack("Antonio");
	DiamondTrap pepe;

	pepe = joselito;

	// std::cout << pepe.getName() << std::endl;
	// std::cout << pepe.ClapTrap::getName() << std::endl;
	std::cout << joselito.getHitPoints() << std::endl;
	std::cout << joselito.getEnergyPoints() << std::endl;
	std::cout << joselito.getAttackDamage() << std::endl;
	std::cout << pepe.getHitPoints() << std::endl;
	std::cout << pepe.getEnergyPoints() << std::endl;
	std::cout << pepe.getAttackDamage() << std::endl;
	// pepe.attack("Antonio");
	// pepe.whoAmI();
}