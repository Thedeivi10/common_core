#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

int main(void)
{
	struct timeval tv;
	time_t segundos;

	gettimeofday(&tv, NULL);
	printf("%ld\n", tv.tv_sec);
	segundos = tv.tv_sec;// * 1000;
	usleep(5000000); //  toma microsegundos aqui hay 5s
	gettimeofday(&tv, NULL);
	segundos = segundos - tv.tv_sec;
	printf("%ld\n", segundos);
/* 	Formula para el tiempo que es necesario
	(tv.tv_sec * 1000) + (tv.tv_usec / 1000) */
}

void ft_pair(t_args *args, int i)
{
    while (1)
    {
        pthread_mutex_lock(&args->table->philosophers[i]->fork);
        printf("%ld %i has taken a fork\n", ft_time(args), args->table->philosophers[i]->name);

        if (args->table->numPhilo == i + 1)
            pthread_mutex_lock(&args->table->philosophers[0]->fork);
        else
            pthread_mutex_lock(&args->table->philosophers[i + 1]->fork);

        printf("%ld %i has taken a fork\n", ft_time(args), args->table->philosophers[i]->name);
        printf("%ld %i is eating\n", ft_time(args), args->table->philosophers[i]->name);
        usleep(0.98 * args->table->time_eat);

        if (args->table->numPhilo == i + 1)
            pthread_mutex_unlock(&args->table->philosophers[0]->fork);
        else
            pthread_mutex_unlock(&args->table->philosophers[i + 1]->fork);

        pthread_mutex_unlock(&args->table->philosophers[i]->fork);
        printf("%ld %i is sleeping\n", ft_time(args), args->table->philosophers[i]->name);
        usleep(0.98 * args->table->time_sleep);
        printf("%ld %i is thinking\n", ft_time(args), args->table->philosophers[i]->name);
    }
}

void ft_impair(t_args *args, int i)
{
    while (1)
    {
        if (args->table->numPhilo == i + 1)
            pthread_mutex_lock(&args->table->philosophers[0]->fork);
        else
            pthread_mutex_lock(&args->table->philosophers[i + 1]->fork);

        printf("%ld %i has taken a fork\n", ft_time(args), args->table->philosophers[i]->name);
        pthread_mutex_lock(&args->table->philosophers[i]->fork);
        printf("%ld %i has taken a fork\n", ft_time(args), args->table->philosophers[i]->name);
        printf("%ld %i is eating\n", ft_time(args), args->table->philosophers[i]->name);
        usleep(0.98 * args->table->time_eat);

        if (args->table->numPhilo == i + 1)
            pthread_mutex_unlock(&args->table->philosophers[0]->fork);
        else
            pthread_mutex_unlock(&args->table->philosophers[i + 1]->fork);

        pthread_mutex_unlock(&args->table->philosophers[i]->fork);
        printf("%ld %i is sleeping\n", ft_time(args), args->table->philosophers[i]->name);
        usleep(0.98 * args->table->time_sleep);
        printf("%ld %i is thinking\n", ft_time(args), args->table->philosophers[i]->name);
    }
}
