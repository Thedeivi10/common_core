/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:42:09 by davigome          #+#    #+#             */
/*   Updated: 2025/06/30 19:33:56 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <exception>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

class BitcoinExchange
{
	private:
	std::map<std::string,double> _input;
	std::map<std::string,double> _data;

	BitcoinExchange(BitcoinExchange const &other);
	BitcoinExchange &operator=(BitcoinExchange const &other);
	BitcoinExchange();

	public:
		BitcoinExchange(std::string &inputTxt);
		~BitcoinExchange();

		void parseInput(std::string &inputTxt);
};