/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:16:27 by davigome          #+#    #+#             */
/*   Updated: 2025/07/03 16:59:03 by davigome         ###   ########.fr       */
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

void showUnsorted(std::string arg)
{
	std::istringstream iss(arg);
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
	std::deque<long int> aux;
	aux = this->_deque;
	std::sort(aux.begin(), aux.end());
	std::cout << "After:	 ";
	std::cout << aux[0];
	for (size_t i = 1; i < aux.size(); i++)
	{
		std::cout << " " << aux[i];
	}
	std::cout << std::endl;
}

void PmergeMe::pairsOrderDeque()
{
	for (size_t i = 0; i < _deque.size(); i++)
	{
		if (_deque[i] > _deque[i + 1])
		{
			long int aux = _deque[i];
			_deque[i] = _deque[i + 1];
			_deque[i + 1 ] = aux;
		}
		i += 1;
	}
}

/* static std::deque<long int> insertionOrderDeque(size_t size)
{
	std::deque<long int> order;
	int j0 = 0;
	int j1 = 1;
	while (static_cast<size_t>(j1) < size)
	{
		if (std::find(order.begin(), order.end(), j1) == order.end())
		{
			order.push_back(j1);
			if (j0 == 0)
				order.push_back(0);
			int aux = j1;
			while(--aux > j0)
				order.push_back(aux);
		}
		int next = j1 + 2 * j0;
		j0 = j1;
		j1 = next;
	}
	return order;
} */

/* static std::deque<long int> insertionOrderDeque(size_t size)
{
    std::deque<long int> order;
    
    // Generar números de Jacobsthal: 1, 1, 3, 5, 11, 21, 43...
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(1);
    if (size > 1) jacobsthal.push_back(1);
    
    while (jacobsthal.back() < size) {
        size_t next = jacobsthal[jacobsthal.size()-1] + 2 * jacobsthal[jacobsthal.size()-2];
        jacobsthal.push_back(next);
    }
    
    // Crear orden de inserción basado en Jacobsthal
    std::vector<bool> inserted(size, false);
    
    for (size_t i = 1; i < jacobsthal.size() && jacobsthal[i] <= size; ++i) {
        size_t limit = std::min(jacobsthal[i], size);
        size_t start = (i > 1) ? jacobsthal[i-1] : 0;
        
        // Insertar en orden descendente desde limit hasta start+1
        for (size_t j = limit; j > start && j > 0; --j) {
            if (j <= size && !inserted[j-1]) {
                order.push_back(j-1); // Convertir a índice base 0
                inserted[j-1] = true;
            }
        }
    }
    
    // Insertar elementos restantes
    for (size_t i = 0; i < size; ++i) {
        if (!inserted[i]) {
            order.push_back(i);
        }
    }
    
    return order;
} */

void PmergeMe::fordJhonsonDeque(std::deque<long int> &deque)
{
	std::deque<long int> a;
	std::deque<long int> b;

	if (deque.size() <= 1)
		return ;
	long int struggle = -1;
	
	for(size_t i = 0; i + 1 < deque.size(); i+=2)
	{
		long int first = deque[i];
		long int second = deque[i + 1];
		
		if (first > second)
		{
			a.push_back(first);
			b.push_back(second);
		}else
		{
			a.push_back(second);
			b.push_back(first);
		}
	}
	if (deque.size() % 2 != 0)
	{
		struggle = deque.back();
	}
	fordJhonsonDeque(a);
	std::deque<long int> order = insertionOrderDeque(b.size());
	std::cout << "Index of jacostals : ";
	for (size_t i = 0; i < order.size(); ++i)
	{
		int index = order[i];
		std::cout << index << " ";
		std::deque<long int>::iterator pos = std::lower_bound(a.begin(), a.end(), b[index]);
		a.insert(pos, b[index]);
	}
	std::cout <<std::endl;
	if (struggle != -1)
	{
		std::deque<long int>::iterator pos = std::lower_bound(a.begin(), a.end(), struggle);
		a.insert(pos, struggle);
	}
	deque = a;
	std::cout << "A vector before insertion : ";
	std::deque<long int>::iterator it;
	 for (it = a.begin(); it != a.end(); ++it)
    {
        std::cout << *it << " ";
    }
	std::cout << std::endl;
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
	pairsOrderDeque();
	fordJhonsonDeque(this->_deque);
	/* std::deque<long int>::iterator it;
	 for (it = this->_deque.begin(); it != this->_deque.end(); ++it)
    {
        std::cout << *it << " ";
    }
	std::cout << std::endl; */
}
