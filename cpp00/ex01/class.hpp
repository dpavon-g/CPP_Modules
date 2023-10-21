#ifndef CLASS_H
# define CLASS_H

class Contact {
	
	private:
		int			id;
		std::string	name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone;
		std::string	secret;


	public:
		std::string get_name();
		void		set_name(std::string name);
		int 		get_id();
		void 		set_id(int id);
		std::string	get_last_name();
		void		set_last_name(std::string last_name);
		std::string get_nickname();
		void		set_nickname(std::string nickname);
		std::string get_secret();
		void		set_secret(std::string secret);
		std::string	get_phone();
		void		set_phone(std::string phone);

};

class Phone_book {

	private:
		Contact contact_array[8];

	public:
		void set_contact(int i, Contact contact);
		Contact *get_contact(int i);
		Contact *get_contact_array();
};

# endif
