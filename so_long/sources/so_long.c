/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:28:29 by davigome          #+#    #+#             */
/*   Updated: 2024/11/23 12:14:28 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main	(int argc, char **argv)
{
	system("clear");
	// check if there is only one map to read
	if (argc != 2)
	{
		ft_printf("Error:\n");
		ft_printf(E_NUMBER);
		return (FAILURE);
	}
	if (argc == 2)
	{
		//check if the map is valid
		if (ft_checks(argv[1]) >= 1)
			return (FAILURE);
		//The game starts
		
	}
	return (SUCCESS);
}
