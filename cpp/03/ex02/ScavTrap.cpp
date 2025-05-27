/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:50:26 by davigome          #+#    #+#             */
/*   Updated: 2025/05/27 07:25:34 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Scavtrap default constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}
ScavTrap::ScavTrap(const std::string &_name) : ClapTrap(_name)
{
	std::cout << "ScavTrap constructor for " << this->getName() << " called." << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}
ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap default destructor called." << std::endl;
}
void	ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->getName() << " has entered in Gate Keeper Mode." << std::endl;
}