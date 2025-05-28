/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:04:56 by davigome          #+#    #+#             */
/*   Updated: 2025/05/28 20:13:29 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGWrongAnimal_HPP
#define WRONGWrongAnimal_HPP

#include <iostream>
#include <string>

class WrongAnimal{
	private:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(std::string _type);
		WrongAnimal(const WrongAnimal &WrongAnimal);
		WrongAnimal &operator=(const WrongAnimal &WrongAnimal);
		~WrongAnimal();
		std:: string getType(void) const;
		
		void setType(std:: string);
		void	makeSound(void) const;
};

#endif