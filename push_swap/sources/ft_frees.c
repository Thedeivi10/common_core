/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:53:33 by davigome          #+#    #+#             */
/*   Updated: 2025/01/03 22:05:54 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_nums(t_nums *nums)
{
	int	i;

	i = -1;
	while (nums->values[++i])
		free(nums->values[i]);
	if (nums->list)
		free(nums->list);
	free(nums);
}
