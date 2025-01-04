/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:14:57 by davigome          #+#    #+#             */
/*   Updated: 2025/01/05 00:04:56 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	ft_check(argv);
}