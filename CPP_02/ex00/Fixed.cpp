#include "Fixed.hpp"

//Cree un nouvel objet et assigne 0 a son attribut
Fixed::Fixed()
{
	std::cout << YELLOW << "[DEBUG]: Default constructor called" << DEFAULT << std::endl;
	this->rawBits = 0;
}

//Crée un nouvel objet en copiant celui référencé en argument
Fixed::Fixed(const Fixed &original)
{
	std::cout << YELLOW << "[DEBUG]: Copy constructor called" << DEFAULT << std::endl;
	*this = original;
}

Fixed::~Fixed()
{
	std::cout << YELLOW << "[DEBUG]: Destructor called" << DEFAULT << std::endl;
}

//Overload = redéfinir.
//Redéfinit ce que fait un opérateur, ici le '='.
//Assigne la valeur de l'attribut de l'objet référencé en argument.
//Retourne une déréférence de l'instance pour pouvoir faire l'operation
Fixed &Fixed::operator=(Fixed const &original)
{
	std::cout << YELLOW << "[DEBUG]: Copy assignment operator called" << DEFAULT << std::endl;
	this->rawBits = original.getRawBits();
	//this->rawBits = original.rawBits;
	return (*this);
}

//retourne la valeur de l'attribut de l'instance
int		Fixed::getRawBits( void ) const
{
	std::cout << YELLOW << "[DEBUG]: getRawBits member function called" << DEFAULT << std::endl;
	return (this->rawBits);
}

//assigne l'argument recu a l'attribut de l'instance
void	Fixed::setRawBits( int const raw )
{
	std::cout << YELLOW << "[DEBUG]: setRawBits member function called" << DEFAULT << std::endl;
	this->rawBits = raw;
}