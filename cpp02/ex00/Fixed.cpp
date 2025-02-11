#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	primary = 0;
}
Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->primary = obj.primary;
	return (*this);
}

Fixed::Fixed(Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->primary = obj.primary;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (primary);
}
