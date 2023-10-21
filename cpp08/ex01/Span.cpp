#include "Span.hpp"


Span::Span(unsigned int n): _maxIntegers(n) {
    std::cout << "Number <Span> constructor called" << std::endl;
}

Span::Span(): _maxIntegers(0) {
    std::cout << "Default empty <Span> constructor called" << std::endl;
}

Span::Span(Span const &copy) {
    *this = copy;
    std::cout << "Copy constructor called" << std::endl;
}

Span &Span::operator=(Span const &copy) {
    if (this != &copy) {
        this->_maxIntegers = copy._maxIntegers;
        this->_vec = copy._vec;
    }
    return *this;
}

void    Span::addNumber(int n) {
    if (this->_vec.size() >= this->_maxIntegers) {
        throw::std::runtime_error("Error. Too much numbers!!");
        return;
    }
    this->_vec.push_back(n);
    return;
}

int		Span::shortestSpan() {
	int diff;
	int span = INT_MAX;
	if (this->_vec.size() <= 1)
		throw std::runtime_error("Error. Cant calculate span");
	std::vector<int> tmp(_vec.size());
	std::copy(_vec.begin(), _vec.end(), tmp.begin());
	std::sort(tmp.begin(), tmp.end());
    int i = 0;
    while (i < (int)tmp.size() - 1) {
        diff = tmp[i] - tmp[i - 1];
		if (diff && diff < span)
			span = diff;
        i++;
    }
	if (span == INT_MAX)
		throw std::runtime_error("Error. No span found");
	return span;
}

int		Span::longestSpan() {
	if (this->_vec.size() <= 1)
		throw std::runtime_error("Error. Cant calculate span");
	int span =	*std::max_element(_vec.begin(), _vec.end())
		-	*std::min_element(_vec.begin(), _vec.end());
	if (!span)
		throw std::runtime_error("Error. No span found");
	return span;
}

void Span::getNumbers() {
    int i;

    i = 0;
    while (i < (int)_vec.size()) {
        std::cout << "Number: " << _vec[i] << std::endl;
        i++;
    }
}

Span::~Span()
{
    std::cout << "Default destructor called" << std::endl;
}