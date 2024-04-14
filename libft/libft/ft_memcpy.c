/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:00:34 by davigome          #+#    #+#             */
/*   Updated: 2024/04/14 17:18:58 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t				cont;
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	cont = 0;
	while (cont < n)
	{
		d[cont] = s[cont];
		cont++;
	}
	return (dst);
}
