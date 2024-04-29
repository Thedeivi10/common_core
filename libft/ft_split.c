/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 08:51:11 by davigome          #+#    #+#             */
/*   Updated: 2024/04/29 07:51:09 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char conts *s, char c)
{
	int	*characters;
	int	row;
	int	j;
	int i;
	char **arrays;
	row = 0;
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
	arrays= (char **)malloc(row * sizeof(char *));
	if (!arrays)
		return (0);
	i = -1;
	while (++i < row)
	{
		arrays[i] = (char *)malloc(characters[i] * sizeof(char));
		if (!arrays[i])
		{
			while (0 < i)
			{
				free(arrays[i])
				i--;
				return (0);
			}
		}
	}
	i = -1;
	int k;
	k = -1;
	j = 0;
	while (s[++i])
	{
		k = -1;
		while (characters[j] > ++k)
			arrays[j][k] = s[i];
		arrays[j][k] = 0;
		j++;
	}
	arrays[j][0] = 0;
	return (arrays);
}