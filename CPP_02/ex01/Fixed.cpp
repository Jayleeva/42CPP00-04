#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << YELLOW << "[DEBUG]: Default constructor called" << DEFAULT << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const int i)
{
	std::cout << YELLOW << "[DEBUG]: Int constructor called" << DEFAULT << std::endl;
	this->rawBits = i << this->fractionnalBits;
}

Fixed::Fixed(const float f)
{
	std::cout << YELLOW << "[DEBUG]: Float constructor called" << DEFAULT << std::endl;
	this->rawBits = (int)roundf(f * (1 << this->fractionnalBits));
}

Fixed::Fixed(const Fixed &original)
{
	std::cout << YELLOW << "[DEBUG]: Copy constructor called" << DEFAULT << std::endl;
	this->setRawBits(original.getRawBits());
}

Fixed::~Fixed()
{
	std::cout << YELLOW << "[DEBUG]: Destructor called" << DEFAULT << std::endl;
}

Fixed & Fixed::operator=(Fixed const &original)
{
	std::cout << YELLOW << "[DEBUG]: Copy assignment operator = called" << DEFAULT << std::endl;
	this->rawBits = original.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixedPt)
{
	o << fixedPt.toFloat();
	return (o);
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->rawBits / (1 << this->fractionnalBits));
}

int 	Fixed::toInt( void ) const
{
	return (this->rawBits >> this->fractionnalBits);
}

int		Fixed::getRawBits( void ) const
{
	std::cout << YELLOW << "[DEBUG]: getRawBits member function called" << DEFAULT << std::endl;
	return (this->rawBits);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << YELLOW << "[DEBUG]: setRawBits member function called" << DEFAULT << std::endl;
	this->rawBits = raw;
}