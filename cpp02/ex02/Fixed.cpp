#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0)
{
}

Fixed::Fixed(int number) : fixedPoint(number << fbits)
{
}

Fixed::Fixed(float number) : fixedPoint(roundf(number * (1 << fbits)))
{
}

Fixed& Fixed::operator=(const Fixed& obj)
{
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
	fixedPoint = obj.fixedPoint;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return (fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
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

Fixed& Fixed::operator++(void)
{
	fixedPoint++;
	return (*this);
}
Fixed& Fixed::operator--(void)
{
	fixedPoint--;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed old = Fixed(*this);
	++fixedPoint;
	return (old);
}
Fixed Fixed::operator--(int)
{
	Fixed old = Fixed(*this);
	--fixedPoint;
	return (old);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return ((a.getRawBits() < b.getRawBits()) ? a : b);
}
Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return ((a.getRawBits() > b.getRawBits()) ? a : b);
}
const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a.getRawBits() < b.getRawBits()) ? a : b);
}
const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a.getRawBits() > b.getRawBits()) ? a : b);
}
