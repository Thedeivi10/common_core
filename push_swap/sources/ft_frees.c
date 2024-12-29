/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:53:33 by davigome          #+#    #+#             */
/*   Updated: 2024/12/29 11:06:36 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_nums(t_nums *nums)
{
	int i;

	i = -1;
	while(nums->values[++i])
		free(nums->values[i]);
	if (nums->list)
		free(nums->list);
	free(nums);	
}
