#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
}

std::string Zombie::get_name() {
    return (this->_name);
}


void Zombie::set_name(std::string name) {
    this->_name = name;
}

void Zombie::announce(void) {
    std::cout << get_name() << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->_name << std::endl;
}