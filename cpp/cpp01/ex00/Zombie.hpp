/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:09:57 by davigome          #+#    #+#             */
/*   Updated: 2025/05/19 07:03:34 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie{
	private:
	std::string name = "Zombieee";

	public:
	std::string getName();
	void announce(void);
	Zombie* newZombie(std::string name);
	~Zombie();
};

#endif