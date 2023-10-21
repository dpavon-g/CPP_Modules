#include "Harl.hpp"

void    Harl::debug( void ) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-picklespecial-ketchup burger. I really do!\n" << std::endl;
}

void    Harl::info( void ) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void    Harl::warning( void ) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void    Harl::error( void ) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now. \n" << std::endl;
}

void    Harl::complain(std::string level) {
    void        (Harl::*myPointer[4])(void);
    std::string functions[4];
    int         counter;

    myPointer[0] = &Harl::debug;
    myPointer[1] = &Harl::info;
    myPointer[2] = &Harl::warning;
    myPointer[3] = &Harl::error;

    functions[0] = "debug";
    functions[1] = "info";
    functions[2] = "warning";
    functions[3] = "error";

    counter = 0;

    while (counter < 4) {
        if (level == functions[counter]) {
            (this->*myPointer[counter])();
            break;
        }
        counter++;
    }
}