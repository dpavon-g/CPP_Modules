#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

# include <iostream>

    template<typename T>
    void swap(T &a, T &b){
        T aux = a;
        a = b;
        b = aux;
    }

    template<typename T>
    T min(T const &a, T const &b){
        if (a < b)
            return a;
        else
            return b;
    }

    template<typename T>
    T max(T const &a, T const &b) {
        if (a > b)
            return a;
        else
            return b;
    }

#endif