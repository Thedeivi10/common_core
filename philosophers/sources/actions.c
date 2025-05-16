/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:51:40 by davigome          #+#    #+#             */
/*   Updated: 2025/05/16 12:43:38 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	should_continue(t_args *args)
{
	int	result;
	
	pthread_mutex_lock(&args->table->mutex_flag);
	result = args->table->flag;
	pthread_mutex_unlock(&args->table->mutex_flag);
	return (result);
}

void	eat(t_args *args, int i)
{
	struct timeval	tv;
	long long		aux;

	ft_printf(args, 2, i);
	gettimeofday(&tv, NULL);
	aux = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	pthread_mutex_lock(&args->table->philosophers[i]->eat);
	args->table->philosophers[i]->last_eat = aux;
	pthread_mutex_unlock(&args->table->philosophers[i]->eat);
	usleep(0.95 * args->table->time_eat * 1000);
}

void	sleep_and_think(t_args *args, int i)
{
	ft_printf(args, 3, i);
	usleep(0.95 * args->table->time_sleep * 1000);
	if (!should_continue(args))
		return ;
	ft_printf(args, 4, i);
}


void	ft_dead_2(t_args *args, struct timeval tv, int i, int *aux_eats)
{
	long long	aux;

	aux = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	if (args->eats != -1)
		*aux_eats = args->table->numphilo;
	else
		*aux_eats = -1;
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
		pthread_mutex_lock(&args->table->philosophers[i]->mutex_lunchs);
		if (args->table->philosophers[i]->lunchs <= 0 && *aux_eats)
			--(*aux_eats);
		pthread_mutex_unlock(&args->table->philosophers[i]->mutex_lunchs);
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
	*aux_eats = -1;
	pthread_mutex_lock(&args->table->mutex_init);
	args->table->init = 0;
	pthread_mutex_unlock(&args->table->mutex_init);
	gettimeofday(&tv, NULL);
	pthread_mutex_lock(&args->table->mutex_start);
	args->table->time_start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	pthread_mutex_unlock(&args->table->mutex_start);
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
		if (*aux_eats != -1)
			break ;
	}
	free(aux_eats);
	return (NULL);
}
