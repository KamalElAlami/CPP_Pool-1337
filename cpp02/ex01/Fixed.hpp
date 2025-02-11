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
		Fixed& operator=(const Fixed& obj);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );

};


#endif