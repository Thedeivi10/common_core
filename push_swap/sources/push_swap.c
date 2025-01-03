/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:06:55 by davigome          #+#    #+#             */
/*   Updated: 2024/12/30 15:38:35 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_nums	*nums;

	if (argc <= 1)
		exit(0);
	nums = malloc(sizeof(nums));
	if (!nums)
	{
		ft_printf("Error\n");
		exit(2);
	}
//	stack_a = malloc(sizeof(t_stack));
	ft_checks(argv, nums);
	ft_select_algorithm(nums);
	return (0);
}
