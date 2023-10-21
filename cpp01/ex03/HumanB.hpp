#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

    class HumanB {
        private:
            std::string name;
            Weapon *human_weapon;
        public:
			HumanB(std::string _name);
			void		attack();
            std::string getName();
            void		setName(std::string _name);
			void		setWeapon(Weapon &_human_weapon);
			Weapon		*getWeapon();
    };

#endif
