/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:52:53 by davigome          #+#    #+#             */
/*   Updated: 2025/06/13 17:11:52 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form


std::ostream& operator<<(std::ostream& stream, const Form& b) {
	stream << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return stream;
}