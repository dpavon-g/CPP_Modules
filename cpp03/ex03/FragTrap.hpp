#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	protected:
		static const int _base_hitPoints = 100;
		static const int _base_energyPoints = 100;
		static const int _base_attackDamage = 30;

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		FragTrap& operator=(FragTrap const &Copy);
		~FragTrap();
		void	highFiveGuys();
		void	attack(std::string const &target);
};

#endif