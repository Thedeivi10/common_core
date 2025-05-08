/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:14:57 by davigome          #+#    #+#             */
/*   Updated: 2025/05/08 18:50:54 by davigome         ###   ########.fr       */
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
	args->table->philosophers[args->table->numPhilo] = NULL;
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

long long 	ft_time(t_args *args)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000 + tv.tv_usec / 1000) - args->table->time_start;
	return (time);
}

void ft_pair(t_args *args, int i)
{
	struct timeval tv;

    while (args->table->flag == -1)
    {
        pthread_mutex_lock(&args->table->philosophers[i]->fork);
		if (args->table->flag == 0)
			break;
        printf("%lld %i has taken a fork\n", ft_time(args), args->table->philosophers[i]->name);
        if (args->table->numPhilo == i + 1)
            pthread_mutex_lock(&args->table->philosophers[0]->fork);
        else
            pthread_mutex_lock(&args->table->philosophers[i + 1]->fork);
		if (args->table->flag == 0)
			break;
        printf("%lld %i has taken a fork\n", ft_time(args), args->table->philosophers[i]->name);
        printf("%lld %i is eating\n", ft_time(args), args->table->philosophers[i]->name);
		gettimeofday(&tv, NULL);
		args->table->philosophers[i]->last_eat = tv.tv_sec * 1000 + tv.tv_usec / 1000;
        usleep(0.97 * args->table->time_eat * 1000);
        if (args->table->numPhilo == i + 1)
            pthread_mutex_unlock(&args->table->philosophers[0]->fork);
        else
            pthread_mutex_unlock(&args->table->philosophers[i + 1]->fork);
        pthread_mutex_unlock(&args->table->philosophers[i]->fork);
		if (args->table->flag == 0)
			break;
        printf("%lld %i is sleeping\n", ft_time(args), args->table->philosophers[i]->name);
        usleep(0.97 * args->table->time_sleep * 1000);
		if (args->table->flag == 0)
			break;
        printf("%lld %i is thinking\n", ft_time(args), args->table->philosophers[i]->name);
		if (--args->table->philosophers[i]->lunchs == 0)
			break;
    }
}

void ft_impair(t_args *args, int i)
{
	struct timeval tv;

    while (args->table->flag == -1)
    {
        if (args->table->numPhilo == i + 1)
            pthread_mutex_lock(&args->table->philosophers[0]->fork);
        else
            pthread_mutex_lock(&args->table->philosophers[i + 1]->fork);
		if (args->table->flag == 0)
			break;
        printf("%lld %i has taken a fork\n", ft_time(args), args->table->philosophers[i]->name);
        pthread_mutex_lock(&args->table->philosophers[i]->fork);
		if (args->table->flag == 0)
			break;
        printf("%lld %i has taken a fork\n", ft_time(args), args->table->philosophers[i]->name);
        printf("%lld %i is eating\n", ft_time(args), args->table->philosophers[i]->name);
		gettimeofday(&tv, NULL);
		args->table->philosophers[i]->last_eat = tv.tv_sec * 1000 + tv.tv_usec / 1000;
        usleep(0.97 * args->table->time_eat * 1000);
        if (args->table->numPhilo == i + 1)
            pthread_mutex_unlock(&args->table->philosophers[0]->fork);
        else
            pthread_mutex_unlock(&args->table->philosophers[i + 1]->fork);
        pthread_mutex_unlock(&args->table->philosophers[i]->fork);
		if (args->table->flag == 0)
			break;
        printf("%lld %i is sleeping\n", ft_time(args), args->table->philosophers[i]->name);
        usleep(0.97 * args->table->time_sleep * 1000);
		if (args->table->flag == 0)
			break;
        printf("%lld %i is thinking\n", ft_time(args), args->table->philosophers[i]->name);
		if (--args->table->philosophers[i]->lunchs == 0)
			break;
    }
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
	int				i;
	int				j;
	long long aux;
	int				aux_eats;

	args = (t_args *)data;
	i = -1;
	j = -1;
	args->table->init = 0;
	gettimeofday(&tv, NULL);
	args->table->time_start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	while (args->table->philosophers[++i])
		args->table->philosophers[i]->last_eat = args->table->time_start;
	while (args->table->flag == -1 || args->table->eats == -1)
	{
		i = -1;
		gettimeofday(&tv, NULL);
		aux = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		while (args->table->philosophers[++i])
		{
			if (args->table->time_die < (aux - args->table->philosophers[i]->last_eat))
			{
				args->table->flag = 0;
				printf("%lld %i died\n", ft_time(args), args->table->philosophers[i]->name);
				while (args->table->philosophers[++j])
					pthread_mutex_unlock(&args->table->philosophers[j]->fork);
				break;
			}
			
		}
	}
	return (NULL);
}

void	ft_start(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->table->numPhilo)
	{
		args->table->philosophers[i]->name = i + 1;
		pthread_create(&args->table->philosophers[i]->id, NULL, ft_philo, args);
	}
	pthread_create(&args->table->dead, NULL, ft_dead, args);
	i = -1;
	while (++i < args->table->numPhilo){
		pthread_join(args->table->philosophers[i]->id, NULL);
	}	
}

void	ft_free(t_args *args)
{
	int	i;

	i = -1;
	while (args->table->philosophers[++i])
		pthread_mutex_destroy(&args->table->philosophers[i]->fork);
	i = -1;
	while (args->table->philosophers[++i])
		free(args->table->philosophers[i]);
	free(args->table->philosophers);
	free(args->table);
	free(args);
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
	ft_free(args);
}

//valgrind --fair-sched=yes --tool=helgrind ./philo 1 200 200 200
//https://42-evaluation-sheets-hub.vercel.app/Cursus/Philosophers/index.html