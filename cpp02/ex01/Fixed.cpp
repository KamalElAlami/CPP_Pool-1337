#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int number) : fixedPoint(number << fbits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float number) : fixedPoint(roundf(number * (1 << fbits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->fixedPoint = obj.fixedPoint;
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return (out);
}

Fixed::Fixed(Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	fixedPoint = obj.fixedPoint;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPoint);
}

float Fixed::toFloat( void ) const
{
	return (fixedPoint / (1 << fbits));
}

int Fixed::toInt( void ) const
{
	return (fixedPoint >> fbits);
}