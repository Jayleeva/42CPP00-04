#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << YELLOW << "[DEBUG]: Default constructor called" << DEFAULT << std::endl;
	this->rawBits = 0;
}

// prend le int reçu et bitshift de 8 a gauche (le multiplie 8x par 2, donc x256) pour mettre tous les fractional avant "la virgule"
Fixed::Fixed(const int i)
{
	std::cout << YELLOW << "[DEBUG]: Int constructor called" << DEFAULT << std::endl;
	this->rawBits = i << this->fractionnalBits;
}

// comme pour le int, prend le float reçu et le bitshift de 8 a gauche, puis l'arrondit, puis le cast en int
// ppuisque les floats ne peuvent etre bitshift directement, on multiplie par 1 bitshifted de 8 a gauche 
// arrondit pour plus d'exactitude(?) cast en int pare que rawBits est déclaré comme un int
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
	std::cout << YELLOW << "[DEBUG]: Copy assignment operator called" << DEFAULT << std::endl;
	//this->rawBits = original.getRawBits();
	this->rawBits = original.rawBits;
	return (*this);
}

//si pas un fixedPt, ne se lance pas
//Permet d'inserer dans le stream la valeur du fixedPt passee en float par defaut, et en int si on ajoute .ToInt().
std::ostream &operator<<(std::ostream &out, Fixed const &fixedPt)
{
	out << fixedPt.toFloat();
	return (out);
}

// refait le calcul dans l'autre sens en faisant du bitshift dans l'autre sens pour retrouver le nombre de base
int 	Fixed::toInt( void ) const
{
	return (this->rawBits >> this->fractionnalBits);
}

// refait le calcul dans l'autre sens, en faisant du bitshit dans l'autre sens, puis en castant en float puisque c'est ce qu'on doit retourner 
// comme avant, puisque les floats ne peuvent etre bitshift directement, on divise par 1 bitshifted de 8 a gauche 
float	Fixed::toFloat( void ) const
{
	return ((float)this->rawBits / (1 << this->fractionnalBits));
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