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

//-------- equal -------- 
Fixed &Fixed::operator=(Fixed const &original)
{
	std::cout << YELLOW << "[DEBUG]: Copy assignment operator = called" << DEFAULT << std::endl;
	this->rawBits = original.getRawBits();
	return (*this);
}

//-------- lesser greater bool --------
bool	Fixed::operator==(const Fixed &fixedPt) const
{
	return (this->toFloat() == fixedPt.toFloat());
}

bool	Fixed::operator!=(const Fixed &fixedPt) const
{
	return (this->toFloat() != fixedPt.toFloat());
}

bool	Fixed::operator<=(const Fixed &fixedPt) const
{
	return (this->toFloat() <= fixedPt.toFloat());
}

bool	Fixed::operator>=(const Fixed &fixedPt) const
{
	return (this->toFloat() >= fixedPt.toFloat());
}

bool	Fixed::operator<(const Fixed &fixedPt) const
{
	return (this->toFloat() < fixedPt.toFloat());
}

bool	Fixed::operator>(const Fixed &fixedPt) const
{
	return (this->toFloat() > fixedPt.toFloat());
}

//-------- Min max functions --------
const Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.rawBits < b.rawBits)
		return (a);
	return (b);
}

const Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.rawBits > b.rawBits)
		return (a);
	return (b);
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.rawBits < b.rawBits)
		return (a);
	return (b);
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.rawBits > b.rawBits)
		return (a);
	return (b);
}

//-------- Calculs --------
Fixed Fixed::operator+(Fixed const &fixedPt) const
{
	return (Fixed(this->toFloat() + fixedPt.toFloat()));
}

Fixed Fixed::operator-(Fixed const &fixedPt) const
{
	return (Fixed(this->toFloat() - fixedPt.toFloat()));
}

Fixed Fixed::operator*(Fixed const &fixedPt) const
{
	return (Fixed(this->toFloat() * fixedPt.toFloat()));
}

Fixed Fixed::operator/(Fixed const &fixedPt) const
{
	if (fixedPt.toFloat() == 0)
	{
		std::cout << RED << "Error: division by 0." << DEFAULT << std::endl;
		exit(1);
	}
	return (Fixed(this->toFloat() / fixedPt.toFloat()));
}

//-------- incr decr --------
Fixed	Fixed::operator++(void) // void parce que placé après la variable à incrémenter? 
{
	++(this->rawBits); // devrait être (this->rawBits)++ du coup non? non, car le calcul est le même dans tous les cas. Comment signifier "fais-le après?"
	return (*this);
}

Fixed	Fixed::operator++(int) // int parce que placé avant la variable à incrémenter? on ne l'utilise pas? jpp??
{
	Fixed	tmp = *this; // pourquoi utiliser une temporaire si on renvoie aussi *this?

	++(this->rawBits);
	return (tmp);
}

Fixed	Fixed::operator--(void)
{
	--(this->rawBits);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;

	--(this->rawBits);
	return (tmp);
}

//-------- append --------
std::ostream &operator<<(std::ostream &o, Fixed const &fixedPt)
{
	o << fixedPt.toFloat();
	return (o);
}

//-------- Convert --------
float	Fixed::toFloat( void ) const
{
	return ((float)this->rawBits / (1 << this->fractionnalBits));
}

int 	Fixed::toInt( void ) const
{
	return (this->rawBits >> this->fractionnalBits);
}

//-------- getter setter --------
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