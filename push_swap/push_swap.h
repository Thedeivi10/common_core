/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:18:02 by davigome          #+#    #+#             */
/*   Updated: 2024/12/29 15:45:30 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

typedef struct	s_stack
{
	int				value;		//The integer we must sort
	int				index;		//Its index in the list of all values that must be sorted
	int				pos;		//Its current position in its stack
	int				target_pos; //For elements in stack B, the target position in stack A where it should be
	int				cost_a;		//How many actions it would cost to rotate stack A so that the element at the target position gets to the top of stack A
	int				cost_b;		//How many actions it would cost to rotate stack B so that this element gets to the top of stack B
	struct	s_stack	*next;		//Pointer to the next element in the list.
}	t_stack;

typedef struct	s_nums
{
	char			**values;	//Here we are going to 
	int				num_of_values;	//It's ussefull to allocate memory and save the values
	int				*list;
}	t_nums;

// FT_CHECKS.C //
void	ft_checks(char **argv, t_nums *nums);
void	ft_alloc_mem_values(char **argv, t_nums *nums);
void	ft_cpy_values(char **argv, t_nums *nums);
void	ft_check_sign_digit(t_nums *nums);
void	ft_not_digit(t_nums *nums);
void	ft_atoi_list_and_max_min(t_nums *nums);
void	ft_check_reps(t_nums *nums);
void	ft_check_sort(t_nums *nums);

// FT_FREES.C //
void	ft_free_nums(t_nums *nums);

// FT_UTILS.C //
long long	ft_atoi_long(const char *str);

// FT_START.C //
void	ft_two_values(t_nums *nums);
void	ft_three_values(t_nums *nums);
void	ft_select_algorithm(t_nums *nums);
void	ft_more_values(t_nums *nums);

# endif
