/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:10:10 by davigome          #+#    #+#             */
/*   Updated: 2025/05/19 07:07:40 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <array>
#include "Zombie.hpp"

std::string Zombie::getName(){
	return (name);
}

void Zombie::announce(void){
	std::cout << getName << ": BraiiiiiiinnnzzzZ..."<< std::endl;
}