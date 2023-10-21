#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <string>

class Convert {
	public:
		Convert();
		Convert(Convert const &copy);
		Convert& operator=(Convert const &copy);
		~Convert();
		static void startConvert(const std::string &lit);
};
#endif