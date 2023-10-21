#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <cstdlib>
# include <stdexcept>
# include <vector>
# include <climits>
# include <algorithm>

class Span
{
    private:
        unsigned int _maxIntegers;
        std::vector<int> _vec;
    public:
        Span();
        Span(unsigned int n);
        Span(Span const &copy);
        ~Span();
        Span &operator=(Span const &copy);
        int     shortestSpan();
        int     longestSpan();
        void    addNumber(int n);
        void    getNumbers();

    template <typename InputIterator>
    void addRange(InputIterator begin, InputIterator end) {
        while (begin != end) {
            this->addNumber(*begin);
            ++begin;
        }
        std::cout << "Range added" << std::endl;
    }
};

#endif