#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

# include <iostream>
# include <stdexcept>
# include <vector>

    template <typename T>
    
    typename T::iterator easyfind(T& container, int value) {
        typename T::iterator it;
        for (it = container.begin(); it != container.end(); ++it) {
            if (*it == value) {
                return it;
            }
        }
        throw::std::runtime_error("No value matches!!");
    }

#endif