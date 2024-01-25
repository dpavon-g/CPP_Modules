#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>
# include <cctype>
# include <cstdlib>

class RPN
{
private:
    std::stack<int> stack;
public:
    RPN();
    ~RPN();
    RPN(const RPN &copy);
    RPN& operator=(const RPN& other);
    int calculate(const std::string &expresion);
};
#endif