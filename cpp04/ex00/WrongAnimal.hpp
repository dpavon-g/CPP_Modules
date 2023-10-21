#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal& operator=(WrongAnimal const &copy);
        virtual ~WrongAnimal();
        void makeSound() const;
        std::string getType() const;
};

#endif
