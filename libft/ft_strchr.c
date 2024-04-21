/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:57:06 by davigome          #+#    #+#             */
/*   Updated: 2024/04/21 10:05:51 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strchr(const char *s, int c)
{
	int	cont;

	cont = 0;
	c = (char)c;
	if (c == '\0')
		return (ft_strlen(s));
	while (s[cont] != '\0')
	{
		if (s[cont] == c)
			return (cont);
	}
	return (0);
}
