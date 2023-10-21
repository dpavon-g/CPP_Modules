#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Aform.hpp"

class PresidentialPardonForm: public Form {
    private:
        std::string _target;
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        ~PresidentialPardonForm();
        std::string getTarget() const;
        PresidentialPardonForm &operator=(const PresidentialPardonForm &form);
        void		execute(Bureaucrat const &executor) const;
};

#endif