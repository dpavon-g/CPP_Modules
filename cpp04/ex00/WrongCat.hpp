#ifndef WRONGWrongCAT_HPP
# define WRONGWrongCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
public:
    WrongCat();
    WrongCat(std::string type);
    WrongCat(const WrongCat &copy);
    WrongCat& operator=(WrongCat const &copy);
    ~WrongCat();
    void makeSound() const;
};

#endif