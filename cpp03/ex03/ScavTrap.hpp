#ifndef ScavTRAP_HPP
# define ScavTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	protected:
		static const int _base_hitPoints = 100;
		static const int _base_energyPoints = 50;
		static const int _base_attackDamage = 20;
	
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		ScavTrap& operator=(ScavTrap const &Copy);
		~ScavTrap();
		void	guardGate();
		void	attack(std::string const &target);
};

#endif