/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:57:21 by davigome          #+#    #+#             */
/*   Updated: 2025/05/06 17:42:47 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_mutex_t	fork;
	pthread_t		id;
	long long		last_eat;
	size_t			lunchs;
	int				name;
}				t_philo;

typedef struct s_table
{
	t_philo			**philosophers;
	int				flag;
	long long		time_eat;
	long long		time_sleep;
	long long		time_die;
	long long		time_start;
	int				numPhilo;
	pthread_t		dead;
	int				init;
}				t_table;

typedef struct s_args
{
	t_table			*table;
	int				idPhilo;
}				t_args;

//	FT_CHECK.C //
void	ft_check(char **argv);

// UTILS.C //
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);

#endif