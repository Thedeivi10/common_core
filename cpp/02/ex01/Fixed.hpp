/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 22:39:48 by davigome          #+#    #+#             */
/*   Updated: 2025/05/24 13:21:46 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{

	private:
		static const int _bits = 8;
		int _value;
	public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed(int  _value);
	Fixed(float _value);
	Fixed &operator=(const Fixed &fixed);
	~Fixed();
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif