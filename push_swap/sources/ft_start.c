/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:34:24 by davigome          #+#    #+#             */
/*   Updated: 2025/01/03 14:54:16 by davigome         ###   ########.fr       */
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

void	ft_more_values(t_nums *nums)
{
	t_stack	**stack_a;
	t_stack **stack_b;

	stack_a = malloc(sizeof(t_stack *));
	*stack_a = NULL;
	stack_b = malloc(sizeof(t_stack *));
	*stack_b = NULL;
	ft_values_to_stack_a(stack_a, nums);
	ft_index_to_stack_a(stack_a, nums);
	ft_tostackb_vague(stack_a, stack_b, nums);
	ft_target_pos(stack_a, stack_b);
	ft_calculate_cost(stack_a, stack_b);
	t_stack *temp;
	temp = *stack_b;
	int cheap;
	int aux;
	while (temp)
	{
		cheap = ft_the_cheap(stack_b);
		while (temp)
		{
			if (temp->value == cheap)
				break ;
			temp = temp->next;
		}
		aux = temp->value;
		if (aux != cheap)
			ft_printf("no son iguales");
		while (temp->cost_a > 0 && temp->cost_b > 0)
		{
			ft_moves(stack_a, stack_b, "rr");
			--(temp->cost_a);
			--(temp->cost_b);
		}
		while (temp->cost_a < 0 && temp->cost_b < 0)
		{
			ft_moves(stack_a, stack_b, "rrr");
			++(temp->cost_a);
			++(temp->cost_b);
		}
		while (temp->cost_a > 0)
		{
			ft_moves(stack_a, stack_b, "ra");
			--(temp->cost_a);
		}
		while (temp->cost_a < 0)
		{
			ft_moves(stack_a, stack_b, "rra");
			++(temp->cost_a);
		}
		while (temp->cost_b > 0)
		{
			ft_moves(stack_a, stack_b, "rb");
			--(temp->cost_b);
		}
		while (temp->cost_b < 0)
		{
			ft_moves(stack_a, stack_b, "rrb");
			++(temp->cost_b);
		}
		ft_moves(stack_a, stack_b , "pa");
		ft_target_pos(stack_a,stack_b);
		ft_calculate_cost(stack_a, stack_b);
		temp = *stack_a;
		while(temp)
		{
			ft_printf("%i\n",temp->value);
			temp = temp->next;
		}
		ft_printf("\n\n\n");
		temp = *stack_b;
		while(temp)
		{
			ft_printf("%i con cost_a %i y cost_b %i y pos %i\n",temp->value, temp->cost_a, temp->cost_b, temp->pos);
			temp = temp->next;
		}
		temp = *stack_b;
	}
//	ft_rotate_order(stack_a, stack_b);
	/* temp = *stack_a;
	while(temp)
	{
		ft_printf("%i\n",temp->value);
		temp = temp->next;
	}
	ft_printf("\n\n\n");
	temp = *stack_b;
	while(temp)
	{
		ft_printf("%i con cost_a %i y cost_b %i\n",temp->value, temp->cost_a, temp->cost_b);
		temp = temp->next;
	}	 */
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
	int i ;
	t_stack *temp;

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
				break;
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
	if (temp->index > temp->next->index &&
		temp->index > temp->next->next->index)
	{
		ft_ra(stack);
		ft_printf("ra\n");
	}
	else if(temp->next->index > temp->index &&
		temp->next->index > temp->next->next->index)
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
	while(temp)
	{
		if (temp->index < nums->num_of_values / 2)
		{
			j = -1;
			while (++j < i)
				ft_moves(stack_a, stack_b, "ra");
			ft_moves(stack_a, stack_b, "pb");
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
	while(temp->next->next->next)
	{
		ft_moves(stack_a, stack_b, "pb");
		temp = *stack_a;
	}
	ft_sort_three(stack_a);
}

void	ft_rotate_order(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
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
	if (pos < ft_size_lst(stack_a) / 2)
	{
		while (++rot < pos)
			ft_moves(stack_a, stack_b, "ra");
	}
	else
	{
		rot = 0;
		while (--rot > pos - ft_size_lst(stack_a))
			ft_moves(stack_a, stack_b, "rra");
	}
}
