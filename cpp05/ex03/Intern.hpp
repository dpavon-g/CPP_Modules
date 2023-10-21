#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Form;

class Intern
{

    public:

        class invalidForm: public std::exception {
            public:
                const char* what() const throw() {
                    return "Error. Invalid name for a Form!!";
                }
        };
        
        Intern();
        ~Intern();
        Form* makeForm(std::string formName, std::string targetForm);
    };

#endif