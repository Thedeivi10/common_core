/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:37:52 by davigome          #+#    #+#             */
/*   Updated: 2025/02/19 17:36:14 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	space(const char *str, int cont)
{
	if ((str[cont] >= 9 && str[cont] <= 13) || str[cont] == 32)
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	cont;
	int		number;
	int		neg;

	cont = 0;
	number = 0;
	neg = 1;
	while (space(str, cont))
		cont++;
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

size_t	ft_strlen(const char *s)
{
	size_t	contador;

	contador = 0;
	while (s[contador] != '\0')
		contador++;
	return (contador);
}
