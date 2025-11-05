#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << YELLOW << "[DEBUG]: Default constructor called" << DEFAULT << std::endl;
	this->setRawBits(0);
}

//utilise la surcharge d'opérateur <<
// prend le int reçu et le multiplie 8x par 2 (bitshift à gauche) / multiplie par 2 puissance 8 POURQUOI MON DIEU POURQUOI
Fixed::Fixed(const int i)
{
	std::cout << YELLOW << "[DEBUG]: Int constructor called" << DEFAULT << std::endl;
	this->rawBits = i << this->fractionnalBits;
}

//utilise la surcharge d'opérateur <<
// prend le float reçu et le multiplie par 256 (1x 2 puissance 8), puis l'arrondit, puis le cast en int (wtf???)
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

Fixed & Fixed::operator=(Fixed const &original)
{
	std::cout << YELLOW << "[DEBUG]: Copy assignment operator = called" << DEFAULT << std::endl;
	this->rawBits = original.getRawBits();
	return (*this);
}

//
std::ostream &operator<<(std::ostream &o, Fixed const &fixedPt)
{
	o << fixedPt.toFloat();
	return (o);
}

//utilise la surcharge d'opérateur <<???
// refait le calcul dans l'autre sens, en divisant par 256 (1 x2 puissance 8) POURQUOI FAIRE OMGGGGG ET POURQUOI JE PEUX PAS JUSTE FAIRE DU BITSHIFT DANS L'AUTRE SEEEEENS POURQUOOIIIII MON DIEU TUEZ-MOIII
float	Fixed::toFloat( void ) const
{
	//std::cout << (this->rawBits) << std::endl;
	return ((float)this->rawBits / (1 << this->fractionnalBits));
	//return ((float)this->rawBits >> (float)this->fractionnalBits); // marche PAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAS parce qu'on peut pas mettre l'opérateur avec des floats visiblement jpp
}

// refait le calcul dans l'autre sens en faisant du bitshift dans l'autre sens damn premier truc logique même si putain pourquoi on fait du bitshift de base jpp
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