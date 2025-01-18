#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private :
		int primary;
		static const int fbits = 8;
	public :
		Fixed();
		Fixed(Fixed& obj);
		Fixed& Fixed::operator=(const Fixed& obj);
		~Fixed()

};


#endif