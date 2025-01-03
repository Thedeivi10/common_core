/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:36:17 by davigome          #+#    #+#             */
/*   Updated: 2025/01/03 12:57:58 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack *new_head;
	
	temp = *stack_a;
	new_head = temp->next;
	while (temp->next)
		temp = temp->next;
	temp->next = *stack_a;
	temp = temp->next;
	temp->next = NULL;
	*stack_a = new_head;
}

void	ft_rb(t_stack **stack_b)
{
	ft_ra(stack_b);
}
void	ft_rra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*penultimate;
	t_stack	*last;

	temp = *stack_a;
	while (temp->next->next)
		temp = temp->next;
	penultimate = temp;
	last = temp->next;
	penultimate->next = NULL;
	temp = *stack_a;
	last->next = temp;
	*stack_a = last;
}

void	ft_rrb(t_stack **stack_b)
{
	ft_rra(stack_b);
}

void	ft_sa(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*aux;

	temp = *stack_a;
	aux = temp->next;
	temp->next = aux->next;
	aux->next = temp;
	*stack_a = aux;
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	aux = *stack_a;
	*stack_a = aux->next;
	ft_addfront_lst(stack_b, aux);
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_pb(stack_b, stack_a);
}
void	ft_moves(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (ft_strncmp(move, "pb", 2) == 0)
	{
		ft_printf("pb\n");
		ft_pb(stack_a, stack_b);
	}
	if (ft_strncmp(move, "pa", 2) == 0)
	{
		ft_printf("pa\n");
		ft_pa(stack_a, stack_b);
	}
	if (ft_strncmp(move, "ra", 2) == 0)
	{
		ft_printf("ra\n");
		ft_ra(stack_a);
	}
	if (ft_strncmp(move, "rb", 2) == 0)
	{
		ft_printf("rb\n");
		ft_rb(stack_b);
	}
	if (ft_strncmp(move, "rr", 2) == 0)
	{
		ft_printf("rr\n");
		ft_rb(stack_b);
		ft_ra(stack_a);
	}
	if (ft_strncmp(move, "rra", 3) == 0)
	{
		ft_printf("rra\n");
		ft_rra(stack_a);
	}
	if (ft_strncmp(move, "rrb", 3) == 0)
	{
		ft_printf("rrb\n");
		ft_rrb(stack_b);
	}
	if (ft_strncmp(move, "rrr", 3) == 0)
	{
		ft_printf("rrr\n");
		ft_rrb(stack_b);
		ft_rra(stack_a);
	}
}
