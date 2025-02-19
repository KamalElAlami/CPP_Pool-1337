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

Fixed::Fixed(const Fixed& obj)
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

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	fixedPoint = raw;
}

float Fixed::toFloat( void ) const
{
	return (((float)fixedPoint / (1 << fbits)));
}

int Fixed::toInt( void ) const
{
	return (fixedPoint >> fbits);
}

// comparison

bool Fixed::operator>(const Fixed &obj) const
{
	if (this->fixedPoint > obj.fixedPoint)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &obj) const
{
	if (this->fixedPoint < obj.fixedPoint)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &obj) const
{
	if (this->fixedPoint >= obj.fixedPoint)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &obj) const
{
	if (this->fixedPoint <= obj.fixedPoint)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &obj) const
{
	if (this->fixedPoint == obj.fixedPoint)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &obj) const
{
	if (this->fixedPoint != obj.fixedPoint)
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed &obj) const
{
	return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed Fixed::operator-(const Fixed &obj) const
{
	return (Fixed(this->toFloat() - obj.toFloat()));
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	return (Fixed(this->toFloat() / obj.toFloat()));
}

Fixed& Fixed::operator++()
{
	Fixed old = Fixed(*this);
	fixedPoint++;
	return (old);
}
Fixed& Fixed::operator--()
{
	Fixed old = Fixed(*this);
	fixedPoint--;
	return (old);
}
Fixed Fixed::operator++(int)
{
	fixedPoint++;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	fixedPoint--;
	return (*this);
}

static Fixed& min(Fixed &a, Fixed &b)
{
	return ((a.getRawBits() < b.getRawBits()) ? a : b);
}
static Fixed& max(Fixed &a, Fixed &b)
{
	return ((a.getRawBits() > b.getRawBits()) ? a : b);
}
static const Fixed& min(const Fixed &a, const Fixed &b)
{
	return ((a.getRawBits() < b.getRawBits()) ? a : b);
}
static const Fixed& max(const Fixed &a, const Fixed &b)
{
	return ((a.getRawBits() > b.getRawBits()) ? a : b);
}
