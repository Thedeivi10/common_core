/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:52:53 by davigome          #+#    #+#             */
/*   Updated: 2025/06/13 22:26:29 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << _name << " Form default constructor called." << std::endl;
}

Form::Form(const Form &other) : _name(other._name) , _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form	&Form::operator=(const Form &other)
{
	std::cout << "Form asignator operator called." << std::endl;
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

const std::string	Form::getName() const
{
	return _name;
}

const int Form::getGradeToSign() const
{
	return _gradeToSign;
}

const int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

const bool Form::getIsSigned() const
{
	return _isSigned;
}

std::ostream& operator<<(std::ostream& stream, const Form& b) {
	stream << b.getName() << ", Form grade to sign and to execute are " << b.getGradeToSign() << " and " << b.getGradeToExecute() << ". Finally, the Form is signed: " << b.getIsSigned() << ".";
    return stream;
}