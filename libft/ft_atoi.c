/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:46:29 by davigome          #+#    #+#             */
/*   Updated: 2024/04/23 21:20:57 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	cont;
	int		number;
	int		neg;

	cont = 0;
	number = 0;
	neg = 1;
	while (isspace(str[cont]))
		cont++;
	if (ft_isdigit((str[cont + 2] - '0')) || str[cont + 1] == '\0')
		return (0);
	if (str[cont] == '-' || str[cont] == '+')
	{
		if (str[cont] == '-')
			neg = -1;
		cont++;
	}
	while (ft_isdigit(str[cont]))
	{
		number = number * 10 + (str[cont] - 48);
		cont++;
	}
	number = neg * number;
	return (number);
}
/*int main()
{
	char e= 'e';
	printf("%d",ft_atoi((e + "1").c_str());
	printf("%d",atoi((e + "1").c_str());
	return 0;
}*/