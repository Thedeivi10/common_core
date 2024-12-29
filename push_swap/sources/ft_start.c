/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:34:24 by davigome          #+#    #+#             */
/*   Updated: 2024/12/29 17:01:52 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void	ft_select_algorithm(t_nums *nums)
{
	if (nums->num_of_values == 2)
		ft_two_values(nums);
	if (nums->num_of_values == 3)
		ft_three_values(nums);
	else 
		ft_more_values(nums);
}

void	ft_two_values(t_nums *nums)
{
	ft_printf("sa\n");
	ft_free_nums(nums);
	exit(0);
}

void	ft_three_values(t_nums *nums)
{
	if (nums->list[1] > nums->list[2] && nums->list[2] > nums->list[0])
		ft_printf("rra\nsa\n");
	else if(nums->list[2] > nums->list[0] && nums->list[0] > nums->list[1])
		ft_printf("sa\n");
	else if(nums->list[1] > nums->list[0] && nums->list[0] > nums->list[2])
		ft_printf("rra\n");
	else if(nums->list[0] > nums->list[2] && nums->list[2] > nums->list[1])
		ft_printf("ra\n");
	else if(nums->list[0] > nums->list[1] && nums->list[1] > nums->list[2])
		ft_printf("ra\nsa\n");
	ft_free_nums(nums);
	exit(0);
}

void	ft_more_values(t_nums *nums)
{
	t_stack	**stack_a;
	t_stack **stack_b;

	ft_values_to_stack_a(stack_a, nums);
}

void	ft_values_to_stack_a(t_stack **stack_a, t_nums *nums)
{
	*stack_a = ft_first_value(nums);
}

