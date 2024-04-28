/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 08:51:11 by davigome          #+#    #+#             */
/*   Updated: 2024/04/28 12:09:20 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char conts *s, char c)
{
	int	*characters;
	int	row;
	int	col;
	int i;

	row = 0;
	col = 0;
	i = -1;
	if (!s || !c)
		return NULL
	characters[row] = 0;
	while(s[++i])
	{
		characters[row]++;
		if (s[i] == c)
		{
			row++;
			characters[row] = 0;
		}
	}

}