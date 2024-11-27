/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:04:41 by davigome          #+#    #+#             */
/*   Updated: 2024/11/26 23:31:30 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_cpy_matrix(char **src)
{
	char	**dst;
	int		i;

	i = 0;
	if(!src || !src[i])
		return (NULL);
	while (src[i++])
	dst = malloc(sizeof(char *) * i + 1);
	i = 0;
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
