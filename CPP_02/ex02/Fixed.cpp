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

//-------- incr decr --------
Fixed	&Fixed::operator++(void) // pas par 1 mais par le plus petit représentable, non?
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++(int n) //pourquoi cette méthode alambiquée? pourquoi ps juste return (*this) sans passer par res?
{
	Fixed	res;

	res = *this;

	if (!n)
		n = 1;
	this->setRawBits(this->getRawBits() + n);
	return (res);
}

Fixed	Fixed::operator--(int n)
{
	Fixed	res;

	res = *this;

	if (!n)
		n = 1;
	this->setRawBits(this->getRawBits() - n);
	return (res);
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