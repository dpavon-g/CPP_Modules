#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

    class HumanA {
        private:
            std::string name;
            Weapon &human_weapon;
        public:
			HumanA(std::string _name, Weapon &_human_weapon);
			void		attack();
            std::string& getName();
            void		setName(std::string _name);
			void		setWeapon(Weapon &_human_weapon);
			Weapon&		getWeapon();
    };

#endif
