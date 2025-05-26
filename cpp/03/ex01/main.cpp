/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:39:23 by davigome          #+#    #+#             */
/*   Updated: 2025/05/26 17:21:51 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main( void )
{
	ClapTrap pepe("pepe"), manue("manue");

	pepe.attack("manue");
	pepe.beRepaired(4);
	pepe.takeDamage(3);
}