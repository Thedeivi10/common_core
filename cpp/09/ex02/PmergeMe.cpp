/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:16:27 by davigome          #+#    #+#             */
/*   Updated: 2025/07/01 21:36:44 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _arg("")
{}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(PmergeMe const &other) : _deque(other._deque), _vector(other._vector), _arg(other._arg)
{
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	if (this != &other)
	{
		this->_arg = other._arg;
		this->_vector = other._vector;
		this->_deque = other._deque; 
	}
	return *this;
}

PmergeMe::PmergeMe(std::string arg)
{
	this->_arg = arg;
}

static void error()
{
	throw std::runtime_error("Error");
}

static long int parseInt(std::string token)
{
	errno = 0;
	char *endptr = NULL;

	long val = std::strtol(token.c_str(), &endptr, 10);
	if (errno == ERANGE || *endptr != '\0' || val < 0 || val > INT_MAX)
		error();
	return val;
}

void PmergeMe::showUnsorted()
{
	std::istringstream iss(this->_arg);
	std::string token;
	std::cout << "Before:  ";
	iss >> token;
	std::cout << token;
	while(iss >> token)
	{
		std::cout << " ";
		std::cout << token;
	}
	std::cout << std::endl;
}

void PmergeMe::sorted()
{
	
}

void PmergeMe::mergeDeque()
{
	std::istringstream iss(this->_arg);
	std::string token;

	while(iss >> token)
	{
		if (std::find(this->_deque.begin(), this->_deque.end(), parseInt(token)) != this->_deque.end())
			error();
		this->_deque.push_back(parseInt(token));
	}
	if (this->_deque.size() < 2)
		error();
	/* std::deque<long int>::iterator it;
	 for (it = this->_deque.begin(); it != this->_deque.end(); ++it)
    {
        std::cout << *it << std::endl;
    } */
}