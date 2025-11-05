#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"

class	Fixed
{
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed &original);
		~Fixed();
		Fixed	&operator=(Fixed const &original);

		float	toFloat( void ) const;
		int 	toInt( void ) const;
	
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					rawBits;
		static const int	fractionnalBits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixedPt);

#endif

