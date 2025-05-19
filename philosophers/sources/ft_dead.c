/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:35:15 by davigome          #+#    #+#             */
/*   Updated: 2025/05/19 10:43:15 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_dead_4(t_args *args, int *aux_eats)
{
	if (args->eats != -1)
		*aux_eats = args->table->numphilo;
	else
		*aux_eats = -1;
}

void	ft_dead_5(t_args *args, int i, int *aux_eats)
{
	pthread_mutex_lock(&args->table->philosophers[i]->mutex_lunchs);
	if (args->table->philosophers[i]->lunchs <= 0)
		--(*aux_eats);
	pthread_mutex_unlock(&args->table->philosophers[i]->mutex_lunchs);
}

void	ft_dead_2(t_args *args, struct timeval tv, int i, int *aux_eats)
{
	long long	aux;

	aux = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	ft_dead_4(args, aux_eats);
	while (args->table->philosophers[++i])
	{
		pthread_mutex_lock(&args->table->philosophers[i]->eat);
		if (args->table->time_die
			< (aux - args->table->philosophers[i]->last_eat))
		{
			pthread_mutex_unlock(&args->table->philosophers[i]->eat);
			if (args->table->philosophers[i]->lunchs == 0)
				break ;
			pthread_mutex_lock(&args->table->mutex_flag);
			args->table->flag = 0;
			pthread_mutex_unlock(&args->table->mutex_flag);
			ft_printf(args, 5, i);
			break ;
		}
		else
			pthread_mutex_unlock(&args->table->philosophers[i]->eat);
		ft_dead_5(args, i, aux_eats);
	}
}

void	ft_dead_3(int *aux_eats, t_args *args, struct timeval tv)
{
	*aux_eats = -1;
	pthread_mutex_lock(&args->table->mutex_init);
	args->table->init = 0;
	pthread_mutex_unlock(&args->table->mutex_init);
	gettimeofday(&tv, NULL);
	pthread_mutex_lock(&args->table->mutex_start);
	args->table->time_start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	pthread_mutex_unlock(&args->table->mutex_start);
}

int	ft_checkEats(t_args *args)
{
	int i;

	i = -1;

	while (++i < args->table->numphilo)
	{
		
	}
}

void	*ft_dead(void *data)
{
	t_args			*args;
	struct timeval	tv;
	int				i;
	int				*aux_eats;

	args = (t_args *)data;
	i = -1;
	aux_eats = malloc(sizeof(int));
	ft_dead_3(aux_eats, args, tv);
	while (args->table->philosophers[++i])
	{
		pthread_mutex_lock(&args->table->philosophers[i]->eat);
		args->table->philosophers[i]->last_eat = args->table->time_start;
		pthread_mutex_unlock(&args->table->philosophers[i]->eat);
	}
	while (args->table->flag == -1)
	{
		i = -1;
		gettimeofday(&tv, NULL);
		ft_dead_2(args, tv, i, aux_eats);
		if (!ft_checkEats(args))
			break ;
	}
	free(aux_eats);
	return (NULL);
}
