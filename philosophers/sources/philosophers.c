/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:14:57 by davigome          #+#    #+#             */
/*   Updated: 2025/05/06 18:33:10 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <stdio.h>

void	ft_init(t_args *args, char **argv, int argc)
{
	int i;

	i = -1;
	args->table->numPhilo = ft_atoi(argv[1]);
	args->table->time_die = ft_atoi(argv[2]);
	args->table->time_eat = ft_atoi(argv[3]);
	args->table->time_sleep = ft_atoi(argv[4]);
	args->table->philosophers = malloc(sizeof(t_philo) * (args->table->numPhilo + 1));
	while (++i < args->table->numPhilo)
	{
		args->table->philosophers[i] = malloc(sizeof(t_philo));
		pthread_mutex_init(&args->table->philosophers[i]->fork, NULL);
		if (argc == 6)
			args->table->philosophers[i]->lunchs = ft_atoi(argv[5]);
		else
			args->table->philosophers[i]->lunchs = -1;
	}
	args->idPhilo = -1;
	args->table->init = -1;
	args->table->flag = -1;
}

void	ft_pair(t_args *args, int i)
{
	pthread_mutex_lock(&args->table->philosophers[i]->fork);
	if (args->table->numPhilo == i + 1)
		pthread_mutex_lock(&args->table->philosophers[0]->fork);
	else
		pthread_mutex_lock(&args->table->philosophers[i + 1]->fork);
	usleep(0.98 * args->table->time_eat);
	if (args->table->numPhilo == i + 1)
		pthread_mutex_unlock(&args->table->philosophers[0]->fork);
	else
		pthread_mutex_unlock(&args->table->philosophers[i + 1]->fork);
	usleep(0.98 * args->table->time_sleep);
}

void	ft_impair(t_args *args, int i)
{
	if (args->table->philosophers[i + 1])
		pthread_mutex_lock(&args->table->philosophers[i + 1]->fork);
	if (args->table->numPhilo == i + 1 && i != 0)
		pthread_mutex_lock(&args->table->philosophers[0]->fork);
	pthread_mutex_lock(&args->table->philosophers[i]->fork);
	usleep(0.98 * args->table->time_eat);
	if (args->table->philosophers[i + 1])
		pthread_mutex_unlock(&args->table->philosophers[i + 1]->fork);
	if (args->table->numPhilo == i + 1 && i != 0)
		pthread_mutex_unlock(&args->table->philosophers[0]->fork);
	pthread_mutex_unlock(&args->table->philosophers[i]->fork);
	usleep(0.98 * args->table->time_sleep);
}

void	*ft_philo(void *data)
{
	t_args *args;
	int		i;
	
	args = (t_args *)data;
	i = ++args->idPhilo;
	while (args->table->init == -1);
	if (i % 2 == 0)
		usleep(10);
	if (i % 2 == 0)
		ft_pair(args, i);
	else
		ft_impair(args, i);
	return (NULL);
}

void	*ft_dead(void *data)
{
	t_args *args;
	struct	timeval tv;

	args = (t_args *)data;
	args->table->init = 0;
	gettimeofday(&tv, NULL);
	args->table->time_start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	printf("empieza en t = %ld\n",args->table->time_start);
	return (NULL);
}

void	ft_start(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->table->numPhilo)
	{
		args->table->philosophers[i]->name = i + 1;
		printf("creando hilo de filosofo %i\n", args->table->philosophers[i]->name);
		pthread_create(&args->table->philosophers[i]->id, NULL, ft_philo, args);
	}
	pthread_create(&args->table->dead, NULL, ft_dead, args);
	i = -1;
	while (++i < args->table->numPhilo)
		pthread_join(args->table->philosophers[i]->id, NULL);
}
//para optimizar el usleep coger y poner usleep 0.95
int	main(int argc, char **argv)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	args->table = malloc(sizeof(t_table));
	if (argc < 5 || argc > 6)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	ft_check(argv);
	ft_init(args, argv, argc);
	ft_start(args);
}
