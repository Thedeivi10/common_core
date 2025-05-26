/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:49:10 by davigome          #+#    #+#             */
/*   Updated: 2025/05/26 20:25:34 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
	public:
		ScavTrap();
		ScavTrap(std::string& _name);
		ScavTrap(const ScavTrap& new);
		~ScavTrap();
		void	guardGate();
};

#endif