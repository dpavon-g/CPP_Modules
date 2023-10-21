#include "ClapTrap.hpp"

int main() {
	ClapTrap c1("Jose");
	ClapTrap c2 = c1;
	ClapTrap c3(c1);

	std::cout << c1.getEnergyPoints() << std::endl;
	c1.takeDamage(9);
	std::cout << c1.getEnergyPoints() << std::endl;
	c1.attack("Pepito");
}
