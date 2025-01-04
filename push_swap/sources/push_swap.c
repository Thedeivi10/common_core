/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:06:55 by davigome          #+#    #+#             */
/*   Updated: 2025/01/04 08:13:57 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_nums	*nums;

	if (argc <= 1)
		exit(0);
	nums = malloc(sizeof(t_nums));
	if (!nums)
	{
		write(2, "Error\n", 6);
		exit(2);
	}
	ft_checks(argv, nums);
	ft_select_algorithm(nums);
	return (0);
}
