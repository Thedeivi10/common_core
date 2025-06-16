/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 22:18:35 by davigome          #+#    #+#             */
/*   Updated: 2025/06/16 11:56:36 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
	
}
ScalarConverter::~ScalarConverter(){
	
}
ScalarConverter::ScalarConverter(const ScalarConverter &other){
	*this = other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){
	(void)other;
	return *this;
}

std::string*	isChar(const std::string &argv, std::string *type)
{
	if (argv.length() > 1)
	{
		type = NULL;
		return type;
	}
	
}

void	ScalarConverter::convert(const std::string &argv)
{
	std::string *type;
	type = NULL;
	
	type = isChar(argv, type);
}