/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:10:03 by davigome          #+#    #+#             */
/*   Updated: 2024/12/29 13:41:20 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_checks(char **argv, t_nums *nums)
{	
	ft_alloc_mem_values(argv, nums);
	ft_cpy_values(argv, nums);
	ft_check_sign_digit(nums);
	ft_atoi_list_and_max_min(nums);
	ft_check_reps(nums);
	ft_check_sort(nums);
}

void	ft_alloc_mem_values(char **argv, t_nums *nums)
{
	int		i;
	int		j;
	char	**aux_val;

	i = 0;
	nums->num_of_values = 0;
	while(argv[++i])
	{
		j = -1;
		aux_val = ft_split(argv[i], ' ');
		while(aux_val[++j])
			nums->num_of_values++;
		ft_free_matrix(aux_val);
	}
	nums->values = malloc(sizeof(char *) * ((nums->num_of_values) + 1));
	if (!nums->values)
	{
		ft_free_nums(nums);
		ft_printf("Error, could not allocate memory");
		exit (1);
	}
}

void	ft_cpy_values(char **argv, t_nums *nums)
{
	int		i;
	int		j;
	char	**aux_val;
	int		k;
	
	i = 0;
	j = 1;
	k = 0;
	while (i < nums->num_of_values)
	{
		aux_val = ft_split(argv[j], ' ');
		k = 0;
		while (aux_val[k])
		{
			nums->values[i] = malloc(sizeof(char) * (ft_strlen(aux_val[k]) + 1));
			ft_strlcpy (nums->values[i], aux_val[k], ft_strlen(aux_val[k]) + 1);
			i++;
			k++;
		}
		j++;
		ft_free_matrix(aux_val);
	}
}

void	ft_check_sign_digit(t_nums *nums)
{
	int		i;
	int		j;

	i = -1;
	while (nums->values[++i])
	{
		j = 0;
		while (nums->values[i][j] == ' ')
			j++;
		if (nums->values[i][j] == '+' || nums->values[i][j] == '-')
			j++;
		if (nums->values[i][j] == '+' || nums->values[i][j] == '-')
		{
			ft_printf("One or more values have more than one sign\n");
			ft_free_nums(nums);
			exit(1);
		}
		while (nums->values[i][j] != '\0')
		{
			if (!ft_isdigit(nums->values[i][j]))
				ft_not_digit(nums);
			j++;
		}
	}
}

void	ft_not_digit(t_nums *nums)
{
	ft_printf("One or more values are not digits\n");
	ft_free_nums(nums);
	exit(1);
}

void	ft_atoi_list_and_max_min(t_nums *nums)
{
	int i = -1;

	nums->list = malloc(sizeof(int) * nums->num_of_values);
	while(nums->values[++i])
	{
		if(ft_atoi_long(nums->values[i]) > 2147483647 || ft_atoi_long(nums->values[i]) < -2147483648)
		{
			ft_printf("Error: number bigger or smaller than MAX or MIN integer\n");
			ft_free_nums(nums);
			exit(1);
		}
		else
			nums->list[i] = ft_atoi(nums->values[i]);
	}
	i = -1;
}

void	ft_check_reps(t_nums *nums)
{
//	int	*aux;
	int reps;
	int i;
	int j;

	reps = 0;
	i = -1;
	while (++i < nums->num_of_values)
	{
		j = -1;
		reps = 0;
		while (++j < nums->num_of_values)
		{
			if (nums->list[i] == nums->list[j])
				reps++;
		}
		if (reps > 1)
		{
			ft_printf("There is the same value two or more times\n");
			ft_free_nums(nums);
			exit(1);
		}
	}
}

void	ft_check_sort(t_nums *nums)
{
	int i;
	int flag;

	i = -1;
	flag = 0;
	while (++i < nums->num_of_values - 1)
	{
		if(nums->list[i] > nums->list[i + 1])
			flag++;
	}
	if (flag == 0)
	{
		ft_free_nums(nums);
		exit(0);
	}
}
