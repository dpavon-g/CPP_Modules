#include <iostream>
#include <stdlib.h>
#include "class.hpp"

void	print_menu() {
	std::cout << "*************" << std::endl;
	std::cout << "* 1. ADD    *" << std::endl;
	std::cout << "* 2. SEARCH *" << std::endl;
	std::cout << "* 3. EXIT   *" << std::endl;
	std::cout << "*************" << std::endl;
}

std::string	Contact::get_name() {
	return (this->name);
}

void	Contact::set_name(std::string name) {
	this->name = name;
}

int	Contact::get_id() {
	return (this->id);
}

void	Contact::set_id(int id) {
	this->id = id;
}

std::string	Contact::get_last_name() {
	return (this->last_name);
}

void	Contact::set_last_name(std::string last_name) {
	this->last_name = last_name;
}

std::string	Contact::get_nickname() {
	return (this->nickname);
}

void	Contact::set_nickname(std::string nickname) {
	this->nickname = nickname;
}

std::string	Contact::get_secret() {
	return (this->secret);
}

void	Contact::set_secret(std::string secret) {
	this->secret = secret;
}

std::string	Contact::get_phone() {
	return (this->phone);
}

void	Contact::set_phone(std::string phone) {
	this->phone = phone;
}


void	add_contact(Contact *contact_array) {
	std::string input;
	
	std::cout << "NAME: ";
	std::getline(std::cin, input);
	if (std::cin.eof()) {
		std::cout << "See you soon!!" << std::endl;
		exit(1);
	}
	contact_array->set_name(input);
	
	std::cout << "LAST NAME: ";
	std::getline(std::cin, input);
	if (std::cin.eof()) {
		std::cout << "See you soon!!" << std::endl;
		exit(1);
	}
	contact_array->set_last_name(input);

	std::cout << "NICKNAME: ";
	std::getline(std::cin, input);	
	if (std::cin.eof()) {
		std::cout << "See you soon!!" << std::endl;
		exit(1);
	}
	contact_array->set_nickname(input);

	std::cout << "PHONE NUMBER: ";
	std::getline(std::cin, input);
	if (std::cin.eof()) {
		std::cout << "See you soon!!" << std::endl;
		exit(1);
	}
	contact_array->set_phone(input);
	
	std::cout << "DARKEST SECRET: ";
	std::getline(std::cin, input);
	if (std::cin.eof()) {
		std::cout << "See you soon!!" << std::endl;
		exit(1);
	}
	contact_array->set_secret(input);

	std::cout << "Adding contact...\n" << std::endl;
}

int	strlen(std::string str) {
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	write_space(int num)
{
	int i;

	i = 0;
	while (i + num < 10)
	{
		std::cout << " ";
		i++;
	}
	return (num);
}

void	print_dates(Contact contact_array, std::string (Contact::*func)()){
	int j;
	j = 0;
	if (write_space(strlen((contact_array.*func)())) <= 10)
		std::cout << (contact_array.*func)() << "|";
	else {
		while(j < 9) {
			std::cout << ((contact_array.*func)())[j];
			j++;
		}
		std::cout << "." << "|";
	} 

}

int		check_num_err(std::string str) {
	
		if (strlen(str) != 1 || str[0] <= '0' || str[0] > '8')
			return (1);

		return (0);

	}

	void	print_person(Contact contact_array) {
		
		std::cout << "------------------------------" << std::endl;
		std::cout << "NAME: " << contact_array.get_name() << std::endl;
		std::cout << "------------------------------" << std::endl;
		std::cout << "LAST NAME: " << contact_array.get_last_name() << std::endl;
		std::cout << "------------------------------" << std::endl;
		std::cout << "NICKNAME: " << contact_array.get_nickname() << std::endl;
		std::cout << "------------------------------" << std::endl;
		std::cout << "PHONE: " << contact_array.get_phone() << std::endl;
		std::cout << "------------------------------" << std::endl;
		std::cout << "DARKEST SECRET: " << contact_array.get_secret() << std::endl;
		std::cout << "------------------------------\n" << std::endl;
	}

	void	search_contact(Contact contact_array[8]) {
		int	i;
		std::string input;

		i = 0;
		std::cout << "--------------------------------------------------------" << std::endl;
		while (i < 8) {
			std::cout << "|         " << contact_array[i].get_id() << "|";
			print_dates(contact_array[i], &Contact::get_name);
			print_dates(contact_array[i], &Contact::get_last_name);
			print_dates(contact_array[i], &Contact::get_nickname);
			print_dates(contact_array[i], &Contact::get_phone);
			std::cout << "\n";
			i++;
		}
		std::cout << "--------------------------------------------------------" << std::endl;

		std::cout << "\nImput a user ID: ";
		std::getline (std::cin, input);
		if (std::cin.eof()) {
			std::cout << "See you soon!!" << std::endl;
			exit(1);
		}
		while (check_num_err(input)) {
			std::cout << "Invalid user ID, repeat: ";
			std::getline (std::cin, input);
		}
		std::cout << "Searching contact...\n" << std::endl;
		print_person(contact_array[(input[0] - 48) - 1]);
	}

	void Phone_book::set_contact(int i, Contact contact) {
		this->contact_array[i] = contact;
	}

Contact *Phone_book::get_contact(int i) {
	return (&(this->contact_array[i]));
}

Contact *Phone_book::get_contact_array() {
	return (this->contact_array);
}

int	main() {
	std::string input;
	int			i;
	
	i = 1;
	Contact contact_array[8];
	Phone_book book;

	while (i < 9) {

		contact_array[i - 1].set_id(i);
		book.set_contact(i - 1, contact_array[i - 1]);
		i++;
	}
	i = 0;
	while (input != "EXIT") {
		print_menu();
		std::cout << "Imput a word: ";
		std::getline (std::cin, input);
		if (std::cin.eof()) {
			std::cout << "See you soon!!" << std::endl;
			exit(1);
		}
		if (input == "SEARCH")
			search_contact(book.get_contact_array());
		else if (input == "ADD") {
			Contact *contact = book.get_contact(i);
			add_contact(contact);
			i++;
		}
		if (i > 7)
			i = 0;
	}
}
