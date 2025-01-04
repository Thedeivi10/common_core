/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 23:47:57 by davigome          #+#    #+#             */
/*   Updated: 2025/01/04 23:59:16 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_check(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		if (argv[i][0] == '-')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		while (argv [i][++j])
		{
			if (argv [i][j] < 0 || argv[i][j] > 9)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
		}
	}
}
