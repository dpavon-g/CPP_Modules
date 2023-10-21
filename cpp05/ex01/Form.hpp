#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_execute_grade;
	public:

		class GradeTooHighException: public std::exception {
		public:
    		const char* what() const throw() {
       			return "Error. Bureaucrat grade is too high!!";
   			}
		};

		class GradeTooLowException: public std::exception {
		public:
    		const char* what() const throw() {
       			return "Error. Bureaucrat grade is too low!!";
   			}
		};

		Form();
		Form(Form &copy);
		Form(std::string name, int sign_grade, int execute_grade);
		~Form();
		std::string get_name() const;
		bool		get_signed() const;
		int			get_sign_grade() const;
		int			get_execute_grade() const;
		void		beSigned(const Bureaucrat &b);
		Form		&operator=(const Form &copy);
		friend std::ostream& operator<<(std::ostream& os, const Form& form);

};

#endif