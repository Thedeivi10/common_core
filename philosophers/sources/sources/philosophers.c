/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:14:57 by davigome          #+#    #+#             */
/*   Updated: 2025/05/05 21:15:25 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <stdio.h>

void	ft_init(t_args *args, char **argv, int argc)
{
	int i;

	i = -1;
	args->table->numPhilo = ft_atoi(argv[1]);
	
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
}

void	*ft_philo(void *data)
{
	t_args *args;
	
	args = (t_args *)data;
	args->table->philosophers[args->idPhilo]->name = args->idPhilo;
	printf("Hilo del filosofo %i", args->table->philosophers[args->idPhilo]->name);
	
}

void	ft_start(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->table->numPhilo)
	{
		args->idPhilo = i + 1;
		pthread_create(&args->table->philosophers[i]->id, NULL, ft_philo, args);
		if (i == 0)
			pthread_join(&args->table->philosophers[i]->id, NULL);
	}
	
}

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
