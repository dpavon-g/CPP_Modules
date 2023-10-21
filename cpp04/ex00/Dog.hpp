#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal {
public:
    Dog();
    Dog(std::string type);
    Dog(const Dog &copy);
    Dog& operator=(Dog const &copy);
    ~Dog();
    virtual void makeSound() const;
};

#endif