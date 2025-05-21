/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:22:48 by davigome          #+#    #+#             */
/*   Updated: 2025/05/21 08:01:56 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA{

	private:

		std::string name;
		Weapon weapon;
	public:
	HumanA(std::string weapon);
	void attack();
	~HumanA();
};