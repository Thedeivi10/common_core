/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 09:17:37 by davigome          #+#    #+#             */
/*   Updated: 2025/06/27 12:11:43 by davigome         ###   ########.fr       */
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

Span::Span