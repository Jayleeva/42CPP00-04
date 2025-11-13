#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << YELLOW << "[DEBUG]: Default constructor called" << DEFAULT << std::endl;
	this->rawBits = 0;
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
	*this = original;
}

Fixed::~Fixed()
{
	std::cout << YELLOW << "[DEBUG]: Destructor called" << DEFAULT << std::endl;
}

Fixed &Fixed::operator=(Fixed const &original)
{
	std::cout << YELLOW << "[DEBUG]: Copy assignment operator = called" << DEFAULT << std::endl;
	this->rawBits = original.rawBits;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixedPt)
{
	out << fixedPt.toFloat();
	return (out);
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

///---------- NEW OVERLOADS -----------
//-------- lesser greater bool --------

bool	Fixed::operator>(const Fixed &fixedPt) const
{
	return (this->toFloat() > fixedPt.toFloat());
}

bool	Fixed::operator<(const Fixed &fixedPt) const
{
	return (this->toFloat() < fixedPt.toFloat());
}

bool	Fixed::operator>=(const Fixed &fixedPt) const
{
	return (this->toFloat() >= fixedPt.toFloat());
}

bool	Fixed::operator<=(const Fixed &fixedPt) const
{
	return (this->toFloat() <= fixedPt.toFloat());
}

bool	Fixed::operator==(const Fixed &fixedPt) const
{
	return (this->toFloat() == fixedPt.toFloat());
}

bool	Fixed::operator!=(const Fixed &fixedPt) const
{
	return (this->toFloat() != fixedPt.toFloat());
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

//Pour siginifier de faire l'incr/décr avant ou après avoir utilisé la variable, il faut deux choses:
//1) si l'incr/décr est faite après, la fonction ne reçoit pas d'argument, car il n'y a rien après les ++/--.
// si elle est faite avant, la fonction reçoit un int (pas nommé car pas important), soit la variable à incr/décr.
//2) si l'incr/décr est faite après, on déréférence "this" au moment de return uniquement, soit APRES l'incr/décr.
// si elle est faite avant, on déréférence "this" dès le départ, soit AVANT l'incr/décr. C'est pourquoi une temporaire est nécessaire.
//Pas besoin de s'embêter à trouver ce que vaut "the smallest representable epsilon", on peut juste utiliser les ++/-- de base.
Fixed	Fixed::operator++(void)
{
	++(this->rawBits);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;

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
