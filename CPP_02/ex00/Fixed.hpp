#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

using namespace std;

class	Fixed
{
	public:
		Fixed();
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					fixedPt;
		static const int	fractionnalBits;
};

#endif