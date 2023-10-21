#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>
# include <list>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        typedef typename std::deque<T>::iterator iterator;
        iterator begin(void);
        iterator end(void);
        MutantStack(const MutantStack &src);
        MutantStack &operator=(MutantStack const &);
        MutantStack();
        ~MutantStack();
};

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &rhs){
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs)
        this.c = rhs.c;
    return (*this);
}

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
    std::cout << "Default <MutantStack> constructor called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src) {
    std::cout << "Copy <MutantStack> constructor called" << std::endl;
}

template<typename T>
MutantStack<T>::~MutantStack(){
    std::cout << "Destructor called" << std::endl;
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void){
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void){
	return (this->c.end());
}

#endif