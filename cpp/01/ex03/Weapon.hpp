/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:23:02 by davigome          #+#    #+#             */
/*   Updated: 2025/05/20 19:31:52 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Weapon{

	private:
		std::string type;

	public:
		Weapon();
		~Weapon();
		void	setType(std::string type);
		const std::string &getType();
		
};