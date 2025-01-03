/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:20:47 by davigome          #+#    #+#             */
/*   Updated: 2025/01/03 22:05:37 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	space(const char *str, int cont)
{
	if ((str[cont] >= 9 && str[cont] <= 13) || str[cont] == 32)
		return (1);
	return (0);
}

long long	ft_atoi_long(const char *str)
{
	size_t		cont;
	long long	number;
	int			neg;

	cont = 0;
	number = 0;
	neg = 1;
	while (space(str, cont))
		cont++;
	if (str[cont] == '-' || str[cont] == '+')
	{
		if (str[cont] == '-')
			neg = -1;
		cont++;
	}
	while (ft_isdigit(str[cont]))
	{
		number = number * 10 + (str[cont] - 48);
		cont++;
	}
	number = neg * number;
	return (number);
}

t_stack	*ft_newlst_value(t_nums *nums, int i)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
	{
		ft_printf("Error\n");
		ft_free_nums(nums);
		exit(1);
	}
	new->value = nums->list[i];
	new->next = NULL;
	return (new);
}

void	ft_addback_lst(t_stack **stack, t_stack *new)
{
	t_stack	*now;

	if (*stack == NULL)
	{
		*stack = new;
	}
	else
	{
		now = *stack;
		while (now->next)
			now = now->next;
		now->next = new;
	}
}

void	ft_sort(t_nums *nums)
{
	int	i;
	int	j;
	int	aux;

	i = -1;
	while (++i < nums->num_of_values)
	{
		j = -1;
		while (++j < nums->num_of_values)
		{
			if (nums->list[i] < nums->list[j])
			{
				aux = nums->list[i];
				nums->list[i] = nums->list[j];
				nums->list[j] = aux;
			}
		}
	}
}

int	ft_size_lst(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	ft_addfront_lst(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

void	ft_calculate_pos(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (temp)
	{
		temp->pos = i;
		i++;
		temp = temp->next;
	}
}

void	ft_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		temp_max;
	int		min_index;
	int		pos_min;
	int		pos_max;

	ft_calculate_pos(stack_a);
	ft_calculate_pos(stack_b);
	temp_b = *stack_b;
	temp_a = *stack_a;
	min_index = temp_a->index;
	pos_min = temp_a->pos;
	while (temp_a)
	{
		if (temp_a->index < min_index)
		{
			pos_min = temp_a->pos;
			min_index = temp_a->index;
		}
		temp_a = temp_a->next;
	}
	while (temp_b)
	{
		temp_a = *stack_a;
		temp_max = -1;
		while (temp_a)
		{
			if (temp_max == -1)
			{
				if (temp_a->index > temp_b->index)
				{
					temp_max = temp_a->index;
					pos_max = temp_a->pos;
				}
			}
			if (temp_a->index > temp_b->index && temp_a->index < temp_max)
			{
				temp_max = temp_a->index;
				pos_max = temp_a->pos;
			}
			temp_a = temp_a->next;
		}
		if (temp_max == -1)
			temp_b->target_pos = pos_min;
		else
			temp_b->target_pos = pos_max;
		temp_b = temp_b->next;
	}
}

void	ft_calculate_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;

	temp_b = *stack_b;
	while (temp_b)
	{
		if (temp_b->pos <= ft_size_lst(stack_b) / 2)
			temp_b->cost_b = temp_b->pos;
		else
			temp_b->cost_b = temp_b->pos - ft_size_lst(stack_b);
		if (temp_b->target_pos <= ft_size_lst(stack_a) / 2)
			temp_b->cost_a = temp_b->target_pos;
		else
			temp_b->cost_a = temp_b->target_pos - ft_size_lst(stack_a);
		temp_b = temp_b->next;
	}
}

int	ft_the_cheap(t_stack **stack_b)
{
	t_stack *temp;
	int cheap;
	int prize;

	temp = *stack_b;
	prize = abs(temp->cost_a) + abs(temp->cost_b);
	cheap = temp->value;
	while (temp)
	{
		if ((abs(temp->cost_a) + abs(temp->cost_b)) < prize)
		{
			cheap = temp->value;
			prize = abs(temp->cost_a) + abs(temp->cost_b);
		}
		temp = temp->next;
	}
	return (cheap);
}