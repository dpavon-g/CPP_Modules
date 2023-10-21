#ifndef WRONGWrongDOG_HPP
# define WRONGWrongDOG_HPP

# include "WrongAnimal.hpp"

class WrongDog: public WrongAnimal {
public:
    WrongDog();
    WrongDog(std::string type);
    WrongDog(const WrongDog &copy);
    WrongDog& operator=(WrongDog const &copy);
    ~WrongDog();
    void makeSound() const;
};

#endif