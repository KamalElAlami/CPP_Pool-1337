 #ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private :
		int fixedPoint;
		static const int fbits = 8;
	public :
		Fixed();
		Fixed(int number);
		Fixed(float number);
		Fixed(const Fixed& obj);
		~Fixed();

		Fixed& operator=(const Fixed& obj);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		// comparison 

		bool operator>(const Fixed &obj) const;
		bool operator<(const Fixed &obj) const;
		bool operator>=(const Fixed &obj) const;
		bool operator<=(const Fixed &obj) const;
		bool operator==(const Fixed &obj) const;
		bool operator!=(const Fixed &obj) const;

		// arithmetic
		Fixed operator+(const Fixed &obj) const;
		Fixed operator-(const Fixed &obj) const;
		Fixed operator*(const Fixed &obj) const;
		Fixed operator/(const Fixed &obj) const;

};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);


#endif