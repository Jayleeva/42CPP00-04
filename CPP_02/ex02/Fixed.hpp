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
		Fixed &operator=(Fixed const &original);
		~Fixed();
	
		float	toFloat( void ) const;
		int 	toInt( void ) const;
	
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		bool	operator==(Fixed const &fixedPt) const;
		bool	operator!=(Fixed const &fixedPt) const;
		bool	operator<=(Fixed const &fixedPt) const;
		bool	operator>=(Fixed const &fixedPt) const;
		bool	operator<(Fixed const &fixedPt) const;
		bool	operator>(Fixed const &fixedPt) const;

		static const Fixed	&min(Fixed &a, Fixed &b);
		static const Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&min(Fixed const &a, Fixed const &b);
		static const Fixed	&max(Fixed const &a, Fixed const &b);

		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int n);
		Fixed	operator--(int n);

	private:
		int					rawBits;
		static const int	fractionnalBits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixedPt);


#endif