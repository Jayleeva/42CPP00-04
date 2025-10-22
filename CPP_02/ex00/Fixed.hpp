#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"

class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &original);
		Fixed &operator=(Fixed const &original);
		~Fixed();
	
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					rawBits;
		static const int	fractionnalBits = 8;
};

#endif