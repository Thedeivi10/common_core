/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:23:00 by davigome          #+#    #+#             */
/*   Updated: 2025/05/20 19:31:16 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void	Weapon::setType(std::string type){
	this->type = type;
}

Weapon::Weapon(){
	
}

Weapon::~Weapon(){
	
}

const std::string &Weapon::getType(){
	return (this->type);
}