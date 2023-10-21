#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <string>
# include "Aform.hpp"

class Form;

class Bureaucrat
{

	private:
		const std::string	_name;
		int			_grade;
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

		Bureaucrat();
		Bureaucrat(Bureaucrat &copy);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		std::string	get_name() const;
		int			get_grade()	const;
		void		increment_grade(int value);
		void		decrement_grade(int value);
		void		signForm(Form &f);
		void		executeForm(Form const &form);
		Bureaucrat& operator=(const Bureaucrat& other);
		friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureau);
};

#endif
