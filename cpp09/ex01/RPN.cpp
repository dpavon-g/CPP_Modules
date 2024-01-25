#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &copy) {
    this->stack = copy.stack;
}

RPN& RPN::operator=(const RPN& copy) {
    if (this != &copy)
        this->stack = copy.stack;
    return *this;
}

RPN::~RPN(){}

int RPN::calculate(const std::string &expresion) {
    std::string v;
    std::stringstream expString(expresion);
    int num1;
    int num2;
    while (expString >> v) {
        if (v == "+") {
            if (this->stack.size() < 2) {
                std::cout << "Error" << std::endl;
                return (-1);
            }
            num1 = this->stack.top();
            this->stack.pop();
            num2 = this->stack.top();
            this->stack.pop();
            this->stack.push(num1 + num2);
        }
        else if (v == "-") {
            if (this->stack.size() < 2) {
                std::cout << "Error" << std::endl;
                return (-1);
            }
            num1 = this->stack.top();
            this->stack.pop();
            num2 = this->stack.top();
            this->stack.pop();
            this->stack.push(num2 - num1);
        }
        else if (v == "/") {
            if (this->stack.size() < 2) {
                std::cout << "Error" << std::endl;
                return (-1);
            }
            num1 = this->stack.top();
            if (num1 == 0) {
                std::cout << "Error" << std::endl;
                return (-1);
            }
            this->stack.pop();
            num2 = this->stack.top();
            this->stack.pop();
            this->stack.push(num2 / num1);
        }
        else if (v == "*") {
            if (this->stack.size() < 2) {
                std::cout << "Error" << std::endl;
                return (-1);
            }
            num1 = this->stack.top();
            this->stack.pop();
            num2 = this->stack.top();
            this->stack.pop();
            this->stack.push(num1 * num2);
        }
        else {
            if (v.size() != 1) {
                std::cout << "Error" << std::endl;
                return -1;
            }
            else if (!(std::isdigit(v[0]))) {
                std::cout << "Error" << std::endl;
                return (-1);
            }
            else
                this->stack.push(atoi(v.c_str()));
        }
    }
    if (this->stack.size() != 1) {
        std::cout << "Error" << std::endl;
        return (-1);
    }
    std::cout << this->stack.top() << std::endl;
    return (0);
}