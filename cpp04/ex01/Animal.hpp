#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &copy);
        Animal& operator=(Animal const &copy);
        virtual ~Animal();
        virtual void makeSound() const;
        virtual std::string getType() const;
};

#endif
