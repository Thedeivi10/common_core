/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:34:24 by davigome          #+#    #+#             */
/*   Updated: 2025/01/03 22:25:38 by davigome         ###   ########.fr       */
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
	t_stack	**stack_a;

	stack_a = malloc(sizeof(t_stack *));
	*stack_a = NULL;
	ft_values_to_stack_a(stack_a, nums);
	ft_index_to_stack_a(stack_a, nums);
	ft_sort_three(stack_a);
	ft_free_nums(nums);
	exit(0);
}

void	ft_initialize_stacks(t_stack ***stack_a, t_stack ***stack_b,
		t_nums *nums)
{
	*stack_a = malloc(sizeof(t_stack *));
	**stack_a = NULL;
	*stack_b = malloc(sizeof(t_stack *));
	**stack_b = NULL;
	ft_values_to_stack_a(*stack_a, nums);
	ft_index_to_stack_a(*stack_a, nums);
}

void	ft_move_cheap_to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		cheap;

	temp = *stack_b;
	while (temp)
	{
		cheap = ft_the_cheap(stack_b);
		while (temp)
		{
			if (temp->value == cheap)
				break ;
			temp = temp->next;
		}
		ft_handle_costs(stack_a, stack_b, temp);
		ft_moves(stack_a, stack_b, 2);
		ft_target_pos(stack_a, stack_b);
		ft_calculate_cost(stack_a, stack_b);
		temp = *stack_b;
	}
}

void	ft_handle_costs(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	while (temp->cost_a > 0 && temp->cost_b > 0)
	{
		ft_moves(stack_a, stack_b, 5);
		temp->cost_a--;
		temp->cost_b--;
	}
	while (temp->cost_a < 0 && temp->cost_b < 0)
	{
		ft_moves(stack_a, stack_b, 8);
		temp->cost_a++;
		temp->cost_b++;
	}
	ft_handle_individual_costs(stack_a, stack_b, temp);
}

void	ft_handle_individual_costs(t_stack **stack_a, t_stack **stack_b,
		t_stack *temp)
{
	while (temp->cost_a > 0)
	{
		ft_moves(stack_a, stack_b, 3);
		temp->cost_a--;
	}
	while (temp->cost_a < 0)
	{
		ft_moves(stack_a, stack_b, 6);
		temp->cost_a++;
	}
	while (temp->cost_b > 0)
	{
		ft_moves(stack_a, stack_b, 4);
		temp->cost_b--;
	}
	while (temp->cost_b < 0)
	{
		ft_moves(stack_a, stack_b, 7);
		++(temp->cost_b);
	}
}

void	ft_more_values(t_nums *nums)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	ft_initialize_stacks(&stack_a, &stack_b, nums);
	ft_tostackb_vague(stack_a, stack_b, nums);
	ft_target_pos(stack_a, stack_b);
	ft_calculate_cost(stack_a, stack_b);
	ft_move_cheap_to_stack_a(stack_a, stack_b);
	ft_rotate_order(stack_a, stack_b);
}

void	ft_values_to_stack_a(t_stack **stack_a, t_nums *nums)
{
	t_stack	*temp;
	int		i;

	i = -1;
	while (++i < nums->num_of_values)
	{
		temp = ft_newlst_value(nums, i);
		ft_addback_lst(stack_a, temp);
	}
}

void	ft_index_to_stack_a(t_stack **stack_a, t_nums *nums)
{
	int		i;
	t_stack	*temp;

	ft_sort(nums);
	temp = *stack_a;
	while (temp->next)
	{
		i = -1;
		while (++i < nums->num_of_values)
		{
			if (temp->value == nums->list[i])
			{
				temp->index = i + 1;
				temp = temp->next;
				break ;
			}
		}
	}
	i = -1;
	while (++i < nums->num_of_values)
	{
		if (temp->value == nums->list[i])
			temp->index = i + 1;
	}
}

void	ft_sort_three(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (temp->index > temp->next->index
		&& temp->index > temp->next->next->index)
	{
		ft_ra(stack);
		ft_printf("ra\n");
	}
	else if (temp->next->index > temp->index
		&& temp->next->index > temp->next->next->index)
	{
		ft_rra(stack);
		ft_printf("rra\n");
	}
	temp = *stack;
	if (temp->index > temp->next->index)
	{
		ft_sa(stack);
		ft_printf("sa\n");
	}
}

void	ft_tostackb_vague(t_stack **stack_a, t_stack **stack_b, t_nums *nums)
{
	t_stack	*temp;
	int		i;
	int		j;

	i = 0;
	temp = *stack_a;
	while (temp)
	{
		if (temp->index < nums->num_of_values / 2)
		{
			j = -1;
			while (++j < i)
				ft_moves(stack_a, stack_b, 3);
			ft_moves(stack_a, stack_b, 1);
			temp = *stack_a;
			i = 0;
		}
		else
		{
			temp = temp->next;
			i++;
		}
	}
	ft_tostackb_vague_2(stack_a, stack_b);
}

void	ft_tostackb_vague_2(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = *stack_a;
	while (temp->next->next->next)
	{
		ft_moves(stack_a, stack_b, 1);
		temp = *stack_a;
	}
	ft_sort_three(stack_a);
}

void	ft_rotate_order(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		pos;
	int		rot;

	temp = *stack_a;
	rot = -1;
	ft_calculate_pos(stack_a);
	while (temp)
	{
		if (temp->index == 1)
			pos = temp->pos;
		temp = temp->next;
	}
	if (pos <= ft_size_lst(stack_a) / 2)
	{
		while (++rot < pos)
			ft_moves(stack_a, stack_b, 3);
	}
	else
	{
		rot = 1;
		while (--rot > pos - ft_size_lst(stack_a))
			ft_moves(stack_a, stack_b, 6);
	}
}
