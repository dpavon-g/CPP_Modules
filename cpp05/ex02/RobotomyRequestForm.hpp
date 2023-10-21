#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Aform.hpp"

class RobotomyRequestForm: public Form {
    private:
        std::string _target;
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(std::string _target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        ~RobotomyRequestForm();
        std::string getTarget() const;
        RobotomyRequestForm &operator=(const RobotomyRequestForm &form);
        void		execute(Bureaucrat const &executor) const;

};

#endif