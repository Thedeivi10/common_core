/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 09:17:37 by davigome          #+#    #+#             */
/*   Updated: 2025/06/28 10:53:19 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char* Span::FullException::what() const throw(){
	return "The vector is fullfilled, sorry baby";
}

const char* Span::NotEnoughException::what() const throw()
{
	return "Cannot span because there is a number or less";
}

Span::Span() : _size(0), _vector(std::vector<int>())
{
	
}

Span::Span(unsigned int size) : _size(size), _vector(std::vector<int>())
{
	
}

Span::Span(Span const &other) : _size(other._size)
{
	for (unsigned int i  = 0; i < _size; i++)
		this->_vector[i] = other._vector[i];
}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		this->_size = other._size;
		for (unsigned int i  = 0; i < _size; i++)
			this->_vector[i] = other._vector[i];
	}
	return *this;
}

Span::~Span()
{
	
}

void Span::addNumber(int n)
{
	if (this->_vector.size() + 1 > this->_size)
		throw FullException();
}

int	Span::longestSpan()
{
	if (this->_vector.size() <= 1)
		throw NotEnoughException();
	std::vector<int>::iterator min = std::min_element(this->_vector.begin(), this->_vector.end());
	std::vector<int>::iterator max = std::max_element(this->_vector.begin(), this->_vector.end());

	return (*max - *min);
}

int Span::shortestSpan()
{
	if (this->_vector.size() <= 1)
		throw NotEnoughException();
	int shortest;
	std::vector<int> aux = this->_vector;
	std::sort(aux.begin(), aux.end());
	shortest = aux[1] - aux[0];

	for (unsigned int i = 1; i < aux.size() - 1; ++i)
	{
		if ((aux[i + 1] - aux[i]) < shortest)
			shortest = aux[i + 1] - aux[i];
	}
	return shortest;
}
