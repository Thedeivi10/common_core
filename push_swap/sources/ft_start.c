/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:34:24 by davigome          #+#    #+#             */
/*   Updated: 2024/12/30 18:47:55 by davigome         ###   ########.fr       */
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
//	t_stack **stack_b;

	stack_a = malloc(sizeof(t_stack *));
	*stack_a = NULL;
	ft_values_to_stack_a(stack_a, nums);
	ft_index_to_stack_a(/* stack_a,  */nums);
}

void	ft_values_to_stack_a(t_stack **stack_a, t_nums *nums)
{
	t_stack	*temp;
	int		i;

	i = -1;
	while (++i < nums->num_of_values)
	{
//		ft_printf("%i\n", i);
		temp = ft_newlst_value(nums, i);
		ft_addback_lst(stack_a, temp);
	}
	temp = *stack_a;
	while (temp->next)
	{
		ft_printf("%i\n", temp->value);
		temp = temp->next;
	}
	ft_printf("%i\n", temp->value);
} 

void	ft_index_to_stack_a(/* t_stack **stack_a,  */t_nums *nums)
{
	ft_sort(nums);
	int i = -1;
	ft_printf("\n\n\n");
	while(++i < nums->num_of_values)
		ft_printf("%i\n", nums->list[i]);
}